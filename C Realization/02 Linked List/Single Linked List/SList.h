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


//打印链表
void SListPrint(SLTNode* phead);

//链表后插
void SListPushBack(SLTNode** pphead, SLTDataType x);

//链表尾删
void SListPopBack(SLTNode** pphead);

//链表头插
void SListPushFront(SLTNode** pphead, SLTDataType x);

//链表头删
void SListPopFront(SLTNode** pphead);

//链表元素查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//给定位置pos插入元素
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//给定位置pos删除元素
void SListErase(SLTNode** pphead, SLTNode* pos);

//清空链表
void SListDistroy(SLTNode** pphead);