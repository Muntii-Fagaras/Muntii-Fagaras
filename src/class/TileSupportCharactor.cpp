#include "TileSupportCharactor.hpp"

TileSupportCharactor::TileSupportCharactor(SDL_Window	*window,
										   SDL_Renderer *renderer)
	: Tile(window, renderer)
{
	setBackgroundColor(255, 0, 0, 128);
}

TileSupportCharactor::~TileSupportCharactor() {}

int TileSupportCharactor::run()
{
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

	return 0;
}