#pragma once
#include "utqueue.h"

#include "gtest.h""

TEST(Queue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> q(5));
}

TEST(Queue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> q(-1));
}

TEST(Queue, can_return_front_element) {
	Queue<int> q(2);
	q.push(7);
	EXPECT_EQ(7, q.Front());
}

TEST(Queue, can_return_back_element) {
	Queue<int> q(2);
	q.push(1);
	q.push(3);
	q.pop();
	q.push(8);
	EXPECT_EQ(8, q.Back());
}

TEST(Queue, push_element_in_start_of_queue_if_queue_is_empty) {
	Queue<int> q(1);
	q.push(7);
	EXPECT_EQ(true, 7 == q[0]);
}

TEST(Queue, can_pop_element_from_queue) {
	Queue<int> q(2);
	q.push(2);
	q.push(10);
	q.pop();
	EXPECT_EQ(10, q.Back());
}

TEST(Queue, cant_do_pop_from_empty_queue) {
	Queue<int> q;
	ASSERT_ANY_THROW(q.pop());
}

TEST(Queue, return_true_when_queue_is_empty) {
	Queue<int> q;
	EXPECT_EQ(true, q.empty());
}

TEST(Queue, return_false_when_queue_isnt_empty) {
	Queue<int> q(3);
	q.push(2);
	EXPECT_EQ(false, q.empty());
}

TEST(Queue, return_true_when_queue_is_full) {
	Queue<int> q(2);
	q.push(2);
	q.push(2);
	EXPECT_EQ(true, q.full());
}

TEST(Queue, return_false_when_queue_isnt_full) {
	Queue<int> q(10);
	q.push(1);
	q.push(4);
	EXPECT_EQ(false, q.full());
}

TEST(Queue, right_algoritm) {
	Queue<int> q(6);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.pop();
	q.pop();
	q.push(7); 
	q.push(8);
	q.push(9);
	q.push(10);
	std::cout << std::endl;
	int res[] = { 3,4,5,6,7,8,9,10 };
	int i = 0;
	while (!q.empty()) {
		std::cout << "expected: " << res[i++] << " actual " << q.Pop() << std::endl;
	}
	std::cout << std::endl;
}
