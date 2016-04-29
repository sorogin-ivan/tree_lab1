#include "sets.h"

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	int n;
	cout << "Кол-во верщин" << endl;
	cout << "позязя" << endl;

	cin >> n;

	cout << "кол-во веток, позязя" << endl;
	int m;
	cin >> m;
	Graph<int> *graph = new Graph<int> (n,m);
	
	cout << "минимальное значение" << endl;
	cout << "и максимальное)" << endl;
	int min, max;
	cin >> min;
	cin >> max;
	graph->CreateGraph(min, max);
	system ("cls");
	
	cout << "До: " << endl<<endl;
	graph->Print();

	cout << "после:" << endl;
	Graph<int> *res = new Graph<int> (n,m);
	Sets<int> *a = new Sets<int> (n);

	res = a->kruskal(graph);
	cout << endl << endl;
	res->Print();
}