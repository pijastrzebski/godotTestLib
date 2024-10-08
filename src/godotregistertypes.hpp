#pragma once

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

struct GodotRegisterTypes
{
	static void initializeTestAppModule(ModuleInitializationLevel level);
	static void uninitializeTestAppModule(ModuleInitializationLevel level);
};
