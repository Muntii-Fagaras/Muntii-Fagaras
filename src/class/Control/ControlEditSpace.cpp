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

void ControlEditSpace::presentText() { presentText(text); }

void ControlEditSpace::presentText(Text *text)
{
	put(area);
	this->text = text;

	list<string> *rText = text->ref();
	int			  line = text->line, pos = text->pos;

	int			 w, h;	// 'M' �̕��ƍ������擾
	const char	*testStr = "M";
	SDL_Surface *testSurface =
		TTF_RenderUTF8_Blended(font->font, testStr, textColor);

	SDL_Texture *testTexture =
		SDL_CreateTextureFromSurface(renderer, testSurface);
	SDL_QueryTexture(testTexture, NULL, NULL, &w, &h);
	SDL_FreeSurface(testSurface);
	SDL_DestroyTexture(testTexture);

	int numLine = area.h / h;
	int startDrawLine;

	list<string>::iterator it, endDraw;

		if (numLine >= rText->size()) {
			it			  = rText->begin();
			endDraw		  = rText->end();
			startDrawLine = 1;
		}
		else if (line + numLine / 2 >= rText->size()) {
			it			  = next(rText->begin(), line - numLine / 3);
			endDraw		  = rText->end();
			startDrawLine = line - numLine / 3 + 1;
		}
		else {
			it			  = next(rText->begin(), line - numLine / 2);
			endDraw		  = next(rText->begin(), line + numLine / 2);
			startDrawLine = line - numLine / 2 + 1;
		}

	list<SDL_Texture *> textures;

	int count = 0;
		while (it != endDraw) {
				if (strcmp(it->c_str(), "") != 0) {
					// �T�[�t�F�C�X�𐶐�
					SDL_Surface *surface = TTF_RenderUTF8_Blended(
						font->font, it->c_str(), textColor);

						if (surface == NULL) {	// �T�[�t�F�C�X�̐������s
							throw std::invalid_argument(SDL_GetError());
						}

					// �e�N�X�`���𐶐�
					SDL_Texture *newTexture =
						SDL_CreateTextureFromSurface(renderer, surface);
					textures.push_back(newTexture);
					SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_MUL);
					SDL_FreeSurface(surface);

					SDL_Rect dstrect = {0, h * count,
										static_cast<int>(w * it->length()), h};
					SDL_RenderCopy(renderer, newTexture, NULL, &dstrect);
				}

			count++;
			it++;
		}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 127);
	SDL_RenderDrawLine(renderer, w * (pos - 1), h * (line - startDrawLine),
					   w * (pos - 1), h * (line - startDrawLine + 1));

	SDL_RenderPresent(renderer);

		for (SDL_Texture *texture : textures) {
			SDL_DestroyTexture(texture);
		}
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