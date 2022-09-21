#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

void TestSeqList1()
{
	SL sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	//SeqListPopBack(&sl);对于空数组，不能执行尾删

	SeqListDestroy(&sl);
}

void TestSeqList2()
{
	SL sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);

	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);

	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList3()
{
	SL sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);

	int pos = SeqListFind(&sl, 56);
	if (pos != -1)
	{
		printf("找到了，下标为%d\n", pos);
	}
	else
	{
		printf("没找到");
	}

	SeqListDestroy(&sl);
}

void TestSeqList4()
{
	SL sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);

	SeqListInsert(&sl, 4, 10);
	SeqListInsert(&sl, 2, 20);

	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList5()
{
	SL sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);

	SeqListErase(&sl, 3);

	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	//TestSeqList4();
	TestSeqList5();

	return 0;
}