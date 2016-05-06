#include "tree.h"
#include "queue.h"

void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Кол-во элементов" << endl << endl;
	
	cout << "Позязя" << endl;
	int n;
	cin >> n;

	cout << "Кол-во веток" << endl;
	int m;
	cin >> m;
	Graph<float> *graph = new Graph<float> (n,m);
	
	cout << "минимальный вес" << endl;
	cout << "и максимальный, позязя)" << endl;
	float min, max;
	cin >> min;
	cin >> max;
	graph->CreateGraph(min, max);
	system ("cls");
	
	cout << "вот что вышло: " << endl<<endl;
	graph->Print();

	cout << "от чего путь?)" << endl;
	int a;
	cin >> a; 
	cout << "делается.." << endl << endl;
	float *dist = graph->deykstra(a);

	cout << "вот путь): " << endl << endl;	
	for (int i = 0; i < n; i++)
		if (dist[i] == MAX_HTYPE){
			cout<< "В "<<i<<" нету пути(  ";
			cout <<"Вес  " << -1 << endl;}
		else{
			cout <<"Передидущая: " << dist[i];
			cout << "  Вес " << dist[i]<< endl;
	
		}
		cout << endl;

}	