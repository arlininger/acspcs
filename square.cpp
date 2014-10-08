#include "square.h"

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;


square::square(const square& rhs)
{
	if (this != &rhs)
	{
		this->size = rhs.size;
		this->array = new int[rhs.size*rhs.size];
		memcpy(this->array,rhs.array,rhs.size*rhs.size);
	}
}

square::square(int size)
{
	this->size = size;
	this->array = new int[size*size];

	this->randomize();
}

square::~square()
{
	delete[] this->array;
	this->array = 0;
}

void square::randomize()
{
	for (int i = 0; i < this->size * this->size; i++)
	{
		this->array[i] = i+1;
	}
	for (int i = 0; i < (size*size); i++)
	{
		swap(this->array[i],this->array[rand()%(size*size)]);
	}
//	random_shuffle(this->array,this->array+(size*size));
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

int getDistance(const int i, const int j,const int size)
{
	int x = diff(i/size,j/size);
	int y = diff(i%size,j%size);
	return i*i + j*j;
}

extern int gcd[256][256];
int GCD (const int a, const int b )
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

square& square::operator= (square &lhs)
{
	if (this->array) delete[] this->array;
	this->array = new int[lhs.size*lhs.size];

	for (int i = 0; i < lhs.size*lhs.size; i++)
	{
		this->array[i] = lhs.array[i];
	}
	this->size = lhs.size;
	return *this;
}


bool square::operator> (square &lhs)
{
	return this->score() > lhs.score();
}

bool square::operator< (square &lhs)
{
	return this->score() < lhs.score();
}



