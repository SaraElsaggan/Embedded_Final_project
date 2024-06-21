################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Gpio/GPIO.c 

OBJS += \
./Gpio/GPIO.o 

C_DEPS += \
./Gpio/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Gpio/%.o: ../Gpio/%.c Gpio/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Gpio" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Led" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\WatchDog" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Lib" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


