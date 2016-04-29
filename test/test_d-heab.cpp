
#include <d-heab.h>
#include <gtest.h>




TEST(dheap, can_create_dheap)
{
	ASSERT_NO_THROW(DHeap<int> *a = new DHeap<int>(3,10));
}

TEST(dheap, throw_if_nekorrect_dannye)
{
	ASSERT_ANY_THROW(DHeap<int> *a = new DHeap<int>(-3,10));
}

TEST(dheap, can_copy_dheap)
{
	DHeap<int> *a = new DHeap<int>(3,10);
	ASSERT_NO_THROW (DHeap<int> *b = new DHeap<int> (*a));
}

TEST(dheap, proverka_getidx)
{
	DHeap<int> *a = new DHeap<int>(3,11);
	int c = a->GetIdx(6);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_transa)
{
	int c;
	DHeap<int> *a = new DHeap<int>(3,0);
	a->Push(5);
	a->Push(8);
	DHeap<int> *b = new DHeap<int>(3,0);
	b->Push (8);
	b->Push (5);

	b->Swap(0,1);
	c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, throw_if_trans_uncorrect)
{
	DHeap<int> *a = new DHeap<int>(3,13);
	ASSERT_ANY_THROW(a->Swap(15,17));
}

TEST(dheap, provarka_vsplytiya)
{
	DHeap<int> *a = new DHeap<int>(3,0);
	a->Push (5);
	a->Push (8);
	ASSERT_NO_THROW(a->Up(1));
}


TEST(dheap, throw_if_vsplyt_uncorrect)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	ASSERT_ANY_THROW(a->Up(16));
}

TEST(dheap, proverka_minchild)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->Push (5);
	a->Push (8);
	a->Push (7);
	a->Push (14);
	a->Push (15);
	a->Push (12);
	a->Push (18);
	a->Push (8);
	a->Push (10);
	a->Push (12);
	a->Push (14);
	a->Push (15);
	a->Push (13);
	int b = a->MinChild(0);
	EXPECT_EQ(b,2);
}



TEST(dheap, proverka_pogryzh2)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->Push (5);
	a->Push (8);
	a->Push (7);
	a->Push (14);
	a->Push (15);
	a->Push (12);
	a->Push (18);
	a->Push (8);
	a->Push (10);
	a->Push (12);
	a->Push (14);
	a->Push (15);
	a->Push (13);
	a->Down(12);
	int c = a->operator==(*a);
	EXPECT_EQ(c,1);
}

TEST(dheap, throw_if_pogryzh_uncorrect)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	ASSERT_ANY_THROW(a->Down(20));
}


TEST(dheap, proverka_pogryzh)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->Push (5);
	a->Push (30);
	a->Push (7);
	a->Push (12);
	a->Push (15);
	a->Push (12);
	a->Push (18);
	a->Push (8);
	a->Push (10);
	a->Push (12);
	a->Push (14);
	a->Push (15);
	a->Push (13);
	a->Down(1);

	DHeap<int> *b = new DHeap <int> (3,0);
	b->Push (5);
	b->Push (12);
	b->Push (7);
	b->Push (12);
	b->Push (15);
	b->Push (30);
	b->Push (18);
	b->Push (8);
	b->Push (10);
	b->Push (12);
	b->Push (14);
	b->Push (15);
	b->Push (13);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, provekra_delet_s_min)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->Push (5);
	a->Push (8);
	a->Push (7);
	a->Push (12);
	a->Push (15);
	a->Push (12);
	a->Push (18);
	a->Push (8);
	a->Push (10);
	a->Push (12);
	a->Push (14);
	a->Push (15);
	a->Push (13);
	a->DeleteMin();

	DHeap<int> *b = new DHeap <int> (3,0);
	b->Push (7);
	b->Push (8);
	b->Push (8);
	b->Push (12);
	b->Push (15);
	b->Push (12);
	b->Push (18);
	b->Push (13);
	b->Push (10);
	b->Push (12);
	b->Push (14);
	b->Push (15);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_delet_s_zadan)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->Push (5);
	a->Push (8);
	a->Push (7);
	a->Push (12);
	a->Push (15);
	a->Push (12);
	a->Push (18);
	a->Push (8);
	a->Push (10);
	a->Push (12);
	a->Push (14);
	a->Push (15);
	a->Push (13);
	a->DeleteKey(2);

	DHeap<int> *b = new DHeap <int> (3,0);
	b->Push (5);
	b->Push (8);
	b->Push (8);
	b->Push (12);
	b->Push (15);
	b->Push (12);
	b->Push (18);
	b->Push (13);
	b->Push (10);
	b->Push (12);
	b->Push (14);
	b->Push (15);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}
	
TEST(dheap, throw_if_idx_uncorrect)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	ASSERT_ANY_THROW(a->DeleteKey(16));
}

TEST(dheap, proverka_okychivaniya)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->Push (5);
	a->Push (8);
	a->Push (7);
	a->Push (12);
	a->Push (15);
	a->Push (12);
	a->Push (18);
	a->Push (8);
	a->Push (10);
	a->Push (12);
	a->Push (14);
	a->Push (15);
	a->Push (13);
	a->Sort();
	int c = a->operator==(*a);
	EXPECT_EQ(c,1);
}

TEST(dheap, throw_if_kycha_pusta_pri_okych)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	ASSERT_ANY_THROW(a->Sort());
}

TEST(dheap, proverka_operatora_ravno)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->Push (5);
	a->Push (8);
	a->Push (7);
	a->Push (14);
	a->Push (15);
	a->Push (12);
	a->Push (18);
	a->Push (8);
	a->Push (10);
	a->Push (12);
	a->Push (14);
	a->Push (15);
	a->Push (13);

	DHeap<int> *b = new DHeap <int> (3,0);

	a = b;
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}
