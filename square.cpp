#include "square.h"

#include <cstdio>

square::square(int size)
{
	this->size = size;
	this->array = new int[size*size];
}

square::~square()
{
	delete this->array;
	this->array = 0;
}

void square::print()
{
	for (int i = 0; i < this->size; i++)
	{
		if (i) printf(",");
		printf("(");
		for (int j = 0; j < this->size; j++)
		{
			if (j) printf(",");
			printf("%d",this->array[i*size+j]);
		}
		printf(")");
	}
	printf("\n");
	return;
}