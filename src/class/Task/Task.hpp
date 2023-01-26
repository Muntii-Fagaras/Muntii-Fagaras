#pragma once
#ifdef __GNUC__
	#include "../../stdafx.h"
#endif
#include "TaskKind.hpp"

struct Task
{
	RECEIVER receiver;
	virtual ~Task() {}
};