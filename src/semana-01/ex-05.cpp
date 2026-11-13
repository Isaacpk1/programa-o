#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,v;
    long long maior = -1000000000, comNegativo = 0, semNegativo = 0, contador = 0, maior_negativo = -1000000000;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> v;
        comNegativo += v;
        if (maior_negativo < v){
            maior_negativo = v;
        }
        if (v >= 0){
            semNegativo += v;
        }
        else{
            semNegativo = 0;
            contador += 1;
        }
        if (semNegativo > comNegativo){
            comNegativo = semNegativo;
            if (maior < comNegativo){
                maior = comNegativo;
            }
        }
        else{
            semNegativo = comNegativo;
            if (maior < semNegativo){
                maior = semNegativo;
            }
        }
    }
    if (contador == n){
        cout << maior_negativo << "\n";
    }
    else{
        cout << maior << "\n";
    }
    return 0;
}