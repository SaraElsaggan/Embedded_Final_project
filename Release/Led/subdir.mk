################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Led/LEDM.c 

C_DEPS += \
./Led/LEDM.d 

OBJS += \
./Led/LEDM.o 


# Each subdirectory must supply rules for building sources it contributes
Led/%.o: ../Led/%.c Led/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"C:\Users\lenovo\Desktop\Embedded_Final_project\Gpio" -I"C:\Users\lenovo\Desktop\Embedded_Final_project\Nvic" -I"C:\Users\lenovo\Desktop\Embedded_Final_project\WatchDog" -I"../include" -I"C:\Users\lenovo\Desktop\Embedded_Final_project\Led" -I"C:\Users\lenovo\Desktop\Embedded_Final_project\Lib" -I"C:\Users\lenovo\Desktop\Embedded_Final_project\Rcc" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


