
#include <stdio.h>

int 
gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}


int main()
{
	int array[30*30][30*30];
	int i,j;
	for (i = 0; i < 30*30; i++)
	{
		for (j = i; j < 30*30; j++)
		{
			array[i][j] = gcd(i,j);
			array[j][i] = array[i][j];
		}
	}
	printf("int gcd[30*30][30*30] = {\n");
	for (i = 0; i < 30*30; i++)
	{
		printf("    {");
		for (j = 0; j < 30*30; j++)
		{
			printf("%d,",array[i][j]);
		}
		printf("    },\n");
	}
	printf("};");
	return 0;
}
