#include <queue.h>

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "���������� ������:" << endl;
	int a;
	cin >> a;
	DHeap<int> *heap = new DHeap <int> (a, 0);
	cout << "���������� �����:" << endl;
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
	cout << "�����������" << endl;
	heap->Output();

	cout << "���������� ���" << endl;
	heap->Sort();
	heap->Output();
	cout << "���������� ���" << endl;
	heap->Sortir();
	heap->Output();

}