#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const int mod = 1e9 + 7;


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*-------------------------------------------------------------------------------------------------*/
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
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
/*--------------------------------------------------------------------------------------------------------------------------------*/

void harshitha(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

ll arr[200005];
ll seg[800005];


void build(ll node, ll st, ll end) {
    if (st == end) {
        seg[node] = arr[st];
        return;
    }
    ll mid = (st + end) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, end);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}
 
 void update(ll node, ll st, ll end, ll pos, ll val) {
    if (st == end) {
        seg[node] = arr[pos] = val;
        return;
    }
    ll mid = (st + end) / 2;
    if (pos <= mid) {
        update(2 * node, st, mid, pos, val);
    } else {
        update(2 * node + 1, mid + 1, end, pos, val);
    }
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

ll query(ll node, ll st, ll end, ll l, ll r) {
    // Complete overlap
    if (st >= l && end <= r) {
        return seg[node];
    }
    // No overlap
    if (end < l || st > r) {
        return 0;
    }
    // Partial overlap
    ll mid = (st + end) / 2;
    return query(2 * node, st, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

void solve(){
    ll n, q;
    cin>>n>>q;
    for(ll i = 1; i <= n; i++){
    	cin>>arr[i];
    }
    build(1, 1, n);
    while(q--){
    	ll a, b, c;
    	cin>>a>>b>>c;
    	if(a == 1){
    		update(1 , 1 , n , b, c);
    	}
    	else{
    		cout<<query(1, 1, n, b, c)<<"\n";
    	}
    }

}
	
int main(){	

    int t;
    harshitha();
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
