#include <SDL2/SDL.h>

#include <cinttypes>

//https://gist.githubusercontent.com/sprae/4c9f364ad1e0741e8f9629b2c676a0fa/raw/e4a6fe9f093c826b4ac8393d54135cc16d905fd0/main.cpp

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK);

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_CreateWindowAndRenderer(320, 240, SDL_WINDOW_SHOWN, &window, &renderer);

    SDL_Joystick *joystick;
    joystick = SDL_JoystickOpen(0);

    printf("Name: %s\n", SDL_JoystickNameForIndex(0));


    SDL_Event event;
    while (1) {
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        } else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                break;
            }
        } else if (event.type == SDL_JOYAXISMOTION) {
            printf("axis: %i %i\n", event.jaxis.axis, event.jaxis.value);
        } else if (event.type == SDL_JOYBUTTONDOWN) {
            printf("button: %i\n", event.jbutton.button);
        }
    }

    SDL_JoystickClose(joystick);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
