#include "godotcustomsprite.hpp"

#if __cplusplus >= 202002L
#include <format>
#endif

#include <iostream>

auto main() -> int
{
#if __cplusplus >= 202002L  
	std::cout << std::format("Hello {}!", "godot engine!");
#else
	std::cout << "Hello godot engine!" << std::endl;
#endif
	return 0;
}
