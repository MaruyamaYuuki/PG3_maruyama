#include "MilkChoco.h"
#include <stdio.h>

MilkChoco::MilkChoco()
{
	name = "Milk Chocolate";
}

MilkChoco::~MilkChoco()
{
}

void MilkChoco::DrawName()
{
	printf("%s\n", name);
}
