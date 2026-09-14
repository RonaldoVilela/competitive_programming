/* -----
    Problem name: Array Division
    Problem link: https://cses.fi/problemset/task/2162/

    Time complexity: O(n log(n))
    Space compexity: O(n)


    Approach: first we create a method to discover how many subarrays divisions we can form that the sum of each one of it's 
    elements does not exceed a given M, if we have a method that does that, we can just do binary search to find the maximum
    value of M in witch the number of possible divisions is K;

    Obs: A = array; max(A) <= M <= sum(A);

    by: Ronaldo Vilela

 ----- */

#include <bits/stdc++.h>

 
using namespace std;
using ll = unsigned long long;
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }

int subsWithMaxSum(vector<ll>&v, ll max){
    int subs = 0;
    int i = 0;
    for(int f = 1; f < v.size(); f++){
        if(v[f] - v[i] > max){
            i = f-1;
            subs++;
        }
    }
    if(i < v.size()-1){
        subs++;
    }
    return subs;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> v(n + 1);
    ll hi = 0;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        hi = max(hi, v[i]);
        v[i] += v[i-1];
    }

    ll i = hi;
    ll f = v.back();

    ll res = 0;

    while(i < f){
        ll m = i + (f-i)/2;

        int rc = subsWithMaxSum(v, m);
        
        if(rc <= k){
            f = m;
            
        }else{
            i = m+1;
            
        }

    }
   
    cout << i << endl;

    return 0;
}
