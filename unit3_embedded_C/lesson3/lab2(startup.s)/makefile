#@copyright : Mohammed
CC=arm-none-eabi-
CFLAGS=-gdwarf-2 -mcpu=cortex-m3
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS  = $(wildcard *.s)
AsOBJ = $(AS:.s=.o)
PROJECT_NAME = learn-in-depthcortex_m3.bin
	
all: $(PROJECT_NAME)
	@echo "<<<<<<<<The operation is done>>>>>>>>"
	
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
learn-in-depthcortex_m3.elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	
$(PROJECT_NAME): learn-in-depthcortex_m3.elf
	$(CC)objcopy.exe -O binary $< $@
	
clear_all:
	rm *.o *.elf *.bin
	
clear:
	rm *.elf *.bin
	
	
	
	
	
	