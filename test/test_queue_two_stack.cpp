#include "stack.h"

#include <gtest.h>

TEST(TQueueTwoStack, can_create_empty_queue)
{
  ASSERT_NO_THROW(QueueTwoStack<int> q);
}

TEST(TQueueTwoStack, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(QueueTwoStack<int> q(4));
}

TEST(TQueueTwoStack, cant_create_queue_with_negative_length)
{
  ASSERT_ANY_THROW(QueueTwoStack<int> q(-2));
}

TEST(TQueueTwoStack, can_create_copied_queue)
{
  QueueTwoStack<int> q1(3);
  ASSERT_NO_THROW(QueueTwoStack<int> q2(q1));
}

TEST(TQueueTwoStack, can_detect_empty_queue)
{
	QueueTwoStack<int> q;
	EXPECT_EQ(true, q.empty());
}

TEST(TQueueTwoStack, can_detect_not_empty_queue)
{
	QueueTwoStack<int> q;
	q.push(2);
	EXPECT_FALSE(q.empty());
}

TEST(TQueueTwoStack, can_detect_not_full_queue)
{
	QueueTwoStack<int> q;
	q.resize(3);
	EXPECT_FALSE(q.full());
}

TEST(TQueueTwoStack, can_detect_full_queue)
{
	QueueTwoStack<int> q;
	q.push(2);
	EXPECT_TRUE(q.full());
}

TEST(TQueueTwoStack, can_push)
{
	QueueTwoStack <int> q;
	ASSERT_NO_THROW(q.push(5));
}

TEST(TQueueTwoStack, can_pop_with_empty_stack2)
{
	QueueTwoStack <int> q;
	q.push(2); q.push(3);
	ASSERT_NO_THROW(q.pop());
}

TEST(TQueueTwoStack, can_pop_with_not_empty_stack2)
{
	QueueTwoStack <int> q;
	q.push(2); q.push(3); q.pop();
	ASSERT_NO_THROW(q.pop());
}

TEST(TQueueTwoStack, can_get_size)
{
	QueueTwoStack<int> q;
	q.push(3);
	EXPECT_EQ(1, q.GetSize());
}

TEST(TQueueTwoStack, can_get_size_with_not_empty_stack2)
{
	QueueTwoStack<int> q;
	q.push(3); q.push(2); q.pop(); q.push(1);
	EXPECT_EQ(2, q.GetSize());
}

