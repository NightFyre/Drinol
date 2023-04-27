#pragma once
#include <cassert>
#include <cstdio>
#include <d3d11.h>
#include <dxgi.h>
#include <framework.h>
#include <iostream>
#include <memory>
#include <ostream>
#include <regex>
#include <ShellAPI.h>
#include <unordered_map>

#include "commctrl.h"
#include "console.h"
#include "detour.h"
#include "framework.h"
#include "imgui.h"
#include "ntpebteb.h"
#include "Psapi.h"
#include "utils.h"
#include "backends/imgui_impl_dx11.h"
#include "backends/imgui_impl_win32.h"
#include "config/config.h"
#include "games/halo1/halo1.h"
#include "games/halo1/halo1_hooks.h"
#include "games/halo1/halo1_offsets.h"
#include "games/halo1/halo1_sigs.h"
#include "games/halo2/halo2.h"
#include "games/halo2/halo2_hooks.h"
#include "games/halo2/halo2_offsets.h"
#include "games/halo2/halo2_sigs.h"
#include "games/halo3/halo3.h"
#include "games/halo3/halo3_hooks.h"
#include "games/halo3/halo3_offsets.h"
#include "games/halo3/halo3_sigs.h"
#include "games/halo3odst/halo3odst.h"
#include "games/halo3odst/halo3odst_offsets.h"
#include "games/halo3odst/halo3odst_sigs.h"
#include "games/halo4/halo4.h"
#include "games/halo4/halo4_hooks.h"
#include "games/halo4/halo4_offsets.h"
#include "games/halo4/halo4_sigs.h"
#include "games/haloreach/haloreach.h"
#include "games/haloreach/haloreach_hooks.h"
#include "games/haloreach/haloreach_offsets.h"
#include "games/haloreach/haloreach_sigs.h"
#include "gui/gui.h"
#include "gui/menu/menu.h"
#include "kiero/kiero.h"
#include "logging/logging.h"
#include "memcury/memcury.h"
#include "Memcury/memcury.h"
#include "middleware/middleware.h"
#include "middleware/middleware_sigs.h"
#include "minhook/include/MinHook.h"
#include "mINI/src/mini/ini.h"
#include "spdlog/logger.h"
#include "spdlog/spdlog.h"
#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"
#include "spdlog/fmt/bundled/color.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "version_checking/version_checking.h"
