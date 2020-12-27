#include <iostream>
#include "ItemBase.h"

void ItemBase::Display()
{
	std::cout << "No["<<itemNo<<"] OP["<<offensePower<<" DP["<<defensePower<<"]";
}
