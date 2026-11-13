#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long a, acumulador = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        acumulador += a;
    }
    cout << acumulador <<"\n";
    return 0;
}