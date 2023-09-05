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


void solve(){
    //cout<<"hello"<<"\n";
    int n, q;
    cin>>n>>q;
    vi arr(n + 1);
    f(i, 1, n + 1){
        cin>>arr[i];
        arr[i] ^= arr[i - 1];
    }
    while(q--){
        int a, b; 
        cin>>a>>b;
        cout<<(arr[b] ^ arr[a - 1])<<"\n";
    }


}
    
int main(){    

    int t = 1;
    harshitha();
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
