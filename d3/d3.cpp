#include <bits/stdc++.h>
using namespace std;

int64_t parse(int r, int c, vector<string> const & in, vector<vector<bool>> & visit) {
    //  cerr << "(r, c) = "<<r << ", " << c << endl;
    while (c >= 0 && in[r][c] >= '0' && in[r][c] <= '9') {
        --c;
    }
    ++c;
    // cerr << "left = "<<c<<endl;
    string s = "";
    while (c < in[r].size() && in[r][c] >= '0' && in[r][c] <= '9') {
        s += in[r][c];
        visit[r][c] = true;
        ++c;
    }
    // cerr << "right = "<<c<<endl;
    // cerr << "parsed string = "<<s << endl;
    return stoll(s);
}

int64_t calc(vector<string> const & in) {
    int R = in.size(), C = in[0].size();
    int64_t total = 0LL;
    int dir[8][2] = {{-1,1},{-1,0},{-1,-1},{0,1},{0,-1},{1,1},{1,0},{1,-1}};
    for (int r=0;r<R;r++) {
        for (int c=0;c<C;c++) {
            if ((in[r][c] >= '0' && in[r][c] <= '9') || in[r][c] == '.') {
                continue;
            }
            auto visit = vector(R, vector<bool>(C));
            vector<int64_t> adj;
            for (auto [a,b]: dir) {
                int nr = r + a, nc = c + b;
                if (nr >= 0 && nc >= 0 && nr < R && nc < C ) {
                    if (in[nr][nc] >= '0' && in[nr][nc] <= '9' && !visit[nr][nc]) {
                        adj.emplace_back(parse(nr, nc, in, visit));
                    }
                }
            }
            if (adj.size() == 2) {
                cerr << adj[0] <<" * "<<adj[1] << " = "<<adj[0]*adj[1] <<endl;
                total += adj[0] * adj[1];
            }
        }
    }
    return total;
}

int main() {
    ifstream cin("in");
    string s;
    vector<string> input;
    while (getline(cin, s)){
        if (!s.empty()) input.emplace_back(s);
    }
    cout << "ans = " << calc(input) << endl;
    return 0;
}
