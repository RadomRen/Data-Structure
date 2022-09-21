#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SlistNode* next;
}SLTNode;

typedef struct SList
{
	SLTNode* phead;
	size_t sz;
}SLT;

//��ӡ����
void SListPrint(SLT* plist);

//������
void SListPushBack(SLT* plist, SLTDataType x);

//����βɾ
void SListPopBack(SLT* plist);

//����ͷ��
void SListPushFront(SLT* plist, SLTDataType x);

//����ͷɾ
void SListPopFront(SLT* plist);

//����λ��pos����Ԫ��
void SListInsert(SLT* plist, size_t pos, SLTDataType x);

//����λ��posɾ��Ԫ��
void SListErase(SLT* plist, size_t pos);

//�������
void SListClear(SLT* plist);