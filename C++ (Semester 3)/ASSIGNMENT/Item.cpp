// Milestone 1 - Assembly Line
// Item.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-11-10

#include "Item.h"
#include "Utilities.h"

Item::Item(std::string & record) {
	Utilities utilities;
	for (size_t count = 0, current_pos = 0; count < 4; count++) {
		bool more = true;
		switch (count) {
		case 0:
			name = utilities.extractToken(record, current_pos, more);
			break;
		case 1:
			serialNumber = static_cast<unsigned>(std::stoi(utilities.extractToken(record, current_pos, more)));
			break;
		case 2:
			Quantity = static_cast<unsigned int>(std::stoi(utilities.extractToken(record, current_pos, more)));
			break;
		default:
			description = utilities.extractToken(record, current_pos, more);
		}
	}
	if (utilities.getFieldWidth() > this->field_width)
		this->field_width = utilities.getFieldWidth();
}

const std::string & Item::getName() const {
	return name;
}

const unsigned int Item::getSerialNumber() {
	return serialNumber++;
}

const unsigned int Item::getQuantity() {
	return Quantity;
}

void Item::updateQuantity() {
	if (Quantity > 0)
		Quantity -= 1;
}

void Item::display(std::ostream &os, bool full) const {
	os << std::setw(field_width + 1) << std::left << std::fixed << name << '[' << serialNumber << ']';
	if (full) os << " Quantity " << Quantity << "   Description: " << description;
	os << std::endl;
}
