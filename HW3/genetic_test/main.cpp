#include <iostream>

#include <vector>

#include <cstdlib>
#include <ctime>

#include <algorithm>

using namespace std;

int main()
{
    //Q1

    int case_num, gene_len, target_len;
    cin >> case_num >> gene_len >> target_len;

    vector<char> gene[case_num], target[case_num];
    char in[8] = {'A', 'C', 'G', 'T', 'a', 'c', 'g', 't'};

    int i, j;

    srand((unsigned)time(nullptr));

    for(i = 0; i < case_num; ++i){
        for(j = 0; j < gene_len; ++j)
            gene[i].push_back(in[rand()%8]);
        for(j = 0; j < target_len; ++j)
            target[i].push_back(in[rand()%8]);
    }

    cout << "\nGenerated test case(s):\n";
    for(i = 0; i < case_num; ++i){
        for(char out : gene[i])
            cout << out;
        cout << " ";
        for(char out : target[i])
            cout << out;
        cout << "\n";
    }

    //Q2

    cout << "\nAsked Output:\n";

    int ans;
    vector<char>::iterator curr_gene;

    for(i = 0; i < case_num; ++i){
        for(j = 0; j < 4; ++j){
            ans = 0;
            curr_gene = find(gene[i].begin(), gene[i].end(), in[j]);
            while(curr_gene != gene[i].end()){
                ++ans;
                curr_gene = find(curr_gene+1, gene[i].end(), in[j]);
            }
            if(j == 0)
                cout << ans;
            else
                cout <<  " " << ans;
        }
        cout << "\n";

        ans = 0;
        curr_gene = search(gene[i].begin(), gene[i].end(), target[i].begin(), target[i].end());
        while(curr_gene != gene[i].end()){
            cout << distance(gene[i].begin(), curr_gene) << " ";
            ++ans;
            curr_gene = search(curr_gene+1, gene[i].end(), target[i].begin(), target[i].end());
        }
        cout << ans << "\n";
    }

    return 0;
}
