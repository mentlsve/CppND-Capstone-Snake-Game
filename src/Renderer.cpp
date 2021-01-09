#include "Renderer.h"

#include <SDL2/SDL_image.h>

SDL_Window* createWindow() {
  SDL_Window* rawWindow = nullptr;
  rawWindow =
      SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
  if (nullptr == rawWindow) {
    printf("SDL could not create window! SDL_Error: %s\n", SDL_GetError());
    throw SDL_GetError();
  }
  return rawWindow;
}

SDL_Renderer* createRenderer(SDL_Window* window) {
  SDL_Renderer* rawRenderer = nullptr;
  rawRenderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (nullptr == rawRenderer) {
    printf("SDL could not create renderer! SDL_Error: %s\n", SDL_GetError());
    throw SDL_GetError();
  }
  return rawRenderer;
}

Renderer::Renderer() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }

  window_ = createWindow();
  renderer_ = createRenderer(window_);

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    printf("SDL_image could not initialize! SDL_image Error: %s\n",
           IMG_GetError());
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

SDL_Renderer* Renderer::getRenderer() { return renderer_; }

void Renderer::show(SDL_Texture* image) {
  SDL_RenderClear(renderer_);
  // SDL_RenderCopy(renderer_, image, NULL, NULL);
  SDL_RenderPresent(renderer_);
}

void Renderer::updateScreen() { SDL_RenderPresent(renderer_); }

void Renderer::updateTitle(std::string title) {
  SDL_SetWindowTitle(window_, title.c_str());
}

void Renderer::clearScreen() {
  SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer_);
}