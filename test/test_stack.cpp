#include "stack.h"

#include <gtest.h>

TEST(Stack, can_create_stack_with_positive_capacity)
{
  ASSERT_NO_THROW(Stack<int> m(5));
}

TEST(Stack, cant_create_too_large_matrix)
{
  //ASSERT_ANY_THROW(Stack<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(Stack, throws_when_create_stack_with_negative_capacity)
{
  ASSERT_ANY_THROW(Stack<int> m(-5));
}

TEST(Stack, can_create_copied_stack)
{
  Stack<int> m(5);

  ASSERT_NO_THROW(Stack<int> m1(m));
}

TEST(Stack, copied_stack_is_equal_to_source_one)
{
	Stack<int> s(3);
	s.push(1);
	s.push(2);
	s.push(3);
	Stack<int> z(s);
	bool f = true;
	for (int i = 0; i < 3; i++) {
		if (z.getTop() != s.getTop())
			ADD_FAILURE();
		s.pop();
		z.pop();
	}
	EXPECT_TRUE(f);

}

TEST(Stack, copied_stack_has_its_own_memory)
{
	Stack<int> s(3);
	s.push(1);
	s.push(2);
	s.push(3);
	Stack<int> z(s);
	z.pop();
	z.push(4);
	EXPECT_EQ(s.getTop(), 3);
}

TEST(Stack, can_get_size)
{
	Stack<int> s(3);
	s.push(1);
	s.push(2);
	EXPECT_EQ(2, s.getSize());
}

TEST(Stack, can_push_and_get_top_element)
{
	Stack<int> s(3);
	s.push(1);
	EXPECT_EQ(1, s.getTop());
}

TEST(Stack, works_correctly_when_push_element_with_capacity_exceeded)
{
	Stack<int> s(3);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(1);
	int a[4] = { 1, 3, 2, 1 };
	for (int i : a) {
		if (i != s.getTop())
			ADD_FAILURE();
		s.pop();
	}
	EXPECT_TRUE(true);
}

TEST(Stack, throws_when_pop_in_0_size_stack)
{
	Stack<int> s(3);
	EXPECT_ANY_THROW(s.pop());
}

TEST(Stack, throws_when_get_top_in_0_size_stack)
{
	Stack<int> s(3);
	EXPECT_ANY_THROW(s.getTop());
}

