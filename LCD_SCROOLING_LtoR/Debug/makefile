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
LCD_SCROOLING_LtoR.lss \

FLASH_IMAGE += \
LCD_SCROOLING_LtoR.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: LCD_SCROOLING_LtoR.elf secondary-outputs

# Tool invocations
LCD_SCROOLING_LtoR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LCD_SCROOLING_LtoR.map -mmcu=atmega32 -o "LCD_SCROOLING_LtoR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LCD_SCROOLING_LtoR.lss: LCD_SCROOLING_LtoR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LCD_SCROOLING_LtoR.elf  >"LCD_SCROOLING_LtoR.lss"
	@echo 'Finished building: $@'
	@echo ' '

LCD_SCROOLING_LtoR.hex: LCD_SCROOLING_LtoR.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LCD_SCROOLING_LtoR.elf  "LCD_SCROOLING_LtoR.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LCD_SCROOLING_LtoR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LCD_SCROOLING_LtoR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LCD_SCROOLING_LtoR.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
