#include </Users/kushaldas/Desktop/bits/stdc++.h>
using namespace std;
#define endl '\n'

// best time to sell and buy stocks LEETCODE EASY	
int maximumProfit(vector<int> &prices){
	int maxi=INT_MIN;
	int profit=0;
	int cur=INT_MAX;
	for(int i=0;i<prices.size();i++)
	{
		cur=min(cur,prices[i]);
		profit=prices[i]-cur;
		maxi=max(maxi,profit);
	}
	return maxi;
}

// best time to sell and buy stocks 2 LEETCODE MEDIUM	
int mprofit(int ind,bool canbuy,vector<int> &prices,vector<vector<long long>> &dp)
{
	if(ind==prices.size()) return 0;
	if(dp[ind][canbuy]!=-1) return dp[ind][canbuy];
	if(canbuy)
	{
		// if we can buy then we can either buy or not buy
		// if we buy then we add -prices[ind] in the profit
		return dp[ind][canbuy]=max(-prices[ind]+mprofit(ind+1,false,prices,dp),									       	mprofit(ind+1,true,prices,dp));
	}
	else
	{
		// if we cannot buy then we can sell or not sell
		return dp[ind][canbuy]=max(prices[ind]+mprofit(ind+1,true,prices,dp),										
											   mprofit(ind+1,false,prices,dp));
	}
}
int maxProfit(vector<int>& prices) {
	int n=prices.size();
	vector<vector<long long>> dp(n,vector<long long> (2,-1));
	bool canbuy=true;
	return mprofit(0,canbuy,prices,dp);
}
// best time to buy and sell stock 2 CODE STUDIO
long help(int ind,bool buy,long*values,vector<vector<long long>> &dp)
{
	if(ind==n) return 0;
	if(dp[ind][buy]!=-1) return dp[ind][buy];
	long profit=0;
	if(buy)
	{
		profit=max(-values[ind]+help(ind+1,false,values,dp),
								help(ind+1,true,values,dp));
	}
	else
	{
		profit=max(values[ind]+help(ind+1,true,values,dp),
							   help(ind+1,false,values,dp));
	}
	return dp[ind][buy]=profit;
}
long getMaximumProfit(long *values, int n)
{
    bool buy=true;
    vector<vector<long long>> dp(n,vector<long long> (2,-1));
    return help(0,buy,values,dp);
}
// tabulation
long getMaximumProfit(long *values, int n)
{
	vector<vector<long long>> dp(n+1, vector<long long> (2,0));
	dp[n][0]=dp[n][1]=0;
	for(int ind=n-1;ind>=0;ind--)
	{
		for(int buy=0;buy<=1;buy++)
		{
			long long profit=0;
			if(buy)
			{
				profit=max(-values[ind]+dp[ind+1][0],dp[ind+1][1]);
			}
			else
			{
				profit=max(values[ind]+dp[ind+1][1],dp[ind+1][0]);
			}
			dp[ind][buy]=profit;
		}
	}
	return dp[0][1];
}

// space optimisation
long getMaximumProfit(long *values, int n)
{
	vector<long>cur(2,0),prev(2,0);
	prev[0]=prev[1]=0;
	for(int ind=n-1;ind>=0;ind--)
	{
		for(int buy=0;buy<=1;buy++)
		{
			long profit=0;
			if(buy)
			{
				profit=max(-values[ind]+prev[0],prev[1]);
			}
			else
			{
				profit=max(values[ind]+prev[1],prev[0]);
			}
			cur[buy]=profit;
		}
		prev=cur;
	}
	return prev[1];
}

// best time to buy and sell stock 3 (with atmost 2 transactions)
int help2(int ind,bool buy,int transactionLeft,vector<int>& prices,vector<vector<vector<int>>>&dp)
{
	if(ind==prices.size() or transactionLeft==0)
	{
		return 0;
	}
	if(dp[ind][buy][transactionLeft]!=-1) return dp[ind][buy][transactionLeft];
	if(buy)
	{
		return dp[ind][buy][transactionLeft]=max(-prices[ind]+help2(ind+1,false,transactionLeft,prices,dp),
															  help2(ind+1,true,transactionLeft,prices,dp));
	}
	else
	{
		return dp[ind][buy][transactionLeft]=max(prices[ind]+help2(ind+1,true,transactionLeft-1,prices,dp),
															 help2(ind+1,false,transactionLeft,prices,dp));
	}
}
int maxProfit(vector<int>& prices) {
	int n=prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    bool buy=true;
    int transactionLeft=2;
    return help2(0,buy,transactionLeft,prices,dp);
}

// tabulation
int maxProfit(vector<int> &prices)
{
	int n=prices.size();
	vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(2,vector<long long>(3,0)));
	for(int ind=n-1;ind>=0;ind--)
	{
		for(int buy=0;buy<=1;buy++)
		{
			for(int transactionLeft=1;transactionLeft<=2;transactionLeft++)
			{
				if(buy)
				{
					dp[ind][buy][transactionLeft]=max(-prices[ind]+dp[ind+1][0][transactionLeft],dp[ind+1][1][transactionLeft]);
				}
				else 
				{
					dp[ind][buy][transactionLeft]=max(prices[ind]+dp[ind+1][true][transactionLeft-1],
															 dp[ind+1][false][transactionLeft]);
				}
			}
		}
	}
	return dp[0][1][2];
}
//space optimisation
int maxProfit(vector<int> &prices)
{
	int n=prices.size();
	vector<vector<long long>> after(2,vector<long long> (3,0));
	vector<vector<long long>> cur(2,vector<long long> (3,0));
	for(int ind=n-1;ind>=0;ind--)
	{
		for(int buy=0;buy<=1;buy++)
		{
			for(int transactionLeft=1;transactionLeft<=2;transactionLeft++)
			{
				if(buy)
				{
					cur[buy][transactionLeft]=max(-prices[ind]+after[0][transactionLeft],after[1][transactionLeft]);
				}
				else 
				{
					cur[buy][transactionLeft]=max(prices[ind]+after[true][transactionLeft-1],
															 after[false][transactionLeft]);
				}
			}
		}
		after=cur;
	}
	return after[1][2];
}

// best time to buy and sell stock 4  (with atmost k transactions)
int bss4(int ind,int buy,int transLeft,vector<int> &prices, vector<vector<vector<long long>>> &dp)
{
	if(ind==prices.size() or transLeft==0) return 0;
	if(dp[ind][buy][transLeft]!=-1) return dp[ind][buy][transLeft];
	if(buy)
	{
		return dp[ind][buy][transLeft]=max(-prices[ind]+bss4(ind+1,0,transLeft,prices,dp),bss4(ind+1,1,transLeft,prices,dp));
	}
	return dp[ind][buy][transLeft]=max(prices[ind]+bss4(ind+1,1,transLeft-1,prices,dp),bss4(ind+1,0,transLeft,prices,dp));
}
int maxProfit(int k, vector<int>& prices) {
	int n=prices.size();
	vector<vector<vector<long long>>> dp(n,vector<vector<long long>> (2,vector<long long> (k+1,-1)));
	int buy=1;
	int transLeft=k;
	return bss4(0,buy,transLeft,prices,dp);
}

//Best Time to Buy and Sell Stock with Cooldown 
int bsscd(int ind,int buy,vector<int> &prices,vector<vector<long long>> &dp)
{
	if(ind>=prices.size()) return 0;
	if(dp[ind][buy]!=-1) return dp[ind][buy];
	if(buy)
	{
		return dp[ind][buy]=max(-prices[ind]+bsscd(ind+1,0,prices,dp),bsscd(ind+1,1,prices,dp));
	}
	return dp[ind][buy]=max(prices[ind]+bsscd(ind+2,1,prices,dp),bsscd(ind+1,0,prices,dp));
}
int maxProfit(vector<int>& prices) {
	int n=prices.size();
	vector<vector<long long>> dp(n,vector<long long> (2,-1));
	int buy=1;
	return bsscd(0,buy,prices,dp);
}

// best time to buy and sell stock with transaction fee
int bsstf(int ind,int buy,int fee,vector<int> &prices,vector<vector<long long>> &dp)
{
	if(ind==prices.size()) return 0;
	if(dp[ind][buy]!=-1) return dp[ind][buy];
	if(buy)
	{
		return dp[ind][buy]=max(-prices[ind]+bsstf(ind+1,0,fee,prices,dp),bsstf(ind+1,1,fee,prices,dp));
	}
	return dp[ind][buy]=max(prices[ind]-fee+bsstf(ind+1,1,fee,prices,dp),bsstf(ind+1,0,fee,prices,dp));
}
int maxProfit(vector<int>& prices, int fee) {
	int n=prices.size();
	vector<vector<long long>> dp(n,vector<long long> (2,-1));
	int buy=1;
	return bsstf(0,buy,fee,prices,dp);
}
int32_t main(int argc, char **argv)
{
	// driver code
	return 0;
}
