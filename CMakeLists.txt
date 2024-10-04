cmake_minimum_required (VERSION 3.12)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Set project name
project ("godotengineTestApp")

# Add other projects
add_subdirectory(godot-cpp)

# Add src files
set(SRC_FILES 
  src/godotengineTestApp.cpp
  src/godotengineTestApp.h
)

# Add executable target
add_executable (godotengineTestApp ${SRC_FILES})

# Set target properties
set_target_properties(godotengineTestApp PROPERTIES 
  VERSION 1.0
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
)

# Link libraries
target_link_libraries(godotengineTestApp godot-cpp)
