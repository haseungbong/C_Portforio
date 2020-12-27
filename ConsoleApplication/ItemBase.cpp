#include <iostream>
#include "ItemBase.h"

void ItemBase::Display()
{
	std::cout << "No["<<itemNo<<"] Equip["<< GetEquipPos()<<"] OP["<<offensePower<<"] DP["<<defensePower<<"]"<<std::endl;
}

ItemBase::~ItemBase()
{
	std::cout << itemNo << " 소멸자" << std::endl;
}
