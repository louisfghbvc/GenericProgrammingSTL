#include <bits/stdc++.h>
#define N 505
//#define time
using namespace std;

vector<multiset<int>> Groups;
vector<int> graph[N];
vector<int> dep;
vector<bool> vis;
vector<int> nxt;

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
    nxt.clear();
    nxt.resize(m, mod);
}

int dfs(int u){
    if(vis[u]) return dep[u];
    vis[u] = 1;
    int uDep = 1;
    for(const auto &v : graph[u]){
        int vDep = dfs(v);
        if(vDep+1 > uDep){
            uDep = vDep+1;
            nxt[u] = v;
        }
    }
    return dep[u] = uDep;
}

void print(int u){
    for(; u != mod; u = nxt[u]){
        cout << " " << u+1;
    }
}

int main()
{
    //freopen("input2.txt", "r", stdin);
    //freopen("output2.txt", "w", stdout);
    srand(time(NULL));
    while(cin >> m >> n, m + n){
        init();

#ifdef time
        clock_t t;
        float Time_total=0.0;
        t = clock();
#endif

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

#ifdef time
        t = clock() - t;
        cout << "input took " << t << " clicks (" << ((float) t)/CLOCKS_PER_SEC << " seconds).\n";
        Time_total+=((float) t)/CLOCKS_PER_SEC;
        t = clock();
#endif

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

#ifdef time
        t = clock() - t;
        cout << "compare each two group took " << t << " clicks (" << ((float) t)/CLOCKS_PER_SEC << " seconds).\n";
        Time_total+=((float) t)/CLOCKS_PER_SEC;
        t = clock();
#endif

        // every node run dfs
        for(int i = 0; i < m; ++i){
            if(!vis[i]){
                dfs(i);
            }
        }

#ifdef time
        t = clock() - t;
        cout << "every node run dfs took " << t << " clicks (" << ((float) t)/CLOCKS_PER_SEC << " seconds).\n";
        Time_total+=((float) t)/CLOCKS_PER_SEC;
        t = clock();
#endif

        // find max group
        int mx = 0, mxid = -1;
        for(int i = 0; i < m; ++i){
            if(dep[i] > mx){
                mx = dep[i];
                mxid = i;
            }
        }

#ifdef time
        t = clock() - t;
        cout << "find max group took " << t << " clicks (" << ((float) t)/CLOCKS_PER_SEC << " seconds).\n";
        Time_total+=((float) t)/CLOCKS_PER_SEC;

        t = clock();
#endif

        cout << mx;
        print(mxid);
        cout << endl;

#ifdef time
        t = clock() - t;
        cout << "Total took " << Time_total*1000 << " clicks (" << Time_total << " seconds).\n";
#endif

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
