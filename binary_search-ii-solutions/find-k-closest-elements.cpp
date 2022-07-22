/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = size(arr), R = lower_bound(begin(arr), end(arr), x) - begin(arr), L = R - 1;
		// expand the [L, R] window till its size becomes equal to k
        while(k--) 
            if(R >= n || L >= 0 && x - arr[L] <= arr[R] - x) L--;  // expand from left
            else R++;             
        // expand from right
        cout <<  L  << " " << R <<endl;
        return vector<int>(begin(arr) + L + 1, begin(arr) + R);
    }
};