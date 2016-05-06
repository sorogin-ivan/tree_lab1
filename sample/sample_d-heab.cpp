#include <queue.h>

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Количество вершин:" << endl;
	int a;
	cin >> a;
	DHeap<int> *heap = new DHeap <int> (a, 0);
	cout << "Количество веток:" << endl;
	int b;
	cin >> b;
	int c;
	for (int i=0;i<b;i++)
	{
		cout << "i" << i << endl;
		c=rand()%5;
		heap->Push(c);
	}
	system("cls");
	cout << "Изначальное" << endl;
	heap->Output();

	cout << "Сортировка раз" << endl;
	heap->Sort();
	heap->Output();
	cout << "Сортировка два" << endl;
	heap->Sortir();
	heap->Output();

}