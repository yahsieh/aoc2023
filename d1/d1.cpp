#include <bits/stdc++.h>
using namespace std;
int parse(string_view s, unordered_map<string,int> const & mp) {
    int l = 0, r = 0, rl = 0, rr = 0;
    bool first = true;
    while (r<s.size()) {
        if (s[r] >= '0' && s[r] <= '9') {
            if (first) {
                rl = rr = s[r]-'0';
                first = false;
            } else {
                rr = s[r]-'0';
            }
            ++r;
            l=r;
        } else {
            int tmp = l;
            while (r-tmp+1>=3) {
                string sub = string{s.substr(tmp, r-tmp+1)};
                auto it = mp.find(sub);
                if (it != mp.end()) {
                    if (first) {
                        rl = rr = it->second;
                        first = false;
                    } else {
                        rr = it->second;
                    }
                    l = tmp+1;
                    break;
                }
                ++tmp;
            }
            ++r;
        }
    }
    cerr << "string = " << s << ", parse = "<< rl*10+rr<<endl;
    return rl*10+rr;
}
int main(){
    string s = "";
    unordered_map<string, int> mp;
    mp["one"] = 1; mp["two"] = 2; mp["three"] = 3; mp["four"] = 4; mp["five"] = 5;
    mp["six"] = 6; mp["seven"] = 7; mp["eight"] = 8; mp["nine"] = 9;
    int cnt = 0;
    ifstream cin("in");
    while(cin>>s){
        cnt += parse(s, mp);
    }
    cout << "cnt = "<< cnt << endl;
    return 0;
}

