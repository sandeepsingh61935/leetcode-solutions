/**
 * @file StackUsingQueues.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * @solution1 :
 *    1. make push operation costly:
 *          1.1. push to queue2
 *          1.2. pop from queue1 and push everything to queue2
 *          1.3. swap queue1 and queue2
 *    2. pop operation:
        2.1: pop from queue1

    @solution2:
        1. make pop operation costly:
                1.1. pop everything from queue1, except the last element and push them to queue2
                1.2. store the last element as result and pop it.
                1.3. swap queue1 and queue2
        2. push operation:
                2.1: push into queue1
    @solution 3:
        1. implement a stack with a queue
        2. push into queue and pop from queue till last pushed element and repush into the queue.
        3. pop from queue
 */

class StackUsingQueue {
    private: 
        queue<int> q;
        int cur_size;
    public:
        StackUsingQueue() {
            cur_size = 0;
        }
        void push(int x) {
            q.push(x);
            cur_size++;
            while(q.front() != x) {
                q.push(q.front());
                q.pop();
            }
        }
        void pop() {
            if (cur_size == 0)
                return;
            q.pop();
            cur_size--;
        }

        int top() {
            if (cur_size == 0)
                return -1;
            return q.front();
        }
};