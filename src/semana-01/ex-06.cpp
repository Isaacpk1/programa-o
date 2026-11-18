#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, diferente = 1;

    cin >> a;
    vector<int> vetor(a);
    for (int i = 0; i < a; i++){
        cin >> vetor[i];
    }
    sort(vetor.begin(), vetor.end());
    for (int n = 1; n < a; n++){
        if (vetor[n] != vetor[n-1]){
            diferente += 1;
        }
    }
    cout << diferente << "\n";
    return 0;
}