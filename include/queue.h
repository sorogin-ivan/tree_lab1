#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <d-heab.h>

template <class HType>
class HQueue
{
private:
	TypeQueue<HType>* queue; 
	int MaxSize; 
	int RealSize;
public:
	HQueue(int);//+
	~HQueue();//+
	HQueue(const HQueue&);//+
	HQueue(Data<HType>**, int, int);//+

	void Push(const HType&);//+
	void Pop();//+
	int IsEmpty();//+
	HType Top();//+
    void Output();//+
	int operator ==(const HQueue<HType>&)const;//+

};



template <class HType>
HQueue<HType>::HQueue (int size)
{
	queue->dheab = new DHeap<HType>;
	queue->priority = 0;
	MaxSize = size;
	RealSize = 0;
}

template <class HType>
HQueue<HType>::~HQueue ()
{
	delete queue;
}

template <class HType>
HQueue<Htype>::HQueue(const HQueue& a)
{
	this->heap = new DHeap<HType>(*(a.heap));
}



 template <class HType>
int HQueue<HType>::IsEmpty()
{
	if (queue->GetLen() == 0)
		return 1;
	else return 0;
}


template <class HType>
void HQueue<HType>::Pop()
{
	if (isEmpty())
		throw
		exception ("Error");
	queue->DeleteMin();
}



template <class HType>
void HQueue<HType>::Push(const Htype>& a){


	queue->Push(a);


}

template <class HType>

HType HQueue<HType>::Top(){

if (isEmpty())
throw
   exception ("Error");
return queue->GetKey(0);



}

template <class HType>
void HQueue<HType>::Output()
{
	queue->Output();
}


template <class HType>
int HQueue<HType>::operator== (const HQueue<HType>& a)const
{
	 return *queue == *a.queue;
}

template <class HType>
HQueue<HType>::HQueue (Data<HType> **a, int n, int d)
{
	queue = new DHeap<HType> (d, n);
	queue->Add(a, n);
}



#endif