#include<bits/stdc++.h>
using namespace std;

int main() {


    int t ;
    const int dir_x[8] = {1,1,-1,-1,2,2,-2,-2};
    const int dir_y[8] = {2,-2,-2,2,1,-1,1,-1};
    cin >> t;
    while(t--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2 || y1 == y2) {
            cout << "YES" << endl;
        }
        else {
            int x = x2 - x1;
            int y = y2 - y1;
            int i = 0;
            while(i < 8){
                if(x == dir_x[i] && y == dir_y[i]){
                    cout << "YES" << endl;
                    break;
                }
                i++;
            }
            if(i == 8){
                cout << "NO" << endl;
            }
        }
        
    }
    return 0;
}