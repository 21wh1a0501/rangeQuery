#include <bits/stdc++.h>
using namespace std;
/*-------------------------------------------------------------------------------------------------*/
typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin(), (x).end(), greater <ll>() 
#define ff first
#define ss second
#define f(i,s,e) for(long long int i = s; i < e; ++i)
#define cf(i,s,e) for(long long int i = s; i <= e; ++i)
#define rf(i,e,s) for(long long int i = e-1; i >= s; --i)
const int mod = 1e9 + 7;
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------*/

struct segtree{
    int size;
    vector <ll> vec;
    
    void build(vector <int> &a){
        size = 1;
        while(size < a.size()){
            size *= 2;
        }
        vec.assign(2 * size, 0);
        build(a, 0, 0, size);
    }
    void build(vector <int> &a, int x, int l, int r){
        if(r - l == 1){
            if(l < a.size()){
                vec[x] = a[l];
            }
        }
        else{
            int m = (l + r) / 2;
            build(a, 2 * x + 1, l, m);
            build(a, 2 * x + 2, m, r);
            vec[x] = vec[2 * x + 1] + vec[2 * x + 2];
        }
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    //update
    void set(int i, int v, int x, int l, int r) {
        if (r - l == 1) {
            vec[x] = v;
        } 
        else {
            int m = (l + r) / 2;
            if (i < m) {
                set(i, v, 2 * x + 1, l, m);
            } else {
                set(i, v, 2 * x + 2, m, r);
            }
            vec[x] = vec[2 * x + 1] + vec[2 * x + 2];
        }
    }
    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
    //query
     ll sum(int l, int r, int x, int lx, int rx) {
        if (r <= lx) return 0;
        if (l >= rx) return 0;
        if (lx >= l && rx <= r) return vec[x];
        int m = (lx + rx) / 2;
        ll s1 = sum(l, r, 2 * x + 1, lx, m);
        ll s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }
};

void solve(){
    segtree st;
    int n, m;
    cin>>n>>m;
    vi a(n);
    f(i, 0, n){
        cin>>a[i];
    }
    st.build(a);
    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int i, v;
            cin>>i>>v;
            st.set(i, v);
        }
        else{
            int l, r;
            cin>>l>>r;
           cout<<st.sum(l, r)<<"\n";
        }
        
        
    }
    
    
}

int main()
{
    int t = 1;
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}



