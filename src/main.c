#include "constants.h"
#include <SDL2/SDL.h>
#include <stdio.h>

const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int isGameRunning = FALSE;
int ticksLastFrame = 0;

int playerX, playerY;

int initializeWindow() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Error initializing SDL.\n");
    return FALSE;
  }
  window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                            WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_BORDERLESS);
  // lots of if states low performance
  if (!window) {
    fprintf(stderr, "Error creating SDL window.\n");
    return FALSE;
  }
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    fprintf(stderr, "Error creating SDL renderer.\n");
    return FALSE;
  }
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

  return TRUE;
}

void destroyWindow() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void setup() {}

void processInput() {
  SDL_Event event;
  SDL_PollEvent(&event);

  // checks if user closes game using EscapeKey
  switch (event.type) {
  case SDL_QUIT: {
    isGameRunning = FALSE;
    break;
  }
  case SDL_KEYDOWN: {
    if (event.key.keysym.sym == SDLK_ESCAPE) isGameRunning = FALSE;
    break;
  }
  }
}

void update() {
  /*example of bad performace
    waste time until we reach target frame time length (Sets FPS)
    in the future we will not be while loop as it takes up  all the
    porcessor and slows down our PC and our app
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TIME_LENGHT));
  */

  // Compute how long we have until the reach the target frame in milliseconds
  int timeToWait = FRAME_TIME_LENGHT - (SDL_GetTicks() - ticksLastFrame);
  // Only delay is running too fast
  if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGHT) SDL_Delay(timeToWait);

  // compute the delta time to be used as an update factor when changing game objects
  float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
  // store milliseconds of the current frame to be used in the future
  ticksLastFrame = SDL_GetTicks();

  // TODO remember to updater game objects as a function of delta time
  playerX += 50 * deltaTime;
  playerY += 50 * deltaTime;
}

void render() {
  SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
  SDL_RenderClear(renderer);

  // TODO:
  // Render Game Objects
  
  SDL_RenderPresent(renderer);
}

// program entery point
int main() {
  isGameRunning = initializeWindow();

  setup();

  // mainGameLoop
  while (isGameRunning) {
    processInput();
    update();
    render();
  }

  destroyWindow();

  return 0;
}
