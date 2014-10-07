#include "square.h"

#include <cstdio>

square::square(int size)
{
	this->size = size;
	this->array = new int[size*size];

	this->randomize();
}

square::~square()
{
	delete this->array;
	this->array = 0;
}

void square::randomize()
{
	for (int i = 0; i < this->size * this->size; i++)
	{
		this->array[i] = i+1;
	}
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
	printf("  %d\n",this->score());
	return;
}

int diff(int a, int b)
{
	if (a < b) return b - a;
	else return a - b;
}

int getDistance(int i,int j,int size)
{
	int x = diff(i/size,j/size);
	int y = diff(i%size,j%size);
	return i*i + j*j;
}

extern int gcd[256][256];
int GCD ( int a, int b )
{
//  int c;
//  while ( a != 0 ) {
//     c = a; a = b%a;  b = c;
//  }
  return gcd[a][b];
}


int square::score()
{
	int gcd = 0;
	int distance = 0;
	int score = 0;
	for (int i = 0; i < (this->size * this->size); i++)
	{
		for (int j = i + 1; j < (this->size * this->size); j++)
		{
			distance = getDistance(i,j,this->size);
			gcd = GCD(this->array[i],this->array[j]);
			score += gcd * distance;
		}
	}
	return score;
}
