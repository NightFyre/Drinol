#include "logging.h"

#include <iostream>
#include <ostream>

#include "config/config.h"
#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

void logging::init()
{
	try
	{
		std::vector<spdlog::sink_ptr> sinks;
		sinks.push_back(std::make_shared<spdlog::sinks::stderr_color_sink_mt>());
		sinks.push_back(std::make_shared<spdlog::sinks::daily_file_sink_mt>("Drinol/logs/drinol.txt", 23, 59));
		auto _logger = std::make_shared<spdlog::logger>("Drinol", begin(sinks), end(sinks));

		// Gets log level from config and sets it. (also some sanity checks)
		switch (log_level)
		{
		case spdlog::level::level_enum::trace:
			_logger->set_level(spdlog::level::level_enum::trace);
			break;

		case spdlog::level::level_enum::debug:
			_logger->set_level(spdlog::level::level_enum::debug);
			break;

		case spdlog::level::level_enum::info:
			_logger->set_level(spdlog::level::level_enum::info);
			break;
		case spdlog::level::level_enum::warn:
			_logger->set_level(spdlog::level::level_enum::warn);
			break;
		case spdlog::level::level_enum::err:
			_logger->set_level(spdlog::level::level_enum::err);
			break;
		case spdlog::level::level_enum::critical:
			_logger->set_level(spdlog::level::level_enum::critical);
			break;
		case spdlog::level::level_enum::off:
			_logger->set_level(spdlog::level::level_enum::off);
			break;
		default:
		{
			char buf[30] = { 0 };
			sprintf_s(buf, "Invalid log level! %i", log_level);

			MessageBoxA(NULL, buf, "Drinol Error!", 0);
		}
		}

		spdlog::register_logger(_logger);

		set_default_logger(_logger);

		spdlog::flush_on(spdlog::level::info);
	}
	catch (const spdlog::spdlog_ex& ex)
	{
		std::cout << "Log initialization failed: " << ex.what() << std::endl;
	}
}