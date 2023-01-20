#include "rpn.hpp"

void reverse_polish_notation::create_reverse_polish_notation(
	std::string normal_notation_formula)
{
	// �t�|�[�����h�L�@�Œ������߂Ɏ��𐮂���
	enable_polish_notation(normal_notation_formula);
	// �ԕ�
	calcurating_stack.push("end");
	std::string test;
	for (int i = 0; i < reverse_polish_notation_formula.size(); i++) {
			test=reverse_polish_notation_formula.at(i);
			if (test == "43") {
					fixed_reverse_polish_notation_formula.push_back(
						calcurating_stack.top());
				calcurating_stack.pop();
				calcurating_stack.push("+");
			}
			else {
				calcurating_stack.push(test);
			}
		}
	std::string s;
	while (1) {
		s=calcurating_stack.top();
			calcurating_stack.pop();
			if (s == "end") {
				break;
			}
			fixed_reverse_polish_notation_formula.push_back(s);
	}
}

// �t�|�[�����h�L�@�ɒ������߂̉������Ƃ���vector�ɂ��ꂼ����i�[����
void reverse_polish_notation::enable_polish_notation(
	std::string normal_notation_formula)
{
	int num = 0;
	int			multiplier = 1;
	std::string s;
		for (int i = 0; i < normal_notation_formula.size(); i++) {
				switch (normal_notation_formula.at(i) ){
					case '+':
					case '-':
					case '*':
					case '/':
						reverse_polish_notation_formula.push_back(
							std::to_string(num));
						s=std::to_string(normal_notation_formula.at(i));
						reverse_polish_notation_formula.push_back(s);
						multiplier = 1;
						num		   = 0;
						break;
					default:
						num =(normal_notation_formula.at(i)-48) * multiplier+num;
						multiplier *= 10;
						break;
				}
		}
	reverse_polish_notation_formula.push_back(std::to_string(num));
}