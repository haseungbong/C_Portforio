#pragma once
#include <iostream>
#include <unordered_map>
#include <list>
#include "DisplayableObject.h"

class ItemBase;
class Inventory : public DisplayableObject
{
private:
	using itemsMap = std::unordered_map<int, std::shared_ptr<ItemBase>>;
	std::unique_ptr<itemsMap> items;
	using weaponsList = std::list<std::weak_ptr<ItemBase>>;
	std::unique_ptr<weaponsList> weapons;

public:
	//�κ��� ���ֿ� ����. ������ ����� �ƴ�
	Inventory(const Inventory&) = delete;
	Inventory& operator=(const Inventory&) = delete;
	Inventory(Inventory&&) = delete;
	Inventory& operator=(Inventory&&) = delete;
	
	Inventory();
	~Inventory() = default;
	void AddItem(const std::shared_ptr<ItemBase>& item) const;
	void Display() const override;
};

