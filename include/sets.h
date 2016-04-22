
#ifndef __SETS_H__
#define __SETS_H__

#include "queue.h"
#include "tree.h"
#include "d-heab.h"
#include <stack>

template <class HType>
class Sets
{
private:
	HType n;
	HType *parent;
public:
	Sets(HType);
	~Sets();

	void MakeSets (HType);
	HType FindSets (HType);
	void UnionSets (HType, HType);
	void Output();

	HType* GetSets(HType);
	Graph<HType>* kruskal(Graph<HType>*&);
};

template <class HType>
Sets<HType>::Sets(HType a)
{
	n = a;
	parent = new HType[n];
	for (int i=0;i<n;i++)
		parent[i] = -1;
}

template <class HType>
Sets<HType>::~Sets()
{
	delete[] parent;
}

template <class HType> 
void Sets<HType>::MakeSets(HType a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("Error");
	if (parent[a] != -1)
		throw 
		exception ("Error");

	parent[a] = a;
}

template <class HType>
HType Sets<HType>::FindSets (HType a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("Error");
	if (parent[a] == -1)
		return -1;

	while (parent[a] != a)
		a = parent[a];
	return a;	
}

template <class HType>
void Sets<HType>::UnionSets (HType a, HType b)
{
	if ((a > n) || (a < 0) || (b > n) || (b < 0))
		throw 
		exception ("Error");
	if ((parent[a] == -1) || (parent[b] == -1))
		throw
		exception ("Error");

	a = FindSets (a);
	b = FindSets (b);
	if (a != b)
		parent [b] = a;
}

template <class HType>
HType* Sets<HType>::GetSets (HType a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("Error");
	if (parent[a] != a)
		throw 
		exception ("Error");
	
	stack<HType> st;
	HType *res = new HType;
	for (int i=0; i<n; i++)
	{
		if (parent[i] == a)
			st.push(i);
	}
	res[0] = st.size();
	int j=1;
	while (!st.empty())
	{
		res[j] = st.top();
		st.pop();
		j++;
	}
	return res;
}

template <class HType>
void Sets<HType>::Output ()
{
	HType*tmp = new HType;
	for (int i=0; i<n;i++)
	{
		if (parent[i] == i)
		{
			tmp = GetSets(i);

			if (tmp[0] > 1)
			{
				cout << '{';
				for (int k = 1; k<=tmp[0]; k++)
					cout << tmp[k] << ' ';
				cout << "} ";
			}
			else 
				cout << '{' << tmp[1] << "} ";
		}
	}
	cout << endl;
}

template <class HType>
Graph<HType>* Sets<HType>::kruskal (Graph<HType>*& gr)
{
	
	int n = gr->GetLen();
	int m = gr->GetRealSize();
	Graph<HType> *tree = new Graph<HType>(n,m);

	Sets<HType> *s = new Sets<HType>(n);
	for (int i=0; i<n; i++)
		s->MakeSets(i);

	gr->Sortir();
	int treeSize = 0;
	int i = 0;
	while ((treeSize < n-1) && (i < m))
	{
		edge<HType> *tmp = gr->getMinEdge(i);
		int o = tmp->o;
		int k = tmp->k;
		int weight = tmp->weight;
		int Ao = s->FindSets(o);
		int Ak = s->FindSets(k);
		if (Ao != Ak)
		{
			s->UnionSets(Ao, Ak);
			tree->addEdge(o, k, weight);
			treeSize++;
		}
		i++;
	}

	return tree;
}


#endif