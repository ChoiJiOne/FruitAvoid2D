#include "CommandLine.h"

#include <Windows.h>

std::wstring CommandLine::CommandLine_;
std::vector<std::wstring> CommandLine::Arguments_;
std::unordered_map<std::wstring, std::wstring> CommandLine::Options_;

void CommandLine::Parse()
{
	CommandLine_ = GetCommandLineW();
	Arguments_ = Text::Split(CommandLine_, L" ");

	for (const auto& Argument : Arguments_)
	{
		if (Argument.find(L"=") != std::string::npos)
		{
			std::vector<std::wstring> Tokens = Text::Split(Argument, L"=");
			Options_.insert({ Tokens.front(), Tokens.back() });
		}
	}
}

bool CommandLine::HaveOption(const std::wstring& InOption)
{
	auto Iter = Options_.find(InOption);

	return Iter != Options_.end();
}

std::wstring CommandLine::GetValue(const std::wstring& InOption)
{
	if (!HaveOption(InOption)) return L"";

	return Options_.at(InOption);
}
