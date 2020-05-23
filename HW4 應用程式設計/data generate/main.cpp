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
    int N, M, i, j;
    srand( time( NULL ) );
    int A[5]={1000, 5000, 10000, 50000, 100000},B[3]={100, 500, 1000};
    for(int k=0;k<5;k++)
    {
    	for(int l=0;l<3;l++)
    	{
            N=A[k];
    		M=B[l];
    	    string name= "N"+to_string(N)+"M"+to_string(M);
            ofstream out (name+".in");

			for( i = 0; i < N; i++ ){
				for( j = 0; j < M; j++ ){
					out << rand()% mod << " ";
				}
                out << endl;
			}
            out << 0 << " " << 0 << "\n";
            out.close();
    	}
    }
    cout<<"end"<<endl;
    return 0;
}
