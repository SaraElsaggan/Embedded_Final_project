################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Led/LEDM.c 

OBJS += \
./Led/LEDM.o 

C_DEPS += \
./Led/LEDM.d 


# Each subdirectory must supply rules for building sources it contributes
Led/%.o: ../Led/%.c Led/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Gpio" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Led" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Lib" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Nvic" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\WatchDog" -Wall -g3 -gdwarf-2 -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


