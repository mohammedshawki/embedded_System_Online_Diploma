#@copyright : Mohammed
CC=arm-none-eabi-
CFLAGS=-gdwarf-2 -g -mcpu=cortex-m4
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS  = $(wildcard *.s)
AsOBJ = $(AS:.s=.o)
PROJECT_NAME =high_pressure_detection
	
all: $(PROJECT_NAME)
	@echo "<<<<<<<<The operation is done>>>>>>>>"
	
	
%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
$(PROJECT_NAME).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf
	
$(PROJECT_NAME): $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@
	
clear_all:
	rm *.o *.elf *.bin
	
clear:
	rm *.elf *.bin
	
	
	
	
	
	