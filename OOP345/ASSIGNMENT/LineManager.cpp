// Milestone 3 - Assembly Line
// LineManager.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-12-02

#include "LineManager.h"
#include "Utilities.h"

LineManager::LineManager(std::string& fileName, std::vector<Task*>& tasks, std::vector<CustomerOrder>& orders) {
	bool more = true;
	size_t old_token_index;
	Utilities utilities;
	std::ifstream file(fileName);
	std::string record;
	if (file) {
		for (size_t pos = 0, count = 0; !file.eof(); more = true, pos = 0u, count = 0u) {
			std::getline(file, record);
			std::string old_token = utilities.extractToken(record, pos, more);
			std::string next_token = (more) ? utilities.extractToken(record, pos, more) : "";
			for (size_t i = 0; i < tasks.size(); i++) {
				if (tasks[i]->getName() == old_token)
					old_token_index = i;
			}
			if (!next_token.empty()) {
				for (size_t i = 0; i < tasks.size(); i++) {
					if (tasks[i]->getName() == next_token)
						tasks[old_token_index]->setNextTask(*tasks[i]);
				}
			}
			else
				tasks[old_token_index]->setNextTask(*AssemblyLine[0]);
			AssemblyLine.push_back(tasks[old_token_index]);
		}
		for (size_t i = 0; i < orders.size(); i++) {
			ToBeFilled.push_back(std::move(orders[i]));
		}
	}
}

bool LineManager::Run(std::ostream& os) {
	size_t ToBeFilled_size = ToBeFilled.size();
	for (size_t i = 0; i < ToBeFilled_size; i++) {
		*AssemblyLine[0] += std::move(ToBeFilled[i]);
		Completed.emplace_back();
	}
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->RunProcess(os);
		if (i == AssemblyLine.size() - 1) {
			for (size_t j = 0; j < ToBeFilled_size; j++)
				AssemblyLine[0]->getCompleted(Completed[j]);
		}
	}
	if (Completed.size() == ToBeFilled_size) {
		os << std::endl << "COMPLETED" << std::endl;
		for (size_t i = 0; i < Completed.size(); i++)
			Completed[i].Display(os);
		return true;
	}
	return false;
}
