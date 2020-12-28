#pragma once
#include "DisplayableObject.h"

class ItemBase : public DisplayableObject
{
public:

	enum class EquipPos
	{
		None = 0,
		Weapon = 1,
		Head = 2,
		Armor = 3,
		Shoes = 4,
		Ring = 5,
		Neck = 6,
		Max,
	};

	enum class Grade
	{
		None = 0,
		Common, 
		Uncommon,
		Rare,
		Unique,
		Max,
	};
	
	ItemBase() = delete;
	ItemBase(EquipPos pos, int item_no, int offense, int defense)
	{
		equipPos = pos;
		itemNo = item_no;
		offensePower = offense;
		defensePower = defense;
	}
	~ItemBase();

	void Display() const override;

	EquipPos GetEquipPos() const { return equipPos; }

private:
	EquipPos equipPos;
	int itemNo;
	int offensePower;
	int defensePower;
};

template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
	return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

