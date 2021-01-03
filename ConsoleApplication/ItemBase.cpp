#include <iostream>
#include <iomanip>
#include "ItemBase.h"

ItemBase::ItemBase(EquipPos pos, int item_no, int offense, int defense)
{
	equipPos = pos;
	itemNo = item_no;
	offensePower = offense;
	defensePower = defense;
}

void ItemBase::Display() const
{
	std::cout << "No["<<itemNo<<"] Equip["<<std::setw(8)<<*this<<"] OP["<<offensePower<<"] DP["<<defensePower<<"]"<<std::endl;
}

std::ostream& operator<<(std::ostream& os, ItemBase const& dt)
{
	switch (dt.GetEquipPos())
	{
	case EquipPos::Weapon: { os << "Weapon"; }break;
	case EquipPos::Head: { os << "Head"; }break;
	case EquipPos::Chest: { os << "Chest"; }break;
	case EquipPos::Shoes: { os << "Shoes"; }break;
	case EquipPos::Ring: { os << "Ring"; }break;
	default: { os << "Unknown"; }break;
	}
	return os;
}
