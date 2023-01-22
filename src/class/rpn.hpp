#pragma once

#ifdef __GNUC__
	#include "../stdafx.h"
#endif
class reverse_polish_notation {
   public:
	// 逆ポーランド記法へ直すための式
	std::vector<std::string> reverse_polish_notation_formula;
	// 逆ポーランド記法になった式
	std::vector<std::string> fixed_reverse_polish_notation_formula;

	void create_reverse_polish_notation(std::string normal_notation_formula);

   private:
	// 逆ポーランド記法に直すために整えるメソッド
	void enable_polish_notation(std::string normal_notation_formula);
	// 逆ポーランド記法の計算用スタック
	std::stack<std::string> calcurating_stack;
};