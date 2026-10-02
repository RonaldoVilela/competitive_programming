/* -----

    Problem name: Book Shop
    Problem link: https://cses.fi/problemset/task/1158/

    Time complexity: 0(n * x)
    Space complexity: 0(x)
    
    by: Ronaldo Vilela de Souza Pereira

-----*/


#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

template<class T> void Vin(vector<T>& v){ for (auto& x : v) cin >> x; }
template<typename T> void Vout(const vector<T>& v) {if (v.empty()) return;
    for (int i = 0; i < v.size(); ++i)cout << v[i] << " \n"[i == v.size() - 1];}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);

    Vin(price);
    Vin(pages);

    //Vout(price);
    //Vout(pages);

    vector<int> dp(x+1);

    for(int i = 0; i < n; i++){

        // test if each dp can buy this i-th book (and if is worth it)
        for(int f = x; f > 0; f--){

            if(price[i] > f){continue;}

            // i see the page number i get when buying the i-th book plus the max amount of pages i can
            // buy with the remaining money (f - price[i]);

            // if is not higher than the last book checked i just ignore it;

            dp[f] = max(dp[f], pages[i] + dp[f - price[i]]);
        }
    }

    cout << dp[x] << endl;


    return 0;
}