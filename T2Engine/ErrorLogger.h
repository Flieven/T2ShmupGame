#pragma once

#include <string>
#include <stdio.h>
#include <SDL_log.h>

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define RaukStein_LOG(text) T2::Log(text, __FILENAME__, __LINE__)

namespace T2
{
#define LOG_FILE "log.txt"

	void Log(const char* text, const char* file = '\0', int line = 0);

	void logSDL(void* userData, int category, SDL_LogPriority priority, const char* message);

	std::string RemovePathFromFile(const std::string& file);
}
