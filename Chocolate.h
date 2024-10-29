#pragma once

class Chocolate {
public:

	Chocolate();

	~Chocolate();

	virtual void DrawName();

protected:

	const char* name;
};