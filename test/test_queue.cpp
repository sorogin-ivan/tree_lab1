#include <gtest.h>
#include <queue.h>


TEST(queue, can_create_queue)
{
	ASSERT_NO_THROW(HQueue<int> *a = new HQueue<int> (2));
}

TEST(queue, throw_if_uncorrect_arn)
{
	ASSERT_ANY_THROW(HQueue<int> *a = new HQueue<int> (-1));
}

TEST(queue, can_copy_queue)
{
	HQueue<int> *a = new HQueue<int> (2);
	ASSERT_NO_THROW(HQueue<int> *b = new HQueue<int> (*a));
}

TEST(queue, proverka_isEmpty)
{
	HQueue<int> *a = new HQueue<int> (2);
	EXPECT_EQ (a->IsEmpty(), 1);
}

TEST(queue, proverka_popa)
{
	HQueue<int> *a = new HQueue<int> (2);
	a->Push(5);
	a->Pop();
	EXPECT_EQ(a->IsEmpty(), 1);
}

TEST(queue, throw_if_pop_iz_pustoi_queue)
{
	HQueue<int> *a = new HQueue<int> (2);
	ASSERT_ANY_THROW(a->Pop());
}

TEST(queue, proverka_topa)
{
	HQueue<int> *a = new HQueue<int> (2);
	a->Push(5);
	EXPECT_EQ(a->Top()->arr, 5);
}

TEST(queue, proverka_na_ravenstvo)
{
	HQueue<int> *a = new HQueue<int> (2);
	a->Push(5);
	HQueue<int> *b = new HQueue<int> (2);
	b->Push(5);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}
