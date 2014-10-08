
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
	int array[626][626];
	int i,j;
	for (i = 0; i <= 625; i++)
	{
		for (j = i; j <= 625; j++)
		{
			array[i][j] = gcd(i,j);
			array[j][i] = array[i][j];
		}
	}
	printf("int gcd[626][626] = {\n");
	for (i = 0; i < 626; i++)
	{
		printf("    {");
		for (j = 0; j < 626; j++)
		{
			printf("%d,",array[i][j]);
		}
		printf("    },\n");
	}
	printf("};");
	return 0;
}
