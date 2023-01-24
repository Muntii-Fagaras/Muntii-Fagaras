#include "ManageTexts.hpp"

ManageTexts::ManageTexts(list<Task> &tasks) : tasks(tasks)
{
	texts.push_back(Text());
	tasks.push_back(PresentText(texts[0]));
}

void ManageTexts::runTask()
{
	TaskManageTexts &task = (TaskManageTexts &)tasks.front();

	texts[0].insertStr(((InsertStr &)task).str);
	tasks.push_back(PresentText(texts[0]));

	switch (task.kind) {
		case TASK_KIND_ManageTexts::INSERT_STR:
			texts[0].insertStr(((InsertStr &)task).str);
			tasks.push_back(PresentText(texts[0]));
			break;
		case TASK_KIND_ManageTexts::DELETE_STR:
			break;
		case TASK_KIND_ManageTexts::INSERT_CHAR:
			texts[0].insertChar(((InsertChar &)task).c);
			break;
		case TASK_KIND_ManageTexts::DELETE_CHAR:
			texts[0].deleteChar();
			break;
	}
}