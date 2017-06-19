/*you are given rods of certain lengths with random price of all. If you have to sell certain given length of rod. How should you sell in order to make maximum profit. Say you have rod of length 1m,2m,3m and 4m that you
can sell for rupees 2,5,7 and 8 respectively. Which rods should you sell if you have to sell total of 5 m and what is the maximum profit that you can make?
Aman Vats*/ 
#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define in insert
#define pb push_back
#define all(a) a.begin(),a.end()
#define pf push_front
#define pob pop_back
#define pof pop_front
#define bitcnt(x) __builtin_popcountll(x)
typedef long long int ll;typedef long int l;typedef pair<int,int> pii;
const ll INF=(1<<28);
const ll MOD = (1e9+7);
int arr[1000]; //array to contain price of different lengths of rod.Here index is the length and the value at that index is the price at which it can be sold.
pii dp[501][501];
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int num_rods; //total num of small rods;
	cin>>num_rods;
	int total; //total length to sell
	cin>>total;
	for(int i=1;i<=num_rods;i++){
		cin>>arr[i];	//prices of rods
	}
	for(int i=1;i<=num_rods;i++)
	{
		for(int j=1;j<=total;j++)
		{
			if(j<i){dp[i][j].first=dp[i-1][j].first;dp[i][j].second = i-1;
			}
			else{
				if(dp[i-1][j].first > (dp[i][j-i].first + arr[i])){
					dp[i][j].first = dp[i-1][j].first;
					dp[i][j].second = i-1;
				}
				else{
					dp[i][j].first  = dp[i][j-i].first + arr[i];
					dp[i][j].second = i;
				}
			}
		}
	}
	for(int i=0;i<=num_rods;i++)
	{
		for(int j=0 ; j<=total;j++){cout<<dp[i][j].first<<","<<dp[i][j].second<<" ";
		}
		cout<<'\n';
	}
	vector<int> v; //for storing the lengths i am gonna sell for max profit.
	int i=num_rods,j=total;
	while(dp[i][j].second!=0)
	{
		if(dp[i][j].second == i){v.pb(i);j-=i;
		}
		else{
			i=dp[i][j].second;
		}
	}
	for(int i=0;i<v.size();i++)	cout<<v[i]<<endl;
return 0;
}
