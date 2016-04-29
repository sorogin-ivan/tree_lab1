#ifndef __GRAPHS_H__
#define __GRAPHS_H__

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "queue.h"
#include <d-heab.h>

#define maxVerticesSize 1000	

using namespace std;

template <class HType>
class edge 
{
public:
	edge(int, int, HType);

	int o; 
	int k; 
	HType weight;
};

template <class HType>
class Graph 
{
private:
	int n; 
	int m; 
	edge<HType>** edges; 
	int* vertices; 
	int m_cur; 

public:
	Graph(int, int);
	~Graph();

	void CreateGraph (HType, HType);
	void AddEdge(int, int, HType);
	void DelEdge(int, int);
	int GetLen();
	int GetEdgeSize();
	int GetRealSize();	
	edge<HType>** GetEdgesets ();
	edge<HType>*  GetMinEdge(int);
	HType GetWeight(int, int); 
	void Print();
	int FindEdge(int, int);
	void Gen(int&, int&);

	bool Visit (int, int*);
	void Sortir();
	HType* deykstra (int);
};

template <class HType>
edge<HType>::edge(int a, int b, HType c)
{
	o = a;
	k = b;
	weight = c;
}

template <class HType>
Graph<HType>::Graph(int a, int b)
{
	if (a < 0)
		throw 
		exception ("Error");
	else
		n = a;

	if ((b < 0) || (b > n*(n - 1) / 2))
		throw 
		exception ("Error");
	else
		m = b;

	m_cur = 0;

	vertices = new int[n];
	for (int i=0;i<n;i++)
		vertices[i] = i;
	edges = new edge<HType>*[m];
}

template <class HType>
Graph<HType>::~Graph()
{
	for (int i = 0; i < m_cur; i++)
		delete edges[i];
	delete[] edges;
	delete[]vertices;
}

template <class HType>
void Graph<HType>::AddEdge(int a, int b, HType c)
{
	if (m_cur == m)
		throw 
		exception ("Error");
	if (a == b)
		throw 
		exception ("Error");
	if ((a > n) || (b > n))
		throw
		exception ("Error");

	edges[m_cur] = new edge<HType>(a, b, c);
	m_cur++;
}

template <class HType>
void Graph<HType>::Gen (int &a, int &b)
{
	do
	{
		a = rand() % n;
		b = rand() % n;
	} 
	while ((a == b) || (FindEdge(a, b) != -1));
}

template <class HType>
void Graph<HType>::CreateGraph (HType a, HType b)
{
	if (a > b)
		throw "Error";

	int u, v;
	HType weight;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		Gen(u, v);
		weight = rand() % (int)(a - b - 1) + a;
		edges[i] = new edge<HType>(u, v, weight);
		m_cur++;
	}
}

template <class HType>
int Graph<HType>::GetLen()
{
	return n;
}

template <class HType>
int Graph<HType>::GetEdgeSize()
{
	return m;
}

template <class HType>
int Graph<HType>::GetRealSize()
{
	return m_cur;
}

template <class HType>
HType Graph<HType>::GetWeight(int a, int b)
{
	for (int i = 0; i < m_cur; i++)
		if ((edges[i]->o == a) && (edges[i]->k == b) || (edges[i]->o == b) && (edges[i]->k == a))
			return edges[i]->weight;
	return 0;
}

template <class HType>
void Graph<HType>::Print()
{
	cout << "printing" << endl;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m_cur; j++)
		{
			if (edges[j]->o == i)
				cout << edges[j]->o << "<->" << edges[j]->k << " (" << edges[j]->weight << ")" << endl;
		}
	}
}

template <class HType>
edge<HType>* Graph<HType>::GetMinEdge(int a)
{
	return edges[a];
}

template <class HType>
void Graph<HType>::DelEdge(int a, int b)
{
	int tmp = FindEdge(a, b);
	if (tmp == -1)
		throw 
		exception ("Error");
	delete edges[tmp];
	edges[tmp] = edges[m_cur - 1];
	m_cur--;
}

template <class HType>
int Graph<HType>::FindEdge(int a, int b)
{	
	for (int i = 0; i < m_cur; i++)
	{
		if ((edges[i]->o == a) && (edges[i]->k == a) || (edges[i]->o == b) && (edges[i]->k == b))
			return -1;
		if ((edges[i]->o == a) && (edges[i]->k == b) || (edges[i]->k == a) && (edges[i]->o == b))
			return i;
	}
	return -1;

}

template <class HType>
void Graph<HType>::Sortir()
{
	edge<HType>* tmp = edges[0];
	for (int i=0; i<m_cur-1; i++)
		for (int j=0; j<m_cur-1; j++)
			if (edges[j+1]->weight < edges[j]->weight)
			{
				tmp = edges[j+1];
				edges[j+1] = edges[j];
				edges[j] = tmp;
			}
}

template <class HType>
edge<HType>** Graph<HType>::GetEdgesets()
{
	return edges;
}

template <class HType>
bool Graph<HType>::Visit (int a, int* b)
{
	bool res = false;
	for (int i=0;i<n;i++)
		if (b[i] == a)
			res = true;
	return res;
}

template <class HType>
HType* Graph<HType>::deykstra(int s)
{
	if ((s < 0) || (s >= n))
		throw 
		exception ("error");
	
	HType **graph = new HType*[n];
	for (int i=0;i<n;i++)
		graph[i] = new HType[n];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			graph[i][j] = 0;

	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			if ((edges[j]->o == i) || (edges[j]->k == i))
			{
				graph[edges[j]->o][edges[j]->k] = edges[j]->weight;
				graph[edges[j]->k][edges[j]->o] = edges[j]->weight;
			}
		}

	HType *dist = new HType[n]; 
	HType *P = new HType[n]; 
	int *vis = new int[n]; 
	for (int i=0; i<n;i++)
		vis[i] = -1;
	vis[0] = s;
	int w, min;
//////////////////////////////////////////////////////////////
	for (int i=0; i<n; i++) 
	{                       
		if (graph[s][i]==0)
			dist[i]=MAX_HTYPE;
			else dist[i]=graph[s][i];
	}
	for (int i=1; i<n-1; i++) 
	{
		min=MAX_HTYPE;
		for (int k=0; k<n; k++) {
			if (dist[k] < min && k!=s && !Visit(k, vis) ) 
			{
				w=k;
				min=dist[k];
			}
		}
		if (min == MAX_HTYPE) break;
		vis[i]=w;
		for (int j=0; j < n; j++) {
			if (!Visit(j,vis) && graph[w][j]!=0 && (dist[w]+graph[w][j])<=dist[j]) 
			{
				P[j]=w;
				dist[j]=dist[w]+graph[w][j];
			}
		}
	}

	dist[s] = 0;
	return dist;
}

#endif