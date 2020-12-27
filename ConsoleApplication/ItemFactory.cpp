#include <random>
#include "ItemFactory.h"

std::shared_ptr<ItemBase> ItemFactory::Create()
{
	++seq;
	return std::make_shared<ItemBase>(GetRandomEquipPos(), seq, 0, 0);
}

ItemBase::EquipPos ItemFactory::GetRandomEquipPos()
{
	static std::random_device randomDevice;
	static std::mt19937 rnd(randomDevice());
	static std::uniform_int_distribution<int> dist(static_cast<int>(ItemBase::EquipPos::Weapon), static_cast<int>(ItemBase::EquipPos::Max) - 1);
	return static_cast<ItemBase::EquipPos>(dist(rnd));
}