# I'm using an F722ZE board, so it's not technically a F7X2RE_TARGETS but actually it turns out that only two things happen as a
# result of using F7X2RE_TARGETS:
# * make/mcu/STM32F7.mk defines STM32F722xx as the DEVICE_FLAGS
# * make/targets.mk adds the target to F7_TARGETS
# So given that DEVICE_FLAGS value, it would seems F7X2RE_TARGETS would have been more appropriately named F722XX_TARGETS.
F7X2RE_TARGETS += $(TARGET)

# Some features have to be explicitly enabled by adding to FEATURES. To see which features search make/source.mk for FEATURES.
#FEATURES += VCP

# The majority of files under src/main/drivers/accgyro are included automatically but specific devices have to be included
# explicitly. This is done using TARGET_SRC like so:
# TARGET_SRC = drivers/accgyro/accgyro_fake.c drivers/barometer/barometer_ms5611.c ...
