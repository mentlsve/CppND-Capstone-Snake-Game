#include <Renderer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include <iostream>
#include <string>

#include "Ball.h"
#include "Racket.h"
#include "Timer.h"

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Screen dimension constants
const SDL_Rect fieldDimensions = {20, 20, SCREEN_WIDTH - 20,
                                  SCREEN_HEIGHT - 20};

// player bounding box
const SDL_Rect playerPaddleBB = {10, 10, 10, 50};

int main(int argc, char* args[]) {
  Timer timer;
  Renderer renderer;
  std::size_t ball_hit = SDL_GetTicks();
  std::size_t ms_passed_since_last_ball_hit = 0;
  Ball ball(renderer.getRenderer(), fieldDimensions);
  Racket player(renderer.getRenderer(), SCREEN_WIDTH, SCREEN_HEIGHT,
                playerPaddleBB);

  bool quit = false;
  SDL_Event e;

  timer.start();
  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) quit = true;
    }
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    ms_passed_since_last_ball_hit = SDL_GetTicks() - ball_hit;
    if (currentKeyStates[SDL_SCANCODE_UP]) {
      player.up();
      ball_hit = SDL_GetTicks();
    } else if (currentKeyStates[SDL_SCANCODE_DOWN]) {
      player.down();
    }
    renderer.clearScreen();

    /* player.update();
     ball.update(ms_passed_since_last_ball_hit);
     SDL_Rect ballbb = ball.getBoundingBox();
     SDL_Rect playerbb = player.getBoundingBox();

     bool hit = SDL_HasIntersection(&ballbb, &playerbb);

    // if (hit) {
    if (ball.isOutside()) {
      ball.inverse();
      ball_hit = SDL_GetTicks();
    }*/

    // update objects
    player.update();
    ball.update(timer.getTicks());

    // check for intersection
    bool intersection = ball.isOutside();
    if (intersection) {
      timer.start();
      ball.inverse();
    } else {
    }
    renderer.updateScreen();
    std::string title = std::to_string(ball.isOutside());
    renderer.updateTitle(title);
    SDL_Delay(10);
  }

  // Destroy window
  return 0;
}
