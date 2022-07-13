/**
 * @brief this is space efficient solution for two stacks
 * TC: O(1) for every operations
 * SC: O(1) 
 */
class TwoStacks {
    private:
        int t1,t2;
        int *arr;
        int size ;
    public :
        TwoStacks(int n) {
            size = n;
            arr = new int[size];
            t1 = -1;
            t2 = size;
        }

        void push1(int x) {
            if (t1 == t2 - 1)
            {
                cout << "Stack Overflow" << endl;
                return;
            }
            t1++;
            arr[t1] = x;
        }
        void push2(int x) {
            if (t2 == t1 + 1)
            {
                cout << "Stack Overflow" << endl;
                return;
            }
            t2--;
            arr[t2] = x;
        }

        void pop1() {
            if (t1 == -1)
            {
                cout << "Stack Underflow" << endl;
                return;
            }
            t1--;
        }

        void pop2() {
            if (t2 == size)
            {
                cout << "Stack Underflow" << endl;
                return;
            }
            t2++;
        }

        int top1() {
            if (t1 == -1)
            {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return arr[t1];
        }
        int top2() {
            if (t2 == size)
            {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return arr[t2];
        }
}