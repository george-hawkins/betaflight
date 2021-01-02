/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>

#include "platform.h"

#include "io/serial.h"

#include "hardware_revision.h"

// TODO: what's the correct way to do the inverse of RESOURCE_INDEX in resource.h?
#define RESOURCE_OFFSET(x) (x - 1)

void targetPreInit(void)
{
    int indexA = RESOURCE_OFFSET(serialConfigMutable()->swap_ports[0]);
    int indexB = RESOURCE_OFFSET(serialConfigMutable()->swap_ports[1]);

    if (indexA < 0 || indexB < 0) {
        return;
    }

    uint8_t enabled = hardwareRevision == NUCLEOF722_SWAP_PORTS_ENABLED;

    // If enabled has changed then indexA port swaps its pins with indexB port.
    if (serialConfig()->swap_ports_enabled != enabled) {
        serialConfigMutable()->swap_ports_enabled = enabled;

        ioTag_t tx = serialPinConfig()->ioTagTx[indexA];
        ioTag_t rx = serialPinConfig()->ioTagRx[indexA];

        serialPinConfigMutable()->ioTagTx[indexA] = serialPinConfig()->ioTagTx[indexB];
        serialPinConfigMutable()->ioTagRx[indexA] = serialPinConfig()->ioTagRx[indexB];
        serialPinConfigMutable()->ioTagTx[indexB] = tx;
        serialPinConfigMutable()->ioTagRx[indexB] = rx;

    }
}
