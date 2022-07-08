/***
 * @problem statemet
 * 
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.




Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true    


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/



// Complexity: TC: O(N*M) SC: O(N*M)

class Solution {
public:
    bool isInterleave(string A, string B, string C) {
        int M = (A).length(), N = (B).length(); 
  
    // Let us create a 2D table to store solutions of 
    // subproblems.  C[i][j] will be true if C[0..i+j-1] 
    // is an interleaving of A[0..i-1] and B[0..j-1]. 
    bool IL[M + 1][N + 1]; 
  
    memset(IL, 0, sizeof(IL)); // Initialize all values as false. 
  
    // C can be an interleaving of A and B only of sum 
    // of lengths of A & B is equal to length of C. 
    if ((M + N) != (C).length()) 
        return false; 
  
    // Process all characters of A and B 
    for (int i = 0; i <= M; ++i) { 
        for (int j = 0; j <= N; ++j) { 
            // two empty strings have an empty string 
            // as interleaving 
            if (i == 0 && j == 0) 
                IL[i][j] = true; 
  
            // A is empty 
            else if (i == 0) { 
                if (B[j - 1] == C[j - 1]) 
                    IL[i][j] = IL[i][j - 1]; 
            } 
  
            // B is empty 
            else if (j == 0) { 
                if (A[i - 1] == C[i - 1]) 
                    IL[i][j] = IL[i - 1][j]; 
            } 
  
            // Current character of C matches with current character of A, 
            // but doesn't match with current character of B 
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) 
                IL[i][j] = IL[i - 1][j]; 
  
            // Current character of C matches with current character of B, 
            // but doesn't match with current character of A 
            else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
                IL[i][j] = IL[i][j - 1]; 
  
            // Current character of C matches with that of both A and B 
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
                IL[i][j] = (IL[i - 1][j] || IL[i][j - 1]); 
        } 
    } 
  
    return IL[M][N]; 
    }
};




// solution 2 :


// TC: O(N*M) SC: O(M)

class Solution {
    public :
    bool isInterleave(string a ,string b , string str) {
        int a_len = a.length();
        int b_len = b.length();
        int c_len = c.length();

        if (a_len + b_len != c_len) return false;

        vector<vector<bool>> cur(b_len + 1,false));
        vector<vector<bool>> cur(b_len + 1,false));

        // b string is empty
        if (b_len == 0 && a_len != c_len) return false;
        if (a_len == 0 && b_len != c_len) return false;
        dp[0][0] = true;
        for (int i = 1; i <= a_len; i++) {
            if (a[i-1] == c[i-1]) 
                dp[i][0] = dp[i - 1][0];
        }   

        for(int j = 1; j <= b_len; j++) {
            if (b[j-1] == c[j-1]) 
                dp[0][j] = dp[0][j - 1];
        }

        for(int i = 1; i <= a_len; i++) {
            for(int j = 1; j <= b_len; j++) {
                if (a[i-1] == c[i + j-1]) 
                    dp[i][j] = dp[i - 1][j];
                if (b[j-1] == c[i + j-1]) 
                    dp[i][j] = dp[i][j - 1];
                if (a[i-1] == c[i + j-1] && b[j-1] == c[i + j -1]) 
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }

        return dp[a_len][b_len];
    }
}