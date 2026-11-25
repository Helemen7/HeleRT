cmake_minimum_required(VERSION 3.22.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(HeleRT LANGUAGES C CXX ASM)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MCUX_SDK_DIR $ENV{HOME}/sdk/mcuxsdk CACHE PATH "Path for mcuxsdk downloaded from official NXP website")

if (NOT EXISTS ${MCUX_SDK_DIR})
	message(FATAL_ERROR "Cannot find mcuxsdk at '${MCUX_SDK_DIR}'")
endif()

set(DEV_FOLDER ${MCUX_SDK_DIR}/devices/MCX/MCXA/MCXA153)

set(CMAKE_EXECUTABLE_SUFFIX .elf)

add_executable(HeleRT src/main.cpp)

set_target_properties(HeleRT PROPERTIES LINK_DEPENDS ${CMAKE_SOURCE_DIR}/linker/MCXA153_flash.ld)

target_include_directories(HeleRT PRIVATE ${DEV_FOLDER} ${MCUX_SDK_DIR}/arch/arm/CMSIS/Core/Include ${MCUX_SDK_DIR}/devices/MCX/MCXA/periph)

target_compile_definitions(HeleRT PRIVATE CPU_MCXA153VLH)

target_compile_options(HeleRT PRIVATE $<$<CONFIG:Debug>:-Og> -fno-threadsafe-statics -ffreestanding  -ffunction-sections -fdata-sections -Wall -Wextra -Wshadow -Wconversion $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti> $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>)

target_link_options(HeleRT PRIVATE -T ${CMAKE_SOURCE_DIR}/linker/MCXA153_flash.ld -nostdlib -Wl,--gc-sections -Wl,-Map=${CMAKE_BINARY_DIR}/$<TARGET_PROPERTY:NAME>.map -Wl,--print-memory-usage -Wl,--no-warn-rwx-segments)

target_link_libraries(HeleRT PRIVATE gcc)
