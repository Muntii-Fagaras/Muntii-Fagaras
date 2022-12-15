#include "Tile.hpp"

Tile::Tile(SDL_Window *window, SDL_Event *eventPtr, SDL_Renderer *renderer)
{
	this->window   = window;
	this->eventPtr = eventPtr;
	this->renderer = renderer;
}

Tile::~Tile() {}

void Tile::put(SDL_Rect area)
{
	this->area = area;

	// �`��̈���^�C���̗̈�ɂ���
	SDL_RenderSetViewport(renderer, &area);
	// �^�C���̔w�i�F
	SDL_SetRenderDrawColor(renderer, baseColor.r, baseColor.g, baseColor.b,
						   baseColor.a);
	// �^�C����h��Ԃ�
	SDL_RenderFillRect(renderer, NULL);

	// ��ʂɔ��f������
	SDL_RenderPresent(renderer);
}

void Tile::setBaseColor(SDL_Color color) { baseColor = color; }

int Tile::handleEvent() { return 0; }