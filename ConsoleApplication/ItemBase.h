#pragma once
#include <iostream>
#include "DisplayableObject.h"

enum class EquipPos
{
	None = 0,
	Weapon = 1,
	Head = 2,
	Chest = 3,
	Shoes = 4,
	Ring = 5,
	Max,
	First = Weapon,
};

enum class Grade
{
	None = 0,
	Common,
	Uncommon,
	Rare,
	Unique,
	Max,
};

class ItemBase : public DisplayableObject
{
public:
	ItemBase() = delete;
	ItemBase(EquipPos pos, int item_no, int offense, int defense);
	~ItemBase() = default;

	void Display() const override;

	EquipPos GetEquipPos() const { return equipPos; }
	int GetItemNo() const { return itemNo; }
	int GetOffensePower() const { return offensePower; }
	int GetDefensePower() const { return defensePower; }

private:
	friend std::ostream& operator<<(std::ostream& os, ItemBase const& dt);

	EquipPos equipPos;
	int itemNo;
	int offensePower;
	int defensePower;
};
/*
template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
	return stream << static_cast<typename std::underlying_type<T>::type>(e);
}*/

