#include <d-heab.h>


template <class HType>
struct TypeQueue
{
	DHeap<HType>* dheab; 
	int priority;
};

template <class HType>
class HQueue
{
private:
	TypeQueue<HType>* queue; 
	int MaxSize; 
	int RealSize;
public:
	HQueue(int);
	~HQueue();
	HQueue(const HQueue&);

	void Push(const DHeap<HType>&);
	void Pop();
	int IsEmpty();
	int IsFull();
	DHeap<HType>* Top();
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
	delete [queue];
}