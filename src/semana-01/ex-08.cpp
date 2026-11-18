#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x;
    bool tem_resp = false;
    cin >> n >> x;

    vector<pair<int, int>> vect(n);

    for (int i = 0; i< n; i++){
        cin >> vect[i].first;
        vect[i].second = i+1; 
    }
    
    sort(vect.begin(), vect.end());
    long long i= 0, j = n-1;

    while (i != j){
        if (vect[i].first + vect[j].first == x){
            cout << vect[i].second << " " << vect[j].second << "\n";
            tem_resp = true;
            break;
        }
        else if (vect[i].first + vect[j].first > x){
            j--;
        }
        else{
            i++;
        }
    }
    if (!tem_resp){
        cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}