#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include "../Text.hpp"
#include "Task.hpp"

struct TaskMainScreen : Task
{
	TASK_KIND_MainScreen kind;
	TaskMainScreen() { receiver = RECEIVER::MAIN_SCREEN; }
};

struct PresentText : TaskMainScreen
{
	Text &text;

	PresentText(Text &text) : text(text)
	{
		kind = TASK_KIND_MainScreen::PRESENT_TEXT;
	};
};