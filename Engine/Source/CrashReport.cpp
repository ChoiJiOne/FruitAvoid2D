#include "CrashReport.h"
#include "CommandLine.h"

#include <chrono>
#include <ctime>
#include <string>

void CrashReport::Init()
{
	SetUnhandledExceptionFilter(UnhandledExceptionHandler);
}

LONG __stdcall CrashReport::UnhandledExceptionHandler(_EXCEPTION_POINTERS* InExceptionInfo)
{
	CreateCrashDumpFile(InExceptionInfo);
	return EXCEPTION_CONTINUE_SEARCH;
}

void CrashReport::CreateCrashDumpFile(_EXCEPTION_POINTERS* InExceptionInfo)
{
	time_t CurrentTime = time(nullptr);
	tm* CurrentLocalTime = localtime(&CurrentTime);

	std::wstring DumpFile = Text::Format(
		L"%s%d-%d-%d-%d-%d-%d.dmp",
		CommandLine::GetValue(L"-Dump").c_str(),
		CurrentLocalTime->tm_year + 1900,
		CurrentLocalTime->tm_mon + 1,
		CurrentLocalTime->tm_mday,
		CurrentLocalTime->tm_hour,
		CurrentLocalTime->tm_min,
		CurrentLocalTime->tm_sec
	);
	
	HANDLE  FileHandler = CreateFile(
		DumpFile.c_str(),
		GENERIC_WRITE, 
		FILE_SHARE_WRITE, 
		NULL, 
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, 
		NULL
	);

	_MINIDUMP_EXCEPTION_INFORMATION ExceptionInfo;
	ExceptionInfo.ThreadId = GetCurrentThreadId();
	ExceptionInfo.ExceptionPointers = InExceptionInfo;
	ExceptionInfo.ClientPointers = FALSE;

	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), FileHandler, MiniDumpNormal, &ExceptionInfo, NULL, NULL);
	CloseHandle(FileHandler);
}
