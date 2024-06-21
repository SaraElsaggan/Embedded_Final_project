################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../WatchDog/WDGDRV.c \
../WatchDog/WDGM.c 

OBJS += \
./WatchDog/WDGDRV.o \
./WatchDog/WDGM.o 

C_DEPS += \
./WatchDog/WDGDRV.d \
./WatchDog/WDGM.d 


# Each subdirectory must supply rules for building sources it contributes
WatchDog/%.o: ../WatchDog/%.c WatchDog/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Gpio" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Led" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Lib" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Nvic" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\WatchDog" -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


