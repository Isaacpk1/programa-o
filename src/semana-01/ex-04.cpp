#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long atual = 0, anterior = 0, contador = 0, diferenca;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> atual;
        diferenca = atual - anterior;
        if (diferenca < 0){
            contador += diferenca * -1;
            atual += diferenca * -1;
        }
        anterior = atual;
    }
    cout << contador << "\n";
    return 0;
}