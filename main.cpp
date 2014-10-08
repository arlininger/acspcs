
#include "square.h"
#include <ctime>
#include <cstdlib>

int main(int argc, char* arvg[])
{
	srand(time(NULL));
	square min(3);
	square max(3);
	square x(3);
	for (int i = 0; i < 10000; i++)
	{
		x.randomize();
		if (x < min) min = x;
		if (x > max) max = x;
	}
	min.print();
	max.print();
	return 0;
}
