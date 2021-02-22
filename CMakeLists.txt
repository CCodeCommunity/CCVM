cmake_minimum_required(VERSION 3.17)
project(CCVM C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(flags)
include_directories(instructionset)
include_directories(ram)
include_directories(stack)

add_executable(
        flags/flags.c
        flags/flags.h
        instructionset/instructionset.c
        instructionset/instructionset.h
        ram/ram.c
        ram/ram.h
        stack/stack.c
        stack/stack.h
        CCVM.c
        CCVM.h
        main.c)
