#include "godotregistertypes.hpp"

#include "godotcustomsprite.hpp"

extern "C" {
	GDExtensionBool GDE_EXPORT godotTestLibLibraryInit(GDExtensionInterfaceGetProcAddress procAddress, const GDExtensionClassLibraryPtr libraryPtr, GDExtensionInitialization* initializationPtr)
	{
		GDExtensionBinding::InitObject initObject(procAddress, libraryPtr, initializationPtr);

		initObject.register_initializer(GodotRegisterTypes::initializeTestLibModule);
		initObject.register_terminator(GodotRegisterTypes::uninitializeTestLibModule);
		initObject.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return initObject.init();
	}
}

void GodotRegisterTypes::initializeTestLibModule(ModuleInitializationLevel level)
{
	if (level != MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		std::cerr << "The level is not correct";
		return;
	}

	GDREGISTER_CLASS(GodotCustomSprite);
}

void GodotRegisterTypes::uninitializeTestLibModule(ModuleInitializationLevel level)
{
	if (level != MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		std::cerr << "The level is not correct";
		return;
	}
}
