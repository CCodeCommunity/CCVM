cmake_minimum_required(VERSION 3.17)
project(ccvm C)

file(GLOB_RECURSE CCVM_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/sources/*.c")

add_executable(ccvm)
target_sources(ccvm PRIVATE ${CCVM_SOURCES})
target_include_directories(ccvm PUBLIC "include" "thirdparty")

if (UNIX)
    target_link_libraries(ccvm PRIVATE m)
endif (UNIX)

set_target_properties(ccvm PROPERTIES LINKER_LANGUAGE C C_STANDARD 11)