################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GDL/tools/vector.cpp 

CPP_DEPS += \
./src/GDL/tools/vector.d 

OBJS += \
./src/GDL/tools/vector.o 


# Each subdirectory must supply rules for building sources it contributes
src/GDL/tools/%.o: ../src/GDL/tools/%.cpp src/GDL/tools/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-GDL-2f-tools

clean-src-2f-GDL-2f-tools:
	-$(RM) ./src/GDL/tools/vector.d ./src/GDL/tools/vector.o

.PHONY: clean-src-2f-GDL-2f-tools

