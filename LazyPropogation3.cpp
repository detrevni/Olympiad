# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair < ll, ll > pll;
typedef pair < int, int > pii;

const ll maxN = ll(8e5);
const ll smaxN = ll(5e3);
const ll mmaxN = ll(3e4);
const ll lmaxN = ll(3e6);
const ll oo = ll(1e18);
const ll MOD = ll(1e9) + 7;
const ld EPS = 1e-10;
const ld PI = acos(0.0) * 2;
const ll dx[] = {-1, +0, +0, +1};
const ll dy[] = {+0, -1, +1, +0};

template < typename T >
T Sqr(T x) {
    return x * x;
}

template < class T >
ll Sz(T x) {
    return ll(x.size());
}

inline ll MultMod(ll a, ll b, ll mod) {
    if(b == 0)
        return 0;
    if(b % 2)
        return (MultMod(a, b - 1, mod) + a) % mod;
    return (MultMod(a, b / 2, mod) * 2) % mod;
}

inline ll ModPow(ll a, ll b, ll mod) {
    if(b == 0)
        return 1ll % mod;
    if(b == 1)
        return a % mod;
    if(b % 2)
        return MultMod(ModPow(a, b - 1, mod), a, mod) % mod;
    ll z = ModPow(a, b / 2, mod);
    return (MultMod(z, z, mod)) % mod;
}

void compress(vector < ll > &a){
    vector < ll > b(a);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(auto &i : a) i = lower_bound(b.begin(), b.end(), i) - b.begin() + 1;
}

inline bool Prime(ll x){
    if(x < 2)
        return 0;
    for(ll i = 2; i * i <= x; ++i)
        if(x % i == 0)
            return 0;
    return 1;
}

inline bool IsProbablePrime(ll x){
    return 1; // -> returns 1
}


const ll pikachu = (ll)2e6;

struct Tree{

    ll t[pikachu], f[pikachu];

    Tree(){
        fill(f, f + pikachu, 0);
        fill(t, t + pikachu, 0);
    }

    void Push(ll v){
        if(f[v]){
            t[v * 2] += f[v];
            t[v * 2 + 1] += f[v];
            f[v * 2] += f[v];
            f[v * 2 + 1] += f[v];
            f[v] = 0;
        }
    }

    void Inc(ll v, ll tl, ll tr, ll l, ll r, ll val){
        ll tm = (tl + tr) >> 1;
        Push(v);
        if(l > r) return;
        if(l == tl && r == tr){
            t[v] += val;
            f[v] += val;
            return;
        }
        Inc(v * 2, tl, tm, l, min(r, tm), val);
        Inc(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }

    ll Get(ll v, ll tl, ll tr, ll l, ll r){
        Push(v);
        ll tm = (tl + tr) >> 1;
        if(l > r)
            return ll(1e9);
        if(l == tl && r == tr)
            return t[v];
        return min(Get(v * 2, tl, tm, l, min(r, tm)),
                Get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    ~Tree(){}
}T;

main(){
    return 0;
}
