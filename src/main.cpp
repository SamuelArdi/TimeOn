#include <raylib.h>
#include <string>

#include "helper.h"

int main() {
  int screenWidth = 520;
  int screenHeight = 640;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "TimeOn");

  Texture2D texBg = LoadTexture("assets/images/bg.png");
  Texture2D texVhs = LoadTexture("assets/images/vhs_filter.png");

  Texture2D texClock = LoadTexture("assets/images/rect_clock.png");
  Texture2D texHourHand = LoadTexture("assets/images/hour_hand.svg");
  Texture2D texMinuteHand = LoadTexture("assets/images/minute_hand.svg");
  
  Texture2D texTimecard = LoadTexture("assets/images/timecard.png");

  SetTargetFPS(60);

  while(!WindowShouldClose()) {
    // set the minimum and maximum window size
    SetWindowMinSize(520, 640);
    SetWindowMaxSize(1080, 1440);

    // update changes to the window size
    if (IsWindowResized()) {
      screenWidth = GetScreenWidth();
      screenHeight = GetScreenHeight();
    }

    BeginDrawing();
      Rectangle recBg{(float)texBg.width/2, (float)texBg.height/2, (float)screenWidth, (float)screenHeight};
      DrawTextureRec(texBg, recBg, { 0, 0 }, WHITE);
    EndDrawing();
  }

  UnloadTexture(texBg);
  UnloadTexture(texVhs);
  UnloadTexture(texClock);
  UnloadTexture(texHourHand);
  UnloadTexture(texMinuteHand);
  UnloadTexture(texTimecard);

  CloseWindow();
  return 0;
}