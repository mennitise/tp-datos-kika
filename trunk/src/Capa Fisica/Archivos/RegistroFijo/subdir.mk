################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
./RegistroFijo.cpp 

OBJS += \
./Capa\ Fisica/Archivos/RegistroFijo/RegistroFijo.o 

CPP_DEPS += \
./Capa\ Fisica/Archivos/RegistroFijo/RegistroFijo.d 


# Each subdirectory must supply rules for building sources it contributes
Capa\ Fisica/Archivos/RegistroFijo/RegistroFijo.o: ./Capa\ Fisica/Archivos/RegistroFijo/RegistroFijo.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


