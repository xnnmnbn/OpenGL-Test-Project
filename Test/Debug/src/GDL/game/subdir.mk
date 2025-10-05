################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GDL/game/camera.cpp \
../src/GDL/game/gameobject.cpp \
../src/GDL/game/scene.cpp 

CPP_DEPS += \
./src/GDL/game/camera.d \
./src/GDL/game/gameobject.d \
./src/GDL/game/scene.d 

OBJS += \
./src/GDL/game/camera.o \
./src/GDL/game/gameobject.o \
./src/GDL/game/scene.o 


# Each subdirectory must supply rules for building sources it contributes
src/GDL/game/%.o: ../src/GDL/game/%.cpp src/GDL/game/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-GDL-2f-game

clean-src-2f-GDL-2f-game:
	-$(RM) ./src/GDL/game/camera.d ./src/GDL/game/camera.o ./src/GDL/game/gameobject.d ./src/GDL/game/gameobject.o ./src/GDL/game/scene.d ./src/GDL/game/scene.o

.PHONY: clean-src-2f-GDL-2f-game

