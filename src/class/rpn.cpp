#include "rpn.hpp"

void reverse_polish_notation::create_reverse_polish_notation(
	std::string normal_notation_formula)
{
	// 逆ポーランド記法で直すために式を整える
	enable_polish_notation(normal_notation_formula);
	// 番兵
	calcurating_stack.push("end");
	// スタックに積まれている一番上の値
	std::string stack_top;
	// 式の最後まで繰り返す
		for (int i = 0; i < reverse_polish_notation_formula.size(); i++) {
			// 式の因子が数字の時にはスタックに積む
				if (reverse_polish_notation_formula.at(i) != "*" &&
					reverse_polish_notation_formula.at(i) != "-" &&
					reverse_polish_notation_formula.at(i) != "+" &&
					reverse_polish_notation_formula.at(i) != "/") {
					calcurating_stack.push(
						reverse_polish_notation_formula.at(i));
				}
				// 式の因子が演算子の時
				else {
					// 演算子で*と/の時
						if (reverse_polish_notation_formula.at(i) == "*" ||
							reverse_polish_notation_formula.at(i) == "/") {
							// 因子の優先順位よりスタックの一番上の優先順位が高いとき
								while (1) {
									stack_top = calcurating_stack.top();
										if (stack_top == "end") {
											break;
										}
										else if (stack_top == "-" ||
												 stack_top == "+") {
											break;
										}
										else {
											calcurating_stack.pop();
											fixed_reverse_polish_notation_formula
												.push_back(stack_top);
										}
								}
								// 演算子を積む
								if (reverse_polish_notation_formula.at(i) ==
									"*") {
									calcurating_stack.push("*");
								}
								else {
									calcurating_stack.push("/");
								}
						}
						else if (reverse_polish_notation_formula.at(i) == "+" ||
								 reverse_polish_notation_formula.at(i) == "-") {
								while (1) {
									stack_top = calcurating_stack.top();
										if (stack_top == "end") {
											break;
										}
										else {
											calcurating_stack.pop();
											fixed_reverse_polish_notation_formula
												.push_back(stack_top);
										}
								}
								if (reverse_polish_notation_formula.at(i) ==
									"+") {
									calcurating_stack.push("+");
								}
								else {
									calcurating_stack.push("-");
								}
						}
						else {
							calcurating_stack.push(
								reverse_polish_notation_formula.at(i));
						}
				}
		}
	// 式の最後になったとき式のスタックからすべて取り出す
	// 式の因子の変数
	std::string s;
		while (1) {
			s = calcurating_stack.top();
			calcurating_stack.pop();
				if (s == "end") {
					break;
				}
			fixed_reverse_polish_notation_formula.push_back(s);
		}
}

int reverse_polish_notation::calc(std::string notation)
{
	int ans = 0;
	reverse_polish_notation::create_reverse_polish_notation(notation);
	std::stack<std::string> calcurating_stack_rpn;
	calcurating_stack_rpn.push("bottom");
	std::string left, right;
		for (int i = 0; i < fixed_reverse_polish_notation_formula.size(); i++) {
				if (fixed_reverse_polish_notation_formula.at(i) != "+" &&
					fixed_reverse_polish_notation_formula.at(i) != "-" &&
					fixed_reverse_polish_notation_formula.at(i) != "*" &&
					fixed_reverse_polish_notation_formula.at(i) != "/") {
					calcurating_stack_rpn.push(
						fixed_reverse_polish_notation_formula.at(i));
				}
				else {
						if (fixed_reverse_polish_notation_formula.at(i) ==
							"+") {
							left = calcurating_stack_rpn.top();
							calcurating_stack_rpn.pop();
							right = calcurating_stack_rpn.top();
								if (right == "bottom") {
									right = "0";
								}
								else {
									calcurating_stack_rpn.pop();
								}
							ans = std::stoi(left) + std::stoi(right) + ans;
						}
						else if (fixed_reverse_polish_notation_formula.at(i) ==
								 "-") {
							left = calcurating_stack_rpn.top();
							calcurating_stack_rpn.pop();
							right = calcurating_stack_rpn.top();
								if (right == "bottom") {
									right = "0";
								}
								else {
									calcurating_stack_rpn.pop();
								}
							ans = std::stoi(right) - std::stoi(left) + ans;
						}
						else if (fixed_reverse_polish_notation_formula.at(i) ==
								 "*") {
							left = calcurating_stack_rpn.top();
							calcurating_stack_rpn.pop();
							right = calcurating_stack_rpn.top();
								if (right == "bottom") {
									right = "0";
								}
								else {
									calcurating_stack_rpn.pop();
								}
							ans = std::stoi(right) * std::stoi(left) + ans;
						}
						else if (fixed_reverse_polish_notation_formula.at(i) ==
								 "/") {
							left = calcurating_stack_rpn.top();
							calcurating_stack_rpn.pop();
							right = calcurating_stack_rpn.top();
								if (right == "bottom") {
									right = "0";
								}
								else {
									calcurating_stack_rpn.pop();
								}
							ans = std::stoi(right) / std::stoi(left) + ans;
						}
				}
		}
	return ans;
}

// 逆ポーランド記法に直すための下準備としてvectorにそれぞれを格納する
void reverse_polish_notation::enable_polish_notation(
	std::string normal_notation_formula)
{
	// ポーランド記法での数字
	int num = 0;
	// 10や100といった式で表すために倍数として計算している
	int multiplier = 1;
	// ポーランド記法に直すための下準備式の最後まで
		for (int i = 0; i < normal_notation_formula.size(); i++) {
			// 演算子が現れた時
				switch (normal_notation_formula.at(i)) {
					case '+':
					case '-':
					case '*':
					case '/':
						// 前のループで計算してできた数字をvectorに追加する
						reverse_polish_notation_formula.push_back(
							std::to_string(num));
						// それぞれの演算子で追加する
							switch (normal_notation_formula.at(i)) {
								case '+':
									reverse_polish_notation_formula.push_back(
										"+");
									break;
								case '-':
									reverse_polish_notation_formula.push_back(
										"-");
									break;
								case '*':
									reverse_polish_notation_formula.push_back(
										"*");
									break;
								case '/':
									reverse_polish_notation_formula.push_back(
										"/");
									break;
								default:
									break;
							}
						multiplier = 1;
						num		   = 0;
						break;
					default:
						// 式の因子が数字の時、ループごとに倍数にして足して一つの場所へ格納する
						num = num * multiplier +
							  (normal_notation_formula.at(i) - 48);
						multiplier *= 10;
						break;
				}
		}
	reverse_polish_notation_formula.push_back(std::to_string(num));
}