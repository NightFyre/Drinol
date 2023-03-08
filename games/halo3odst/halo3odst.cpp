#include "halo3odst.h"

#include <iostream>

#include "halo3odst_offsets.h"
#include "memcury/memcury.h"

void halo3odst::game::init() // Initialize hooks and shit for halo 1
{
	std::cout << "Initializing Halo 3: ODST" << std::endl;

	Memcury::Scanner::SetTargetModule("halo3odst.dll");

	offsets::init();
}

#if defined _DEBUG
void halo3odst::game::test_function()
{
}

void halo3odst::game::list_all_hs_functions()
{
	for (engine::_hs_script_op* function : offsets::hs_function_table->table)
	{
		if (function->evaluate_func != nullptr && function->evaluate_func != offsets::hs_null_evaluate)
		{
			std::cout << "Return Type: " << offsets::hs_type_names->types[function->return_type] << " Name: " << function->name << " Address: " << std::hex << function->evaluate_func << std::endl;
		}
	}
}

void halo3odst::game::list_all_hs_globals()
{
	for (engine::hs_external_global* global : offsets::hs_external_globals->globals)
		if (global->address != nullptr) // Check if globals functionality has not been stripped from retail.
		{
			std::cout << "Name: " << global->name << " Address: " << global->address << " Parameter Type:" << offsets::hs_type_names->types[global->param_type] << std::endl;
		}
}

#endif

void* halo3odst::game::get_hs_global(const char* global_name) // Gets the address of the specified global.
{
	for (const engine::hs_external_global* global : offsets::hs_external_globals->globals)
	{
		if (strcmp(global->name, global_name) == 0)
		{
			// bool has been found
			if (global->address != nullptr)
			{
				return global->address;
			}

			throw std::runtime_error("halo3odst::game::get_global: global has been found but does not have a working address");
		}
	}

	throw std::runtime_error("halo3odst::game::get_global:: global was not found");
}

void* halo3odst::game::get_hs_function(const char* func_name) // Gets the address of the specified function.
{
	for (const engine::_hs_script_op* function : offsets::hs_function_table->table)
	{
		if (strcmp(function->name, func_name) == 0)
		{
			// bool has been found
			if (function->evaluate_func != nullptr || function->evaluate_func != offsets::hs_null_evaluate)
			{
				return function->evaluate_func;
			}

			throw std::runtime_error("halo3odst::game::get_hs_function: function has been found but does not have a working address");
		}
	}

	throw std::runtime_error("halo3odst::game::get_hs_function:: function was not found");
}