#include "ControlLabel.hpp"

ControlLabel::ControlLabel(SDL_Window *window, SDL_Renderer *renderer,
						   std::string text, Font *font)
	: Control(window, renderer)
{
	setBaseColor(SDL_Color{255, 255, 255, 0});
	setEdgeColor(SDL_Color{255, 255, 255, 255});
	setTextColor(SDL_Color{0, 0, 0, 255});

	this->text = text;
	this->font = font;

	// サーフェイスを生成
	SDL_Surface *surface =
		TTF_RenderUTF8_Blended(font->font, text.c_str(), textColor);

	if (surface == NULL) {	// サーフェイスの生成失敗
		throw std::invalid_argument(SDL_GetError());
	}

	// テクスチャを生成し、サーフェイスを解放
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	// ブレンドモードを設定
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_MUL);

	// テクスチャの幅と高さを取得
	SDL_QueryTexture(texture, nullptr, nullptr, &textureW, &textureH);
}

ControlLabel::~ControlLabel() { SDL_DestroyTexture(texture); }

void ControlLabel::setTextColor(SDL_Color color) { textColor = color; }

void ControlLabel::put(SDL_Rect area)
{
	this->area = area;

	// 描画領域をラベルの領域にする
	SDL_RenderSetViewport(renderer, &area);

	// ラベルの背景
	SDL_SetRenderDrawColor(renderer, baseColor.r, baseColor.g, baseColor.b,
						   baseColor.a);
	SDL_RenderFillRect(renderer, NULL);

	// ラベルのふち
	SDL_SetRenderDrawColor(renderer, edgeColor.r, edgeColor.g, edgeColor.b,
						   edgeColor.a);
	SDL_RenderDrawRect(renderer, NULL);

	// テキストのテクスチャ
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	// 画面に反映
	SDL_RenderPresent(renderer);
}