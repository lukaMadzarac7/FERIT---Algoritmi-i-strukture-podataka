#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 50

int StackPointer1 = 0 , StackPointer2 = 0;
int A1[N], A2[N];
int X1 = 0, X2 = 0;

int rekpovrh(int n, int m)

{
    if (m > n)
        return 0;
    if (m == 0 || m == n)
        return 1;
 
    // Recur
    return rekpovrh(n - 1, m - 1)
           + rekpovrh(n - 1, m);
}


void stogPOVRH(int n, int m)
{
	pushSTOG1(n);
	pushSTOG2(m);
	int POVRH = 0;
	while (StackPointer1 != 0)
	{
		n = popSTOG1();
		m = popSTOG2();
		if (n == m || m == 0)
		{
			POVRH += 1;
		}
		else
		{
			pushSTOG1(n - 1);
			pushSTOG2(m - 1);
			pushSTOG1(n - 1);
			pushSTOG2(m);
		}
	}
	printf("STOG: %d\n\n", POVRH);
}

void pushSTOG1(int k)
{
	if (StackPointer1 == N)
	{
		printf("STOG PUN!");
	}
	else
	{
		StackPointer1 += 1;
		A1[StackPointer1] = k;
	}
}

void pushSTOG2(int k)
{
	if (StackPointer2 == N)
	{
		printf("STOG PUN!");
	}
	else
	{
		StackPointer2 += 1;
		A2[StackPointer2] = k;
	}
}

int popSTOG1()
{
	if (StackPointer1 == 0)
	{
		printf("Illegal POP. Aborting!");
		return 0;
	}
	else
	{
		X1 = A1[StackPointer1];
		StackPointer1 -= 1;
		return X1;
	}
}

int popSTOG2()
{
	if (StackPointer2 == 0)
	{
		printf("Illegal POP. Aborting!");
		return 0;
	}
	else
	{
		X2 = A2[StackPointer2];
		StackPointer2 -= 1;
		return X2;
	}

}
int main()
{
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = clock();
	printf("Rekurzivno: %d\n\n", rekpovrh(12, 6));
	t2 = clock();
	t3 = clock();
	stogPOVRH(12, 6);
	t4 = clock();
	printf("Vrijeme trajanja rekurzije: %d[ms]\n Vrijeme trajanja Stoga: %d[ms]\n", t2 - t1, t4 - t3);
	return 0;
}