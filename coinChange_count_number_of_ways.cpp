#include </Users/kushaldas/Desktop/bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define sz(x) (int)x.size()
#define all(vec) vec.begin(),vec.end()
const ll mod = 1e9+7;
const ll inf = 1e8;

class Solution {
public:
	int help(int ind,int target,vector<int>coins,vector<vector<int>>&dp)
	{
		if(target==0) return 1;
		if(ind==0 and target>=1) return 0;
		if(dp[ind][target]!=-1) return dp[ind][target];
		if(coins[ind-1]<=target) return dp[ind][target]=help(ind-1,target,coins,dp)+help(ind,target-coins[ind-1],coins,dp);
		else return dp[ind][target]=help(ind-1,target,coins,dp);
		
	}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return help(n,amount,coins,dp);
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++)
        {
			for(int j=0;j<=amount;j++)
			{
				if(j==0) dp[i][j]=1;
				if(i==0) dp[i][j]=0;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=amount;j++)
			{
				if(coins[i-1]<=j) dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
				else dp[i][j]=dp[i-1][j];
			}
		}
		return dp[n][amount];
    }
    
    
};

double_t power(int a,int b)
{
	double_t res=1;
	while(b>0)
	{
		if(b%2) res*=a;
		a*=a;
		b/=2;
	}
	return res;
}
int32_t main()
{
	cout<<power(10,30)<<endl;
	cout<<power(2,4)<<endl;
	// here we will do the solution
	return 0;
}
