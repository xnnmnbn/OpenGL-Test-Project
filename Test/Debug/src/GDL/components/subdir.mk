################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GDL/components/renderer.cpp \
../src/GDL/components/transform.cpp 

CPP_DEPS += \
./src/GDL/components/renderer.d \
./src/GDL/components/transform.d 

OBJS += \
./src/GDL/components/renderer.o \
./src/GDL/components/transform.o 


# Each subdirectory must supply rules for building sources it contributes
src/GDL/components/%.o: ../src/GDL/components/%.cpp src/GDL/components/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-GDL-2f-components

clean-src-2f-GDL-2f-components:
	-$(RM) ./src/GDL/components/renderer.d ./src/GDL/components/renderer.o ./src/GDL/components/transform.d ./src/GDL/components/transform.o

.PHONY: clean-src-2f-GDL-2f-components

