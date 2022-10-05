#include "GameEngine.h"

int main(int argc, char* argv[])
{
    GameEngine::Init();

    WindowSystem& Window = GameEngine::CreateWindowSystem("FruitAvoid2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
    RenderSystem& Renderer = GameEngine::CreateRenderSystem();
    InputSystem& Input = GameEngine::CreateInputSystem();
    ResourceSystem& Resource = GameEngine::CreateResourceSystem();

    std::string ResourcePath = "D:\\ToyEngine\\FruitAvoid2D\\Resource\\";
    Texture& BGTexture = Resource.LoadTextureFromFile(Text::GetHash("Beach"), ResourcePath + "texture\\Beach.jpg");
    Font& MonoFont = Resource.LoadFontFromFile(Text::GetHash("Mono"), ResourcePath + "font\\JetBrainsMono-Bold.ttf", 0x20, 0x7E, 32.0f);

    while (!Input.Tick())
    {
        Renderer.BeginFrame(Color::Black);

        Renderer.DrawTexture2D(BGTexture, Vec2i(500, 400), 1000, 800);
        Renderer.DrawText2D(MonoFont, L"Hello World!", Vec2i(500, 400), Color::Red);
        
        Renderer.EndFrame();
    }

    GameEngine::Quit();
    return 0;
}