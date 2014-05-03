#include <SDL.h>
#include <cstdio>
#include <random>


#undef main
#define RGB_COLOR(R, G, B) (((B) << 24) | ((G) << 16) | ((R) << 8)) 

SDL_Window *window;
SDL_Event event;
SDL_Renderer *render;
SDL_Surface *surface;

const int screenWidth = 1280;
const int screenHeight = 720;

struct point {
	int x;
	int y;
};

struct rectangle {
	point min;
	point max;
} player;

struct vector2 {
	float x;
	float y;
};

struct physic {
	vector2 pos; // koordinat
	vector2 velocity; //riktade hastighten
	vector2 forces;
};

const int rectSize = 40;
const int numBarrier = 1;

rectangle arrBarrier[numBarrier];
float enemySpeed = 0.5;

void integrate(physic* ph , float delta) {
	vector2 vec = ph->forces * delta;
}

void fillRect(int x, int y, int w, int h, int color) {
	SDL_Rect rect = {x, y, w, h};
	SDL_FillRect(surface, &rect, color);
}

void drawBarriers() {
	for (int i = 0; i < numBarrier; i++) {
		fillRect(arrBarrier[i].min.x, arrBarrier[i].min.y, rectSize, rectSize, RGB_COLOR(255, 0, 255));		
	}
}

void barrierRect() {
	for (int i = 0; i < numBarrier; i++) {
		arrBarrier[i].min.x = (rand() % 1180 + 50);
		arrBarrier[i].min.y = (rand() % 620 + 50);
		arrBarrier[i].max.x = arrBarrier[i].min.x + rectSize;
		arrBarrier[i].max.y = arrBarrier[i].min.y + rectSize;
	}
}

void playerRect() {
	fillRect(player.min.x, player.min.y, player.max.x - player.min.x, player.max.y - player.min.y , RGB_COLOR(255, 255, 0)); // rectSize rectSize
}

void wallCollision() {
	if (player.min.x < 0) {
		player.min.x = 0;
		player.max.x = rectSize;
	}
	if (player.min.y < 0) {
		player.min.y = 0;
		player.max.y = rectSize;
	}
	if (player.max.x > screenWidth) {
		player.max.x = screenWidth;
		player.min.x = screenWidth - rectSize;
	}
	if (player.max.y > screenHeight) {
		player.max.y = screenHeight;
		player.min.y = screenHeight - rectSize;
	}
}

bool intersection() {
	for (int i = 0; i < numBarrier; i++) {
		if (player.min.x > arrBarrier[i].max.x ||
		player.min.y > arrBarrier[i].max.y ||
		arrBarrier[i].min.x > player.max.x ||
		arrBarrier[i].min.y > player.max.y) {
			return false;
		} else {
			return true;
		}
	}
}

rectangle recCollision() {

	// player
	int playerTop = player.min.y;
	int playerBottom = player.max.y;
	int playerRight = player.max.x;
	int playerLeft = player.min.x;

	//Barrier
	for (int i = 0; i < numBarrier; i++) {

		int barrierTop = arrBarrier[i].min.y;
		int barrierBottom = arrBarrier[i].max.y;
		int barrierRight = arrBarrier[i].max.x;
		int barrierLeft = arrBarrier[i].min.x;

		if(intersection()) 
		{
			if (playerBottom > barrierTop) {
				++player.min.y;
				++player.max.y;
			}
			if (playerRight > barrierLeft) {
				++player.min.x;
				++player.max.x;
			}
			if (playerLeft < barrierRight) {
				--player.min.x;
				--player.max.x;
			}
			if (playerTop < barrierBottom) {
 				--player.min.y;
				--player.max.y;
			}
			return player;
		}	
		return player;
	}
}

void enemyMovement() {
	for (int i = 0; i < numBarrier; i++) {
		if (player.min.x > arrBarrier[i].min.x) {
			++arrBarrier[i].min.x;
			++arrBarrier[i].max.x;
		}
		if (player.min.x < arrBarrier[i].min.x) {
			--arrBarrier[i].min.x;
			--arrBarrier[i].max.x;
		}
		if (player.max.y < arrBarrier[i].max.y) {
			--arrBarrier[i].max.y;
			--arrBarrier[i].min.y;
		}
		if (player.max.y > arrBarrier[i].max.y) {
			++arrBarrier[i].max.y;
			++arrBarrier[i].min.y;
		}
	}
}

void controlls() {
	const Uint8 *keys = SDL_GetKeyboardState(0); 
	if (keys[SDL_SCANCODE_LEFT]) {
		--player.min.x;
		--player.max.x;
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		++player.min.x;
		++player.max.x;
	}
	if (keys[SDL_SCANCODE_UP]) {
		--player.max.y;
		--player.min.y;
	}
	if (keys[SDL_SCANCODE_DOWN]) {
		++player.max.y;
		++player.min.y;
	}
}

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("FirstGame", 600, 200, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, 0, 0);
	surface = SDL_GetWindowSurface(window);

	player.max.x = rectSize;
	player.max.y = rectSize;
	barrierRect();	

	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			// quit window
			if (event.type == SDL_QUIT) {
				running = false;
			}	
		}

		fillRect(0, 0, screenWidth, screenHeight, 0);

		drawBarriers();
		playerRect();

		//enemyMovement();

		controlls();
		wallCollision();

		recCollision();

		SDL_UpdateWindowSurface(window);
		SDL_Delay(1);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

