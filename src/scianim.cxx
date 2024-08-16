#include <cstdio>
#include <iostream>

#include <raylib.h>

#include "objects/square.hxx"
#include "canvas.hxx"

class Test {};

int main(void)
{
    InitWindow(1280, 720, "SciAnim-Renderer");

    SetTargetFPS(60);

    Square square = Square(Vector2{100, 100}, 100.0f);
    Square square2 = Square(Vector2{300, 400}, 150.0f);

    Canvas canvas;
    square.setColor(GREEN);
    square2.setColor(RED);
    auto object = canvas.addObject(square);
    object->setColor(WHITE);
    canvas.addObject(square2);

    canvas.setBackgroundColor(DARKBLUE);

    object->move(Vector2{100, 100}, Vector2{200, 600}, 4.0f);
    object->move(Vector2{200, 600}, Vector2{1000, 200}, 3.0f);
    object->delay(2.5f);
    object->move(Vector2{1000, 200}, Vector2{100, 100}, 10.0f);

    while(!WindowShouldClose())
    {
        canvas.update();
        BeginDrawing();
        canvas.draw();
#ifdef SCIANIM_DEBUG
    DrawFPS(20, 10);
#endif
        EndDrawing();
    }

    CloseWindow();
}
