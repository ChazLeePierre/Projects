// Milestone 3 - Assembly Line
// Task.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-12-02

#include "Task.h"

Task::Task(std::string &record) : Item::Item(record), pNextTask{ nullptr } {}

void Task::RunProcess(std::ostream &os) {
	for (size_t count = 0, orderSize = Orders.size(); !Orders.empty() && count != orderSize; count++) {
		while (!(Orders.back().getItemFillState(this->getName()))) {
			Orders.back().fillItem(*this, os);
		}
		if (this->pNextTask != nullptr) {
			*this->pNextTask += std::move(Orders.back());
			Orders.pop_back();
		}
	}
}

bool Task::MoveTask() {
	if (!Orders.empty()) {
		if (Orders.back().getOrderFillState()) {
			pNextTask->Orders.push_back(std::move(Orders.back()));
			Orders.pop_back();
		}
	} else
		return false;
	return true;
}

void Task::setNextTask(Task &task) {
	this->pNextTask = &task;	
}

bool Task::getCompleted(CustomerOrder &src) {
	if (!Orders.empty()) {
		src = std::move(Orders.back());
		Orders.pop_back();
		return true;
	} 
	return false;
}

void Task::Validate(std::ostream &os) {
	os << this->getName() << std::endl;
	if (pNextTask) os << pNextTask->getName() << std::endl;
}

Task& Task::operator+=(CustomerOrder &&newOrder) {
	Orders.push_front(std::move(newOrder));
	return *this;
}
