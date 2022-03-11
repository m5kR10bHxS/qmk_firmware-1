# Pegasus Hoof / Filco Majestouch TKL rules.mk

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

# Build Options - Disable unused features to reduce the size of the binary. 
# Change yes to no to disable
# Hardware 
BLUETOOTH_ENABLE = no                # Enable Bluetooth with the Adafruit EZ-Key HID
CUSTOM_MATRIX = yes                  # Custom matrix file for the Pegasus Hoof due to the 2x74HC42
ENCODER_ENABLE = no                  # Enable the use of one or more encoders
HD44780_ENABLE = no                  # Enable support for HD44780 based LCDs
OLED_DRIVER_ENABLE = no              # Enable the use of OLED displays
SPLIT_KEYBOARD = no                  # Split, or 1-piece
# Illumination
#BACKLIGHT_DRIVER = custom           # Custom driver
BACKLIGHT_ENABLE = no                # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = yes                # Enable addressable underglow RGB LEDs - Enabled in info.json
SLEEP_LED_ENABLE = yes               # Breathing sleep LED during USB suspend - CAUTION: may conflict with BACKLIGHT_ENABLE
# Audio
AUDIO_ENABLE = no                    # Audio output on port C6
EXTRAKEY_ENABLE = yes                # Audio control and System control
FAUXCLICKY_ENABLE = no               # Use buzzer to emulate clicky switches
MIDI_ENABLE = no                     # MIDI support
# Features
BOOTMAGIC_ENABLE = no                # Virtual DIP switch configuration
COMMAND_ENABLE = no                  # Commands for debug and configuration
CONSOLE_ENABLE = no                  # Console for debug
DYNAMIC_TAPPING_TERM_ENABLE = yes    # Allow tapping term adjustmet on the fly NOTE: Adjustments are not persistent
LEADER_ENABLE = yes                  # Enable the Leader Key feature
LTO_ENABLE = yes                     # Link Time Optimization - creates smaller binary
MOUSEKEY_ENABLE = no                 # Enable mouse emulation
NKRO_ENABLE = no                     # USB Nkey Rollover - See: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
UNICODE_ENABLE = yes                 # Enable unicode support for codes up to 0x7FFF

SRC += features/caps_word.c          # Include the caps word features folder

# DEFAULT_FOLDER = 
