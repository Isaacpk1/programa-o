#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, pa, a, acumulador = 0;

    cin >> n;
    pa = ((n+1)*n)/2;
    for (int i = 1; i < n; i++){
        cin >> a;
        acumulador += a;
    }
    cout << pa-acumulador << "\n";
}