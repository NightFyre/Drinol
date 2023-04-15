#include "stdafx.h"

void utils::handle_game_init(int game_number)
{
	switch (game_number) {
	case 0:
		running_game = "Halo 1 Anniversary";
		halo1::game::init();
		break;
	case 1:
		running_game = "Halo 2 Anniversary";
		halo2::game::init();
		break;
	case 2:
		running_game = "Halo 3";
		halo3::game::init();
		break;
	case 3:
		running_game = "Halo 4";
		break;
	case 4:
		running_game = "Halo 2 Anniversary MP (Groundhog)";
		break;
	case 5:
		running_game = "Halo 3: ODST";
		halo3odst::game::init();
		break;
	case 6:
		running_game = "Halo Reach";
		haloreach::game::init();
		break;
	default:
		assert(game_number <= 6);
	}

#if defined _DEBUG
	spdlog::debug("{} is active.", running_game.c_str());
#endif
}

void utils::handle_game_deinit()
{
	if (running_game == "Halo 1 Anniversary")
	{
		halo1::game::deinit();
		return;
	}

	if (running_game == "Halo 2 Anniversary")
	{
		halo2::game::deinit();
		return;
	}

	if (running_game == "Halo 3")
	{
		halo3::game::deinit();
		return;
	}
}

// Saves the currently running games settings.
void utils::save_running_game_settings()
{
	if (running_game == "Halo 1 Anniversary")
	{
		if (config::halo1_save())
		{
			spdlog::info("Saved settings for Halo 1!");
			return;
		}
	}

	if (running_game == "Halo 2 Anniversary")
	{
		if (config::halo2_save())
		{
			spdlog::info("Saved settings for Halo 2!");
			return;
		}
	}

	if (running_game == "Halo 3")
	{
		if (config::halo3_save())
		{
			spdlog::info("Saved settings for Halo 3!");
			return;
		}
	}
}

// Loads the currently running games settings.
void utils::load_running_game_settings()
{
	if (running_game == "Halo 1 Anniversary")
	{
		if (config::halo1_load())
		{
			spdlog::info("Loaded settings for Halo 1!");
			return;
		}
	}

	if (running_game == "Halo 2 Anniversary")
	{
		if (config::halo2_load())
		{
			spdlog::info("Loaded settings for Halo 2!");
			return;
		}
	}

	if (running_game == "Halo 3")
	{
		if (config::halo3_load())
		{
			spdlog::info("Loaded settings for Halo 3!");
			return;
		}
	}
}

void utils::reset_running_game_settings()
{
	if (running_game == "Halo 1 Anniversary")
	{
		if (!config::halo1_create())
		{
			spdlog::error("Failed to create fresh settings for Halo 1!");
			return;
		}
		if (!config::halo1_load())
		{
			spdlog::error("Failed to load fresh settings for Halo 1!");
			return;
		}

		spdlog::info("Reset settings for Halo 1");
	}

	if (running_game == "Halo 2 Anniversary")
	{
		if (!config::halo2_create())
		{
			spdlog::error("Failed to create fresh settings for Halo 2!");
			return;
		}
		if (!config::halo2_load())
		{
			spdlog::error("Failed to load fresh settings for Halo 2!");
			return;
		}

		spdlog::info("Reset settings for Halo 2");
	}

	if (running_game == "Halo 3")
	{
		if (!config::halo3_create())
		{
			spdlog::error("Failed to create fresh settings for Halo 3!");
			return;
		}
		if (!config::halo3_load())
		{
			spdlog::error("Failed to load fresh settings for Halo 3!");
			return;
		}

		spdlog::info("Reset settings for Halo 3");
	}
}

//https://github.com/citizenfx/fivem/blob/f3bb0460562b1eb1a7f9652ffcf73ad7282fd45e/code/client/shared/Hooking.h#L91-L113
char* utils::get_tls_pointer(LPCWSTR module_name, int TLSFunctionIndex)
{
	// ah, the irony in using TLS to get TLS
	static auto tlsIndex = ([module_name]()
		{
			auto base = (char*)GetModuleHandleW(module_name);
			auto moduleBase = (PIMAGE_DOS_HEADER)base;
			auto ntBase = (PIMAGE_NT_HEADERS)(base + moduleBase->e_lfanew);
			auto tlsBase = (PIMAGE_TLS_DIRECTORY)(base + ntBase->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress);

			return reinterpret_cast<uint32_t*>(tlsBase->AddressOfIndex);
		})();

#if defined(_M_IX86)
		LPVOID* tlsBase = (LPVOID*)__readfsdword(0x2C);
#elif defined(_M_AMD64)
		LPVOID* tlsBase = (LPVOID*)__readgsqword(0x58);
#endif
		if (!TLSFunctionIndex)
		{
			return static_cast<char*>(tlsBase[*tlsIndex]);
		}
		else
		{
			return static_cast<char*>(tlsBase[*tlsIndex]) + TLSFunctionIndex;
		}
}

void utils::test_func(int test_int)
{
	halo3::engine::player_datum* crap = halo3::game::local_player_datum_get();
	crap->player_traits.m_appearance_traits.m_active_camo_setting = halo3::engine::invisible;
	crap->player_traits.m_shield_traits.m_shield_recharge_rate_percentage_setting = halo3::engine::_shield_recharge_rate_percentage_setting_200_percent;
}

//0x00007ff8
#if defined _DEBUG
void utils::list_game_base_addresses()
{
	Memcury::Scanner::SetTargetModule("halo1.dll");

	spdlog::debug("Halo 1 base : 0x{:X}", Memcury::PE::GetModuleBase());

	Memcury::Scanner::SetTargetModule("halo2.dll");

	spdlog::debug("Halo 2 base : 0x{:X}", Memcury::PE::GetModuleBase());

	Memcury::Scanner::SetTargetModule("halo3.dll");

	spdlog::debug("Halo 3 base : 0x{:X}", Memcury::PE::GetModuleBase());

	Memcury::Scanner::SetTargetModule("halo4.dll");

	spdlog::debug("Halo 4 base : 0x{:X}", Memcury::PE::GetModuleBase());
}

void utils::backtrace(const char* func) {
	const int trace_count = 15;
	void* trace_back[trace_count];
	DWORD hash;
	RtlCaptureStackBackTrace(1, trace_count, trace_back, &hash);
	printf("%s callstack: ", func);
	for (int i = 0; i < trace_count; i++) {
		if (i == trace_count - 1) {
			printf("%p\n", (uintptr_t)trace_back[i]);
		}
		else {
			printf("%p:", (uintptr_t)trace_back[i]);
		}
	}
}

#endif

void utils::detach()
{
	handle_game_deinit();
	middleware::deinit();
	kiero::shutdown();
	console::deinit();
	//FreeLibraryAndExitThread(dll_module, 0);
}