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




template <class HType>
void DHeap<HType>::Sort ()
{
	if (len == 0)
		throw
		exception ("Error");
	for (int i=len-1; i>=0;i--)
		Down(i);
}

template <class HType>
void DHeap<HType>::Output()
{
	int level=0, tmp = 0;
	while (tmp < len)
	{
		tmp += pow (d,level);
		level++;
	}
	int k=1, z=0;
	cout << "\t" << keys[0]->arr << endl;
	for (int i = 1; i < level;i++)
	{
		for (int j = k; (j<k+pow(d,i)) && (j < kolvo); j++)
			cout << keys[j]->arr << "\t";
		cout << endl;
		if (k + pow(d,i) > kolvo)
				k = len;
			else k += pow(d,i);
	}

}

template <class HType>
void DHeap<HType>::Sortir () 
{
	int tmp = len;
	for (int i= len-1; i >0; i--)
		DeleteKey(0);
	len = tmp;

	tmp = 0;
	int tmp2 = len-1;
	while (tmp <= tmp2)
	{
		Swap(tmp2,tmp);
		tmp++;
		tmp2--;
	}	
}

template <class HType>
void DHeap<HType>:: Add (Data<HType> **a, int n)
{
	if (len + n >= MAX_HTYPE)
		throw
		exception ("Error");
	for (int i = len+1; i <len+n+1; i++)
		keys[i] = a[i-len-1];
	len += n;
}

template <class HType>
int DHeap<HType>::GetLen ()
{
	return len;
}


template <class HType>
HType DHeap<HType>::GetKey (int a)
{
	return keys[a]->arr;
}


template <class HType>
void DHeap<HType>::DeleteKey (int a)
{
	if (a >= len)
		throw
		exception ("Error");
	Swap(a, len - 1);

	len--;
	if (keys[a]->arr < keys[GetIdx(a)]->arr)
		Up(a);

	else Down(a);
}

template <class HType>
int DHeap<HType>::operator==(const DHeap<HType>& a)const
{
	if (a.len != len)
		return 0;
	for (int i=0;i<a.len;i++)
	{
		if (keys[i]->arr != a.keys[i]->arr)
			return 0;
	}
	return 1;
}


template <class HType>
DHeap<HType>& DHeap<HType>::operator=(const DHeap<HType>& a)
{
	arity = a.arity;
	len = a.len;
	for (int i=0;i<len;i++)
		keys[i] = a.keys[i];
	return *this;
}