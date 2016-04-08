#include "d-heab.h"


template <class HType>
DHeap<HType>::DHeap (const int arnost, const int size)
{
	if ((arnost <= 0) || (size < 0))
	throw
	exception ("Error");
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