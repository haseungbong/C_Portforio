#pragma once
#include <iostream>
#include <map>
#include <list>
#include "ItemBase.h"

class Inventory : public DisplayableObject
{
private:
	using itemsMap = std::map<int, std::shared_ptr<ItemBase>>;
	std::unique_ptr<itemsMap> items;
	using weaponsList = std::list<std::weak_ptr<ItemBase>>;
	std::unique_ptr<weaponsList>  weapons;

public:
	Inventory();
	void Display() const override;
};

