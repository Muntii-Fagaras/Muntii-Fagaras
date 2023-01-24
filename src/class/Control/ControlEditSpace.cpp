#include "ControlEditSpace.hpp"

ControlEditSpace::ControlEditSpace(SDL_Window *window, SDL_Renderer *renderer,
								   Font *font)
	: Control(window, renderer)
{
	setBaseColor(SDL_Color{255, 255, 255, 0});
	setEdgeColor(SDL_Color{255, 255, 255, 255});
	setTextColor(SDL_Color{0, 0, 0, 255});

	this->font = font;
}

ControlEditSpace::~ControlEditSpace() {}

void ControlEditSpace::setTextColor(SDL_Color color) { textColor = color; }

void ControlEditSpace::presentText() { presentText(*text); }

void ControlEditSpace::presentText(Text &text)
{
	put(area);

	list<string> &rText = text.ref();
	int			  line = text.line, pos = text.pos;

	int w, h;	// 'M' �̕��ƍ������擾
	SDL_Surface *testSurface =
		TTF_RenderUTF8_Blended(font->font, "M", textColor);
	SDL_Texture *testTexture = SDL_CreateTextureFromSurface(renderer, testSurface);
	SDL_QueryTexture(testTexture, NULL, NULL, &w, &h);
	SDL_FreeSurface(testSurface);
	SDL_DestroyTexture(testTexture);

	int numLine = area.h / h;

	list<string>::iterator it, endDraw;

	if (numLine >= rText.size()) {
		it = next(rText.begin(), line - numLine / 2);
		endDraw = rText.end();
	}
	else if (line + numLine / 2 >= rText.size()) {
		it = next(rText.end(), - numLine);
		endDraw = rText.end();
	}
	else {
		it = next(rText.begin(), line - numLine / 2);
		endDraw = next(rText.begin(), line + numLine / 2);
	}
	
	int count = 0;
	while (it != endDraw) {
		// �T�[�t�F�C�X�𐶐�
		SDL_Surface *surface =
			TTF_RenderUTF8_Blended(font->font, it->c_str(), textColor);

		if (surface == NULL) {	// �T�[�t�F�C�X�̐������s
			throw std::invalid_argument(SDL_GetError());
		}

		// �e�N�X�`���𐶐����A�T�[�t�F�C�X�����
		SDL_Texture *texture =
			SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		SDL_Rect dstrect = {0, h * count, area.w, h};
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);

		SDL_DestroyTexture(texture);
		count++; it++;
	}

	SDL_RenderPresent(renderer);
}

void ControlEditSpace::put(SDL_Rect area)
{
	this->area = area;

	// �`��̈��ݒ�
	SDL_RenderSetViewport(renderer, &area);

	// �w�i
	SDL_SetRenderDrawColor(renderer, baseColor.r, baseColor.g, baseColor.b,
						   baseColor.a);
	SDL_RenderFillRect(renderer, NULL);

	// �ӂ�
	SDL_SetRenderDrawColor(renderer, edgeColor.r, edgeColor.g, edgeColor.b,
						   edgeColor.a);
	SDL_RenderDrawRect(renderer, NULL);

	// ��ʂɔ��f
	SDL_RenderPresent(renderer);
}