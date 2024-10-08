#include "godotcustomsprite.hpp"

#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

GodotCustomSprite::GodotCustomSprite()
{
	//if (Engine::get_singleton()->is_editor_hint())
	//{
	//	set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
	//}

	//UtilityFunctions::print("This is a constructor honey");
}

void GodotCustomSprite::_process(double delta)
{
	m_timePassed += delta;

	const auto newPos = Vector2(
		static_cast<real_t>(10.0 * sin(m_timePassed * 2.0)),
		static_cast<real_t>(10.0 + (10.0 * cos(m_timePassed * 1.5)))
	);

	set_position(newPos);


	// test keyboard input
	if (Input::get_singleton()->is_key_pressed(KEY_UP))
	{
		UtilityFunctions::print("Up key pressed");
	}
	else if (Input::get_singleton()->is_key_pressed(KEY_DOWN))
	{
		UtilityFunctions::print("Down key pressed");
	}
	else if (Input::get_singleton()->is_key_pressed(KEY_LEFT))
	{
		UtilityFunctions::print("Left key pressed");
	}
	else if (Input::get_singleton()->is_key_pressed(KEY_RIGHT))
	{
		UtilityFunctions::print("Right key pressed");
	}

}

void GodotCustomSprite::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("getAmplitude"), &GodotCustomSprite::getAmplitude);
	ClassDB::bind_method(D_METHOD("setAmplitude"), &GodotCustomSprite::setAmplitude);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "setAmplitude", "getAmplitude");
}

double GodotCustomSprite::getAmplitude()
{
	return m_amplitude;
}

void GodotCustomSprite::setAmplitude(double amplitude)
{
	m_amplitude = amplitude;
}
