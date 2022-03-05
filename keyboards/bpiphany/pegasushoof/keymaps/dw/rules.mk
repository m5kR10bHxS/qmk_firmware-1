# Pegasus Hoof rules.mk

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
MCU = atmega32u2
BOOTLOADER = atmel-dfu

# Build Options - Disable unused featfures to reduce the size of the binary. 
# Change yes to no to disable
#
# Hardware 
SPLIT_KEYBOARD = no        # Split common
BLUETOOTH_ENABLE = no      # Enable Bluetooth with the Adafruit EZ-Key HID
CUSTOM_MATRIX = yes        # Custom matrix file for the Pegasus Hoof due to the 2x74HC42
ENCODER_ENABLE = no        # Enable the use of one or more encoders
HD44780_ENABLE = no        # Enable support for HD44780 based LCDs
OLED_DRIVER_ENABLE = no    # Enable the use of OLED displays
# Illumination
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
SLEEP_LED_ENABLE = no      # Breathing sleep LED during USB suspend - CAUTION: may conflict with BACKLIGHT_ENABLE
# Audio
EXTRAKEY_ENABLE = yes      # Audio control and System control
MIDI_ENABLE = no           # MIDI support
AUDIO_ENABLE = no          # Audio output on port C6
FAUXCLICKY_ENABLE = no     # Use buzzer to emulate clicky switches
# Features
BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
LEADER_ENABLE = no         # Enable the Leader Key feature
MOUSEKEY_ENABLE = no       # Enable mouse emulation
NKRO_ENABLE = no           # USB Nkey Rollover - See: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
UNICODE_ENABLE = no        # Enable unicode support for codes up to 0x7FFF
LTO_ENABLE = yes           # Link Time Optimization - creates smaller binary
# DEFAULT_FOLDER = 

