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
void solve(){
    //3 2 4 5 1 1 5 3
    //3 5 9 14 15 16 21 24
   int n, q;
   cin>>n>>q;
   vl arr(n + 1, 0);
   vl pref(n + 1, 0);
   for(int i = 1; i < n + 1; i++){
   		   cin>>arr[i];
       pref[i] = pref[i - 1] + arr[i];
   }
   while(q--){
       int l, r;
       cin>>l>>r;
       cout<<pref[r] - pref[l - 1]<<"\n";
   }
}

int main()
{
    int t;
    t = 1;
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
