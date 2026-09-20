#include <raylib.h>

int main() {
  int screenWidth = 520;
  int screenHeight = 640;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "TimeOn");

  SetTargetFPS(60);

  while(!WindowShouldClose()) {
    // set the minimum window size
    SetWindowMinSize(520, 640);

    // update changes to the window size
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Hello World!", screenWidth/2, screenHeight/2, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}