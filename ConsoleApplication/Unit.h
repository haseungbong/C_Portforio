#pragma once
#include <iostream>
#include "DisplayableObject.h"

class Inventory;
class ItemBase;
class Unit : public DisplayableObject
{
private:
	std::unique_ptr<Inventory> inventory;
public:
	Unit();
	virtual ~Unit() = default;
	void AddItem(const std::shared_ptr<ItemBase>& item) const;
	void AutoEquip() const;

	void Display() const override;
};