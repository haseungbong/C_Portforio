#include <iostream>
#include <ppl.h>
#include "Unit.h"
#include "ItemFactory.h"

int main()
{
    std::wcout << "unit inventory sample code !\n";

	auto unit = std::make_unique<Unit>();

	for (size_t i = 0; i < 10; ++i)
	{		
		unit->AddItem(ItemFactory::GetInstance().Create());
	}
	
	Concurrency::parallel_for(0, 50, [&](int n)// start(0), end(50), index(n)
		{
			unit->AddItem(ItemFactory::GetInstance().Create());
		});
	
	unit->Display();
	unit->AutoEquip();
}