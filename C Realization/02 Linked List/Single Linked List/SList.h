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

//打印链表
void SListPrint(SLT* plist);

//链表后插
void SListPushBack(SLT* plist, SLTDataType x);

//链表尾删
void SListPopBack(SLT* plist);

//链表头插
void SListPushFront(SLT* plist, SLTDataType x);

//链表头删
void SListPopFront(SLT* plist);

//给定位置pos插入元素
void SListInsert(SLT* plist, size_t pos, SLTDataType x);

//给定位置pos删除元素
void SListErase(SLT* plist, size_t pos);

//清空链表
void SListClear(SLT* plist);