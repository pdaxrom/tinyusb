CROSS_COMPILE = mips64-elf-
DEPS_SUBMODULES += hw/mcu/mips
SKIP_NANOLIB = 1

#SDK_DIR = $(N64_INST)/include

include $(TOP)/$(BOARD_PATH)/board.mk

CFLAGS += \
    -march=vr4300 -mtune=vr4300 \
    -falign-functions=32 -ffunction-sections -fdata-sections \
    -ffast-math -ftrapping-math -fno-associative-math \
    -DCFG_TUSB_MCU=OPT_MCU_VR4300 \
    -DCFG_TUD_ENDPOINT0_SIZE=8

#LDFLAGS += -lc -Wl,-g -Wl,-L/Users/sash/Library/n64-toolchain-opengl/mips64-elf/lib -Wl,-ldragon -Wl,-lm -Wl,-ldragonsys -Wl,-Tn64.ld -Wl,--gc-sections -Wl,--wrap -Wl,__do_global_ctors

#SRC_C += src/portable/ti/msp430x5xx/dcd_msp430x5xx.c

#INC += \
#	${TOP}/${SDK_DIR} \
#	$(TOP)/$(BOARD_PATH)

INC += \
	$(TOP)/$(BOARD_PATH)

# export for libmsp430.so to same installation
ifneq ($(OS),Windows_NT)
export LD_LIBRARY_PATH=$(dir $(shell which MSP430Flasher))
endif

# flash target using TI MSP430-Flasher
# http://www.ti.com/tool/MSP430-FLASHER
# Please add its installation dir to PATH
#flash: $(BUILD)/$(PROJECT).hex
#	MSP430Flasher -w $< -z [VCC]

# flash target using mspdebug.
#flash-mspdebug: $(BUILD)/$(PROJECT).elf
#	$(MSPDEBUG) tilib "prog $<" --allow-fw-update
