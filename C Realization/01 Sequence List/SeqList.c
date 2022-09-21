#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

// 接口函数

//打印顺序表
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//初始化顺序表
void SeqListInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//销毁顺序表
void SeqListDestroy(SL* ps)
{
	if (ps->arr != NULL)
	{
		free(ps->arr);
		ps->arr = NULL;
		ps->capacity = ps->size = 0;
	}
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* ptr = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));
		if (ptr == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		ps->arr = ptr;
		ps->capacity = newcapacity;
	}
}

//顺序表尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}

//顺序表尾删
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);//对于空数组不能进行尾删
	ps->size--;
}

//顺序表头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	int i = 0;
	for (i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//顺序表头删
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);
	int i = 0;
	for(i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//查找指定值，找到了返回下标，没找到，返回-1
int SeqListFind(SL* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//在指定位置插入一个元素
int SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps->size >= pos && pos >= 0);
	SeqListCheckCapacity(ps);
	int i = 0;
	for (i = ps->size - 1; i >= pos; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[pos] = x;
	ps->size++;
}

//删除pos位置的数据
void SeqListErase(SL* ps, int pos)
{
	assert(ps->size > pos && pos >= 0);
	int i = 0;
	for (i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}