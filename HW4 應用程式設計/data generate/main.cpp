#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9;
const int N = 501;
const int X = 5000;
int main()
{
    freopen("input.txt", "w", stdout);
    srand(time(NULL));

    int data_num = 10;
    int m, n, x;
    for(int i = 0; i < data_num; ++i){
        m = rand() % N;
        n = rand() % N;
        cout << m << " " << n << endl;
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                x = rand()%mod;
                if(!k)
                    cout << x;
                else
                    cout << " " << x;
            }
            cout << endl;
        }
    }
    cout << "0 0\n";
    return 0;
}
