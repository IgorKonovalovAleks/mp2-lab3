#include "queue.h"

#include <gtest.h>

TEST(Queue, can_create_queue_with_positive_capacity)
{
  ASSERT_NO_THROW(Queue<int> v(5));
}

TEST(Queue, throws_when_create_queue_with_negative_capacity)
{
  ASSERT_ANY_THROW(Queue<int> v(-5));
}

TEST(Queue, can_create_copied_queue)
{
  Queue<int> v(1);

  ASSERT_NO_THROW(Queue<int> v1(v));
}

TEST(Queue, copied_queue_is_equal_to_source_one)
{
	Queue<int> s(3);
	s.push_front(1);
	s.push_front(2);
	s.push_front(3);
	Queue<int> z(s);
	for (int i = 0; i < 3; i++) {
		if (z.getBottom() != s.getBottom())
			ADD_FAILURE();
		s.pop_back();
		z.pop_back();
	}
	EXPECT_TRUE(true);
}

TEST(Queue, copied_vector_has_its_own_memory)
{
	Queue<int> s(3);
	s.push_front(1);
	s.push_front(2);
	s.push_front(3);
	Queue<int> z(s);
	z.pop_back();
	z.push_front(4);
	EXPECT_EQ(s.getTop(), 3);
}

TEST(Queue, can_get_size)
{
  Queue<int> v(4);
  v.push_front(1);

  EXPECT_EQ(1, v.getSize());
}

TEST(Queue, can_push_and_get_element)
{
  Queue<int> v(4);
  v.push_front(1);

  EXPECT_EQ(1, v.getBottom());
}

TEST(Queue, throws_when_pop_element_in_0_item_queue)
{
	Queue<int> v(1);
	EXPECT_ANY_THROW(v.pop_back());
}

TEST(Queue, works_correctly_when_push_element_with_capacity_exceeded_top_is_greater_than_bottom)
{
	Queue<int> s(3);
	s.push_front(1);
	s.push_front(2);
	s.push_front(3);
	s.push_front(1);
	int a[4] = { 1, 2, 3, 1 };
	for (int i : a) {
		if (i != s.getBottom())
			ADD_FAILURE();
		s.pop_back();
	}
	EXPECT_TRUE(true);
}

TEST(Queue, works_correctly_when_push_element_with_capacity_exceeded_bottom_is_greater_than_top)
{
	Queue<int> s(3);
	s.push_front(1);
	s.push_front(2);
	s.push_front(3);
	s.pop_back();
	s.push_front(1);
	s.push_front(1);
	int a[4] = { 2, 3, 1, 1 };
	for (int i: a) {
		if (i != s.getBottom())
			ADD_FAILURE();
		s.pop_back();
	}
	EXPECT_TRUE(true);
}



