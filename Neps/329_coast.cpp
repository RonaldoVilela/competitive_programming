/* -----
    Problem name: Coast
    Problem link: https://neps.academy/exercise/329

    Time complexity: O(n)
    Space compexity: O(n)

    by: Ronaldo Vilela
 ----- */

#include <bits/stdc++.h>

 
using namespace std;
using ll = unsigned long long;
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }

ll parse_coord(ll x, ll y, int m){
    return (m+1)*x + y;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<ll, pair<ll, ll>> s;

    string line;
    for(int y = 0; y < m; y++){
        cin >> line;
        for(int x = 0; x < n; x++){
            if(line[x] == '#'){
                s.insert(make_pair(parse_coord(x, y, m), pair{x, y}));
            }
        }
    }

    ll coasts = 0;

    for(auto land : s){
        if(!s.count(parse_coord(land.second.first-1, land.second.second, m))){
            coasts++;
            continue;
        }
        if(!s.count(parse_coord(land.second.first+1, land.second.second, m))){
            coasts++;
            continue;
        }
        if(!s.count(parse_coord(land.second.first, land.second.second-1, m))){
            coasts++;
            continue;
        }
        if(!s.count(parse_coord(land.second.first, land.second.second+1, m))){
            coasts++;
            continue;
        }
    }

    cout << coasts << endl;

    return 0;
}

