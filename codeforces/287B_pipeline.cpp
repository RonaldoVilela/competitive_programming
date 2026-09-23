/*
    Problem link: https://codeforces.com/problemset/problem/287/B
    Problem name: Pipeline
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll pipesWithSplitters(ll k, ll pipes){
    return 1+pipes*(k-1) - pipes*(pipes-1)/2;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    ll n;
    cin >> n;

    ll k;
    cin >> k;


    ll i = 0;
    ll f = k;
    ll res = -1;


    while(i <= f){
        ll m = i + (f-i)/2;
        if(pipesWithSplitters(k, m) >= n){
            res = m;
            f = m-1;
        }else{
            i = m+1;
        }
    }
    
    cout << res << endl;

    return 0;
}