#include "stdafx.h"
#include "haloreach_offsets.h"

#include "haloreach.h"
#include "haloreach_sigs.h"
#include "games/haloreach/haloreach_engine.h"

void haloreach::offsets::init()
{
	//Blamscript Functions Table
	blamscript::hs_function_table = reinterpret_cast<engine::_hs_function_table*>(Memcury::Scanner::FindPattern(sigs::list["hs_function_table"].c_str()).RelativeOffset(3).Get());

	blamscript::functions::hs_null_evaluate = game::get_eval_hs_function("voice_force_global_repeater_use");

	blamscript::functions::hs_null_evaluate2 = game::get_eval_hs_function("debug_scripting");

	//Blamscript External Globals Table
	blamscript::hs_external_globals = reinterpret_cast<engine::_hs_external_globals*>(Memcury::Scanner::FindPattern(sigs::list["hs_external_globals"].c_str()).RelativeOffset(3).Get());

	//Blamscript type names.
	blamscript::hs_type_names = reinterpret_cast<engine::_hs_type_names*>(Memcury::Scanner::FindPattern(sigs::list["hs_type_names"].c_str()).RelativeOffset(3).Get());

	//TODO: it would be nice to dynamically fill the imgui menu with all possible globals and functions, instead of manually defining them like below.
	//Blamscript Globals
	//toggle_hud = static_cast<bool*>(game::get_hs_global("disable_hud"));

	//Blamscript Functions TODO: Figure out a way to call these without crashing the game or having to hook into the main thread of the game.

	functions::player_mapping_get_unit_by_output_user = Memcury::Scanner::FindPattern(sigs::list["player_mapping_get_unit_by_output_user"].c_str()).FindFunctionBoundary().Get();

	functions::game_tick = Memcury::Scanner::FindPattern(sigs::list["game_tick"].c_str()).FindFunctionBoundary().Get();

	functions::weapon_has_infinite_ammo = Memcury::Scanner::FindPattern(sigs::list["weapon_has_infinite_ammo"].c_str()).FindFunctionBoundary().Get();
}