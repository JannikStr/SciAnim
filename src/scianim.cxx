#include <cstdio>
#include <iostream>
#include <raylib.h>

#include "objects/square.hxx"
#include "canvas.hxx"

int main(void)
{
    InitWindow(1280, 720, "SciAnim-Renderer");

    std::shared_ptr<Square> square =  std::make_shared<Square>(Vector2{100, 100}, 100.0f);

    square->addKeyFramePosition(4, Vector2{300, 300});
    square->addKeyFramePosition(4, Vector2{400, 200});


    Canvas canvas;

    canvas.addObject(square);

    while(!WindowShouldClose())
    {
        canvas.update(GetTime());
        BeginDrawing();
        ClearBackground(DARKGRAY);
        canvas.draw(GetTime());
        EndDrawing();
    }

    CloseWindow();
}
