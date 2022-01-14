#include <SDL/SDL.h>
#include <GL/glew.h>

#include "Bengine.h"

namespace Bengine
{
	int init()
	{
		// initialize SDL
		SDL_Init(SDL_INIT_EVERYTHING);

		// tells sdl we want to double buffer, will make this one smoother
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		return 0;
	}
}