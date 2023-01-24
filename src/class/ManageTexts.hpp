#pragma once
#ifdef __GNUC__
	#include "../stdafx.h"
#endif
#include <vector>
#include "Text.hpp"
#include "Task/TaskMainScreen.hpp"
#include "Task/TaskManageTexts.hpp"

class ManageTexts {
   private:
	std::vector<Text> texts;
	list<Task> &tasks;

   public:
	ManageTexts(list<Task> &tasks);
	void runTask();
};