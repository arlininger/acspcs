#include "square.h"

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cassert>

using namespace std;


square::square(const square& rhs)
{
	if (this != &rhs)
	{
		this->size = rhs.size;
		this->array = new int[rhs.size*rhs.size];
		memcpy(this->array,rhs.array,(rhs.size*rhs.size)*4);
	}
	for (int i = 0; i < (rhs.size*rhs.size); i++)
	{
		assert(rhs.array[i]);
	}
	for (int i = 0; i < (this->size*this->size); i++)
	{
		assert(this->array[i]);
	}
}

square::square(const int size, bool randomize)
{
	this->size = size;
	this->array = new int[size*size];

	if (randomize)
	{
		this->randomize();
	}
	for (int i = 0; i < (this->size*this->size); i++)
	{
		assert(this->array[i]);
	}
}

square::~square()
{
	delete[] this->array;
	this->array = 0;
}

void square::randomize()
{
	for (int i = 0; i < (this->size * this->size); i++)
	{
		this->array[i] = i+1;
	}
	for (int i = 0; i < (this->size*this->size); i++)
	{
		swap(this->array[i],this->array[rand()%(this->size*this->size)]);
	}
	for (int i = 0; i < (this->size*this->size); i++)
	{
		assert(this->array[i]);
	}
//	random_shuffle(this->array,this->array+(size*size));
}

void square::print() const
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
	printf(";");
//	printf(" %d;",this->score());
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
	return x*x + y*y;
}

extern int gcd[30*30][30*30];
int GCD (const int a, const int b )
{
//  int c;
//  while ( a != 0 ) {
//     c = a; a = b%a;  b = c;
//  }
  return gcd[a][b];
}


int square::score() const
{
	int gcd = 0;
	int distance = 0;
	int score = 0;
	for (int i = 0; i < (this->size * this->size); i++)
	{
		assert(this->array[i]);
		for (int j = i + 1; j < (this->size * this->size); j++)
		{
			distance = getDistance(i,j,this->size);
			gcd = GCD(this->array[i],this->array[j]);
			score += gcd * distance;
			//printf("%d  %d  %d  %d\n",this->array[i],this->array[j],gcd,distance);
		}
	}
	return score;
}

square& square::operator= (const square &lhs)
{
	if (this->array) delete[] this->array;
	this->array = new int[lhs.size*lhs.size];

	memcpy(this->array,lhs.array,(lhs.size*lhs.size)*4);
	this->size = lhs.size;
	for (int i = 0; i < (this->size*this->size); i++)
	{
		assert(this->array[i]);
	}
	return *this;
}


bool square::operator> (const square &lhs)
{
	return this->score() > lhs.score();
}

bool square::operator< (const square &lhs)
{
	return this->score() < lhs.score();
}

void square::increment()
{
	std::next_permutation(this->array,(this->array)+(this->size*this->size));
	return;
}

