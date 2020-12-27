#pragma once
#include <iostream>
#include <atomic>
#include "ItemBase.h"
#include "Singleton.h"

class IItemFactory
{
public:
	virtual ItemBase::EquipPos GetEquipPos() = 0;
	virtual int GetOffensePower() = 0;
	virtual int GetDefensePower() = 0;
};

class ItemWeaponFactory : public IItemFactory
{
public:
	ItemBase::EquipPos GetEquipPos() override;
	int GetOffensePower() override;
	int GetDefensePower() override;
};

class ItemFactory final : public Singleton<ItemFactory>
{
private:
	std::atomic_int seq;

	ItemBase::EquipPos GetRandomEquipPos();
public:
	ItemFactory() = default;
	std::shared_ptr<ItemBase> Create();
};

