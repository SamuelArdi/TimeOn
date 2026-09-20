#include <raylib.h>

int main() {
  int screenWidth = 520;
  int screenHeight = 640;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "TimeOn");
  SetTargetFPS(60);

  while(!WindowShouldClose()) {
    // set the minimum and maximum window size
    SetWindowMinSize(520, 640);
    SetWindowMaxSize(1080, 1440);

    // update changes to the window size
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Hello World", screenWidth/2, screenHeight/2, 20, MAROON);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}