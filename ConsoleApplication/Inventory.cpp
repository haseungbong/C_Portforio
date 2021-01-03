#include <algorithm>
#include "Inventory.h"
#include "EquailityComparers.h"

Inventory::Inventory()
{
	items = std::make_unique<itemsMap>();
	
	comparers.insert(std::make_pair(ItemBase::EquipPos::Weapon, std::make_unique<WeaponEquailityComparer>()));
}

void Inventory::AddItem(const std::shared_ptr<ItemBase> item)
{
	items->insert(std::make_pair(item->GetItemNo(), item));
	switch (item->GetEquipPos())
	{
	case ItemBase::EquipPos::Weapon:
	{
		weapons.push_back(item);
	}break;
	default:
		break;
	}
}

void Inventory::Display() const
{
	for (const auto& element : *items)
	{
		element.second->Display();
	}
}

std::shared_ptr<const ItemBase> Inventory::GetBestItem(const ItemBase::EquipPos pos) const
{
	auto comparer = comparers.find(pos);
	if (comparer != comparers.end())
	{
		auto ret = std::max_element(weapons.begin(), weapons.end(), [&comparer](const auto& lhs, const auto& rhs) {
			return comparer->second->Compare(*lhs.lock(), *rhs.lock());
			});
		return ret->lock();
	}

	return nullptr;
}

