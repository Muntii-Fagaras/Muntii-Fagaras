#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include <list>
#include <string>
#include <tuple>
#include "TextFile.hpp"

using std::list;
using std::next;
using std::string;
using std::tuple;

class Text {
   private:
	string		 name;
	list<string> text;
	TextFile	 textFile;

   public:
	Text();
	list<string> *ref();
	int			  line = 1, pos = 1;
	void		  getPos(int &line, int &pos);
	void		  insertStr(string str);
	void		  insertChar(char c);
	void		  makeNewLine();
	void		  deleteChar();
	void		  deleteLine(int line);
	void		  deleteLine(list<string>::iterator it);
	void		  deleteLinesFT(int from, int to);
	void		  moveCursor(int right, int upper);

	void save();
};