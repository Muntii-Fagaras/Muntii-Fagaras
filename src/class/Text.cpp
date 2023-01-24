#include "Text.hpp"

Text::Text()
{
	text.push_back("");
}

list<string> &Text::ref() { return text; }

void Text::getPos(int &line, int &pos)
{
	line = this->line;
	pos  = this->pos;
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
		string newLine = it->substr(pos);
		it->erase(pos);
		text.insert(next(it, 1), newLine);
		line++; pos = 1;
		return;
	}

	it->insert(pos, string{c});
	pos++;
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
		pos = (int) next(it, -1)->length() + 1;
		deleteLine(it);
		return;
	}

	it->erase(pos - 1, 1);
	pos--;
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