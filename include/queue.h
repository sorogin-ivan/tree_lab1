#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <d-heab.h>

template <class HType>
class HQueue
{
private:
	DHeap<HType> *heap;
public:
	HQueue(int);
	~HQueue();
	HQueue(const HQueue<HType>&);
	HQueue(Data<HType>**, int, int);	

	void Push(const HType);
	void Push(Data<HType>*);
	void Pop();
	int IsEmpty();
	Data<HType>* Top();
	void Output();
	int GetSize ();
	int operator ==(const HQueue<HType>&)const;
};

template <class HType>
HQueue<HType>::HQueue (int d)
{	
	if (d < 0)
		throw
		exception ("Error");
	heap = new DHeap<HType> (d, 0);
}

template <class HType>
HQueue<HType>::~HQueue ()
{
	delete heap;
}

template <class HType>
HQueue<HType>::HQueue (const HQueue<HType>& a)
{
	this->heap = new DHeap<HType>(*(a.heap));
}

 template <class HType>
int HQueue<HType>::IsEmpty()
{
	if (heap->GetLen() == 0)
		return 1;
	else return 0;
}

template <class HType>
void HQueue<HType>::Pop()
{
	if (IsEmpty())
		throw
		exception ("Error");
	heap->DeleteMin();
}

template <class HType>
int HQueue<HType>::GetSize()
{
	return heap->GetLen();
}

template <class HType>
void HQueue<HType>::Push(const HType a)
{
	heap->Push(a);
}

template <class HType>
void HQueue<HType>::Push(Data<HType> *a)
{
	heap->Push(a);
}

template <class HType>
Data<HType>* HQueue<HType>::Top ()
{
	if (IsEmpty())
		throw
		exception ("Error");
	return heap->GetKey(0);
}

template <class HType>
void HQueue<HType>::Output ()
{
	heap->Output();
}

template <class HType>
int HQueue<HType>::operator== (const HQueue<HType>& a)const
{
	 return *heap == *a.heap;
}

template <class HType>
HQueue<HType>::HQueue (Data<HType>** a, int n, int d)
{
	heap = new DHeap<HType> (d, 0);
	heap->add(a, n);
}
	
#endif