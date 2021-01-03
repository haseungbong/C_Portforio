#pragma once

class DisplayableObject
{
public:
	DisplayableObject() = default;
	virtual ~DisplayableObject() = default;

	virtual void Display() const = 0;
};

