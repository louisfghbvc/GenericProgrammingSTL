#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <string.h>
#include <string>
#include <set>
using namespace std;

const int mod=1e9;
int main(){
    int N, M, length, i, j;
    srand( time( NULL ) );
    int A[5]={1000, 5000, 10000, 50000, 100000},B[3]={100, 500, 1000};
    for(int k=0;k<6;k++)
    {
    	for(int l=0;l<3;l++)
    	{
            N=A[k];
    		M=B[l];
    	    string name= "N"+to_string(N)+"M"+to_string(M);
            ofstream out (name+".in");

			for( i = 0; i < N; i++ ){
				   multiset<int> group;
				for( j = 0; j < M; j++ ){
					group.insert(rand()%mod);
				}
				for(auto B:group)
                    out<<B++<<" ";
                out << endl;
			}
	    out<<0<<" "<<0;
            out.close();
    	}
    }
    cout<<"end"<<endl;
    return 0;
}
