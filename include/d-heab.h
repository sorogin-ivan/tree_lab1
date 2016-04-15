#ifndef __D_HEAP__H__
#define __D_HEAP__H__

#include <cstdlib>
#include <iostream>
#include <cmath>


#define MAX_HTYPE 1000


using namespace std;


template <class HType>
class Data
{
public:
	HType arr;
};



template <class HType>
class DHeap
{
private:
	int arity; 
	Data<HType>** keys;
	int len;
public:
	DHeap (const int, const int);
	DHeap (const DHeap<HType>&);
	~DHeap ();
	int GetIdx (int);
	void Swap (const int, const int);
	void PushOnIdx (const int, const HType);
	void Up (int);
	void Down (int);
	int MinChild (int);
	void DeleteMin ();
	void DeletKey (int);
	void Push (HType);
	void Sort ();
	int Ñonclusion(int);
	int operator == (const DHeap<HType>&)const;
	DHeap& operator=(const DHeap<HType>&);


	int GetLen(); 
	HType GetKey(int); 

	void Sortir();

	void add (Data<HType>**, int);
};



#endif