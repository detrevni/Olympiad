# include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = (int)1e9 + 7;
const int maxn = (int)3e5 + 7;
const int lmaxn = (int)4e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};


const ll MAX = (ll)1e5;

struct node{
    node *l, *r;
    ll val;
    node() : l(nullptr), r(nullptr), val(0){}
    ~node(){}
};

struct Tree{
    node *root = new node();
    void update(node *&v, ll tl, ll tr, ll pos, ll val){
        if(tl == tr){
            v -> val += val;
            return;
        }
        ll tm = (tl + tr) >> 1ll;
        if(v -> l == nullptr)
            v -> l = new node();
        if(v -> r == nullptr)
            v -> r = new node();
        if(pos <= tm)
            update(v -> l, tl, tm, pos, val);
        else
            update(v -> r, tm + 1, tr, pos, val);
        v -> val = v -> l -> val + v -> r -> val;
    }
    ll get(node *&v, ll tl, ll tr, ll l, ll r){
        if(l > r) return 0;
        if(l == tl && r == tr)
            return v -> val;
        ll tm = (tl + tr) >> 1ll;
        if(v -> l == nullptr)
            v -> l = new node();
        if(v -> r == nullptr)
            v -> r = new node();
        return get(v -> l, tl, tm, l, min(r, tm)) + get(v -> r, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(ll pos, ll val){
        update(root, 1, MAX, pos, val);
    }

    ll get(ll l, ll r){
        return get(root, 1, MAX, l, r);
    }
};

int main(){
    
}
