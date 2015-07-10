################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/IMADC.cpp \
../src/IMEIO.cpp \
../src/IMGPIO.cpp \
../src/IMI2C.cpp \
../src/IMPWM.cpp \
../src/IMSPI.cpp \
../src/IMSerial.cpp \
../src/IMUM6.cpp 

OBJS += \
./src/IMADC.o \
./src/IMEIO.o \
./src/IMGPIO.o \
./src/IMI2C.o \
./src/IMPWM.o \
./src/IMSPI.o \
./src/IMSerial.o \
./src/IMUM6.o 

CPP_DEPS += \
./src/IMADC.d \
./src/IMEIO.d \
./src/IMGPIO.d \
./src/IMI2C.d \
./src/IMPWM.d \
./src/IMSPI.d \
./src/IMSerial.d \
./src/IMUM6.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


