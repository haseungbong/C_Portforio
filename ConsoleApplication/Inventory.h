#pragma once
#include <iostream>
#include <unordered_map>
#include <list>
#include "ItemBase.h"
#include "DisplayableObject.h"

class IComparer;
class Inventory : public DisplayableObject
{
private:
	using itemsMap = std::unordered_map<int, std::shared_ptr<ItemBase>>;
	std::unique_ptr<itemsMap> items;
	using WeaponsList = std::list<std::weak_ptr<const ItemBase>>;
	WeaponsList weapons;

	std::unordered_map<ItemBase::EquipPos, std::unique_ptr<IComparer>> comparers;

public:
	//인벤은 유닛에 종속. 복사의 대상이 아님
	Inventory(const Inventory&) = delete;
	Inventory& operator=(const Inventory&) = delete;
	Inventory(Inventory&&) = delete;
	Inventory& operator=(Inventory&&) = delete;
	
	Inventory();
	~Inventory() = default;
	void AddItem(const std::shared_ptr<ItemBase> item);
	void Display() const override;
	std::shared_ptr<const ItemBase> GetBestItem(const ItemBase::EquipPos pos) const;
};

