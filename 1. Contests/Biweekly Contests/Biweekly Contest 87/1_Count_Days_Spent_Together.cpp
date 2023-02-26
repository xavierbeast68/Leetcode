/**
 * @author xavierbeast68
 * ? Problem From : Leetcode Biweekly Contest-87
 * @file 1_Count_Days_Spent_Together.cpp
 * @date 17-09-2022
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define print(a) (cout<<(a)<<endl)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;

/*--Loop Macros--*/
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define FORL(i,a,b) for (int i = a; i <= b; ++i)
#define FORR(i,a,b) for (int i = a; i >= b; --i)
/*--Minimum-Maximum Macros--*/
#define Min2(a,b) (a<b?a:b)
#define Max2(a,b) (a>b?a:b)
/*--Vector Macros--*/
#define pb push_back
#define ppb pop_back

/*--Execution Time--*/
#define execTime() (cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl)
/*--Debug--*/
#define debug(i) (cout<<"<==Testing(#"<<i<<")==>"<<endl)
/*--InputOutputError_From/To_File*/
void IOE()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	/*freopen("error.txt", "w", stderr);*/
#endif
}

/*------------------------------||| Here We Go!!! |||------------------------------*/


void solve()
{
	/*--Let's Code--*/
	string arriveAlice, leaveAlice, arriveBob, leaveBob;
	cin >> arriveAlice >> leaveAlice >> arriveBob >> leaveBob;
	int mdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maa = (int)(arriveAlice.substr(0, 2));
	int mal = (int)(leaveAlice.substr(0, 2));
	int mba = (int)(arriveBob.substr(0, 2));
	int mbl = (int)(leaveBob.substr(0, 2));
	int daa = (int)(arriveAlice.substr(3, 2));
	int dal = (int)(leaveAlice.substr(3, 2));
	int dba = (int)(arriveBob.substr(3, 2));
	int dal = (int)(arriveBob.substr(3, 2));
	int days = 0;
	if (mba >= mal || maa >= mbl)
	{
		if (mba = mal)
		{
			if (dal < dba || dbl < daa)
			{
				//
				return;
			}
			days = abs(dba - dal);
		}
		else
		{
			//
		}

	}
	else
	{
		if (mba < maa)
		{
			if ((maa - mba) == 1)
			{
				days = mdays[mba] - dba + daa;
			}
			else
			{
				days = mdays[mba] - dba;
			}
		}
	}

}

signed main()
{
	boost;
	//IOE();

	/*t=1: default value for single test case*/
	int t = 1;
	//cin >> t;
	while (t--)
	{
		//debug();
		solve();
	}

	//execTime();
	return 0;
}

/**
 * check t: comment cin>>t; for single test case
 * if using CPH Judge or CppFastOlympicsCoding: no need to use IOE;
 */