#include <raylib.h>

int main() {
  int screenWidth = 520;
  int screenHeight = 640;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "TimeOn");

  Texture2D bg = LoadTexture("assets/images/bg.jpg");
  Texture2D vhs = LoadTexture("assets/images/vhs_filter.jpg");

  Texture2D clock = LoadTexture("assets/images/rect_clock.png");
  Texture2D hourHand = LoadTexture("assets/images/hour_hand.svg");
  Texture2D minuteHand = LoadTexture("assets/images/minute_hand.svg");
  
  Texture2D timecard = LoadTexture("assets/images/timecard.jpg");

  SetTargetFPS(60);

  while(!WindowShouldClose()) {
    // set the minimum and maximum window size
    SetWindowMinSize(520, 640);
    SetWindowMaxSize(1080, 1440);

    // update changes to the window size
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    BeginDrawing();
      DrawTexture(bg, 0, 0, BLANK);
    EndDrawing();
  }

  UnloadTexture(bg);
  UnloadTexture(vhs);
  UnloadTexture(clock);
  UnloadTexture(hourHand);
  UnloadTexture(minuteHand);
  UnloadTexture(timecard);

  CloseWindow();
  return 0;
}