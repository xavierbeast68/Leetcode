/*
    ▄  ██       ▄   ▄█ ▄███▄   █▄▄▄▄ ███   ▄███▄   ██      ▄▄▄▄▄      ▄▄▄▄▀ 
▀▄   █ █ █       █  ██ █▀   ▀  █  ▄▀ █  █  █▀   ▀  █ █    █     ▀▄ ▀▀▀ █    
  █ ▀  █▄▄█ █     █ ██ ██▄▄    █▀▀▌  █ ▀ ▄ ██▄▄    █▄▄█ ▄  ▀▀▀▀▄       █    
 ▄ █   █  █  █    █ ▐█ █▄   ▄▀ █  █  █  ▄▀ █▄   ▄▀ █  █  ▀▄▄▄▄▀       █     
█   ▀▄    █   █  █   ▐ ▀███▀     █   ███   ▀███▀      █              ▀      
 ▀       █     █▐               ▀                    █                      
        ▀      ▐                                    ▀                       
*/
/**
 * xavierbeast68
 * URL : https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#pragma GCC optimize("O3,Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#define endl                                        '\n'
using ll                                            = long long;
using lld                                           = long double;
#define vi                                          vector<int>

constexpr lld EPS                                   = 1e-9;
constexpr ll MOD                                    = 1e9 + 7; //1000000007
constexpr ll mod1                                   = 998244353;

#define FOR(i,a,b)                                  for(int i = a; i < b; ++i)

#define pb                                          push_back
#define ppb                                         pop_back
#define sz(x)                                       (int)(x).size()
#define all(x)                                      begin(x), end(x)
#define mp(x,y)                                     make_pair(x,y)
#define lb(arr, x)                                  lower_bound(arr.begin(), arr.end(), x) - arr.begin();
#define ub(arr, x)                                  upper_bound(arr.begin(), arr.end(), x) - arr.begin();


/*------------------------------------------------------Read & Print Methods------------------------------------------------------*/

#define read(x)                                     int x; cin >> x; // reads long long
#define readstr(x)                                  string x; cin >> x; // reads string(word)
#define readLine(x)                                 string x; getline(cin, x); // reads string(sentence)
#define print(x)                                    cout<<(x)<<" "
#define println(x)                                  cout<<(x)<<endl

// Vector Read & Print ->
template <class T> vector<T> readvector(T n) { vector<T> arr(n); for (int i = 0; i < n; i++) {cin >> arr[i];} return arr;}   // vector<ll> arr = readvector(n);
template <class T> void printvector(vector<T> arr, T n) {for (int i = 0; i < n; i++) {cout << arr[i] << " ";} cout << endl;}   // printvector(arr, n);


/*--------------------------------------------------------------Debugger--------------------------------------------------------------*/
//            [di:b^b-ing]
// -Being the detective in a crime
//  where you are also the murderer.

#define test(i)                                     cout << "(#" << i << ")" << endl

// #ifndef ONLINE_JUDGE
#ifdef XAVIERBEAST
#define dbg(x)                                      cerr << #x<<" "; _print(x); cerr << endl;
#else
#define dbg(x);
#endif

void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

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
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


/*------------------------------------------------------Functions------------------------------------------------------*/

ll gcd(ll a, ll b)                                  {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b)                                  {return a / gcd(a, b) * b;}
ll countDigit(ll n)                                 {return (floor(log10(n) + 1));}
ll log_a_to_base_b(ll a, ll b)                      {return log2(a) / log2(b);}
ll isPowerof2(ll x)                                 {return (x && !(x & (x - 1)));} // Checking if given 64 bit integer is power of 2
bool is_whole(ll a)                                 {return (a - floor(a) < 1e-9);} // floor(a)==ceil(a)
ll factorial(const int& p)                          {if (p <= 1) {return 1;} return p * factorial(p - 1);}
bool isPrime(ll n)                                  {if (n == 2 || n == 3) {return true;} if (n <= 1 || n % 2 == 0 || n % 3 == 0) {return false;} for (int i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0) {return false;}} return true;}
double nCr(ll n, ll r)                                  {double sum = 1; for(int i = 1; i <= r; ++i){sum = sum * (n - r + i) / i;} return sum;}
ll binpow(ll a , ll b)                              {if (b == 0) {return 1;} if (b == 1) {return a;} if (b % 2 == 0) {return binpow((a * a) % MOD, b / 2);} else {return (a * binpow((a * a) % MOD, b / 2)) % MOD;}}    // binary exponentiation

ll mod(ll x)                                        {return (((x) % MOD + MOD) % MOD);}
ll mod_add(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a+b));}
ll mod_mul(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a*b)); }
ll mod_sub(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a-b));}

// random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r)                      {return uniform_int_distribution<ll>(l, r)(rng); }


/*-------------------------------------------------------||||||||||-----------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
                                        |H| |e| |r| |e|   |w| |e|   |g| |o| |!| |!| |!|
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------||||||||||------------------------------------------------------------------------*/


//* https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/
//* https://www.youtube.com/watch?v=M0RjiC85BZU
//* https://www.youtube.com/watch?v=ZlVNO8BFBCY

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {

        // O(nlogn)
        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());
        
        // for(int i = 0; i<nums1.size(); ++i){
        //     for(int j = 0; j<nums2.size(); ++j){
        //         if(nums1[i] == nums2[j]){
        //             return nums1[i];
        //         }
        //     }
        // }
        
        // int a = min(nums1[0],nums2[0]);
        // int b = max(nums1[0],nums2[0]);
        
        // return (a*10+b);


        // O(n)
        unordered_map<int,int> mp;
        int min_el = 10, min1 = 10, min2 = 10;

        for(int i : nums1){
            mp[i] = 1;
            min1 = min(min1, i);
        }

        for(int i : nums2){
            if(mp[i] == 1){
                min_el = min(min_el, i);
            }

            min2 = min(min2, i);
        }

        if(min_el != 10){
            return min_el;
        }

        return (min(min1, min2) * 10 + max(min1, min2));
    }
};


/*---------------------------------------- DON'T TOUCH IT ----------------------------------------*/

/*
void solve()
{
    // Let's Code

}

#define fastio                                      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//InputOutputError_From/To_File ->
void file_io()
{
// #ifndef ONLINE_JUDGE
#ifdef XAVIERBEAST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

signed main()
{
    fastio;

    cout << fixed << setprecision(10);
    // file_io();
    auto start = high_resolution_clock::now();

    //testcases=1: default value for single test case
    int testcases = 1;
    //cin >> testcases;
    while (testcases--)
    {
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    #ifdef XAVIERBEAST
        cerr << endl << "Time: " << (float)duration.count()/1000000 << " s" << endl;
    #endif

    return 0;
}
*/