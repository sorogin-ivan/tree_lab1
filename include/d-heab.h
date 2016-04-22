#ifndef __D_HEAP__H__
#define __D_HEAP__H__

#include <cstdlib>
#include <iostream>
#include <cmath>

#define MAX_HTYPE 10000

using namespace std;

template <class HType>
class Data
{
public:
	HType arr;
};

template <class HType>
class Dist : public Data<HType> 
{
public:
	int v; 

	Dist (int, HType);
};

template <class HType>
class DHeap
{
private:
	double arity; 
	Data<HType>** keys;
	int len;
public:
	DHeap (const int, const int);
	DHeap (const DHeap<HType>&);
	~DHeap ();

	int GetIdx (int); 
	void Swap (const int, const int); 
	void Up (int);
	void Down (int); 
	int MinChild (int); 
	void DeleteMin (); 
	void DeleteKey (int); 
	void Push (HType);
	void Sort (); 
	void Output (); 

	int operator == (const DHeap<HType>&)const;
	DHeap& operator=(const DHeap<HType>&);
	int GetLen(); 
	Data<HType>* GetKey(int); 

	void Sortir(); 
	void Add(Data<HType>**, int);
	void Push (Data<HType>*);
};





template <class HType>
Dist<HType>::Dist (int a, HType d)
{
	v = a; 
	arr = d; 
}

template <class HType>
DHeap<HType>::DHeap (const int arnost, const int size)
{
	if ((arnost <= 0) || (size < 0) || (size > MAX_HTYPE))
	throw
	exception ("Error");
	arity = arnost; 
	len = size;
	keys = new Data<HType>*[MAX_HTYPE];
}

template <class HType>
DHeap<HType>::DHeap (const DHeap &a)
{	
	arity = a.arity;
	len = a.len;
	keys = new Data<HType>*[MAX_HTYPE];
	for (int i=0;i<=len-1;i++)
		keys[i] = a.keys[i];
}

template <class HType>
DHeap<HType>::~DHeap ()
{
	delete []keys;
}

template <class HType>
int DHeap<HType>::GetIdx (int a)
{
	int p;
	return p = (a-1)/arity;
}

template <class HType>
void DHeap<HType>::Swap (const int a, const int b) 
{
	if ((a > len-1) || (b > len-1))
	throw
	exception ("Error");

	Data<HType> *tmp = new Data<HType>;
	tmp->arr = keys[a]->arr;
	keys[a]->arr = keys[b]->arr;
	keys[b]->arr = tmp->arr;
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
int DHeap<HType>::MinChild (int a) 
{
	if (a*arity+1> len-1) 
		return -1;

    int minCh = a*arity+1;
    int maxCh;
	if (a*arity+arity < len - 1)
		maxCh = a*arity + arity;
	else maxCh = len - 1;

    for (int i = minCh; i <= maxCh; i++) {
        if (keys[i]->arr < keys[minCh]->arr) {
            minCh = i;
        }
    }
    return minCh;
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
	tmp[len - 1] = tmp2;
	keys = tmp;
}

template <class HType>
void DHeap<HType>::Push (Data<HType>* a)
{
	keys[len] = a;
	len++;
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
void DHeap<HType>::Output()
{
	int level=0, tmp = 0;
	while (tmp < len)
	{
		tmp += pow (arity, level);
		level++;
	}
	int k=1, z=0;
	cout << "\t" << keys[0]->arr<< endl;
	for (int i = 1; i < level;i++)
	{
		for (int j = k; (j<k+pow(arity,i)) && (j < len); j++)
			cout << keys[j]->arr << "\t";
		cout << endl;
		if (k + pow(arity,i) > len)
				k = len;
			else k += pow(arity,i);
	}

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

template <class HType>
int DHeap<HType>::GetLen ()
{
	return len;
}

template <class HType>
Data<HType>* DHeap<HType>::GetKey (int a)
{
	return keys[a];
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
void DHeap<HType>::Add (Data<HType>** a, int n)
{
	if (len + n >= MAX_HTYPE)
		throw
		exception ("Error");
	for (int i=len; i < len + n;i++)
	{
		keys[i] = a[i-len];
	}
	len+=n;
	Sort();
}

#endif