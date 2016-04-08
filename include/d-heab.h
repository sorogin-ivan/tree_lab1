#ifndef __D_HEAP__H__
#define __D_HEAP__H__

#include <cstdlib>
#include <iostream>

using namespace std;

template <class HType>
class DHeap
{
private:
	int arity; 
	HType *keys;
	int kolvo;
public:
	DHeap (const int, const int);
	DHeap (const DHeap<HType>&);
	~DHeap ();
	int GetIdx (int a);
	void Swap (const int a, const int b);
	void PushOnIdx (const int idx, const HType a);
	void Up (int a);
	void Down (int a);
	int MinChild (int a);
	void DeleteMin ();
	void DeletKey (int a);
	void Push (HType a);
	void Sort ();
	int Ñonclusion(int idx);
	int operator == (const DHeap<HType>& a)const;
	DHeap& operator=(const DHeap<HType>& a);
};



#endif