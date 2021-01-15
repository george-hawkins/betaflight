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

// Many targets define `USBD_PRODUCT_STRING`. However, it only comes into play if using src/main/vcpf4/usbd_desc.c
// but not if using src/main/vcp_hal/usbd_desc.c (where the hardcoded names "STM32 Virtual ComPort in HS Mode" and
// "STM32 Virtual ComPort in FS Mode" are used). vcp_hal is used by F7 and H7 targets while vcpf4 is used by F4
// targets (and F1 and F3 targets use src/main/vcp).

#define LED0_PIN PB7  // blue
#define LED1_PIN PB14 // red

//#define USE_SMARTAUDIO_DPRINTF

// Works:
//
// * UART1_TX_PIN PB6
// * UART1_RX_PIN NONE
//
// * UART2_RX_PIN PD6 / PA3
// * UART2_TX_PIN PD5
//
// * UART3_TX_PIN PB10 / PC10
// * UART3_RX_PIN PB11 / PC11
//
// * UART4_TX_PIN PC10 / PA0
// * UART4_RX_PIN PC11
//
// * UART5_TX_PIN PC12
// * UART5_RX_PIN PD2
//
// * UART6_TX_PIN PC6
// * UART6_RX_PIN PC7
//
// * UART7_TX_PIN PE8 / PF7
// * UART7_RX_PIN PE7
//
// * UART8_RX_PIN PE0
//
// Didnt't work:
//
// * UART6_TX_PIN PG14
// * UART6_RX_PIN PG9
//
// Note: TARGET_IO_PORTG must be defined in order to use G pins (or compilation fails) but evidently more is still required.
// I suspect this isn't anything fundamental and simply that G pins are not used (no other target currently specifies a G pin for
// anything) and so some minor setup has been missed out for G. However, PG9 and PG14 are defined as UART6 pins in
// src/main/drivers/serial_uart_stm32f7xx.c so they _should_ work.
//

// Like `timerHardware` (discussed below), if you add or remove UARTS or change their pin assignments
// then you have to reset all settings before these changes will show up in the Configurator.

// Many pins can be used for different purposes, e.g. UART, SPI etc. So I looked at which UARTs and which pin combinations are most
// commonly seen in the existing targets and chose the 4 most popular pairs on the basis that these pairs are unlikely to clash
// with some other common popular use for a given pin. Interestingly, UARTs 1 and 2 are far less commonly used that UARTs 3 to 6.
// I thought initially this might be because UARTs 1 and 2 are typically hardwired to other devices on the flight controller but
// even if these UARTs aren't available for end-users to use they still have to be defined for use in Betaflight (i.e. Betaflight
// has to know the pins for a given UART whether it's connected to another device on the flight controller or to something connected
// to UART pins exposed at the edge of the board).
// I guess instead it reflects something to do with what devices are exposed on the low pin-count packages, like LQFP64, typically
// used in flight controllers, i.e. maybe UARTs 1 and 2 aren't exposed on these chips.

// Remember to also comment/uncomment the VCP feature in target.mk to match whether USE_VCP is defined or not.
//#define USE_VCP // Not defining USE_VCP save 18024B.

// If using USE_SOFTSERIAL1 and/or USE_SOFTSERIAL2, each counts towards the port count.
#ifdef USE_VCP
#define USE_USB_DETECT
#define USB_DETECT_PIN PA9
#define SERIAL_PORT_COUNT 5 // VCP, USART3, UART4, UART5, UART6
#else
#define SERIAL_PORT_COUNT 4 // USART3, UART4, UART5, UART6
#define USE_TARGET_CONFIG // Enable specifying MSP port in config.c
#endif

// 90 targets use these pins like this.
#define USE_UART3
#define UART3_TX_PIN PB10
#define UART3_RX_PIN PB11

// 17 targets use these pins like this.
#define USE_UART4
#define UART4_TX_PIN PC10
#define UART4_RX_PIN PC11

// 44 targets use these pins like this.
#define USE_UART5
#define UART5_TX_PIN PC12
#define UART5_RX_PIN PD2

// 56 targets use these pins like this.
#define USE_UART6
#define UART6_TX_PIN PC6
#define UART6_RX_PIN PC7

//#define USE_SOFTSERIAL1
//#define SOFTSERIAL1_TX_PIN PB4 // Alternatively, one could specify `resource SERIAL_TX 11 B04` via the CLI.
//#define USE_SOFTSERIAL2

#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_SBUS

// Define which pins are available, e.g. all PA pins, all PB pins etc.
#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff
#define TARGET_IO_PORTF 0xffff

#define USABLE_TIMER_CHANNEL_COUNT 1 // The number of pins that are defined in timerHardware in target.c.
#define USED_TIMERS  ( TIM_N(3) ) // An ORed list of the timers used in entries in timerHardware.

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
#undef USE_SERIAL_RX // Saves 30810B

// The following are dependant on USE_SERIAL_RX being defined.
//#undef USE_RX_RSSI_DBM // Saves 104B
//#undef USE_SPEKTRUM_FAKE_RSSI // Saves 192B
//#undef USE_SPEKTRUM_REAL_RSSI // Saves 408B
//#undef USE_SERIALRX_SUMH // Saves 508B
//#undef USE_CRSF_LINK_STATISTICS // Saves 648B
//#undef USE_SERIALRX_JETIEXBUS // Saves 680B
//#undef USE_SERIALRX_SUMD // Saves 960B
//#undef USE_SPEKTRUM_BIND // Saves 983B
////#undef USE_SERIALRX_SBUS // Saves 993B
//#undef USE_SERIALRX_XBUS // Saves 1700B
//#undef USE_SERIALRX_CRSF // Saves 1733B
//#undef USE_SERIALRX_IBUS // Saves 1769B
//#undef USE_SERIALRX_SPEKTRUM // Saves 2723B

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

// Telemetry isn't just for data like RSSI or temperature, it's also the channel via which the flight controller can talk back to
// the TX using MSP over telemetry. So we need USE_TELEMETRY and USE_MSP_OVER_TELEMETRY along with the telemetry protocol used by
// the RX.
// Update: I thought MSP was coming in via the SBUS (as it comes in on an RX pin) and going out via SPORT (i.e. telemetry, as it
// goes out on a TX pin). But it turns out telemetry is bi-directional (and half-duplex) and MSP works via telemetry (SBUS is not
// involved).
//#undef USE_TELEMETRY // Saves 18824B
//#undef USE_MSP_OVER_TELEMETRY // Saves 1528B
//#undef USE_TELEMETRY_SMARTPORT // Saves 4728B
#undef USE_TELEMETRY_IBUS_EXTENDED // Saves 292B
#undef USE_TELEMETRY_LTM // Saves 1048B
#undef USE_TELEMETRY_HOTT // Saves 1536B
#undef USE_TELEMETRY_FRSKY_HUB // Saves 1756B
#undef USE_TELEMETRY_IBUS // Saves 1780B
#undef USE_SERIALRX_FPORT // Saves 3312B
#undef USE_TELEMETRY_MAVLINK // Saves 5312B

// Note that there are quite a lot of other telemetry related defines that don't come into play unless additional things are defined:
// * USE_DSHOT_TELEMETRY_STATS                                                                            
// * USE_ESC_SENSOR_TELEMETRY
// * USE_CRSF_CMS_TELEMETRY                                                                               
// * USE_SPEKTRUM_CMS_TELEMETRY
// * USE_TELEMETRY_CRSF
// * USE_TELEMETRY_JETIEXBUS                                                                              
// * USE_TELEMETRY_SRXL                                                                                   
// * USE_TELEMETRY_SENSORS_DISABLED_DETAILS

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
