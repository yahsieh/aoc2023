#include <bits/stdc++.h>
using namespace std;

vector<string> split(string_view s, string const & delim) {
    constexpr auto N = string_view::npos;
    string tok;
    vector<string> result;
    size_t pos;
    while ( ( pos = s.find(delim) ) != N ) {
        result.emplace_back( s.substr(0, pos) );
        s.remove_prefix(pos+delim.size());
    }
    result.emplace_back( s );
    return result;
}

int main() {
    string s;
    ifstream cin("in");
    int64_t id = 1;
    int64_t win = 0LL;
    int64_t total = 0LL;
    int64_t rb = 1;
    vector<int> rbv; // rbv[1] = 5 -> 1: 2,3,4,5,6
    vector<int> memo;
    rbv.emplace_back(0); // rbv[0] = 0
    while (getline(cin, s)) {
        if (s.empty()) continue;
        int64_t cnt = 0;
        string_view view = s;
        view.remove_prefix(view.find(':')+1);
        auto v = split(view, "|");
        unordered_set<int> lucky;
        stringstream ss(v[0]), have(v[1]);
        int num;
        while (ss>>num) lucky.insert(num);
        while (have>>num) {
            if (lucky.find(num) != lucky.end()) {
                ++cnt;
            }
        }
        rbv.emplace_back(cnt);
        ++id;
    }
    memo.resize(rbv.size());
    for (int i = rbv.size()-1 ; i>=1; i--) {
        memo[i] = 1;
        for (int j = 1; j <= rbv[i]; j++ ){
            memo[i] += memo[i+j];
        }
        total += memo[i];
    }
    // for (auto elem: rbv) cout << elem << " "; cout << endl;
    // for (auto elem: memo) cout << elem << " "; cout << endl;
    cout << "total = " << total << endl;
    return 0;
}
