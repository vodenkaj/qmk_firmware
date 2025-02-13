# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
OPT_DEFS += -DNO_USB_STARTUP_CHECK -DENABLE_FACTORY_TEST

TAP_DANCE_ENABLE = yes
MOUSEKEY_ENABLE = yes
UNICODE_ENABLE = yes

SRC += features/custom_shift_keys.c
SRC += matrix.c

include keyboards/keychron/bluetooth/bluetooth.mk
