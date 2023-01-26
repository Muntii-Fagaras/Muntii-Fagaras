#include "Text.hpp"

Text::Text()
{
	text.push_back("");
	textFile = TextFile();
}

list<string> *Text::ref() { return &text; }

void Text::getPos(int &line, int &pos)
{
	line = this->line;
	pos	 = this->pos;
}

void Text::insertStr(string str)
{
		while (!str.empty()) {
			insertChar(str.front());
			str.erase(0, 1);
		}
}

void Text::insertChar(char c)
{
	list<string>::iterator it = next(text.begin(), line - 1);

		if (c == '\n') {
			makeNewLine();
		}

	it->insert(pos - 1, string{c});
	pos++;
}

void Text::makeNewLine()
{
	list<string>::iterator it	   = next(text.begin(), line - 1);
	string				  *newLine = new string(it->substr(pos - 1));
	it->erase(pos - 1);
	text.insert(next(it, 1), *newLine);
	line++;
	pos = 1;
}

void Text::deleteChar()
{
		if (line == 1 && pos == 1) {
			return;
		}

	list<string>::iterator it = next(text.begin(), line - 1);

		if (pos == 1) {
			*next(it, -1) += it->substr();
			line--;
			pos = (int)next(it, -1)->length() + 1;
			deleteLine(it);
			return;
		}

	pos--;
	it->erase(pos - 1, 1);
}

void Text::deleteLine(int line)
{
	list<string>::iterator it = next(text.begin(), line - 1);
	text.erase(it);
}

void Text::deleteLine(list<string>::iterator it) { text.erase(it); }

void Text::deleteLinesFT(int from, int to)
{
	list<string>::iterator it = next(text.begin(), from - 1);
	text.erase(it, next(it, to - from));
}

void Text::moveCursor(int right, int down)
{
		switch (right) {
			case -1:
					if (pos > 1) {
						pos--;
					}
					else if (line > 1) {
						line--;
						list<string>::iterator it =
							next(text.begin(), line - 1);
						pos = (int)it->length() + 1;
					}
				break;
				case +1: {
					list<string>::iterator it = next(text.begin(), line - 1);
						if (pos <= it->length()) {
							pos++;
						}
						else if (next(it, 1) != text.end()) {
							line++;
							pos = 1;
						}
				} break;
		}

		switch (down) {
			case -1:
					if (line > 1) {
						line--;
						list<string>::iterator it =
							next(text.begin(), line - 1);
							if (pos > it->length()) {
								pos = (int)it->length() + 1;
							}
					}
				break;
			case +1:
					if (line < text.size()) {
						line++;
						list<string>::iterator it =
							next(text.begin(), line - 1);
							if (pos > it->length()) {
								pos = (int)it->length() + 1;
							}
					}
				break;
		}
}

void Text::save() { textFile.overwriteText(text); }