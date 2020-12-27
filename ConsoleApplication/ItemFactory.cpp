#include <random>
#include "ItemFactory.h"

ItemFactory::ItemFactory()
{
	itemFactories = std::make_shared<factoryMap>();
	itemFactories->insert(std::make_pair(ItemBase::EquipPos::Weapon, std::make_shared<ItemWeaponFactory>()));
}

std::shared_ptr<ItemBase> ItemFactory::Create()
{	
	auto arg = ItemCreateArg(GetRandomEquipPos(), ++seq);
	factoryMap::const_iterator it = itemFactories->find(arg.GetEqupPos());
	if (itemFactories->end() != it)
	{
		return it->second->Create(arg);
	}
	return std::make_shared<ItemBase>(GetRandomEquipPos(), seq, 0, 0);
}

ItemBase::EquipPos ItemFactory::GetRandomEquipPos()
{
	static std::random_device randomDevice;
	static std::mt19937 rnd(randomDevice());
	static std::uniform_int_distribution<int> dist(static_cast<int>(ItemBase::EquipPos::Weapon), static_cast<int>(ItemBase::EquipPos::Max) - 1);
	return static_cast<ItemBase::EquipPos>(dist(rnd));
}

std::shared_ptr<ItemBase> ItemWeaponFactory::Create(ItemCreateArg& arg)
{
	return std::make_shared<ItemBase>(arg.GetEqupPos(), arg.GetUniqId(), 100, 0);
}