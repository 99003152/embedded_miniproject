################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/STM32Fxx_GPIO_driver.c 

OBJS += \
./drivers/Src/STM32Fxx_GPIO_driver.o 

C_DEPS += \
./drivers/Src/STM32Fxx_GPIO_driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/STM32Fxx_GPIO_driver.o: ../drivers/Src/STM32Fxx_GPIO_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"C:/Users/99003152/STM32CubeIDE/workspace_1.4.0/driverlayer_GPIO/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/STM32Fxx_GPIO_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

