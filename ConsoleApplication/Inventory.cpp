#include "Inventory.h"

Inventory::Inventory()
{
	items = std::make_unique<itemsMap>();
}

void Inventory::Display() const
{
	for (const auto& element : *items)
	{
		element.second->Display();
	}
}