#include <iostream>
#include <utility>
#include "Unit.h"
#include "Inventory.h"
#include "ItemBase.h"

Unit::Unit()
{
	inventory = std::make_unique<Inventory>();
	//std::make_integer_sequence<std::size_t, ItemBase::EquipPos
	auto a = std::make_index_sequence<static_cast<typename std::underlying_type_t<ItemBase::EquipPos>>(ItemBase::EquipPos::Max)>();
	
}

void Unit::AddItem(const std::shared_ptr<ItemBase>& item) const
{
	inventory->AddItem(item);
}

void Unit::Display() const
{
	inventory->Display();
}

void Unit::AutoEquip() const
{
	auto bestWeapon = inventory->GetBestItem(ItemBase::EquipPos::Weapon);
	std::cout << "BestWeapon : ";
	if (bestWeapon != nullptr)
	{		
		bestWeapon->Display();
	}
}
