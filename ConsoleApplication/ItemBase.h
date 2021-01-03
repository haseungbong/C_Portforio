#pragma once
#include <iostream>
#include "DisplayableObject.h"

class ItemBase : public DisplayableObject
{
public:

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

	ItemBase() = delete;
	ItemBase(const EquipPos pos, int item_no, int offense, int defense)
	{
		equipPos = pos;
		itemNo = item_no;
		offensePower = offense;
		defensePower = defense;
	}
	~ItemBase() = default;

	void Display() const override;

	EquipPos GetEquipPos() const { return equipPos; }
	int GetItemNo() const { return itemNo; }
	int GetOffensePower() const { return offensePower; }
	int GetDefensePower() const { return defensePower; }
private:
	friend std::ostream& operator<<(std::ostream& os, const ItemBase& dt)
	{
		switch (dt.GetEquipPos())
		{
		case EquipPos::Weapon:
		{
			os << "Weapon";
		}break;
		case EquipPos::Head:
		{
			os << "Head";
		}break;
		case EquipPos::Chest:
		{
			os << "Chest";
		}break;
		case EquipPos::Shoes:
		{
			os << "Shoes";
		}break;
		case EquipPos::Ring:
		{
			os << "Ring";
		}break;
		default:
			os << "Unkown";
			break;
		}
		return os;
	}

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

