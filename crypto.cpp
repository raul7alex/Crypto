#include"stdafx.h"
#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#include"math.h"
#include"fstream"

using namespace std;


#define BITS 255 //dimensiunea secventei de biti
#define MAX 100  //cel mai mare nr care poate fi generat
#define NR 1 //de cate nr avem nevoie

int a[BITS];

long int random()
{
	srand(time(0));
	int i, x, y, tmp,ind;

	for (i = 0; i<BITS; i++)
		a[i] = rand() % 2;

	x = rand() % BITS;
	y = rand() % x;
	ind = 0;
	for (i = y; i <= x + y / 2; i++)
	{
		tmp = a[i];
		a[i] = a[x + y / 2 + ind];
		a[x + y / 2 + ind] = tmp;
		++ind;
	}


	int decimalNumber = 0;
	i = BITS;
	while (i != 0)
	{

		decimalNumber += a[i] * pow(2, i);
		--i;
	}

	if (decimalNumber<0)decimalNumber = -decimalNumber;

	return decimalNumber;
}

int main()
{
	fstream f("test.out",ios::app);

	int i; long int x;
	for (i = 0; i<NR; i++)
	{
		x = random();
	//	printf("%ld\n", x%MAX);
	//	printf(" ");
		f << x%MAX;
		f << endl;
	}
	f.close();

	return 0;
}
