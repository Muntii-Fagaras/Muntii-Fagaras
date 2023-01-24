#include "MainScreen.hpp"

MainScreen::MainScreen(SDL_Window *window, Uint32 windowID, SDL_Event *eventPtr,
					   SDL_Renderer *renderer, SDL_Color bgColor,
					   list<Task> &tasks)
	: tasks(tasks)
{
	this->window   = window;
	this->windowID = windowID;
	this->eventPtr = eventPtr;
	this->renderer = renderer;
	this->bgColor  = bgColor;

	// タイルを生成
	TileEditSpace *tileEditSpace =
		new TileEditSpace(window, eventPtr, renderer);
	TileMenuBar *tileMenuBar = new TileMenuBar(window, eventPtr, renderer);
	TileSupportCharactor *tileSupportCharactor =
		new TileSupportCharactor(window, eventPtr, renderer);

	// タイルをマップに追加
	tiles.insert(std::make_pair("editSpace", tileEditSpace));
	tiles.insert(std::make_pair("menuBar", tileMenuBar));
	tiles.insert(std::make_pair("supportCharactor", tileSupportCharactor));

	tileAcceptingTyping = tileEditSpace;

	// タイルを配置
	putTiles();

	// テキスト入力イベントの受け入れ開始
	SDL_StartTextInput();
}

MainScreen::~MainScreen()
{
	// タイルを破棄
	for (std::pair<const char *, Tile *> pair : tiles) {
		delete pair.second;
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
	tiles.at("menuBar")->put(SDL_Rect{0, 0, winW, 50});
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
			case SDL_MOUSEMOTION:
				mouseCursorPosition =
					SDL_Point{eventPtr->motion.x, eventPtr->motion.y};
					for (std::pair<const char *, Tile *> pair : tiles) {
							if (pair.second->selectedByMouse(
									mouseCursorPosition)) {
								pair.second->handleEventMOUSEMOTION();
								break;
							}
					}
				break;
			case SDL_MOUSEBUTTONDOWN:
				mouseCursorPosition =
					SDL_Point{eventPtr->button.x, eventPtr->button.y};
					for (std::pair<const char *, Tile *> pair : tiles) {
							if (pair.second->selectedByMouse(
									mouseCursorPosition)) {
								pair.second->handleEventMOUSEBUTTONDOWN();
								break;
							}
					}
				break;
			case SDL_MOUSEBUTTONUP:
				mouseCursorPosition =
					SDL_Point{eventPtr->button.x, eventPtr->button.y};
					for (std::pair<const char *, Tile *> pair : tiles) {
							if (pair.second->selectedByMouse(
									mouseCursorPosition)) {
								pair.second->handleEventMOUSEBUTTONUP();
								break;
							}
					}
				break;
			case SDL_MOUSEWHEEL:
					for (std::pair<const char *, Tile *> pair : tiles) {
							if (pair.second->selectedByMouse(
									mouseCursorPosition)) {
								pair.second->handleEventMOUSEWHEEL();
								break;
							}
					}
				break;
			case SDL_TEXTEDITING:
				// tileAcceptingTyping->
				break;
			case SDL_TEXTINPUT:
				// tileAcceptingTyping->
				tasks.push_back(InsertStr(eventPtr->text.text));
				break;
		}
}

void MainScreen::runTask()
{
	TaskMainScreen &task = (TaskMainScreen &)tasks.front();

	switch (task.kind) {
		case TASK_KIND_MainScreen::PRESENT_TEXT:
			((TileEditSpace *)(tiles.at("editSpace")))
				->present((PresentText &)task);
			break;
	}
}