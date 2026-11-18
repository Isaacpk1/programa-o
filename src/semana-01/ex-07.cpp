#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m, k, saida = 0;

    cin >> n >> m >> k;

    vector<int> vn(n), vm(m);
    for (int a = 0; a < n; a++){
        cin >> vn[a];
    }
    for (int b = 0; b < m; b++){
        cin >> vm[b];
    }
    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());

    int i = 0, j = 0;

    while (i < n && j < m){
        long long dif_sup = vn[i] + k, dif_inf = vn[i] - k;

        if (dif_inf <= vm[j] && vm[j] <= dif_sup){
            i++;
            j++;
            saida++;
        }
        else if(vm[j] < dif_inf){
            j++;
        }
        else{
            i++;
        }
    }
    cout << saida <<"\n";
    return 0;
}