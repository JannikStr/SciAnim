#include <cstdio>
#include <iostream>

#include <raylib.h>

#include "objects/square.hxx"
#include "canvas.hxx"

class Test {};

int main(void)
{
    InitWindow(1280, 720, "SciAnim-Renderer");

    Square square = Square(Vector2{100, 100}, 100.0f);
    Square square2 = Square(Vector2{300, 400}, 150.0f);

    Canvas canvas;
    square.setColor(GREEN);
    square2.setColor(RED);
    auto object = canvas.addObject(square);
    object->setColor(WHITE);
    canvas.addObject(square2);

    canvas.setBackgroundColor(DARKBLUE);

    while(!WindowShouldClose())
    {
        canvas.update(GetTime());
        BeginDrawing();
        canvas.draw(GetTime());
        EndDrawing();
    }

    CloseWindow();
}
