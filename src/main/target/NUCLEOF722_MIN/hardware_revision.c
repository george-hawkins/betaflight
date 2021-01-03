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
#include <stdlib.h>

#include "platform.h"

#include "build/build_config.h"

#include "drivers/io.h"
#include "drivers/time.h"

#include "hardware_revision.h"

uint8_t hardwareRevision = NUCLEOF722_SWAP_PORTS_DISABLED;

void detectHardwareRevision(void)
{
    IO_t pin = IOGetByTag(IO_TAG(HW_PIN));
    IOInit(pin, OWNER_SYSTEM, 0);
    IOConfigGPIO(pin, IOCFG_IPU);

    delayMicroseconds(40);  // allow configuration to settle

    // If HW_PIN is shorted to ground then swap ports.
    if (!IORead(pin)) {
        hardwareRevision = NUCLEOF722_SWAP_PORTS_ENABLED;
    }
}

void updateHardwareRevision(void)
{
}
