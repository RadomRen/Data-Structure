#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

//��ӡ����
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuyListNode(SLTDataType x)
{
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//����β��
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newNode = BuyListNode(x);
	SLTNode* tail = *pphead;
	if (tail == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		while(tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

//����βɾ
void SListPopBack(SLTNode** pphead)
{
	assert(*pphead != NULL);
	SLTNode* tail = *pphead;
	if (tail->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		while(tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

//����ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newNode = BuyListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

//����ͷɾ
void SListPopFront(SLTNode** pphead)
{
	assert(*pphead != NULL);
	SLTNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

//����Ԫ�ز���
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	} 
	return NULL;
}

//����λ��pos����Ԫ��
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(*pphead && pos);
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	newNode->data = x;
	newNode->next = pos;
	SLTNode* cur = *pphead;
	if (cur != pos)
	{
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
	else
	{
		*pphead = newNode;
	}

}

//����λ��posɾ��Ԫ��
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(*pphead && pos);
	SLTNode* cur = *pphead;
	if (cur != pos)
	{
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
	}
	else
	{
		*pphead = pos->next;
	}

	free(pos);
	pos = NULL;
}

//�������
void SListDistroy(SLTNode** pphead)
{
	if (*pphead == NULL)
		return;
	SLTNode* cur = *pphead;
	SLTNode* tmp = cur;
	while(cur != NULL)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*pphead = NULL;
	
}