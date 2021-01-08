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

#pragma once

// My settings - see hardware_revision.c and initialisation.c
#define USE_HARDWARE_REVISION_DETECTION
#define HW_PIN PB1
#define TARGET_PREINIT

#define TARGET_BOARD_IDENTIFIER "NU72"

#define USBD_PRODUCT_STRING "NucleoF722"

#define LED0_PIN   PB7  // blue
#define LED1_PIN   PB14 // red

#define USABLE_TIMER_CHANNEL_COUNT 0

#define USE_VCP
#define USE_USB_DETECT
#define USB_DETECT_PIN PA9

#define USE_UART2
#define UART2_RX_PIN PD6
#define UART2_TX_PIN PD5

#define USE_UART3
#define UART3_RX_PIN PD9
#define UART3_TX_PIN PD8

#define USE_UART4
#define UART4_RX_PIN PA1
#define UART4_TX_PIN PA0

#define USE_SOFTSERIAL1
#define USE_SOFTSERIAL2

#define SERIAL_PORT_COUNT 6 //VCP, USART2, USART3, UART4, SOFTSERIAL x 2

#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_SBUS

// Define which pins are available, e.g. all PA pins, all PB pins etc.
#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff
#define TARGET_IO_PORTF 0xffff

// Setting DEFAULT_AUX_CHANNEL_COUNT, PID_PROFILE_COUNT and CONTROL_RATE_PROFILE_COUNT to 1 saves about 2295B.

#define MINIMAL_CLI // Saves 5196B - if you're using the CLI.

//#undef USE_CLI // Saves 58723B

#undef USE_BLACKBOX // Saves 15084B
#undef USE_BOARD_INFO // Saves 1292B
#undef USE_CMS // Saves 24325B
#undef USE_D_MIN // Saves 1392B
#undef USE_DSHOT // Saves 42261B
#undef USE_DYN_LPF // Saves 1473B
#undef USE_GPS_NMEA // Saves 2096B
#undef USE_GPS_UBLOX // Saves 2952B
#undef USE_GYRO_DATA_ANALYSE // Saves 7072B
#undef USE_INTEGRATED_YAW_CONTROL // Saves 1136B
#undef USE_INTERPOLATED_SP // Saves 1680B
#undef USE_ITERM_RELAX // Saves 1784B
#undef USE_LED_STRIP_STATUS_MODE // Saves 9133B
#undef USE_OSD // Saves 17712B
#undef USE_RCDEVICE // Saves 1845B
#undef USE_RC_SMOOTHING_FILTER // Saves 7024B
#undef USE_RUNAWAY_TAKEOFF // Saves 1264B
#undef USE_SERIAL_4WAY_BLHELI_BOOTLOADER // Saves 2676B
#undef USE_SERIAL_4WAY_SK_BOOTLOADER // Saves 1468B
#undef USE_SERVOS // Saves 5257B
#undef USE_USB_CDC_HID // Saves 2024B

// ----

// Without USE_SERIAL_RX, you won't get SBUS etc.
//#undef USE_SERIAL_RX // Saves 30810B

// The following are dependant on USE_SERIAL_RX being defined.
#undef USE_RX_RSSI_DBM // Saves 104B
#undef USE_SPEKTRUM_FAKE_RSSI // Saves 192B
#undef USE_SPEKTRUM_REAL_RSSI // Saves 408B
#undef USE_SERIALRX_SUMH // Saves 508B
#undef USE_CRSF_LINK_STATISTICS // Saves 648B
#undef USE_SERIALRX_JETIEXBUS // Saves 680B
#undef USE_SERIALRX_SUMD // Saves 960B
#undef USE_SPEKTRUM_BIND // Saves 983B
//#undef USE_SERIALRX_SBUS // Saves 993B
#undef USE_SERIALRX_XBUS // Saves 1700B
#undef USE_SERIALRX_CRSF // Saves 1733B
#undef USE_SERIALRX_IBUS // Saves 1769B
#undef USE_SERIALRX_SPEKTRUM // Saves 2723B

// ----

// Without USE_VTX_CONTROL, you won't get SA etc. at all, without USE_VTX_COMMON you won't
// get support for controlling a common set of features across the various VTX protocols.
//#undef USE_VTX_CONTROL // Saves 12905B
//#undef USE_VTX_COMMON // Saves 11694B

// USE_VTX_TABLE is the modern way for configuring a table of bands, frequencies and power levels.
// However, certain flight controllers may not have enough space to support the resulting tables.
//#undef USE_VTX_TABLE // Saves 2211B

//#undef USE_VTX_SMARTAUDIO // Saves 6013B
#undef USE_VTX_TRAMP // Saves 1320B

// If you want Spektrum VTX support then USE_SERIALRX_SPEKTRUM has to be defined. This enables various
// Spektrum features. If you've defined USE_SERIALRX_SPEKTRUM and then want to specifically disable
// the Spektrum VTX features, you can undefine USE_SPEKTRUM_VTX_TELEMETRY to disable just telemetry data
// about the VTX or undefine USE_SPEKTRUM_VTX_CONTROL to disable Spektrum VTX support altogether but
// both together save only 340B.

// ----

//#undef USE_TELEMETRY // Saves 18824B

// ----

// The following 22 undefines barely save anything, combined they save a total of only 9598B.
#undef USE_BATTERY_VOLTAGE_SAG_COMPENSATION // Saves 756B
#undef USE_BRUSHED_ESC_AUTODETECT // Saves 156B
#undef USE_CAMERA_CONTROL // Saves 744B
#undef USE_CUSTOM_BOX_NAMES // Saves 280B
#undef USE_GPS // Saves 132B
#undef USE_GYRO_OVERFLOW_CHECK // Saves 340B
#undef USE_LAUNCH_CONTROL // Saves 820B
#undef USE_MCO // Saves 176B
#undef USE_MSP_DISPLAYPORT // Saves 48B
#undef USE_MULTI_GYRO // Saves 804B
#undef USE_PERSISTENT_STATS // Saves 388B
#undef USE_PINIOBOX // Saves 120B
#undef USE_PIN_PULL_UP_DOWN // Saves 136B
#undef USE_PPM // Saves 820B
#undef USE_RTC_TIME // Saves 1002B
#undef USE_SERIALRX_SRXL2 // Saves 416B
#undef USE_TASK_STATISTICS // Saves 800B
#undef USE_THROTTLE_BOOST // Saves 208B
#undef USE_THRUST_LINEARIZATION // Saves 204B
#undef USE_TPA_MODE // Saves 16B
#undef USE_UNCOMMON_MIXERS // Saves 736B
#undef USE_VIRTUAL_CURRENT_METER // Saves 496B
