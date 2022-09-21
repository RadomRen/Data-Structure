#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

//打印链表
void SListPrint(SLT* plist)
{
	SLTNode* cur = plist->phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//链表后插
void SListPushBack(SLT* plist, SLTDataType x)
{
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	newNode->data = x;
	newNode->next = NULL;
	SLTNode* phead = plist->phead;
	if (phead == NULL)
	{
		plist->phead = newNode;
	}
	else
	{
		SLTNode* cur = phead;
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
	plist->sz++;
}

//链表尾删
void SListPopBack(SLT* plist)
{
	assert(plist->phead != NULL);
	SLTNode* cur = plist->phead;
	if (cur->next == NULL)
	{
		free(plist->phead);
		plist->phead = NULL;
	}
	else
	{

		SLTNode* tmp = cur->next;
		while(tmp->next != NULL)
		{
			cur = cur->next;
			tmp = cur->next;
		}
		free(tmp);
		cur->next = NULL;
	}
	plist->sz--;
}

//链表头插
void SListPushFront(SLT* plist, SLTDataType x)
{
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	newNode->data = x;
	newNode->next = plist->phead;
	plist->phead = newNode;
	plist->sz++;
}

//链表头删
void SListPopFront(SLT* plist)
{
	assert(plist->phead != NULL);
	SLTNode* tmp = (plist->phead)->next;
	free(plist->phead);
	plist->phead = tmp;
	plist->sz--;
}

//给定位置pos插入元素
void SListInsert(SLT* plist, size_t pos, SLTDataType x)
{
	assert((plist->phead == NULL && pos == 0) || plist->phead != NULL);
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	newNode->data = x;
	//链表为空的情况
	if (plist->phead == NULL)
	{
		newNode->next = NULL;
		plist->phead = newNode;
		return;
	}
	//链表不为空的情况
	SLTNode* cur = plist->phead;
	////统计元素个数
	//int sz = 0;
	////while ((cur = cur->next) != NULL)
	////	sz++;
	//for (; cur->next != NULL; sz++, cur = cur->next);
	//sz++;
	assert(plist->sz >= pos);
	cur = plist->phead;
	SLTNode* tmp = cur;
	int i = 0;
	for (i = 0; i < pos; i++)
	{
		tmp = cur;
		cur = cur->next;
	}
	newNode->next = cur;
	if (pos == 0)
		plist->phead = newNode;
	else
		tmp->next = newNode;
}

//给定位置pos删除元素
void SListErase(SLT* plist, size_t pos)
{
	assert(plist->phead != NULL);

	SLTNode* cur = plist->phead;
	////统计元素个数
	//int sz = 0;
	//for (; cur->next != NULL; sz++, cur = cur->next);
	//sz++;

	assert(plist->sz > pos);

	cur = plist->phead;
	SLTNode* tmp = cur;
	int i = 0;
	for (i = 0; i < pos; i++)
	{
		tmp = cur;
		cur = cur->next;
	}
	SLTNode* next = cur->next;
	if (pos == 0)
	{
		free(plist->phead);
		plist->phead = next;
	}
	else
	{
		free(tmp->next);
		tmp->next = next;
	}
}

//清空链表
void SListClear(SLT* plist)
{
	if (plist->phead == NULL)
		return;
	SLTNode* cur = plist->phead;
	SLTNode* tmp = cur;
	while(cur != NULL)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	plist->phead = NULL;
	plist->sz = 0;
	
}