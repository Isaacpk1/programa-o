#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, t;

    cin >> n >> t;

    vector<int> v(n), pre(n+1, 0);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        pre[i+1] = v[i] + pre[i];
    }
    long long maior = 0, r;

    for (int j = 0; j < n+1; j++){
        long long limite = pre[j] + t;
        r = upper_bound(pre.begin(), pre.end(), limite) - pre.begin() - 1;
        maior = max(maior, r-j);
    }
    cout << maior << "\n";
    return 0;
}