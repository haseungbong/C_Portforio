#pragma once
#include <iostream>
#include <atomic>
#include <unordered_map>
#include "ItemBase.h"
#include "Singleton.h"

struct ItemCreateArg
{
private:
	const ItemBase::EquipPos pos;
	const int uniqId;
public:
	ItemCreateArg(ItemBase::EquipPos pos, int seq)
		: pos(pos), uniqId(seq)
	{
	}

	ItemBase::EquipPos GetEqupPos() { return pos; }
	int GetUniqId() { return uniqId; }
};

class IItemFactory
{
public:
	virtual std::shared_ptr<ItemBase> Create(ItemCreateArg& arg) = 0;
};

class ItemWeaponFactory : public IItemFactory
{
public:
	std::shared_ptr<ItemBase> Create(ItemCreateArg& arg) override;
};

class ItemArmorFactory : public IItemFactory
{
public:
	std::shared_ptr<ItemBase> Create(ItemCreateArg& arg) override;
};

class ItemOtherFactory : public IItemFactory
{
public:
	std::shared_ptr<ItemBase> Create(ItemCreateArg& arg) override;
};

class ItemFactory final : public Singleton<ItemFactory>
{
private:
	std::atomic_int seq;

	ItemBase::EquipPos GetRandomEquipPos();
	using factoryMap = std::unordered_map<ItemBase::EquipPos, std::shared_ptr<IItemFactory>>;
	std::shared_ptr<factoryMap> itemFactories;
	ItemOtherFactory otherFactory;

public:
	ItemFactory();
	~ItemFactory();
	std::shared_ptr<ItemBase> Create();
};


