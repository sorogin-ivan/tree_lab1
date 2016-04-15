#include "d-heab.h"


template <class HType>
DHeap<HType>::DHeap (const int arnost, const int size)
{
	if ((arnost <= 0) || (size < 0))
	throw ("Error");
	arity = arnost; 
	len = size;
	keys = new HType[len];
}

template <class HType>
DHeap<HType>::DHeap (const DHeap &a)
{
	keys = new HType [a.kolvo];
	arity = a.arity;
	len = a.len;
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
	if ((a > len-1) || (b > len-1))
	throw ("Error");

	HType tmp = keys[a];
	keys[a] = keys[b];
	keys[b] = tmp;
}


template <class HType>
void DHeap<HType>::PushOnIdx (const int idx, const HType a)
{
	if (idx > len - 1)
		throw ("Error");
	keys[idx] = a;
}

template <class HType>
void DHeap<HType>::Up (int a) 
{
	if (a > len-1)
	throw
	exception ("Error");

	int p = GetIdx (a);
	while ((p >= 0) && (keys[p]->arr > keys[a]->arr))
	{
		if (p == 0)
		{
			Swap(a,p);
			return;
		}
		Swap(a,p);
		a = p;
		p = GetIdx (a);
	}
}


template <class HType>
void DHeap<HType>::Down (int a)
{
	if (a > len)
	throw
	exception ("Error");

	int c = MinChild(a);
	while ((c!=-1) && (keys[c]->arr < keys[a]->arr))
	{
		Swap (c,a);
		a = c;
		c = MinChild (a);
	}
}



template <class HType>
void DHeap<HType>::DeleteMin ()
{
	keys[0] = keys[len - 1];
	len --;
	Down(0);
}



template <class HType>
void DHeap<HType>::Push (HType a)
{
	Data<HType>* tmp2 = new Data<HType>;
	tmp2->arr = a;

	len ++;
	if (len > MAX_HTYPE)
		throw
		exception ("Error");

	Data<HType>** tmp = new Data<HType>*[MAX_HTYPE];
	for (int i=0;i<len-1;i++)
		tmp[i] = keys[i];
	tmp[kolvo - 1] = tmp2;
	keys = tmp;
}

