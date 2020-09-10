################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../7SEG_ptogram.c \
../BTN_program.c \
../DIO_program.c \
../INT_program.c \
../main.c 

OBJS += \
./7SEG_ptogram.o \
./BTN_program.o \
./DIO_program.o \
./INT_program.o \
./main.o 

C_DEPS += \
./7SEG_ptogram.d \
./BTN_program.d \
./DIO_program.d \
./INT_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


