#pragma once
#include "DisplayableObject.h"

class ItemBase : public DisplayableObject
{
public:

	enum class EquipPos
	{
		None = 0,
		Weapon = 1,
		Head = 2,
		Armor = 3,
		Shoes = 4,
		Ring = 5,
		Neck = 6,
	};
	
	ItemBase() = delete;
	ItemBase(EquipPos pos, int item_no, int offense, int defense)
	{
		equipPos = pos;
		itemNo = item_no;
		offensePower = offense;
		defensePower = defense;
	}

	void Display() override;
private:
	EquipPos equipPos;
	int itemNo;
	int offensePower;
	int defensePower;
};

