################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

C_DEPS += \
./src/main.d 

OBJS += \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -gdwarf-2 -DNDEBUG -DSTM32F401xE -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Gpio" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Nvic" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\WatchDog" -I"../include" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Led" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Lib" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\Embedded_Final_project\Rcc" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


