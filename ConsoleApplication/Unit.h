#pragma once
#include <iostream>
#include "DisplayableObject.h"

class Inventory;
class ItemBase;

class Unit : DisplayableObject
{
public:
	Unit();
	Unit(std::unique_ptr<Inventory>);
	virtual ~Unit() = default;

	void AddItem(const std::shared_ptr<ItemBase>& item) const;
	void AutoEquip() const;

	void Display() const override;

private:
	std::unique_ptr<Inventory> inventory; // Inventory dependency 하락을 위함
};