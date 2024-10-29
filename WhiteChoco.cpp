#include "WhiteChoco.h"
#include <stdio.h>

WhiteChoco::WhiteChoco()
{
	name = "White Chocolate";
}

WhiteChoco::~WhiteChoco()
{
}

void WhiteChoco::DrawName()
{
	printf("%s\n", name);
}
