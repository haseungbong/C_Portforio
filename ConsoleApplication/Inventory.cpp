#include <algorithm>
#include <mutex>
#include "Inventory.h"
#include "EquailityComparers.h"

Inventory::Inventory()
{
	items = std::make_unique<itemsMap>();

	comparers.insert(std::make_pair(EquipPos::Weapon, std::make_unique<WeaponEquailityComparer>()));
}

void Inventory::AddItem(std::shared_ptr<ItemBase> const& item)
{
	std::lock_guard<std::mutex> lock(invenMutex);
	
	items->insert(std::make_pair(item->GetItemNo(), item));
	
	switch (item->GetEquipPos())
	{
	case EquipPos::Weapon:
	{
		weapons.push_back(item);
	}break;
	default: {}break;
	}
}

void Inventory::Display() const
{
	for (auto const& element : *items)
	{
		element.second->Display();
	}
}

std::shared_ptr<ItemBase const> Inventory::GetBestItem(EquipPos const pos) const
{
	auto comparer = comparers.find(pos);
	if (comparers.end() != comparer)
	{
		auto ret = std::max_element(weapons.begin(), weapons.end(),
			[&comparer](auto const& lhs, auto const& rhs)
	{
			return comparer->second->Compare(*lhs.lock(), *rhs.lock());
			});
		return ret->lock();
	}

	return nullptr;
}

