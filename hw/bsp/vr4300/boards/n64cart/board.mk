#

#
#CFLAGS += \
#  -D__MSP430F5529__ \
#
#LD_FILE = ${SDK_DIR}/msp430f5529.ld
#

CROSS_COMPILE=$(N64_INST)/bin/mips64-elf-

CFLAGS += \
    -DN64

LDFLAGS += -lc -Wl,-g -Wl,-L/Users/sash/Library/n64-toolchain-opengl/mips64-elf/lib -Wl,-ldragon -Wl,-lm -Wl,-ldragonsys -Wl,-Tn64.ld -Wl,--gc-sections -Wl,--wrap -Wl,__do_global_ctors
