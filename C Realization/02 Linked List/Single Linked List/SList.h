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


//��ӡ����
void SListPrint(SLTNode* phead);

//������
void SListPushBack(SLTNode** pphead, SLTDataType x);

//����βɾ
void SListPopBack(SLTNode** pphead);

//����ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);

//����ͷɾ
void SListPopFront(SLTNode** pphead);

//����Ԫ�ز���
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//����λ��pos����Ԫ��
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//����λ��posɾ��Ԫ��
void SListErase(SLTNode** pphead, SLTNode* pos);

//�������
void SListDistroy(SLTNode** pphead);