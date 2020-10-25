#include "stack.h"

#include <gtest.h>


TEST(TStack, can_create_empty_stack)
{
  ASSERT_NO_THROW(Stack<int> s());
}

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(Stack<int> s(4));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(Stack<int> s(-2));
}

TEST(TStack, can_create_stack_with_max_size)
{
  ASSERT_NO_THROW(Stack<int> s(MAX_SIZE));
}

TEST(TStack, cant_create_too_large_stack)
{
  ASSERT_ANY_THROW(Stack<int> s(MAX_SIZE + 1));
}

TEST(TStack, can_get_top_of_stack)
{
	Stack<int> s(3);
	s[0]=1; s[1]=3; s[2]=5;
	EXPECT_EQ(5, s.top());
}

TEST(TStack, cant_get_top_of_empty_stack)
{
	Stack<int> s;
	ASSERT_ANY_THROW(s.top());
}

TEST(TStack, can_push_on_the_top_of_stack)
{
	Stack<int> s(3);
	s[0]=1; s[1]=3; s[2]=5;
	ASSERT_NO_THROW(s.push(2));
}

TEST(TStack, cant_push_if_size_larger_max_size)
{
	Stack<int> s(1000);
	ASSERT_ANY_THROW(s.push(2));
}

TEST(TStack, can_pop_the_top_of_stack)
{
	Stack<int> s(3);
	s[0]=1; s[1]=3; s[2]=5;
	ASSERT_NO_THROW(s.pop());
}

TEST(TStack, cant_pop_elem_in_empty_stack)
{
	Stack<int> s;
	ASSERT_ANY_THROW(s.pop());
}

TEST(TStack, can_detect_empty_stack)
{
	Stack<int> s;
	EXPECT_EQ(true, s.empty());
}

TEST(TStack, can_detect_not_empty_stack)
{
	Stack<int> s(3);
	s[0]=1; s[1]=3; s[2]=5;
	EXPECT_EQ(false, s.empty());
}

TEST(TStack, can_detect_full_stack)
{
	Stack<int> s(2);
	s[0]=1; s[1]=3; s.push(2);
	EXPECT_EQ(true, s.full());
}

TEST(TStack, can_detect_not_full_stack)
{
	Stack<int> s(2);
	s[0]=1; s[1]=3;
	EXPECT_EQ(false, s.full());
}

TEST(TStack, can_get_stack_size)
{
	Stack<int> s(5);
	EXPECT_EQ(5, s.GetSize());
}