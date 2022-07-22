class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove >= 0) {
            if (startColumn == -1 || startColumn == n || startRow == -1 || startRow == m) {
                return 1;
            }
            return 0;
        }
        else if (maxMove <0) return 0;
        else 
            return  findPaths(m, n, maxMove-1, startRow, startColumn-1) 
                    + findPaths(m, n, maxMove-1, startRow, startColumn+1) 
                    + findPaths(m, n, maxMove-1, startRow-1, startColumn) 
                    + findPaths(m, n, maxMove-1, startRow+1, startColumn);

    }
};