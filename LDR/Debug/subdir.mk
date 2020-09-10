################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DIO.c \
../LCD.c \
../LED.c \
../Timer1.c \
../main.c \
../timer_zero.c 

OBJS += \
./ADC.o \
./DIO.o \
./LCD.o \
./LED.o \
./Timer1.o \
./main.o \
./timer_zero.o 

C_DEPS += \
./ADC.d \
./DIO.d \
./LCD.d \
./LED.d \
./Timer1.d \
./main.d \
./timer_zero.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


