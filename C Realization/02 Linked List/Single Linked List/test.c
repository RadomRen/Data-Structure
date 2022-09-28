#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//尾删尾插测试
void SLTTest1()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);

	SListPrint(phead);

	SListPopBack(&phead);
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);

	SListPrint(phead);
}

//头删头插测试
void SLTTest2()
{
	SLTNode* phead = NULL;
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);

	SListPrint(phead);

	SListPopFront(&phead);
	SListPopFront(&phead);

	SListPrint(phead);
}

//单链表查找元素和修改测试
void SLTTest3()
{
	SLTNode* phead = NULL;

	SLTNode* ret = SListFind(phead, 4);
	if (ret)
		printf("找到元素：%d\n", ret->data);
	else
		printf("元素不存在。\n");

	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 5);
	SListPushBack(&phead, 2);

	SListPrint(phead);

	SLTNode* pos = SListFind(phead, 2);
	int i = 1;
	while (pos)
	{
		printf("第%d个节点：%p -> %d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	pos = SListFind(phead, 6);
	i = 1;
	while (pos)
	{
		printf("第%d个节点：%p -> %d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 6);
	}
	if (i == 1)
	{
		printf("未找到\n");
	}

	//修改链表节点
	pos = SListFind(phead, 2);
	while (pos)
	{
		pos->data = 6;
		pos = SListFind(pos->next, 2);
	}
	SListPrint(phead);
}


//给定位置插入和删除的测试
void SLTTest4()
{
	SLTNode* phead = NULL;
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPushFront(&phead, 3);

	SListPrint(phead);
	SLTNode* pos = SListFind(phead, 3);
	while (pos)
	{
		SListInsert(&phead, pos, 10);
		pos = SListFind(pos->next, 3);
	}
	SListPrint(phead);


	pos = SListFind(phead, 3);
	while (pos)
	{
		SListErase(&phead, pos);
		pos = SListFind(phead, 3);
	}
	SListPrint(phead);

	SListDistroy(&phead);

	SListPrint(phead);
}

int main()
{
	//SLTTest1();
	//SLTTest2();
	//SLTTest3();
	SLTTest4();
}