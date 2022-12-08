#include "Tile.hpp"

Tile::Tile(SDL_Window *window, SDL_Renderer *renderer)
{
	this->window   = window;
	this->renderer = renderer;
}

Tile::~Tile() {}

void Tile::setArea(SDL_Rect area)
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

	SDL_Delay(10);
}

void Tile::setBackgroundColor(MuntiiColor color) {
	baseColor = color;
}

int Tile::handleEvent(SDL_Event *event) { return 0; }