#include "d-heab.h"


template <class HType>
DHeap<HType>::DHeap (const int arnost, const int size)
{
	if ((arnost <= 0) || (size < 0))
	throw ("Error");
	arity = arnost; 
	kolvo = size;
	keys = new HType[kolvo];
}

template <class HType>
DHeap<HType>::DHeap (const DHeap &a)
{
	keys = new HType [a.kolvo];
	arity = a.arity;
	kolvo = a.kolvo;
	for (int i=0;i<kolvo-1;i++)
		keys[i] = a.keys[i];
}

template <class HType>
DHeap<HType>::~DHeap ()
{
	delete []keys;
}


template <class HType>
int DHeap<HType>::GetIdx(int a){

	return ((a-1)/arity);

}


template <class HType>
void DHeap<HType>::Swap (const int a, const int b) 
{
	if ((a > kolvo-1) || (b > kolvo-1))
	throw ("Error");

	HType tmp = keys[a];
	keys[a] = keys[b];
	keys[b] = tmp;
}


template <class HType>
void DHeap<HType>::PushOnIdx (const int idx, const HType a)
{
	if (idx > kolvo - 1)
		throw ("Error");
	keys[idx] = a;
}

