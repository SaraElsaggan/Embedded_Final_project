################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Nvic/Nvic.c 

OBJS += \
./Nvic/Nvic.o 

C_DEPS += \
./Nvic/Nvic.d 


# Each subdirectory must supply rules for building sources it contributes
Nvic/%.o: ../Nvic/%.c Nvic/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\lenovo\Desktop\Embedded_Final_project\Gpio" -I"C:\Users\lenovo\Desktop\Embedded_Final_project\Led" -I"C:\Users\lenovo\Desktop\Embedded_Final_project\Lib" -I"C:\Users\lenovo\Desktop\Embedded_Final_project\Nvic" -I"C:\Users\lenovo\Desktop\Embedded_Final_project\WatchDog" -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


