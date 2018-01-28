#ifndef _AVL_H_
#define _AVL_H_

#include <stdbool.h>

typedef struct val
{
	int date;
	struct val * left;
	struct val * right;
	int height;
}Val;

Val * Val_Creat();
bool Val_Is_Empty(Val * pval);
int Val_Height(Val * pval);
Val * Val_Add(Val * pval, int pdate);
Val * Val_Min(Val * pval);
Val * Val_Max(Val * pval);
Val * Val_Find(Val * pval, int pdate);

#endif