#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> child(n);
    for (int i = 0; i < n; i++) cin >> child[i];
    
    sort(child.begin(), child.end());
    
    int i = 0, j = n - 1;
    int count = 0;
    
    while (i <= j) {
        if (child[i] + child[j] <= m) {
            i++;
            j--;
        } else {
            j--;
        }
        count++;
    }
    
    cout << count << "\n";
    return 0;
}
