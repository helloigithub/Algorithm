/* list.h -- 简单链表类型的头文件 */
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>	/* C99特性 */

/* 一般类型定义 */

typedef struct node
{
	int Num;
	struct node* Next;
}Node;

typedef struct node* List;

/* 函数原型 */

/*  初始化链表 */
void InitializeList(List * plist);

/* 检查链表是否为空 */
bool ListIsEmpty(const List * plist);

/* 确定链表是否已满 */
bool ListIsFull(const List * plist);

/* 确定链表中的项数 */
unsigned int ListCount(const List * plist);

/* 确定是否到结尾 */
bool ListIsLast(const List * plist, Node * pnode);

/* 添加项 */
bool AddList(List * plist, int item);

/* 删除项 */
void DelList(List * plist, int item);

/* 查找项 */
Node * FindList(List *plist, int item);

/* 查找前一项 */
Node * FindPrevious(List * plist, int item);

/* 插入项 */
bool InsertList(List * plist, int item, int position);

#endif