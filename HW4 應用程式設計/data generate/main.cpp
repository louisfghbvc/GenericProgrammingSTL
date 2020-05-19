#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9;
const int N = 501;
const int X = 5000;

int main()
{
    freopen("input.txt", "w", stdout);
    srand(time(NULL));

    set<int,less<int>> A;

    int data_num = 10;
    int m, n, x;
    for(int i = 0; i < data_num; ++i){
        m = rand() % N;
        n = rand() % N;
        cout << m << " " << n << endl;
        for(int j = 0; j < m; j++){
            while(A.size()!=n)
                A.insert(rand()%mod);
            for(auto B:A)
               cout<<B++<<" ";
            cout << endl;
            A.clear();
        }
    }
    cout << "0 0\n";
    return 0;
}
