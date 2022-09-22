#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 1000
#define ADD 3
typedef int SLDataType;

////��̬˳���
//typedef struct SeqList
//{
//	SLDataType arr[N];
//	int size;//��ʾ�����д洢�˶��ٸ�����
//}SL;
//
//// �ӿں���
//void SeqListInit(SL* ps);
//void SeqListPushBack(SL* ps, SLDataType x);
//void SeqListPopBack(SL* ps);
//void SeqListPushFront(SL* ps, SLDataType x);
//void SeqListPopFront(SL* ps);

//��̬˳���
typedef struct SeqList
{
	SLDataType *arr;
	int size;//��ʾ�����д洢�˶��ٸ�����
	int capacity;//����ʵ���ܴ洢�����ݵĿռ�����ʱ��󣬵�λ��Ԫ�ظ���
}SL;

// �ӿں���
//��ӡ˳���
void SeqListPrint(SL* ps);
//��ʼ��˳���
void SeqListInit(SL* ps);
//����˳���
void SeqListDestroy(SL* ps);
//˳���β��
void SeqListPushBack(SL* ps, SLDataType x);
//˳���βɾ
void SeqListPopBack(SL* ps);
//˳���ͷ��
void SeqListPushFront(SL* ps, SLDataType x);
//˳���ͷɾ
void SeqListPopFront(SL* ps);
//����ָ��ֵ���ҵ��˷����±꣬û�ҵ�������-1
int SeqListFind(SL* ps, SLDataType x);
//��ָ��λ�ò���һ��Ԫ��
int SeqListInsert(SL* ps, int pos, SLDataType x);
//ɾ��posλ�õ�����
void SeqListErase(SL* ps, int pos);