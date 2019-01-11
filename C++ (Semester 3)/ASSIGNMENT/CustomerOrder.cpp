// Milestone 1 - Assembly Line
// CustomerOrder.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-11-18

#include "CustomerOrder.h"
#include "Utilities.h"
#include "Item.h"

CustomerOrder::CustomerOrder() : Name(""), Product(""), ItemCount(0u), ItemList(nullptr), field_width(0u) {}

CustomerOrder::CustomerOrder(std::string & record) {
	Utilities utilities;
	bool more = true;
	for (size_t count = 0u, current_pos = 0u, no_of_items = 0u; more; count++) {
		switch (count) {
		case 0:
			Name = utilities.extractToken(record, current_pos, more);
			break;
		case 1:
			Product = utilities.extractToken(record, current_pos, more);
			break;
		case 2:
			for (size_t item_position = current_pos; more; no_of_items++)
				utilities.extractToken(record, item_position, more);
			ItemCount = no_of_items;
			no_of_items = 0u;
			more = true;
			ItemList = new ItemInfo*[ItemCount];
			break;
		default:
			ItemList[no_of_items] = new ItemInfo(utilities.extractToken(record, current_pos, more));
			no_of_items++;
		}
	}
	if (utilities.getFieldWidth() > this->field_width)
		this->field_width = utilities.getFieldWidth();
}

CustomerOrder::~CustomerOrder() {
	delete[] ItemList;
	ItemList = nullptr;
	ItemCount = 0u;
}

CustomerOrder::CustomerOrder(CustomerOrder && CustOrder) {
	*this = std::move(CustOrder);
}

CustomerOrder & CustomerOrder::operator=(CustomerOrder &&CustOrder) {
	if (this != &CustOrder) {
		if (ItemList != nullptr) {
			delete[] ItemList;
			ItemList = nullptr;
			ItemCount = 0u;
		}
		Name = CustOrder.Name;
		Product = CustOrder.Product;
		ItemCount = CustOrder.ItemCount;
		ItemList = CustOrder.ItemList;
		field_width = CustOrder.field_width;
		CustOrder.Name = "";
		CustOrder.Product = "";
		CustOrder.ItemCount = 0u;
		CustOrder.ItemList = nullptr;
		CustOrder.field_width = 0u;
	}
	return *this;
}

bool CustomerOrder::getOrderFillState() {
	for (size_t i = 0u; i < ItemCount; i++) {
		if (!ItemList[i]->FillState) return false;
	}
	return true;
}


bool CustomerOrder::getItemFillState(std::string s) {
	bool ret = true;
	for (size_t i = 0u; i < ItemCount; i++) {
		if (ItemList[i]->ItemName == s) ret = ItemList[i]->FillState;
		if (ret == false) break;
	}
	return ret;
}

void CustomerOrder::fillItem(Item& item_, std::ostream& os) {
	for (size_t i = 0; i < ItemCount; i++) {
		if (ItemList[i]->ItemName == item_.getName() && !ItemList[i]->FillState) {
			ItemList[i]->FillState = true;
			ItemList[i]->SerialNumber = item_.getSerialNumber();
			os << (ItemList[i]->FillState ? "Filled" : "Unfilled") <<
				' ' << this->Name << ", " << this->Product << '[' << ItemList[i]->ItemName << ']' << std::endl;
		}
	}
}

void CustomerOrder::Display(std::ostream &os) {
	os << Name << std::endl;
	os << Product << std::endl;
	for (size_t i = 0u; i < ItemCount; i++) {
		os << '[' << ItemList[i]->SerialNumber << "] " << ItemList[i]->ItemName << " - "
			<< (ItemList[i]->FillState ? "FILLED" : "MISSING") << std::endl;
	}
}