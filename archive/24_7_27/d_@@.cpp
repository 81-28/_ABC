// https://atcoder.jp/contests/abc364/tasks/abc364_d

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define substring(s,l,r) s.substr(l,r-l)
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;
// using mint = modint998244353;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

int sum(const vector<int>& v) { return accumulate(all(v),0); }
ll sumLL(const vector<int>& v) { return accumulate(all(v),0LL); }
int sum(const set<int>& set) {
    vector<int> vec(all(set));
    return accumulate(all(vec),0);
}
ll sumLL(const set<int>& set) {
    vector<int> vec(all(set));
    return accumulate(all(vec),0LL);
}


int main() {
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    multiset<int> aset(all(a));
    rep(j,q) {
        int b,k;
        cin >> b >> k;
        auto it_l = aset.lower_bound(b);
        auto it_u = aset.upper_bound(b+1);
        it_u--;
        int diff_l = abs(*it_l-b);
        int diff_u = abs(*it_u-b);
        if (k == 1)
        {
            print(min(diff_l,diff_u));
            break;
        } else if (k == 2)
        {
            print(max(diff_l,diff_u));
            break;
        }
        int ans = 0;
        rep(i,k-2) {
            if (diff_l <= diff_u)
            {
                it_l++;
                diff_l = abs(*it_l-b);
                ans = diff_l;
            } else {
                it_u--;
                diff_u = abs(*it_u-b);
                ans = diff_u;
            }
        }
        print(ans);
    }


    return 0;
}
