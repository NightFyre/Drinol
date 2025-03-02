#pragma once

namespace haloreach::engine // Engine related structs, etc
{
	// search the string: hs_doc.txt to find the functions that contain the amount of globals, and functions

		//Generated by reclass.net
		/**
	 * \brief the table of functions that are used in halos scripting system.
	 */
	class _hs_function_table
	{
	public:
		class _hs_script_op* table[1903]; //0x0000
	}; //Size: 0x3B78
	static_assert(sizeof(_hs_function_table) == 0x3B78);

	class _hs_script_op
	{
	public:
		int16_t return_type; //0x0000
		int16_t flags; //0x0002
		int32_t unused; //0x0004
		char* name; //0x0008
		char pad_0010[8]; //0x0010
		void* parse_func; //0x0018
		void* evaluate_func; //0x0020
	}; //Size: 0x0028
	static_assert(sizeof(_hs_script_op) == 0x28);

	/**
	 * \brief the table of globals that are used in halos scripting system.
	 */
	class _hs_external_globals
	{
	public:
		class hs_external_global* globals[1724]; //0x0000 The list of globals.
		// 466 is the hardcoded total number of globals in this array TODO: Fetch this dynamically somehow?
	}; //Size: 0x2930
	static_assert(sizeof(_hs_external_globals) == 0x35E0);

	class hs_external_global
	{
	public:
		char* name; //0x0000 Name of the global
		int64_t param_type; //0x0008 parameter type (unparsed, float, bool, etc)
		void* address; //0x0010 // The address of the global
	}; //Size: 0x0018
	static_assert(sizeof(hs_external_global) == 0x18);

	class _hs_type_names
	{
	public:
		char* types[89]; //0x0000 List of parameter types in the form of a string.
		// 89 is the total number of types in this array TODO: Fetch this dynamically somehow?
	}; //Size: 0x0298
	static_assert(sizeof(_hs_type_names) == 0x2C8);
}
