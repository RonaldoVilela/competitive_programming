/* -----

    Problem name: Distinct Values Subarrays II
    Problem link: https://cses.fi/cghy9c4cc/task/2428

    Time complexity: O(n)
    Space compexity: O(n)

    Approach: use two pointers(i and f) to iterate through the array and calculate the possible number of subarrays between i and f, also
    using a unordered_map to keep track of the checked numbers ocurrences, if the size of keys of the map(distinct values) exceed K,
    the i pointer is ajusted until the number of keys is below or equal K;

    by: Ronaldo Vilela

----- */

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> v(n);

    {
        for(int i = 0; i  < n; i++){
            cin >> v[i];
        }
    }

    unordered_map<ll, int> m;

    {
        int i = 0;
        int f = 0;

        ll cnt = 0;

        while(f < n){

            m[v[f]]++;
            
            while(m.size() > k){
                m[v[i]]--;
                if(m[v[i]] == 0){m.erase(v[i]);}
                i++;
            }

            cnt += f-i+1;

            f++;
        }
        cout << cnt << endl;
    }
    


    return 0;
}