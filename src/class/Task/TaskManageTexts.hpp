#pragma once
#ifdef __GNUC__
	#include "../../stdafx.h"
#endif
#include "Task.hpp"

struct TaskManageTexts : Task
{
	TASK_KIND_ManageTexts kind;
	TaskManageTexts() { receiver = RECEIVER::MANAGE_TEXTS; }
};

struct InsertStr : TaskManageTexts
{
	string str;
	InsertStr(string str) : str(str)
	{
		kind = TASK_KIND_ManageTexts::INSERT_STR;
	}
};

struct DeleteStr : TaskManageTexts
{
	DeleteStr() { kind = TASK_KIND_ManageTexts::DELETE_STR; }
};

struct InsertChar : TaskManageTexts
{
	char c;
	InsertChar(char c) : c(c) { kind = TASK_KIND_ManageTexts::INSERT_CHAR; }
};

struct DeleteChar : TaskManageTexts
{
	DeleteChar() { kind = TASK_KIND_ManageTexts::DELETE_CHAR; }
};

struct MakeNewLine : TaskManageTexts
{
	MakeNewLine() { kind = TASK_KIND_ManageTexts::MAKE_NEW_LINE; }
};

struct MoveCursor : TaskManageTexts
{
	int right, down;
	MoveCursor(int right, int down) : right(right), down(down)
	{
		kind = TASK_KIND_ManageTexts::MOVE_CURSOR;
	}
};

struct Save : TaskManageTexts
{
	Save() { kind = TASK_KIND_ManageTexts::SAVE; }
};