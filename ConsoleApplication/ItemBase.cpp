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
	std::wcout << L"No["<<itemNo<< L"] Equip["<<std::setw(8)<<(*this)<< L"] OP["<<offensePower<< L"] DP["<<defensePower<< L"]"<<std::endl;
}

std::wostream& operator<<(std::wostream& os, ItemBase const& dt)
{
	switch (dt.GetEquipPos())
	{
	case EquipPos::Weapon: { os << L"Weapon"; }break;
	case EquipPos::Head: { os << L"Head"; }break;
	case EquipPos::Chest: { os << L"Chest"; }break;
	case EquipPos::Shoes: { os << L"Shoes"; }break;
	case EquipPos::Ring: { os << L"Ring"; }break;
	default: { os << L"Unknown"; }break;
	}
	return os;
}