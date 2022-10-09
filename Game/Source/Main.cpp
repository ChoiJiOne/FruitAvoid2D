#include "FruitAvoid2D.h"

int main(int argc, char* argv[])
{
    try
    {
        auto Game = std::make_unique<FruitAvoid2D>();
        Game->Init();
        Game->Run();
    }
    catch (const std::exception& Exception)
    {
        spdlog::info(Exception.what());
    }

    return 0;
}