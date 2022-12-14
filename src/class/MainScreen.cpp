#include "MainScreen.hpp"

MainScreen::MainScreen(SDL_Window *window, Uint32 windowID, SDL_Event *eventPtr,
					   SDL_Renderer *renderer, SDL_Color bgColor)
{
	this->window   = window;
	this->windowID = windowID;
	this->eventPtr = eventPtr;
	this->renderer = renderer;
	this->bgColor  = bgColor;

	// タイルを生成
	TileEditSpace		 *tileEditSpace = new TileEditSpace(window, renderer);
	TileSupportCharactor *tileSupportCharactor =
		new TileSupportCharactor(window, renderer);

	// タイルをマップに追加
	tiles.insert(std::make_pair("editSpace", tileEditSpace));
	tiles.insert(std::make_pair("supportCharactor", tileSupportCharactor));

	// タイルを配置
	putTiles();
}

MainScreen::~MainScreen()
{
		// タイルを破棄
		for (std::pair<const char *, Tile *> object : tiles) {
			delete object.second;
		}
}

void MainScreen::putTiles()
{
	int winW, winH;
	SDL_GetWindowSize(window, &winW, &winH);
	putTiles(winW, winH);
}

void MainScreen::putTiles(int winW, int winH)
{
	SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b,
						   bgColor.a);
	SDL_RenderClear(renderer);

	tiles.at("editSpace")->put(SDL_Rect{0, 50, winW / 5 * 4, winH});
	tiles.at("supportCharactor")
		->put(SDL_Rect{winW / 5 * 4, winH / 3 * 2, winW / 5, winH / 3});
}

void MainScreen::handleEvent()
{
	switch (eventPtr->type) {
		case SDL_WINDOWEVENT:
			if (eventPtr->window.windowID == windowID) {
				switch (eventPtr->window.event) {
					case SDL_WINDOWEVENT_SIZE_CHANGED:
						putTiles(eventPtr->window.data1,
									eventPtr->window.data2);
						break;
					case SDL_WINDOWEVENT_CLOSE:
						eventPtr->type = SDL_QUIT;
						SDL_PushEvent(eventPtr);
						break;
				}
			}
			break;
	}
}