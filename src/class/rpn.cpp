#include "rpn.hpp"

std::string reverse_polish_notation::create_reverse_polish_notation(
	std::string normal_notation_formula)
{
	// �t�|�[�����h�L�@�Œ������߂Ɏ��𐮂���
	enable_polish_notation(normal_notation_formula);
}

// �t�|�[�����h�L�@�ɒ������߂̉������Ƃ���vector�ɂ��ꂼ����i�[����
void reverse_polish_notation::enable_polish_notation(
	std::string normal_notation_formula)
{
	int num = 0;
	int multiplier = 1;
		for (int i = 0; i < normal_notation_formula.size(); i++) {
				switch (normal_notation_formula.at(i) ){
					case '+':
						reverse_polish_notation_formula.push_back(
							std::to_string(num));
						reverse_polish_notation_formula.push_back(
							std::to_string(normal_notation_formula.at(i)));
						multiplier = 1;
					default:
						num =(normal_notation_formula.at(i)-48) * multiplier+num;
						multiplier *= 10;
						break;
				}
		}
}