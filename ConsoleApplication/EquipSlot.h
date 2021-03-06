#pragma once
#include "ItemBase.h"
#include "DisplayableObject.h"

template <EquipPos T_Pos, typename T_Comp>
class EquipSlot : public DisplayableObject
{
public:
	EquipSlot() = delete;
	void Display() const override;
};