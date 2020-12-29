#include <Renderer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "Racket.h"

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
  Renderer renderer;
  Racket player(renderer.getRenderer(), SCREEN_WIDTH, SCREEN_HEIGHT);

  bool quit = false;
  SDL_Event e;
  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) quit = true;
    }
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_UP]) {
      player.up();
    } else if (currentKeyStates[SDL_SCANCODE_DOWN]) {
      player.down();
    }
    renderer.clearScreen();

    player.update();
    renderer.updateScreen();
    SDL_Delay(10);
  }

  // Destroy window
  return 0;
}
