# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
OPT_DEFS += -DNO_USB_STARTUP_CHECK -DENABLE_FACTORY_TEST

MOUSEKEY_ENABLE = yes
SRC += features/custom_shift_keys.c
SRC += matrix.c

include keyboards/keychron/bluetooth/bluetooth.mk
