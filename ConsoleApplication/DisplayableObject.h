#pragma once
class DisplayableObject
{
public:
	virtual ~DisplayableObject() = default;
	virtual void Display() const = 0;
};

