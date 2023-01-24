#include "TileEditSpace.hpp"

TileEditSpace::TileEditSpace(SDL_Window *window, SDL_Event *eventPtr,
							 SDL_Renderer *renderer)
	: Tile(window, eventPtr, renderer)
{
	setBaseColor(SDL_Color{0, 0, 0, 128});

	font			  = new Font();
	fs::path fontPath = fs::path("assets/fonts/HackGen-Regular.ttf");
	font->load(fontPath, 40, 0);

	editSpace = new ControlEditSpace(window, renderer, font);
}

TileEditSpace::~TileEditSpace()
{
	delete font;
	delete editSpace;
}

void TileEditSpace::put(SDL_Rect area)
{
	this->area = area;
	putControls();
}

void TileEditSpace::putControls()
{
	SDL_Rect eaArea = {area.x, area.y, area.w, area.h};
	editSpace->put(eaArea);
}

void TileEditSpace::present(PresentText &task)
{
	text = &(task.text);
	editSpace->presentText(task.text);
}