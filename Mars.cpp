#include <stdio.h>
#include <stdlib.h>
#include <Mars.h>

char SBox(unsigned char temp)
{
	char Result;
	return Result;
}

void EFunction(char in, char key1, char key2, unsigned char* M, unsigned char* R, char& L)
{
	char r = ' ';
	int n;
	*M = in + key1;
	*R = (in << 13)*(key2);
	unsigned char i;
	for (n = 0; n < 9; n++)
	{
		i += M[i];
	}
	L = SBox(i);
	*R = *R << 5;
	for (n = 0; n < 5; n++)
	{
		r += R[i];
	}
	*M = *M << r;
	L = L xor *R;
	*R = *R << 5;
	L = L xor *R;
	r = ' ';
	for ( n = 0; n < 5; n++)
	{
		r += R[n];
	}
	L = L << r;
}

void MarsEncrypt(unsigned long* D0, unsigned long* D1, unsigned long* D2, unsigned long* D3, char* K[10])
{
	D0 = D0 + *K[0];
	D1 = D1 + *K[1];
	D2 = D2 + *K[2];
	D3 = D3 + *K[3];

	for (int i = 0; i < 8; i++)
	{
		*D1 = *D1 xor (char)(D0[0]);
		*D1 = *D1 + (char)(D0[1]);
		*D2 = *D2 + (char)(D0[2]);
		*D3 = *D3 xor (char)(D0[3]);
		*D0 = *D0 >> 0x18;
		if (i == 0 || i == 4)
		{
			D0 = D0 + *D3;
		}
		if (i == 1 || i == 5)
		{
			D0 = D0 + *D1;
		}

	}
}
