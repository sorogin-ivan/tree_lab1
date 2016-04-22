#include <queue.h>

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "let's" << endl;
	cout << "do it" << endl;
	int a;
	cin >> a;
	DHeap<int> *heap = new DHeap <int> (a, 0);
	cout << "go" << endl;
	int b;
	cin >> b;
	int c;
	for (int i=0;i<b;i++)
	{
		cout << "i" << i << "yea" << endl;
		cin >> c;
		heap->Push(c);
	}
	system("cls");
	cout << "clear?)" << endl;
	heap->Output();

	cout << "Are you ready?)" << endl;
	cin >> a;
	switch (a)
	{
	case 1:
		cout << "Kaka" << endl;
		break;
	case 2:
		cout << "Go!!!" << endl;
		return;
	default:
		cout << "1 or 2??" << endl;
	}

	cout << "And it" << endl;
	heap->Sort();
	heap->Output();
	cout << "Is" << endl;
	
	heap->Sortir();
	heap->Output();

}