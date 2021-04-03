#include "render.h"

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 900;

Texture::Texture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Texture::~Texture()
{
	free();
}

bool Texture::loadFromFile(string path)
{
	free();

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << "Couldn't load image " << path << ". Error : " << IMG_GetError() << endl;
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		mTexture = SDL_CreateTextureFromSurface(mainRenderer, loadedSurface);
		if (mTexture == NULL)
		{
			cout << "Unable to create texture from surface" << path << ". Error : " << SDL_GetError << endl;
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}

	return mTexture != NULL;
}

void Texture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Texture::render(int x, int y, SDL_Rect* clip)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy(mainRenderer, mTexture, clip, &renderQuad);
}

bool initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL couldn't initialize ! Error : " << SDL_GetError() << endl;
		return false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		mainWindow = SDL_CreateWindow("Let's Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (mainWindow == NULL) {
			cout << "Window couldn't be created ! Error : " << SDL_GetError() << endl;
			return false;
		}
		else {
			mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
			if (mainRenderer == NULL) {
				cout << "Renderer couldn't be created ! Error : " << SDL_GetError() << endl;
				return false;
			}
			else {
				SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError());
					return false;
				}
			}
		}
	}
	return true;
}

void close()
{
	BlockSheet.free();

	SDL_DestroyRenderer(mainRenderer);
	SDL_DestroyWindow(mainWindow);
	mainWindow = NULL;
	mainRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

bool loadBlock()
{
	if (!BlockSheet.loadFromFile("Texture/Block.png"))
	{
		cout << "Failed to load block sheet" << endl;
		return false;
	}
	else
	{
		BlockRect[BLOCK_Z].x = 0;
		BlockRect[BLOCK_Z].y = 0;
		BlockRect[BLOCK_Z].w = 40;
		BlockRect[BLOCK_Z].h = 40;

		BlockRect[BLOCK_S].x = 40;
		BlockRect[BLOCK_S].y = 0;
		BlockRect[BLOCK_S].w = 40;
		BlockRect[BLOCK_S].h = 40;

		BlockRect[BLOCK_J].x = 80;
		BlockRect[BLOCK_J].y = 0;
		BlockRect[BLOCK_J].w = 40;
		BlockRect[BLOCK_J].h = 40;

		BlockRect[BLOCK_L].x = 120;
		BlockRect[BLOCK_L].y = 0;
		BlockRect[BLOCK_L].w = 40;
		BlockRect[BLOCK_L].h = 40;

		BlockRect[BLOCK_O].x = 0;
		BlockRect[BLOCK_O].y = 40;
		BlockRect[BLOCK_O].w = 40;
		BlockRect[BLOCK_O].h = 40;

		BlockRect[BLOCK_I].x = 40;
		BlockRect[BLOCK_I].y = 40;
		BlockRect[BLOCK_I].w = 40;
		BlockRect[BLOCK_I].h = 40;

		BlockRect[BLOCK_T].x = 80;
		BlockRect[BLOCK_T].x = 40;
		BlockRect[BLOCK_T].x = 40;
		BlockRect[BLOCK_T].x = 40;

		BlockRect[BLOCK_DEFAULT].x = 120;
		BlockRect[BLOCK_DEFAULT].y = 40;
		BlockRect[BLOCK_DEFAULT].w = 40;
		BlockRect[BLOCK_DEFAULT].h = 40;
	}
	return true;
}

void print()
{
	for (int a = 0; a < 16; a++) {
		for (int i = 4; i < 24; i++) {
			for (int j = 0; j < 10; j++) {
				if (player1Board[i][j] == 1) BlockSheet.render(150 + 40 * j, 10 + 40 * (i - 4), &BlockRect[BLOCK_I]);
			}
		}
	}
}