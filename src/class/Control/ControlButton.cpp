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

	// �`��̈���{�^���̗̈�ɂ���
	SDL_RenderSetViewport(renderer, &area);

	// �{�^���̔w�i
	SDL_SetRenderDrawColor(renderer, baseColor.r, baseColor.g, baseColor.b,
						   baseColor.a);
	SDL_RenderFillRect(renderer, NULL);

	// �{�^���̂ӂ�
	SDL_SetRenderDrawColor(renderer, edgeColor.r, edgeColor.g, edgeColor.b,
						   edgeColor.a);
	SDL_RenderDrawRect(renderer, NULL);



	// ��ʂɔ��f
	SDL_RenderPresent(renderer);
}