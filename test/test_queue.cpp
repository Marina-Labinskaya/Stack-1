#include "stack.h"

#include <gtest.h>

TEST(TQueue, can_create_empty_queue)
{
  ASSERT_NO_THROW(Queue<int> q);
}

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(Queue<int> q(4));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
  ASSERT_ANY_THROW(Queue<int> q(-2));
}

TEST(TQueue, can_create_queue_with_max_size)
{
  ASSERT_NO_THROW(Queue<int> q(MAX_SIZE));
}

TEST(TQueue, cant_create_too_large_queue)
{
  ASSERT_ANY_THROW(Queue<int> q(MAX_SIZE + 1));
}

TEST(TQueue, can_create_copied_queue)
{
  Queue<int> q1(3);
  ASSERT_NO_THROW(Queue<int> q2(q1));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	Queue<int> q1(3);
	Queue<int> q2(q1);
	EXPECT_EQ(q1,q2);
}

TEST(TQueue, copied_queue_has_its_own_memory)
{
	Queue<int> q1(3);
	Queue<int> q2(q1);
	EXPECT_NE(&q1[0], &q2[0]);
}

TEST(TQueue, can_get_start_elem_of_queue)
{
	Queue<int> q(3);
	q[0]=3; q[1]=5; q[2]=7;
	EXPECT_EQ(3, q.front());
}

TEST(TQueue, cant_get_start_elem_of_empty_queue)
{
	Queue<int> q;
	ASSERT_ANY_THROW(q.front());
}

TEST(TQueue, can_get_end_elem_of_queue)
{
	Queue<int> q(3);
	q[0]=3; q[1]=5; q[2]=7;
	EXPECT_EQ(7, q.back());
}

TEST(TQueue, cant_get_end_elem_of_empty_queue)
{
	Queue<int> q;
	ASSERT_ANY_THROW(q.back());
}

TEST(TQueue, can_detect_empty_queue)
{
	Queue<int> q;
	EXPECT_EQ(true, q.empty());
}

TEST(TQueue, can_detect_not_empty_queue)
{
	Queue<int> q(3);
	q[0]=1; q[1]=3; q[2]=5;
	EXPECT_EQ(false, q.empty());
}

TEST(TQueue, can_detect_full_queue_when_start_is_null_elem)
{
    Queue<int> q(2);
	q[0]=1; q[1]=3; q.push(5);
	EXPECT_EQ(true, q.full());
}

TEST(TQueue,  can_detect_full_queue_when_start_is_not_null_elem)
{
	Queue<int> q(2);
	q[0]=1; q[1]=3; q.pop(); q.push(5); q.push(7);
	EXPECT_EQ(true, q.full());
}
TEST(TQueue, can_detect_not_full_queue)
{
	Queue<int> q(2);
	q[0]=1; q[1]=3;
	EXPECT_EQ(false, q.full());
}

TEST(TQueue, can_resize_queue)
{
	Queue<int> q;
	ASSERT_NO_THROW(q.resize(4));
}

TEST(TQueue, can_push_elem_in_not_full_queue)
{
	Queue<int> q(2);
	q[0]=3; q[1]=5;
    ASSERT_NO_THROW(q.push(7));
}

TEST(TQueue, push_changes_end_pointer)
{
	Queue<int> q(2);
	q[0]=3; q[1]=5;
    q.push(7);
	EXPECT_EQ(7,q.back());
}

TEST(TQueue, can_push_elem_in_full_queue)
{
	Queue<int> q;
	ASSERT_NO_THROW(q.push(2));
}

TEST(TQueue, push_in_null_index_if_queue_is_not_full_chandes_end_pointer)
{
	Queue<int> q(2);
	q[0]=1; q[1]=3; q.pop(); q.push(5); q.push(7);
	EXPECT_EQ(7,q.back());
}
TEST(TQueue, cant_pop_in_empty_queue)
{
	Queue<int> q;
	ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, can_pop_elem)
{
	Queue<int> q(2);
	q[0]=3; q[1]=5;
	ASSERT_NO_THROW(q.pop());
}

TEST(TQueue, pop_changes_start_pointer)
{
	Queue<int> q(2);
	q[0]=3; q[1]=5;
    q.pop();
	EXPECT_EQ(5,q.front());
}