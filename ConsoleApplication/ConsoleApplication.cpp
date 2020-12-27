#include <iostream>
#include "Unit.h"
#include "ItemFactory.h"

int main()
{
    std::cout << "Hello World!\n";

	auto unit = std::make_unique<Unit>();

	auto newItem = ItemFactory::GetInstance().Create();
	newItem->Display();
	auto newItem1 = ItemFactory::GetInstance().Create();
	newItem1->Display();
}