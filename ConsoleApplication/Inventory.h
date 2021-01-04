#pragma once
#include <iostream>
#include <unordered_map>
#include <list>
#include <mutex>
#include "concurrent_unordered_map.h"
#include "ItemBase.h"
#include "DisplayableObject.h"

class IComparer;
class Inventory : public DisplayableObject
{
public:
	Inventory();
	~Inventory() = default;
	void AddItem(std::shared_ptr<ItemBase> const& item);
	void Display() const override;
	std::shared_ptr<ItemBase const> GetBestItem(EquipPos const pos) const;

	//인벤은 유닛에 종속. 복사의 대상이 아님
	Inventory(Inventory const&) = delete;
	Inventory& operator=(Inventory const&) = delete;
	Inventory(Inventory&&) = delete;
	Inventory& operator=(Inventory&&) = delete;

private:

	using itemsMap = Concurrency::concurrent_unordered_map<int, std::shared_ptr<ItemBase>>;
	using WeaponsList = std::list<std::weak_ptr<ItemBase const >>;

	std::unique_ptr<itemsMap> items;
	WeaponsList weapons;
	std::unordered_map<EquipPos, std::unique_ptr<IComparer>> comparers;

	std::mutex invenMutex;
};
