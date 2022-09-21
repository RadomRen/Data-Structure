#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//Œ≤…æŒ≤≤Â≤‚ ‘
void SLTTest1()
{
	SLT slist = { NULL, 0 };
	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	SListPushBack(&slist, 4);

	SListPrint(&slist);

	SListPopBack(&slist);
	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);

	SListPrint(&slist);
}

//Õ∑…æÕ∑≤Â≤‚ ‘
void SLTTest2()
{
	SLT slist = { NULL, 0 };
	SListPushFront(&slist, 1);
	SListPushFront(&slist, 2);
	SListPushFront(&slist, 3);
	SListPushFront(&slist, 4);

	SListPrint(&slist);

	SListPopFront(&slist);
	SListPopFront(&slist);

	SListPrint(&slist);
}

//∏¯∂®Œª÷√≤Â»Î∫Õ…æ≥˝µƒ≤‚ ‘
void SLTTest3()
{
	SLT slist = { NULL, 0 };
	SListPushFront(&slist, 1);
	SListPushFront(&slist, 2);
	SListPushFront(&slist, 3);
	SListPushFront(&slist, 4);

	SListPrint(&slist);

	SListInsert(&slist, 2, 10);

	SListPrint(&slist);

	SListErase(&slist, 0);

	SListPrint(&slist);

	SListClear(&slist);

	SListPrint(&slist);
}

int main()
{
	//SLTTest1();
	//SLTTest2();
	SLTTest3();
}