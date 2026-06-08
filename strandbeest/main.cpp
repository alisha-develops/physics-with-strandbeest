#include <SDL2/SDL.h>
#include <emscripten.h>

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

void mainLoop() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {}

    SDL_SetRenderDrawColor(renderer, 30, 30, 40, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_Rect r = {300, 200, 80, 40};
    SDL_RenderFillRect(renderer, &r);

    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(800, 500, 0, &window, &renderer);
    emscripten_set_main_loop(mainLoop, 0, 1);
    return 0;
}