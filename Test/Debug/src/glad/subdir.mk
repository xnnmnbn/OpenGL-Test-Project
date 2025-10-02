################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/glad/glad.c 

C_DEPS += \
./src/glad/glad.d 

OBJS += \
./src/glad/glad.o 


# Each subdirectory must supply rules for building sources it contributes
src/glad/%.o: ../src/glad/%.c src/glad/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-glad

clean-src-2f-glad:
	-$(RM) ./src/glad/glad.d ./src/glad/glad.o

.PHONY: clean-src-2f-glad

