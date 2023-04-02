#include <bits/stdc++.h>

vector<int> manacher(string s) {

    int len = s.length();
    vector<int> ans(len);
    int center = 0;
    int range = 0;
    ans[0] = 1;
    int loop = 0;

    for(int i = 1; i < len; i++) {
        int mirror;
        if(i > range) 
            mirror = -1;
        else {
            mirror = 2*center - i;
        }
        ans[i] = (mirror == -1 ? 1 : min(ans[mirror], (range-i)*2+1));
        int dif = ans[i]/2;
        int l = i-1-dif;
        int r = i+1+dif;
        while((l >= 0) && (r < len)) {

            if(s[l] == s[r]) {
                ans[i] += 2;
            }
            else 
                break;
            l--;
            r++;
        }
        if(i+ans[i] >= range) {
            center = i;
            range = center + ans[i]/2;
        }
    }
    cout << loop << endl;
    return ans;
}

int main() {
    manacher("Hello");
}