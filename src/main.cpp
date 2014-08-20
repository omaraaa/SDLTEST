
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
#include <chrono>

#include <SDL2/SDL.h>
#include "../include/window.h"
#include "../include/cleanup.h"
#include "../include/CS.h"
#include "../include/system.h"
#include "../include/entities.h"


using namespace std;



int main(int argc, char **argv){
	try {
		Window::Init("GAME");
	}
	catch (const std::runtime_error &e){
		std::cout << e.what() << std::endl;
		Window::Quit();
		return -1;
	}

	TEST(0,0);

	SDL_Event e;
	bool quit=false;
	while(!quit){
		


		auto timePoint1(chrono::high_resolution_clock::now());

		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT)
				quit = true;
			if(e.type == SDL_MOUSEBUTTONDOWN){
				mBox(e.button.x, e.button.y);
			}
			if (e.type == SDL_KEYDOWN){
				switch(e.key.keysym.sym){
					case SDLK_r:
						CS::clear();
						TEST(100,100);
						break;
				}
			}

			CS::eventUpdate(e);
		}

		Timer::slice += Timer::elapsed;
		for(; Timer::slice >= Timer::frame; Timer::slice -= Timer::frame)
		{
			CS::update();
		}
		Window::Clear();
		CS::collisionUpdate();
		CS::draw();
		Window::Present();
		auto timePoint2(chrono::high_resolution_clock::now());
		auto elaspedTime(timePoint2 - timePoint1);

		Timer::elapsed = chrono::duration_cast<
			chrono::duration<float, milli>>(elaspedTime).count();
		// std::cout << (1000.f/ft) << std::endl;
		// if(Timer::elapsed > maxTime){
		// 	int loops = Timer::elapsed/maxTime;
		// 	for(int i=0;i<loops;i++){
		// 		CS::update();
		// 	}
		// } else {
		// 	int delay = maxTime - Timer::elapsed;
		// 	SDL_Delay(delay);
		// }
	}
	Window::Quit();
	return 0;
}