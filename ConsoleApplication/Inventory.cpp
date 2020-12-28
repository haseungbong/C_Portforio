#include "Inventory.h"
#include "ItemBase.h"

Inventory::Inventory()
{
	items = std::make_unique<itemsMap>();
}

void Inventory::AddItem(const std::shared_ptr<ItemBase>& item) const
{
	items->insert(std::make_pair(item->GetItemNo(), item));
}


void Inventory::Display() const
{
	for (const auto& element : *items)
	{
		element.second->Display();
	}
}