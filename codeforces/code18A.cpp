#include <bits/stdc++.h>

using namespace std;

bool IsRight(vector<pair<int,int>>& verts) {

    for(int i = 0; i < 3; i++) {

        int j = (i + 1) % 3;
        int k = (i + 2) % 3;

        int a = verts[j].first  - verts[i].first;
        int b = verts[j].second - verts[i].second;

        int c = verts[k].first  - verts[i].first;
        int d = verts[k].second - verts[i].second;

        if(a*d - b*c == 0)
            continue;

        if(a*c + b*d == 0)
            return true;
    }

    return false;
}

int main() {

    ios::sync_with_stdio(0);cin.tie(0);

    vector<pair<int,int>> verts(3);

    for(int i = 0; i < 3; i++)
        cin >> verts[i].first >> verts[i].second;

    // Já é retângulo?
    if(IsRight(verts)) {
        cout << "RIGHT\n";
        return 0;
    }

    for(int i = 0; i < 3; i++) {

        verts[i].first++;
        if(IsRight(verts)) {
            cout << "ALMOST\n";
            return 0;
        }

        verts[i].first -= 2;
        if(IsRight(verts)) {
            cout << "ALMOST\n";
            return 0;
        }

        verts[i].first++;

        verts[i].second++;
        if(IsRight(verts)) {
            cout << "ALMOST\n";
            return 0;
        }

        verts[i].second -= 2;
        if(IsRight(verts)) {
            cout << "ALMOST\n";
            return 0;
        }

        verts[i].second++;
    }

    cout << "NEITHER\n";
}
