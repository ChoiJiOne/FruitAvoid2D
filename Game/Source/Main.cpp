#include "FruitAvoid2D.h"

int main(int argc, char* argv[])
{
    try
    {
        Game FruitAvoid2D;
        FruitAvoid2D.Init();
        FruitAvoid2D.Run();
    }
    catch (const std::exception& Exception)
    {
        spdlog::info(Exception.what());
    }

    return 0;
}