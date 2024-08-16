#include "object.hxx"
#include "raylib.h"
#include <algorithm>

ObjectBase::ObjectBase(Vector2 position) : position(position), color(BLACK) {}
