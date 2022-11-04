#include "CommandLine.h"

#include <Windows.h>

std::string CommandLine::CommandLine_;
std::vector<std::string> CommandLine::Arguments_;
std::unordered_map<std::string, std::string> CommandLine::Options_;

void CommandLine::Init()
{
	CommandLine_ = GetCommandLineA();
	Arguments_ = Text::Split(CommandLine_, " ");

	for (const auto& Argument : Arguments_)
	{
		if (Argument.find("=") != std::string::npos)
		{
			std::vector<std::string> Tokens = Text::Split(Argument, "=");
			Options_.insert({ Tokens.front(), Tokens.back() });
		}
	}
}

bool CommandLine::HaveOption(const std::string& InOption)
{
	return Options_.find(InOption) != Options_.end();
}

std::string CommandLine::GetValue(const std::string& InOption)
{
	if (!HaveOption(InOption)) return "";

	return Options_.at(InOption);
}
