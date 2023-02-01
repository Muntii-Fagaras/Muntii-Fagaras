#include "TileMenuBar.hpp"

TileMenuBar::TileMenuBar(SDL_Window *window, SDL_Event *eventPtr,
						 SDL_Renderer *renderer)
	: Tile(window, eventPtr, renderer)
{
	setBaseColor(SDL_Color{0, 0, 255, 255});

	font			  = new Font();
	fs::path fontPath = fs::path("assets/fonts/HackGen-Regular.ttf");
	font->load(fontPath, 40, 0);

	buttonSave = new ControlButton(window, renderer, "Save", font);
}

TileMenuBar::~TileMenuBar()
{
	delete buttonSave;
	delete font;
};

void TileMenuBar::put(SDL_Rect area)
{
	Tile::put(area);
	putControls();
}

void TileMenuBar::putControls()
{
	SDL_Rect bSaveArea = {area.x, area.y, area.w / 10, area.h};
	buttonSave->put(bSaveArea);
}

void TileMenuBar::handleEventMOUSEBUTTONDOWN(list<Task *> *tasks)
{
	voice	  tired("assets/voice/periodical/tired.wav");
	SDL_Point mouseCursorPosition =
		SDL_Point{eventPtr->button.x, eventPtr->button.y};
		if (buttonSave->selectedByMouse(mouseCursorPosition)) {
			Save *newTask = new Save();
			tasks->push_back(newTask);
		}
		else {
			tired.play();
		}
}