#include <iostream>
#include <raylib-cpp.hpp>

int main()
{
    // Initialization
    //----------------------------------------------------------------
    int screenWidth = 640;
    int screenHeight = 512;
    std::string windowTitle = "Simple Asteroid Game";
    raylib::Window window = raylib::Window(screenWidth, screenHeight, windowTitle);
    raylib::Texture bgTexture = LoadTexture("resources/background.png");

    window.SetTargetFPS(60);
    //----------------------------------------------------------------
    
    // Main Game Loop
    while (!window.ShouldClose())   // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        window.BeginDrawing();
        window.ClearBackground(BLACK);

        bgTexture.Draw((Vector2) {0, 0}, 0, 0.5f, WHITE);

        window.EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    bgTexture.Unload(); // Unload texture from GPU memory (VRAM)
    window.Close();  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}