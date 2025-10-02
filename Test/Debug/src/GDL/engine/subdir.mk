################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GDL/engine/camera.cpp \
../src/GDL/engine/input.cpp \
../src/GDL/engine/time.cpp \
../src/GDL/engine/window.cpp 

CPP_DEPS += \
./src/GDL/engine/camera.d \
./src/GDL/engine/input.d \
./src/GDL/engine/time.d \
./src/GDL/engine/window.d 

OBJS += \
./src/GDL/engine/camera.o \
./src/GDL/engine/input.o \
./src/GDL/engine/time.o \
./src/GDL/engine/window.o 


# Each subdirectory must supply rules for building sources it contributes
src/GDL/engine/%.o: ../src/GDL/engine/%.cpp src/GDL/engine/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-GDL-2f-engine

clean-src-2f-GDL-2f-engine:
	-$(RM) ./src/GDL/engine/camera.d ./src/GDL/engine/camera.o ./src/GDL/engine/input.d ./src/GDL/engine/input.o ./src/GDL/engine/time.d ./src/GDL/engine/time.o ./src/GDL/engine/window.d ./src/GDL/engine/window.o

.PHONY: clean-src-2f-GDL-2f-engine

