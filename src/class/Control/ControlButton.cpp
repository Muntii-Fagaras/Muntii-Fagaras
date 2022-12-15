#include "ControlButton.hpp"

ControlButton::ControlButton(SDL_Window *window, SDL_Renderer *renderer,
							 std::string text)
	: Control(window, renderer)
{
	setText(text);
	
	setBaseColor(SDL_Color{0, 0, 0, 0});
	setEdgeColor(SDL_Color{255, 255, 255, 255});
}

ControlButton::~ControlButton(){};

void ControlButton::setText(std::string text) { this->text = text; }
void ControlButton::setSlctColor(SDL_Color color) { slctColor = color; }

void ControlButton::put(SDL_Rect area)
{
	this->area = area;

	// •`‰æ—Ìˆæ‚ðƒ{ƒ^ƒ“‚Ì—Ìˆæ‚É‚·‚é
	SDL_RenderSetViewport(renderer, &area);

	// ƒ{ƒ^ƒ“‚Ì”wŒi
	SDL_SetRenderDrawColor(renderer, baseColor.r, baseColor.g, baseColor.b,
						   baseColor.a);
	SDL_RenderFillRect(renderer, NULL);

	// ƒ{ƒ^ƒ“‚Ì‚Ó‚¿
	SDL_SetRenderDrawColor(renderer, edgeColor.r, edgeColor.g, edgeColor.b,
						   edgeColor.a);
	SDL_RenderDrawRect(renderer, NULL);



	// ‰æ–Ê‚É”½‰f
	SDL_RenderPresent(renderer);
}