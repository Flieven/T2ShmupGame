#include "ErrorLogger.h"

void T2::Log(const char* text, const char* file, int line)
{
	static bool isInitialized = false;
	FILE* logFile = nullptr;

	if (isInitialized)
	{
		if (fopen_s(&logFile, LOG_FILE, "a+") != 0) { return; }
	}
	else
	{
		if (fopen_s(&logFile, LOG_FILE, "w") != 0) { return; }
		else { isInitialized = true; }
	}

	if (logFile)
	{
		if (file == '\0') { fprintf_s(logFile, "%s", text); }
		else { fprintf_s(logFile, "%s(%d) %s", file, line, text); }
		fputc('\n', logFile);
		fclose(logFile);
	}
}

void T2::logSDL(void* userData, int category, SDL_LogPriority priority, const char* message)
{
	Log(message);
}

std::string T2::RemovePathFromFile(const std::string& file)
{
	return std::string(file).substr(file.find_last_of("\\/") + 1, file.length());
}
