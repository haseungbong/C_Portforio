#include <iostream>
#include "ItemBase.h"

void ItemBase::Display() const
{
	std::cout << "No["<<itemNo<<"] Equip["<< GetEquipPos()<<"] OP["<<offensePower<<"] DP["<<defensePower<<"]"<<std::endl;
}
