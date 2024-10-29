#include "BitterChoco.h"
#include <stdio.h>

BitterChoco::BitterChoco()
{
	name = "Bitter Coholate";
}

BitterChoco::~BitterChoco()
{
}

void BitterChoco::DrawName()
{
	printf("%s\n", name);
}
