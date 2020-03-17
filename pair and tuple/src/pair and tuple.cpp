//============================================================================
// Name        : pair.cpp
// Author      : louis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>

using namespace std;

bool isSquare(tuple<int, int, int, int> square){
    if(get<0>(square) != get<1>(square) || get<1>(square) != get<2>(square) || get<2>(square) != get<3>(square))
        return false;
    if(get<0>(square) < 0 || get<1>(square) < 0 || get<2>(square) < 0 || get<3>(square) < 0)
        return false;
    return true;
}

int main() {
	//pair pratice
	vector<pair<int, int>> point;

	for(int i = 0; i < 3; ++i){
	        int x, y;
	        cin >> x >> y;
	        point.push_back({x, y});
	}

    sort(point.begin(), point.end());

    for(auto &p : point)
        cout << p.first << " " << p.second << endl;

    //tuple pratice
    tuple<int, int, int, int> square;

    int a, b, c, d;
	cin >> a >> b >> c >> d;

	square = make_tuple(a, b, c, d);

	puts(isSquare(square) ? "Yes" : "No");

	return 0;
}
