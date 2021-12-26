#include "displaymanager.hpp"
#include <raylib.h>

struct Rec : public Object{
  Vector2 position;
  Vector2 size;

  void draw() const override{
    DrawRectangle(position.x, position.y, size.x, size.y, BLUE);
  }
};

int main(){
  DisplayManager dm(200, 300, "Test Window", 60);

  Rec square;
  square.position = (Vector2){(float)GetScreenWidth()/2, (float)GetScreenHeight()/2};
  square.size = (Vector2){20.f, 20.f};

  dm.attachShape(&square);

  while(WindowShouldClose())
    dm.drawShape();

  dm.closeScreen();

  return 0;
}
