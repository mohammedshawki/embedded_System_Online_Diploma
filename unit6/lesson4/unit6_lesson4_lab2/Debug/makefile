################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
unit6_lesson4_lab2.lss \

FLASH_IMAGE += \
unit6_lesson4_lab2.hex \

EEPROM_IMAGE += \
unit6_lesson4_lab2.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: unit6_lesson4_lab2.elf secondary-outputs

# Tool invocations
unit6_lesson4_lab2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,unit6_lesson4_lab2.map -mmcu=atmega32 -o "unit6_lesson4_lab2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

unit6_lesson4_lab2.lss: unit6_lesson4_lab2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S unit6_lesson4_lab2.elf  >"unit6_lesson4_lab2.lss"
	@echo 'Finished building: $@'
	@echo ' '

unit6_lesson4_lab2.hex: unit6_lesson4_lab2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex unit6_lesson4_lab2.elf  "unit6_lesson4_lab2.hex"
	@echo 'Finished building: $@'
	@echo ' '

unit6_lesson4_lab2.eep: unit6_lesson4_lab2.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex unit6_lesson4_lab2.elf  "unit6_lesson4_lab2.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: unit6_lesson4_lab2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 unit6_lesson4_lab2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) unit6_lesson4_lab2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
