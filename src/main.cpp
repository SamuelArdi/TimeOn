#include <raylib.h>
#include <iostream>
#include <random>

#include "helper.hpp"
#include "animation.hpp"

#define FPS 60

int main() {
  const int screenWidth = 520;
  const int screenHeight = 640;

  InitWindow(screenWidth, screenHeight, "TimeOn");

  Texture2D texBg = LoadTexture("assets/images/bg.png");
  Texture2D texVhs = LoadTexture("assets/images/vhs_filter.png");

  Texture2D texClock = LoadTexture("assets/images/rect_clock.png");
  Texture2D texHourHand = LoadTexture("assets/images/hour_hand.png");
  Texture2D texMinuteHand = LoadTexture("assets/images/minute_hand.png");
  
  Texture2D texTimecard = LoadTexture("assets/images/timecard.png");

  // define elements
  Element elemClock {
    { 0.0f, 0.0f, (float)texClock.width, (float)texClock.height },
    { screenWidth/2.0f, (float)(screenHeight-((texClock.width/4)/2))-10, texClock.width/4.0f, texClock.height/4.0f },
    { elemClock.dest.width/2.0f, elemClock.dest.height/2 }
  };

  Element elemTimecard {
    { 0.0f, 0.0f, (float)texTimecard.width, (float)texTimecard.height },
    { screenWidth/2.0f, ((texTimecard.height/4)/2.0f)+10, texTimecard.width/4.0f, texTimecard.height/4.0f },
    { elemTimecard.dest.width/2.0f, elemTimecard.dest.height/2 },
    0.0f
  };

  SetTargetFPS(FPS);

  while(!WindowShouldClose()) {
    Sway clockSway { 0, 360, 0.2 };
    Sway timecardSway {0, 50, 0.2};

    elemClock.rotation = (float)clockSway();
    std::cout << elemClock.rotation << std::endl;

    BeginDrawing();

      // bg
      Rectangle recBg{(float)texBg.width/2, (float)texBg.height/2, (float)screenWidth, (float)screenHeight};
      DrawTextureRec(texBg, recBg, { 0, 0 }, WHITE);

      // clock
      DrawTexturePro(texClock, elemClock.src, elemClock.dest, elemClock.origin, elemClock.rotation, WHITE);
      
      // timecard
      DrawTexturePro(texTimecard, elemTimecard.src, elemTimecard.dest, elemTimecard.origin, elemTimecard.rotation, WHITE);

      // filter
      Rectangle recVhs{0, 0, (float)screenWidth, (float)screenHeight};
      DrawTextureRec(texVhs, recVhs, { 0, 0 }, { 255, 255, 255, 100 });
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
