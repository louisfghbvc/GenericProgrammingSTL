#include <bits/stdc++.h>
#define N 505
using namespace std;

vector<multiset<int>> Groups;
vector<int> graph[N];
vector<int> dep;
vector<bool> vis;
vector<int> par;

const int mod = 1e9;
int m, n;

void init(){
    for(int i = 0; i < m; ++i)
        graph[i].clear();
    Groups.clear();
    dep.clear();
    dep.resize(m, 1);
    vis.clear();
    vis.resize(m);
    par.clear();
    par.resize(m, -1);
}

void dfs(int u, int depth){
    dep[u] = depth;
    vis[u] = 1;
    for(const auto &v : graph[u]){
        if(dep[u]+1 > dep[v]){
            par[v] = u;
            dfs(v, dep[u]+1);
        }
    }
}

void print(int u){
    if(u == -1){
        return;
    }
    print(par[u]);
    cout << " " << u+1;
}

int main()
{
    //freopen("input1.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    srand(time(NULL));

    while(cin >> m >> n, m + n){
        init();

        // build input
        for(int i = 0; i < m; ++i){
            multiset<int> group;
            for(int j = 0; j < n; ++j){
                int t;
                cin >> t;
                group.insert(t);
            }
            Groups.push_back(group);
        }

        // lambda, group compare
        auto group_compare = [](const multiset<int> &A, const  multiset<int> &B){
            for(auto ai = A.begin(), bi = B.begin(); ai != A.end() && bi != B.end(); ++ai, ++bi){
                if(*ai <= *bi) return false;
            }
            return true;
        };

        // compare each two group
        for(int i = 0; i < (int)Groups.size(); ++i){
            for(int j = 0; j < (int)Groups.size(); ++j){
                if(i == j) continue;
                if(group_compare(Groups[i], Groups[j])){
                    // i next can be j
                    graph[i].push_back(j);
                }
            }
        }

        // every node run dfs
        for(int i = 0; i < m; ++i){
            if(!vis[i]){
                dfs(i, 1);
            }
        }

        // find max group
        int mx = 0, mxid = -1;
        for(int i = 0; i < m; ++i){
            if(dep[i] > mx){
                mx = dep[i];
                mxid = i;
            }
        }

        cout << mx;
        print(mxid);
        cout << endl;
    }
    return 0;
}
/**
input:
5 10
159 178 170 179 193 174 182 184 192 173
188 169 164 164 173 152 170 186 157 151
198 161 199 178 172 156 153 154 162 191
182 170 183 188 181 199 178 178 198 176
166 155 168 186 150 192 193 166 190 176
0 0
output:
3 4 1 2
**/
