cmake_minimum_required (VERSION 3.12)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Set project name
project ("godotTestLib")

# Add other projects
add_subdirectory(godot-cpp)

# Add src files
set(SRC_FILES 
  src/godotcustomsprite.cpp
  src/godotregistertypes.cpp
)

# Add header files
set(HEADER_FILES
  src/godotcustomsprite.hpp
  src/godotregistertypes.hpp
)

# Add executable target
add_library (godotTestLib STATIC ${SRC_FILES} ${HEADER_FILES})

# Build the godot-cpp extension dll
add_custom_command(
    TARGET godotTestLib
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running SCons script..."
    COMMAND cmd /c "${CMAKE_SOURCE_DIR}/run_scons"
    COMMENT "Running SCons after building godotTestLib"
)


message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

# Set target properties
set_target_properties(godotTestLib PROPERTIES 
  VERSION 1.0
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
)

# Link libraries
target_link_libraries(godotTestLib godot-cpp)
