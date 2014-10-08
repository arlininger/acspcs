
#include "square.h"
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cassert>

int main(int argc, char* argv[])
{
	assert(argc == 2);
	int size = atoi(argv[1]);
	assert(size >= 3 && size <= 27);

	srand(time(NULL));

	//for (int size = 3; size < 27; size++)
	//{
		square x(size);
		square min(x);
		square max(x);
		for (int i = 0; i < 100000; i++)
		{
			x.randomize();
			if (x < min) min = x;
			if (x > max) max = x;
		}
		min.print();
		max.print();
	//}
	printf("\n\n");
	return 0;
}
