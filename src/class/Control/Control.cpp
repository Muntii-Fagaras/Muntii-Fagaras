#include "Control.hpp"

Control::Control(SDL_Window* window, SDL_Renderer* renderer)
{
	this->window   = window;
	this->renderer = renderer;
}

Control::~Control() {}

// �R���g���[�����ƂɃI�[�o�[���C�h����
void Control::put(SDL_Rect area)
{
	this->area = area;

	// �`��̈���R���g���[���̗̈�ɂ���
	SDL_RenderSetViewport(renderer, &area);
	// �R���g���[���̔w�i�F
	SDL_SetRenderDrawColor(renderer, baseColor.r, baseColor.g, baseColor.b,
						   baseColor.a);
	// �R���g���[����h��Ԃ�
	SDL_RenderFillRect(renderer, NULL);

	// ��ʂɔ��f������
	SDL_RenderPresent(renderer);
}

void Control::setBaseColor(SDL_Color color) { baseColor = color; }

void Control::setEdgeColor(SDL_Color color) { edgeColor = color; }

bool Control::selectedByMouse(SDL_Point mouseCursorPosition)
{
	return SDL_PointInRect(&mouseCursorPosition, &area);
}