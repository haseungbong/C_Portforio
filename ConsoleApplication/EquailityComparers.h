#pragma once
#include "ItemBase.h"

class IComparer
{
public:
	virtual bool Compare(ItemBase const& lhs, ItemBase const& rhs) const = 0;
};

class WeaponEquailityComparer : public IComparer
{
public:
	bool Compare(ItemBase const& lhs, ItemBase const& rhs) const
	{
		return lhs.GetOffensePower() < rhs.GetOffensePower();
	}
};

class ArmorEquailityComparer : public IComparer
{
public:
	bool Compare(ItemBase const& lhs, ItemBase const& rhs) const
	{
		return lhs.GetDefensePower() < rhs.GetDefensePower();
	}
};

class OtherEquailityComparer : public IComparer
{
public:
	bool Compare(ItemBase const& lhs, ItemBase const& rhs) const
	{
		return lhs.GetDefensePower() + lhs.GetOffensePower() <
			rhs.GetDefensePower() + rhs.GetOffensePower();
	}
};
