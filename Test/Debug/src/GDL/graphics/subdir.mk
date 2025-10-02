################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GDL/graphics/mesh.cpp \
../src/GDL/graphics/model.cpp \
../src/GDL/graphics/shader.cpp 

CPP_DEPS += \
./src/GDL/graphics/mesh.d \
./src/GDL/graphics/model.d \
./src/GDL/graphics/shader.d 

OBJS += \
./src/GDL/graphics/mesh.o \
./src/GDL/graphics/model.o \
./src/GDL/graphics/shader.o 


# Each subdirectory must supply rules for building sources it contributes
src/GDL/graphics/%.o: ../src/GDL/graphics/%.cpp src/GDL/graphics/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-GDL-2f-graphics

clean-src-2f-GDL-2f-graphics:
	-$(RM) ./src/GDL/graphics/mesh.d ./src/GDL/graphics/mesh.o ./src/GDL/graphics/model.d ./src/GDL/graphics/model.o ./src/GDL/graphics/shader.d ./src/GDL/graphics/shader.o

.PHONY: clean-src-2f-GDL-2f-graphics

