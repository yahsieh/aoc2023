#include <bits/stdc++.h>
using namespace std;
using dat = array<int,3>; // red, green, blue

vector<string> split(string_view s, string delim) {
    size_t pos;
    string tok;
    vector<string> ret;
    constexpr auto N = string_view::npos;
    while ( (pos = s.find(delim)) != N ) {
        ret.emplace_back( s.substr(0, pos) );
        s.remove_prefix(pos + delim.size());
    }
    ret.emplace_back(s);
    return ret;
}

dat parseSub(string_view s) {
    string color;
    int num;
    dat res{0,0,0};
    auto v = split(s, ",");
    for (auto const & sub: v) {
        stringstream ss(sub);
        ss >> num >> color;
        if (color == "red") {
            res[0] += num;
        } else if (color == "green") {
            res[1] += num;
        } else if (color == "blue") {
            res[2] += num;
        }
    }
    return res;
}
dat parse(string_view s) {
    auto next = s.find(':');
    s.remove_prefix(next+1);
    int r=0,g=0,b=0;
    auto v = split(s, ";");
    for (auto const & q: v) {
        auto subAns = parseSub(q);
        r = max(r, subAns[0]);
        g = max(g, subAns[1]);
        b = max(b, subAns[2]);
    }
    cerr << "rgb = "<<r << ", " << g << ", " << b << endl;
    return dat{r, g, b};
}

bool ok(dat const & ask) {
    return ask[0] <= 12 && ask[1] <= 13 && ask[2] <= 14;
}

int main() {
    string s;
    int id = 1, ans = 0;
    int64_t total = 0LL;
    ifstream cin("test");
    while(getline(cin, s)){
        auto q = parse(s);
        total += (int64_t)q[0] * q[1] * q[2];
        if (ok(q)) {
            ans += id;
        }
        ++id;
    }
    cout << "ans = "<< ans << endl;
    cout << "total = " << total << endl;
    return 0;
}
