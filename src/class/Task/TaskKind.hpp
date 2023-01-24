#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif

enum class RECEIVER
{
	MAIN_SCREEN,
	MANAGE_TEXTS,
	SUPPORT
};

enum class TASK_KIND_MainScreen
{
	PRESENT_TEXT
};

enum class TASK_KIND_ManageTexts
{
	INSERT_STR,
	DELETE_STR,
	INSERT_CHAR,
	DELETE_CHAR
};

enum class TASK_KIND_Support
{
};