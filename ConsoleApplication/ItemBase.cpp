#include <iostream>
#include <iomanip>
#include "ItemBase.h"

void ItemBase::Display() const
{
	std::cout << "No["<<itemNo<<"] Equip["<<std::setw(8)<<*this<<"] OP["<<offensePower<<"] DP["<<defensePower<<"]"<<std::endl;
}

