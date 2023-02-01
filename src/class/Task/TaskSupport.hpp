#pragma once
#ifdef __GNUC__
	#include "../../stdafx.h"
#endif
#include "Task.hpp"

struct TaskSupport : Task
{
	RECEIVER		  receiver = RECEIVER::SUPPORT;
	TASK_KIND_Support kind;
};