#pragma once

#ifdef __GNUC__
	#include "../stdafx.h"
#endif
class reverse_polish_notation {
   public:
	// �t�|�[�����h�L�@�֎������߂̎�
	std::vector<std::string> reverse_polish_notation_formula;
	std::string create_reverse_polish_notation(
		std::string normal_notation_formula);

   private:
	// �t�|�[�����h�L�@�ɒ������߂ɐ����郁�\�b�h
	void enable_polish_notation(std::string normal_notation_formula);

};