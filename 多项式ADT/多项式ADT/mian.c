#include <stdio.h>
#include <stdlib.h>

typedef struct                          //多项式ADT的数组实现的类型声明
{
	int CoeffArray[11];
	int HighPower;
}* Polynomial;

void ZeroPolynomial(Polynomial Poly);			//将多项式初始化为零的过程
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum);		//两个多项式相加的过程
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd);			//两个多项式相乘的过程


void ZeroPolynomial(Polynomial Poly)
{
	for (int i = 0; i <= 10l; i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
	ZeroPolynomial(PolySum);
	PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);

	for (int i = PolySum->HighPower; i >= 0; i--)
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
	ZeroPolynomial(PolyProd);
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

	if (PolyProd->HighPower > 10)
		exit(EXIT_FAILURE);
	else
		for (int i = 0; i <= Poly1->HighPower; i++)
			for (int j = 0; j <= Poly1->HighPower; j++)
				PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
}