#include <iostream>
#include "Unit.h"
#include "ItemFactory.h"

int main()
{
    std::cout << "Hello World!\n";

	auto unit = std::make_unique<Unit>();

	for (size_t i = 0; i < 10; ++i)
	{
		auto newItem = ItemFactory::GetInstance().Create();
		newItem->Display();
	}
}