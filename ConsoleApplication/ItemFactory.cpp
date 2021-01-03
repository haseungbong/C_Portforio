#include <random>
#include "ItemFactory.h"
#include "ItemCreateArg.h"

ItemFactory::ItemFactory()
{
	itemFactories = std::make_shared<factoryMap>();
	itemFactories->insert(std::make_pair(EquipPos::Weapon, std::make_shared<ItemWeaponFactory>()));

	auto armorFactory = std::make_shared<ItemArmorFactory>();
	itemFactories->insert(std::make_pair(EquipPos::Head, armorFactory));
	itemFactories->insert(std::make_pair(EquipPos::Chest, armorFactory));
	itemFactories->insert(std::make_pair(EquipPos::Shoes, armorFactory));
}

ItemFactory::~ItemFactory()
{
	itemFactories->clear();
}

std::shared_ptr<ItemBase> ItemFactory::Create()
{	
	auto arg = ItemCreateArg(GetRandomEquipPos(), ++seq);
	auto it = itemFactories->find(arg.GetEquipPos());
	if (itemFactories->end() != it)
	{
		return it->second->Create(arg);
	}
	
	return otherFactory.Create(arg);
}

EquipPos ItemFactory::GetRandomEquipPos()
{
	static std::random_device randomDevice;
	static std::mt19937 rnd(randomDevice());
	static std::uniform_int_distribution<int> dist(static_cast<int>(EquipPos::First), static_cast<int>(EquipPos::Max) - 1);
	
	return static_cast<EquipPos>(dist(rnd));
}

std::shared_ptr<ItemBase> ItemWeaponFactory::Create(ItemCreateArg& arg)
{
	static std::random_device randomDevice;
	static std::mt19937 rnd(randomDevice());
	static std::uniform_int_distribution<int> dist(100, 999);
	return std::make_shared<ItemBase>(arg.GetEquipPos(), arg.GetUniqId(), dist(rnd), 0);
}

std::shared_ptr<ItemBase> ItemArmorFactory::Create(ItemCreateArg& arg)
{
	return std::make_shared<ItemBase>(arg.GetEquipPos(), arg.GetUniqId(), 0, 100);
}

std::shared_ptr<ItemBase> ItemOtherFactory::Create(ItemCreateArg& arg)
{
	return std::make_shared<ItemBase>(arg.GetEquipPos(), arg.GetUniqId(), 0, 0);
}