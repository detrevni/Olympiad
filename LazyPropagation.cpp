// 1. Assign all elements value x from l to r
// 2. Sum of all elements from l to r
// Tested by problem http://codeforces.com/gym/100093 C

# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll>pll;

const ll maxN = ll(8e5);
const ll smaxN = ll(5e3);
const ll mmaxN = ll(3e4);
const ll lmaxN = ll(3e6);
const ll oo = ll(1e18);
const ll MOD = ll(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(0.0) * 2;
const ll LOGMAX = 22;
const ll dx[] = {-1, +0, +0, +1};
const ll dy[] = {+0, -1, +1, +0};

template<typename T>
T Sqr(T x) {
    return x * x;
}

template<class T>
ll Sz(T x) {
    return ll(x.size());
}

inline ll MultMod(ll a, ll b, ll mod){
    if(b == 0)
        return 0;
    if(b % 2)
        return (MultMod(a, b - 1, mod) + a) % mod;
    return (MultMod(a, b / 2, mod) * 2) % mod;
}

inline ll ModPow(ll a, ll b, ll mod){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    if(b % 2)
        return (ModPow(a, b - 1, mod) * a) % mod;
    ll z = ModPow(a, b / 2, mod);
    return (z * z) % mod;
}

const ll N = ll(2e5);

ll nn = ll(1e5);
ll a[N];
ll t[N * 4], to[N * 4];

void Push(ll v){
    if(to[v] != -1){
        to[v * 2] = to[v * 2 + 1] = to[v], to[v] = -1;
    }
}

void Update(ll v, ll tl, ll tr, ll l, ll r, ll x){
    if(l > r)
        return;
    if(l == tl && r == tr){
        t[v] = (r - l + 1) * x;
        to[v] = x;
        return;
    }
    ll tm = (tl + tr) >> 1LL;
    if(to[v] != -1){
        t[v * 2] = (tm - tl + 1) * to[v];
        t[v * 2 + 1] = (tr - tm) * to[v];
        Push(v);
    }
    Update(v * 2, tl, tm, l, min(r, tm), x);
    Update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

ll Get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)
        return 0;
    if(l == tl && r == tr){
        return t[v];
    }
    ll tm = (tl + tr) >> 1LL;
    if(to[v] != -1){
        t[v * 2] = (tm - tl + 1) * to[v];
        t[v * 2 + 1] = (tr - tm) * to[v];
        Push(v);
    }
    return Get(v * 2, tl, tm, l, min(r, tm)) + Get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

main(){

    return 0;
}
