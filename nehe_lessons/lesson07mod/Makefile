ifeq ($(strip $(DEVKITPPC)),)
$(error "Please set DEVKITPPC in your environment. export DEVKITPPC=<path to>devkitPPC")
endif

include $(DEVKITPPC)/wii_rules

CC = powerpc-eabi-gcc -MMD -MP -Wall -DGEKKO -mrvl -mcpu=750 -meabi -mhard-float -DHW_RVL -DGAMECUBE_WII -ggdb
INCLUDE_FLAGS = -I ../../include/ -I $(DEVKITPRO)/portlibs/wii/include  -I $(DEVKITPPC)/include -I $(DEVKITPRO)/libogc/include
LIB_PATH = -L ../../src/ -L $(DEVKITPRO)/portlibs/wii/lib -L $(DEVKITPRO)/libogc/lib/wii

all:
	$(CC) $(INCLUDE_FLAGS) -c lesson07.c
	$(CC) lesson07.o -o lesson07.elf  -g -MMD -MP -Wl,-Map,$(notdir $@).map  $(LIB_PATH) -lopengx -lSDL -lSDLmain -laesnd -lfat -lwiiuse -lwiikeyboard -logc -lm -lbte
	elf2dol lesson07.elf lesson07.dol

clean:
	rm -f *.elf *.o *.dol *.d all.map lesson07

linux:
	gcc -o lesson07 lesson07.c -lGL -lGLU -lSDL

