#pragma once
#include <iostream>
#include <map>
#include "ItemBase.h"

class Inventory
{
private:
	using itemsMap = std::map<int, std::shared_ptr<ItemBase>>;
	std::unique_ptr<itemsMap> items;
};

