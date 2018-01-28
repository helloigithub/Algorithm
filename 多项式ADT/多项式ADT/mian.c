#include <stdio.h>
#include <stdlib.h>

typedef struct                          //����ʽADT������ʵ�ֵ���������
{
	int CoeffArray[11];
	int HighPower;
}* Polynomial;

void ZeroPolynomial(Polynomial Poly);			//������ʽ��ʼ��Ϊ��Ĺ���
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum);		//��������ʽ��ӵĹ���
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd);			//��������ʽ��˵Ĺ���


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