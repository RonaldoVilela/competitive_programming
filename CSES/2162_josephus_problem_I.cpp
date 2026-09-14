/* -----
    Problem name: Josephus Problem I
    Problem link: https://cses.fi/problemset/task/2162

    Time complexity: O(n)
    Space compexity: O(n)

    obs: we just have to alternate beteen skipping and removing someone until the circle is empty;

    Approach: Use a stack to send the elements being skipped to the end, and removing
    the ones we are supposed to at the front, making both the removal and the skipping O(1);

    by: Ronaldo Vilela

 ----- */

 #include <bits/stdc++.h>

 using namespace std;

 int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    bool is_first = true;
    while(q.size()>0){

        q.push(q.front());
        q.pop();

        if(is_first){is_first = false;}else{
            cout << " ";
        }
        cout << q.front();
        q.pop();
    }

    cout << endl;

    return 0;
 }
