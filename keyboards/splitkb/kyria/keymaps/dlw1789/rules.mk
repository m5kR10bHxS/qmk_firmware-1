# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
MCU = Pro Micro
BOOTLOADER = caterina

# MCU = atmega32u4
# BOOTLOADER = atmel-dfu

# Build Options - Disable unused features to reduce the size of the firmware binary.
# Change yes to no to disable

# Hardware:
BLUETOOTH_ENABLE = no                  # Enable Bluetooth with the Adafruit EZ-Key HID
CUSTOM_MATRIX = no                     # Declare the use of I/O expander
DEBOUNCE_TYPE = no                     # Enable a custom debounce routine
DEFERRED_EXEC_ENABLE = no              # Enable deferred executor support
ENCODER_ENABLE = yes                   # Enable the use of one or more encoders
ENCODER_MAP_ENABLE = yes               # Enable the use of the new encoder map configuration paradigm
HD44780_ENABLE = no                    # Enable support for HD44780 based LCDs
NO_USB_STARTUP_CHECK = no              # Useful for split keyboards
OLED_DRIVER_ENABLE = yes               # Enable the use of OLED displays
SPLIT_KEYBOARD = yes                   # Split, or 1-piece
USB_WAIT_FOR_ENUMERATION = no          # Force the keyboard to wait for a USB connection

# Illumination:
BACKLIGHT_DRIVER = custom              # Custom driver - req'd for Kyria
BACKLIGHT_ENABLE = no                  # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = yes                  # Enable addressable underglow RGB LEDs - Enabled in info.json
SLEEP_LED_ENABLE = no                  # Breathing sleep LED during USB suspend - CAUTION: may conflict with BACKLIGHT_ENABLE

# Audio:
AUDIO_ENABLE = no                      # Audio output on port C6
EXTRAKEY_ENABLE = yes                  # Audio control and System control
FAUXCLICKY_ENABLE = no                 # Use buzzer to emulate clicky switches
MIDI_ENABLE = no                       # MIDI support

# Features:
BOOTMAGIC_ENABLE = no                  # Virtual DIP switch configuration
CAPS_WORD_ENABLE = yes                 # Vanilla QMK Caps Word
COMBO_ENABLE = yes                     # Enable combos - See: http://combos.gboards.ca/
COMMAND_ENABLE = no                    # Commands for debug and configuration; can interfere w/ caps word
CONSOLE_ENABLE = no                    # Console for debug
DEFERRED_EXEC_ENABLE = yes             # Enable deferred execution for SM_TD (home row mods)
DYNAMIC_TAPPING_TERM_ENABLE = yes      # Allow tapping term adjustmet on the fly NOTE: Adjustments are not persistent
KEY_OVERRIDE_ENABLE = no               # Enable Key Override support
LEADER_ENABLE = yes                    # Enable the Leader Key feature
LTO_ENABLE = yes                       # Link Time Optimization - creates smaller binary
MAGIC_ENABLE = no                      # BOOTMAGIC without the boot
MOUSEKEY_ENABLE = no                   # Enable mouse emulation
NKRO_ENABLE = no                       # USB Nkey Rollover - See: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
REPEAT_KEY_ENABLE = Yes                # Enable Repeat and Alt-Repeat - See: https://docs.qmk.fm/features/repeat_key
RING_BUFFERED_6KRO_REPORT_ENABLE = no  # USB 6-key rollover
SEND_STRING_ENABLE = yes               # Enable macro support
TAP_DANCE_ENABLE = no                  # Enable Tap Dance support - See: https://docs.qmk.fm/features/tap_dance
UNICODE_ENABLE = no                    # Enable unicode support for codes up to 0x7FFF

# Third Party Features:
SRC += features/achordion.c            # For Getreuer's Achordion. See https://getreuer.info/posts/keyboards/achordion/index.html
SRC += features/custom_shift_keys.c    # For Getreuer's Custom Shift Keys. See: https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
#SRC += features/layer_lock.c           # For Getreuer's Layer Lock. See: https://getreuer.info/posts/keyboards/layer-lock/index.html
SRC += features/sentence_case.c        # For Getreuer's Sentence case. See: https://getreuer.info/posts/keyboards/sentence-case/index.html
VPATH  +=  keyboards/gboards/          # For Gboards' Combo Dictionary location - See: http://combos.gboards.ca/

DEFAULT_FOLDER = kyria/rev1 
