################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/FreeRTOS_tick_config.c \
../src/ParTest.c \
../src/basic_io.c \
../src/croutine.c \
../src/event_groups.c \
../src/heap_4.c \
../src/list.c \
../src/main.c \
../src/main2.c \
../src/main_blinky.c \
../src/platform.c \
../src/port.c \
../src/printf-stdarg.c \
../src/queue.c \
../src/tasks.c \
../src/timers.c 

S_UPPER_SRCS += \
../src/FreeRTOS_asm_vectors.S \
../src/portASM.S 

OBJS += \
./src/FreeRTOS_asm_vectors.o \
./src/FreeRTOS_tick_config.o \
./src/ParTest.o \
./src/basic_io.o \
./src/croutine.o \
./src/event_groups.o \
./src/heap_4.o \
./src/list.o \
./src/main.o \
./src/main2.o \
./src/main_blinky.o \
./src/platform.o \
./src/port.o \
./src/portASM.o \
./src/printf-stdarg.o \
./src/queue.o \
./src/tasks.o \
./src/timers.o 

S_UPPER_DEPS += \
./src/FreeRTOS_asm_vectors.d \
./src/portASM.d 

C_DEPS += \
./src/FreeRTOS_tick_config.d \
./src/ParTest.d \
./src/basic_io.d \
./src/croutine.d \
./src/event_groups.d \
./src/heap_4.d \
./src/list.d \
./src/main.d \
./src/main2.d \
./src/main_blinky.d \
./src/platform.d \
./src/port.d \
./src/printf-stdarg.d \
./src/queue.d \
./src/tasks.d \
./src/timers.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../my_zynq_platform_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../my_zynq_platform_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


