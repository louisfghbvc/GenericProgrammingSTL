#include <bits/stdc++.h>

using namespace std;

bool isSquare(tuple<int, int, int, int> square){
    if(get<0>(square) != get<1>(square) || get<1>(square) != get<2>(square) || get<2>(square) != get<3>(square))
        return false;
    if(get<0>(square) < 0 || get<1>(square) < 0 || get<2>(square) < 0 || get<3>(square) < 0)
        return false;
    return true;
}

int main()
{
    vector<pair<int, int>> point;
    tuple<int, int, int, int> square;

    for(int i = 0; i < 3; ++i){
        int x, y;
        cin >> x >> y;
        point.push_back({x, y});
    }

    sort(point.begin(), point.end());

    for(auto &p : point)
        cout << p.first << " " << p.second << endl;

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    square = make_tuple(a, b, c, d);

    puts(isSquare(square) ? "Yes" : "No");

    return 0;
}
