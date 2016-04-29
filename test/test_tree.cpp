#include <gtest.h>
#include <tree.h>



TEST(graph, can_create_graph)
{
	ASSERT_NO_THROW(Graph<int> *a = new Graph<int>(5,8) );
}

TEST(graph, throw_if_create_graph_with_uncorrect)
{
	ASSERT_ANY_THROW(Graph<int> *a = new Graph<int>(5,15) );
}

TEST(graph, proverka_get_kolvo)
{
	Graph<int> *a = new Graph<int>(5,8);
		EXPECT_EQ(a->GetLen(), 5);
}

TEST(graph, proverka_getEdgeSize)
{
	Graph<int> *a = new Graph<int>(5,8);
	EXPECT_EQ(a->GetEdgeSize(), 8);
}

TEST(graph, proverka_getRealSize)
{
	Graph<int> *a = new Graph<int>(5,1);
	EXPECT_EQ(a->GetRealSize(), 0);
}

TEST(graph, can_add_edge)
{
	Graph<int> *a = new Graph<int>(5,3);
	a->AddEdge(2,3,6);
	EXPECT_EQ(a->GetRealSize(), 1);
}

TEST(graph, throw_if_uncorrect_add_edge)
{
	Graph<int> *a = new Graph<int>(5,8);
	ASSERT_ANY_THROW(a->AddEdge(6,1,5));
}

TEST(graph, throw_if_uncorrect_add_edge2)
{
	Graph<int> *a = new Graph<int>(5,8);
	ASSERT_ANY_THROW(a->AddEdge(2,2,6));
}

TEST(graph, throw_if_graph_isFull)
{
	Graph<int> *a = new Graph<int>(2,1);
	a->AddEdge(0,1,6);
	ASSERT_ANY_THROW(a->AddEdge(1,0,6));
}

TEST(graph, proverka_getWeight)
{
	Graph<int> *a = new Graph<int>(2,1);
	a->AddEdge(0,1,7);
	EXPECT_EQ(a->GetWeight(0,1), 7);
}

TEST(graph, proverka_delEdge)
{
	Graph<int> *a = new Graph<int>(2,1);
	a->AddEdge(0,1,5);
	a->DelEdge(0,1);
	EXPECT_EQ(a->GetRealSize(), 0);
}

TEST(graph, throw_if_uncorrect_del)
{
	Graph<int> *a = new Graph<int>(2,1);
	ASSERT_ANY_THROW(a->DelEdge(0,1));
}

TEST(graph, proverka_findEdge)
{
	Graph<int> *a = new Graph<int>(2,1);
	a->AddEdge(0,1,5);
	EXPECT_EQ(a->FindEdge(0,1), 0);
}

TEST(graph, proverka_if_uncorrect_find)
{
	Graph<int> *a = new Graph<int>(2,1);
	EXPECT_EQ(a->FindEdge(3,4), -1);
}