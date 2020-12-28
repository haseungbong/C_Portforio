#include "Unit.h"
#include "Inventory.h"
#include "ItemBase.h"

Unit::Unit()
{
	inventory = std::make_unique<Inventory>();
}

void Unit::AddItem(const std::shared_ptr<ItemBase>& item) const
{
	inventory->AddItem(item);
}

void Unit::Display() const
{
	inventory->Display();
}
