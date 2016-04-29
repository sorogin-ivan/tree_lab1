#include <gtest.h>
#include "sets.h"


TEST(sets, can_create_sets)
{
	ASSERT_NO_THROW(Sets<int> *a = new Sets<int>(2));
}

TEST(sets, can_makesets)
{
	Sets<int> *a = new Sets<int>(2);
	ASSERT_NO_THROW(a->MakeSets(1));
}

TEST(sets, can_find_sets)
{
	Sets<int> *a = new Sets<int>(2);
	a->MakeSets(1);
	EXPECT_EQ(a->FindSets(1), 1);
}

TEST(sets, throw_if_uncorrect_find)
{
	Sets<int> *a = new Sets<int>(2);
	ASSERT_ANY_THROW(a->FindSets(5));
}

TEST(sets, throw_if_uncorrect_make)
{
	Sets<int> *a = new Sets<int>(2);
	ASSERT_ANY_THROW(a->MakeSets(8));
}

TEST(sets, throw_if_elem_already_used)
{
	Sets<int> *a = new Sets<int>(2);
	a->MakeSets(1);
	ASSERT_ANY_THROW(a->MakeSets(1));
}

TEST(sets, can_union_sets)
{
	Sets<int> *a = new Sets<int>(2);
	a->MakeSets(1);
	a->MakeSets(0);
	ASSERT_NO_THROW(a->UnionSets(0,1));
}

TEST(sets, throw_if_uncorrect_union)
{
	Sets<int> *a = new Sets<int>(2);
	ASSERT_ANY_THROW(a->UnionSets(5,1));
}

TEST(sets, throw_if_union_not_root_elem)
{
	Sets<int> *a = new Sets<int>(2);
	ASSERT_ANY_THROW(a->UnionSets(0,1));
}