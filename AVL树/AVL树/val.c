#include <stdio.h>
#include <stdlib.h>
#include "val.h"

Val * Left_Left(Val * pval);
Val * Right_Right(Val * pval);
Val * Left_Right(Val * pval);
Val * Right_Left(Val * pval);
int Max(int a, int b);

bool Val_Is_Empty(Val * pval)
{
	if (pval == NULL)
		return true;
	else
		return false;
}

int Val_Height(Val * pval)
{
	if (pval == NULL)
		return -1;
	else
		return pval->height;
}

Val * Val_Add(Val * pval, int pdate)
{
	if (pval == NULL)
	{
		pval = (Val *)malloc(sizeof(Val));
		if (pval == NULL)
		{
			fprintf(stderr, "can't creat node");
			exit(EXIT_FAILURE);
		}
		else
		{
			pval->date = pdate;
			pval->height = 0;
			pval->right = NULL;
			pval->left = NULL;
		}
	}
	else if (pdate<(pval->date))
	{
		pval->left = Val_Add(pval->left, pdate);
		if (Val_Height(pval->left) - Val_Height(pval->right) == 2)
			if (pdate < pval->left->date)
				pval = Left_Left(pval);
			else
				pval = Left_Right(pval);
	}
	else if (pdate>pval->date)
	{
		pval->right = Val_Add(pval->right, pdate);
		if (Val_Height(pval->right) - Val_Height(pval->left) == 2)
			if (pdate > pval->right->date)
				pval = Right_Right(pval);
			else
				pval = Right_Left(pval);
	}

	pval->height = Max(Val_Height(pval->left), Val_Height(pval->right)) + 1;
	return pval;
}

Val * Val_Min(Val * pval)
{
	if (pval == NULL)
		return pval;
	else
		while (pval->left != NULL)
			pval = pval->left;
	return pval;
}

Val * Val_Max(Val * pval)
{
	if (pval == NULL)
		return pval;
	else
		while (pval->right != NULL)
			pval = pval->right;
	return pval;
}

Val * Val_Find(Val * pval, int pdate)
{
	if (pval == NULL)
		return pval;
	else
	{
		while (pval != NULL)
		{
			if (pdate > pval->date)
				pval = pval->right;
			else if (pdate < pval->date)
				pval = pval->left;
			else
				return pval;
		}
		return pval;
	}
}

Val * Left_Left(Val * pval)
{
	Val * new_val;
	new_val = pval->left;
	pval->left = new_val->right;
	new_val->right = pval;

	pval->height = Max(Val_Height(pval->left), Val_Height(pval->right)) + 1;
	new_val->height = Max(Val_Height(new_val->left), pval->height) + 1;

	return new_val;
}

Val * Right_Right(Val * pval)
{
	Val * new_val;
	new_val = pval->right;
	pval->right = new_val->left;
	new_val->left = pval;

	pval->height = Max(Val_Height(pval->left), Val_Height(pval->right)) + 1;
	new_val->height = Max(Val_Height(new_val->right), pval->height) + 1;

	return new_val;
}

Val * Left_Right(Val * pval)
{
	pval->left = Right_Right(pval->left);

	return Left_Left(pval);
}

Val * Right_Left(Val * pval)
{
	pval->right = Left_Left(pval->right);

	return Right_Right(pval);
}

int Max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}