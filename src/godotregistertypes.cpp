#include "godotregistertypes.hpp"

#include "godotcustomsprite.hpp"

extern "C" {
	GDExtensionBool GDE_EXPORT godotEngineTestAppLibraryInit(GDExtensionInterfaceGetProcAddress procAddress, const GDExtensionClassLibraryPtr libraryPtr, GDExtensionInitialization* initializationPtr)
	{
		GDExtensionBinding::InitObject initObject(procAddress, libraryPtr, initializationPtr);

		initObject.register_initializer(GodotRegisterTypes::initializeTestAppModule);
		initObject.register_terminator(GodotRegisterTypes::uninitializeTestAppModule);
		initObject.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return initObject.init();
	}
}

void GodotRegisterTypes::initializeTestAppModule(ModuleInitializationLevel level)
{
	if (level != MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		std::cerr << "The level is not correct";
		return;
	}

	GDREGISTER_CLASS(GodotCustomSprite);
}

void GodotRegisterTypes::uninitializeTestAppModule(ModuleInitializationLevel level)
{
	if (level != MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		std::cerr << "The level is not correct";
		return;
	}
}
