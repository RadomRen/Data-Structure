#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 1000
#define ADD 3
typedef int SLDataType;

////静态顺序表
//typedef struct SeqList
//{
//	SLDataType arr[N];
//	int size;//表示数组中存储了多少个数据
//}SL;
//
//// 接口函数
//void SeqListInit(SL* ps);
//void SeqListPushBack(SL* ps, SLDataType x);
//void SeqListPopBack(SL* ps);
//void SeqListPushFront(SL* ps, SLDataType x);
//void SeqListPopFront(SL* ps);

//动态顺序表
typedef struct SeqList
{
	SLDataType *arr;
	int size;//表示数组中存储了多少个数据
	int capacity;//数组实际能存储的数据的空间容量时多大，单位是元素个数
}SL;

// 接口函数
//打印顺序表
void SeqListPrint(SL* ps);
//初始化顺序表
void SeqListInit(SL* ps);
//销毁顺序表
void SeqListDestroy(SL* ps);
//顺序表尾插
void SeqListPushBack(SL* ps, SLDataType x);
//顺序表尾删
void SeqListPopBack(SL* ps);
//顺序表头插
void SeqListPushFront(SL* ps, SLDataType x);
//顺序表头删
void SeqListPopFront(SL* ps);
//查找指定值，找到了返回下标，没找到，返回-1
int SeqListFind(SL* ps, SLDataType x);
//在指定位置插入一个元素
int SeqListInsert(SL* ps, int pos, SLDataType x);
//删除pos位置的数据
void SeqListErase(SL* ps, int pos);