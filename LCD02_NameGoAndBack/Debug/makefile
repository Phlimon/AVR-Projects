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
LCD02_NameGoAndBack.lss \

FLASH_IMAGE += \
LCD02_NameGoAndBack.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: LCD02_NameGoAndBack.elf secondary-outputs

# Tool invocations
LCD02_NameGoAndBack.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LCD02_NameGoAndBack.map -mmcu=atmega32 -o "LCD02_NameGoAndBack.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LCD02_NameGoAndBack.lss: LCD02_NameGoAndBack.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LCD02_NameGoAndBack.elf  >"LCD02_NameGoAndBack.lss"
	@echo 'Finished building: $@'
	@echo ' '

LCD02_NameGoAndBack.hex: LCD02_NameGoAndBack.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LCD02_NameGoAndBack.elf  "LCD02_NameGoAndBack.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LCD02_NameGoAndBack.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LCD02_NameGoAndBack.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LCD02_NameGoAndBack.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
