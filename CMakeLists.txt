# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Set board type because we are building for PicoW
set(PICO_BOARD pico2_w)

set(PROJECT_NAME blink)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)


# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C   standards
project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

file(GLOB_RECURSE SRC_FILES "src/*.c")
# Add the project source files
add_executable(${PROJECT_NAME}
  ${SRC_FILES}
)
target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    /usr/lib/gcc/arm-none-eabi/14.2.0/include
    /usr/lib/gcc/arm-none-eabi/14.2.0/include-fixed
    /usr/arm-none-eabi/include
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(${PROJECT_NAME}
        pico_stdlib
        hardware_pwm
        hardware_gpio
)

# Disable usb output, enable uart output
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

