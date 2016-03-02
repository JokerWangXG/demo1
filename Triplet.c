#include"stdafx.h"
#include<iostream>
using namespace std;

//抽象数据类型Triplet的表示和实现
#define TRUE				1
#define FALSE				0
#define OK					1
#define ERROR				0
#define INFEASIBLE			-1
#define OVERFLOW			-2

typedef	int	Status;
typedef struct ElemType
{
	int data;
}*Triplet ;

Status	InitTriplet(Triplet& T, ElemType v1, ElemType v2, ElemType v3);
Status DestroyTriplet(Triplet &T);
Status Get(Triplet T, int i, ElemType &e);
Status Put(Triplet &T, int i, ElemType e);
Status IsAscending(Triplet T);
Status IsDescending(Triplet T);
Status Max(Triplet T, ElemType &e);
Status Min(Triplet T, ElemType &e);

void main()
{
	Triplet testT;
	ElemType e1, e2, e3;
	e1.data = 1, e2.data = 2, e3.data = 3;
	InitTriplet(testT, e1, e2, e3);
	cout << e1.data << "haaaaaa" << testT[1].data;
	Put(testT, 1, e3);
	cout << "\n" << testT[0].data << "hahhah";
	system("pause");
}

Status InitTriplet(Triplet& T, ElemType v1, ElemType v2, ElemType v3)
{
	T = (ElemType*)malloc(3 * sizeof(ElemType));
	if (!T) exit(OVERFLOW);
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
}

Status DestroyTriplet(Triplet &T)
{
	free(T);
	return OK;
}

Status Get(Triplet T, int i, ElemType &e)
{
	if (1 < i || i > 3)return ERROR;
	e = T[i - 1];
	return OK;
}

Status Put(Triplet &T, int i, ElemType e)
{
	if (i < 1 || i>3)return ERROR;
	T[i - 1] = e;
	return OK;
}

Status IsAscending(Triplet T)
{
	return(T[0].data <= T[1].data && T[1].data <= T[2].data);
}
Status IsDescending(Triplet T)
{
	return(T[0].data >= T[1].data&&T[1].data >= T[2].data);
}

Status Max(Triplet T, ElemType &e)
{
	int temp = (T[0].data >= T[1].data) ? (T[0].data >= T[2].data ? 0 : 2) : (T[1].data >= T[2].data ? 1 : 2);
	e = T[temp];
	return OK;
}

Status Min(Triplet T, ElemType &e)
{
	int temp = (T[0].data <= T[1].data) ? (T[0].data <= T[2].data ? 0 : 2) : (T[1].data<= T[2].data ? 1 : 2);
	e = T[temp];
	return OK;
}