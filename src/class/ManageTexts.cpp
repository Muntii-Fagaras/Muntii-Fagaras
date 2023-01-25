#include "ManageTexts.hpp"

ManageTexts::ManageTexts(list<Task *> *tasks) : tasks(tasks)
{
	Text *text = new Text();
	texts.push_back(text);
	PresentText *newTask = new PresentText(text);
	tasks->push_back(newTask);
}

void ManageTexts::runTask()
{
	TaskManageTexts *task = dynamic_cast<TaskManageTexts *> (tasks->front());
	// ‚±‚±‚ğ‰ğÁ‚·‚é‚æ‚¤‚ÉƒvƒƒOƒ‰ƒ€‚ğ•ÏX

	switch (task->kind) {
		case TASK_KIND_ManageTexts::INSERT_STR: {
			texts.at(0)->insertStr(((InsertStr *)task)->str);
			PresentText *newTask = new PresentText(texts.at(0));
			tasks->push_back(newTask);
			}
			break;
		case TASK_KIND_ManageTexts::DELETE_STR:
			break;
		case TASK_KIND_ManageTexts::INSERT_CHAR:
			texts.at(0)->insertChar(((InsertChar *)task)->c);
			break;
		case TASK_KIND_ManageTexts::DELETE_CHAR: {
			texts.at(0)->deleteChar();
			PresentText *newTask = new PresentText(texts.at(0));
			tasks->push_back(newTask);
			}
			break;
		case TASK_KIND_ManageTexts::MAKE_NEW_LINE: {
			texts.at(0)->makeNewLine();
			PresentText *newTask = new PresentText(texts.at(0));
			tasks->push_back(newTask);
			}
			break;
		case TASK_KIND_ManageTexts::MOVE_CURSOR: {
			int			 right	 = ((MoveCursor *)task)->right;
			int			 down	 = ((MoveCursor *)task)->down;
			texts.at(0)->moveCursor(right, down);
			PresentText *newTask = new PresentText(texts.at(0));
			tasks->push_back(newTask);
			}
			break;
	}
}