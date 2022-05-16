#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int stogpok1 = 0; 
int stogpok2 = 0;
int A1[50];
int A2[50];
int X1 = 0;
int X2 = 0;

int rekurzivno(int n, int m){
    if (m > n){
        return 0;
    }
    if (m == 0 || m == n){
        return 1;
    }
 
    return rekurzivno(n - 1, m - 1) + rekurzivno(n - 1, m);
}


void stog(int n, int m)
{
	pushSTOG1(n);
	pushSTOG2(m);
	int POVRH = 0;
	while (stogpok1 != 0)
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
	if (stogpok1 == 50)
	{
		printf("STOG PUN!");
	}
	else
	{
		stogpok1 += 1;
		A1[stogpok1] = k;
	}
}

void pushSTOG2(int k)
{
	if (stogpok2 == 50)
	{
		printf("STOG PUN!");
	}
	else
	{
		stogpok2 += 1;
		A2[stogpok2] = k;
	}
}

int popSTOG1()
{
	if (stogpok1 == 0)
	{
		printf("Illegal POP. Aborting!");
		return 0;
	}
	else
	{
		X1 = A1[stogpok1];
		stogpok1 -= 1;
		return X1;
	}
}

int popSTOG2()
{
	if (stogpok2== 0)
	{
		printf("Illegal POP. Aborting!");
		return 0;
	}
	else
	{
		X2 = A2[stogpok2];
		stogpok2 -= 1;
		return X2;
	}

}
int main()
{
	int t1 = 0;
	int t2 = 0; 
	int t3 = 0;
	int t4 = 0;
	t1 = clock();
	printf("Preko rekurzivne funkcije: %d\n\n", rekurzivno(32,16));
	t2 = clock();
	t3 = clock();
	stog(32, 16);
	t4 = clock();
	printf("Rekurzija u micro-sekundama: %d\n ", t2 - t1);
	printf("Stog u micro-sekundama: %d\n", t4 - t3);
	return 0;
}