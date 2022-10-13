#pragma once
#include "button.hpp"
button::button(std::vector<std::string> image_path, SDL_Renderer* renderer, int x, int y, bool mouse_state)
{
	if (mouse_state == true) {
		// チェックボックスの状態を取得できるように代入する
		checkbox_state = !checkbox_state;
	}
	// falseの時は未チェック、trueの時はチェック
	uncheck.load(image_path.at(0), renderer, x, y);
	checked.load(image_path.at(1), renderer, x, y);
}

button::~button()
{
	// チェックボックスの画像サーフェスを解放する
	SDL_FreeSurface(image_surface);
	// テクスチャを解放する
	SDL_DestroyTexture(texture);
	texture = nullptr;	//とりあえずnullptrを入れとく
}

void button::next(bool mouse_state)
{
	if (mouse_state == true) {
		// チェックボックスの状態を取得できるように代入する
		checkbox_state = !checkbox_state;
	}
	this->rect = uncheck.rect;
	this->texture = uncheck.texture;
}