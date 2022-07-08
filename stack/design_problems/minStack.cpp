#include <stdio.h>
#include <iostream>
using namespace std;

class Stack
{
private:
    const int max = 1000;
    int arr[max];
    int top;

public:
    Stack()
    {
        st_ptr = -1;
    }

    void push(int x)
    {
        if (st_ptr == max)
        {
            exit(1);
        }
        st_ptr++;
        arr[st_ptr] = x;
        return;
    }

    void pop()
    {
        if (st_ptr == -1)
        {
            exit(1);
        }
        else
        {
            st_ptr--;
            return;
        }
    }
    int top()
    {
        if (st_ptr == -1)
            exit(1) return arr[st_ptr];
    }
    bool isEmpty()
    {
        if (st_ptr == -1)
            return true;
        else
            return false;
    }
};
class MinStack : public Stack
{
private:
public:
    MinStack()
    {
        Stack minStack;
        Stack st;
    }

    void push(int x)
    {
        if (minStack.isEmpty())
        {
            minStack.push(x);
            st.push(x);
        }
        else
        {
            if (x < minStack.top())
            {
                minStack.push(x);
                st.push(x);
            }
            else
            {
                st.push(x);
            }
        }
    }

    void pop()
    {
        if (st.isEmpty())
            exit(1);
        else
        {
            if (st.top() == minStack.top())
            {
                st.pop();
                minStack.pop();
            }
            else
            {
                st.pop();
            }
        }
    }

    int getMin()
    {
        if (minStack.isEmpty())
            exit(1);
        return minStack.top();
    }
};


class MinStackOptimized : public Stack {
    private: 
        int min = INT_MAX;
        int dummy = 3;
    public:
        void push(int x) {
            if ( Stack.isEmpty() || x  < min) {
                min = x;
            }
            Stack.push(x*dummy + min);
        }

        void pop() {
            if (Stack.isEmpty()) {
                exit(1);
            }
            int x = Stack.top();
            Stack.pop();

            if (!st.isEmpty()){
                min = st.top()%dummy;
            }
            else {
                min = INT_MAX;
            }
            return x / dummy;

        }

        int getMin() {
            if (Stack.isEmpty()) {
                exit(1);
            }
            return min;
        }

}