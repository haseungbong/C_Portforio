#pragma once
#include <iostream>
#include "ItemBase.h"

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

class ItemFactory
{
private:
	int seq = 0;
public:
	static std::shared_ptr<ItemBase> Create();
};

