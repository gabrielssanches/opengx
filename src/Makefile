ifeq ($(strip $(DEVKITPPC)),)
$(error "Please set DEVKITPPC in your environment. export DEVKITPPC=<path to>devkitPPC")
endif

include $(DEVKITPPC)/wii_rules

CC = powerpc-eabi-gcc
AR = powerpc-eabi-ar
CFLAGS = -MMD -MP -Wall -DGEKKO -mrvl -mcpu=750 -meabi -mhard-float  -DHW_RVL -O2 -ggdb
INCLUDE_FLAGS = -I $(DEVKITPRO)/include -I ../include/ -I $(DEVKITPRO)/libogc/include

all:
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c gc_gl.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c image_DXT.c
	$(AR) rcs libopengx.a gc_gl.o image_DXT.o

clean:
	rm -f gc_gl.o image_DXT.o libopengx.a *.d


