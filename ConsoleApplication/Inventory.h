#pragma once
#include <iostream>
#include <map>
#include <list>
#include "DisplayableObject.h"

class ItemBase;
class Inventory : public DisplayableObject
{
private:
	using itemsMap = std::map<int, std::shared_ptr<ItemBase>>;
	std::unique_ptr<itemsMap> items;
	using weaponsList = std::list<std::weak_ptr<ItemBase>>;
	std::unique_ptr<weaponsList>  weapons;

public:
	Inventory();
	void AddItem(const std::shared_ptr<ItemBase>& item) const;
	void Display() const override;
};

