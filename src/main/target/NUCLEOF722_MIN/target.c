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

#include "drivers/timer_def.h"
#include "drivers/timer.h"

// To add a pin, just copy the entry for that pin in src/main/drivers/timer_stm32f7xx.c (or the appropriate drivers
// file if using another MCU) and modify TIM_USE_ANY to one of the other values, e.g. TIM_USE_MOTOR, if appropriate.
const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
    DEF_TIM(TIM3, CH1, PB4, TIM_USE_ANY, 0, 0),
};
