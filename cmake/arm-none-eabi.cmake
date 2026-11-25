# Flags for arm-none-eabi-gcc (Arm arch, No OS (Generic), EABI (Embedded Application Binary Interface), GCC (GNU Compiler Collection))
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_ASM_COMPILER arm-none-eabi-gcc) # SDK startup is .S, so it has preprocessor directives inside. This means it should be able to execute them.
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)


# No Floating Point Unit available, no Digital Signal Processor (which, in this case, is an extension of the Instruction Set to use SIMD)
set(CPU_FLAGS "-mcpu=cortex-m33+nodsp+nofp -mthumb -mfloat-abi=soft")
set(CMAKE_C_FLAGS_INIT "${CPU_FLAGS}")
set(CMAKE_CXX_FLAGS_INIT "${CPU_FLAGS}")
set(CMAKE_ASM_FLAGS_INIT "${CPU_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS_INIT "${CPU_FLAGS}")

# All programs such as code generators must be found around the system (like in .mcuexpressotools), but libraries (libc, etc) have to be found in the toolchain.
# Packages and headers mustn't finish in an ARM binary.
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

