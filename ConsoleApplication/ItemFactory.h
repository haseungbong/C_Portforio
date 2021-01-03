#pragma once
#include <iostream>
#include <atomic>
#include <unordered_map>
#include "ItemBase.h"
#include "Singleton.h"

struct ItemCreateArg;

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
	using factoryMap = std::unordered_map<EquipPos, std::shared_ptr<IItemFactory>>;
	
public:
	ItemFactory();
	~ItemFactory();
	std::shared_ptr<ItemBase> Create();
	
private:
	EquipPos GetRandomEquipPos();

	std::atomic_int seq;
	std::shared_ptr<factoryMap> itemFactories;
	ItemOtherFactory otherFactory;
};