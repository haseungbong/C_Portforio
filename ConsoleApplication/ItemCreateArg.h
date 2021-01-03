#pragma once
#include "ItemBase.h"

struct ItemCreateArg
{
public:
	ItemCreateArg(EquipPos pos = EquipPos::None, int seq = 0);

	EquipPos GetEquipPos() const { return pos; }
	int GetUniqId() const { return uniqId; }

private:
	EquipPos const pos;
	int const uniqId;
};
