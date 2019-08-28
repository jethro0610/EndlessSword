#include <iostream>
#include <SDL.h>

int main(int argc, char** argv) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "SDL failed \n";
	}
	else {
		std::cout << "SDL initialized";
	}

	return 0;
}