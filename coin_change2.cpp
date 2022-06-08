#include </Users/kushaldas/Desktop/bits/stdc++.h>
using namespace std;

class Solution {
public:
	int help(int ind,int target,vector<int> coins,vector<vector<int>> &dp)
	{
		if(ind==0) return target%coins[0]==0;
		if(dp[ind][target]!=-1) return dp[ind][target];
		int ntaken=help(ind-1,target,coins,dp);
		int taken=0;
		if(coins[ind]<=target) taken=help(ind,target-coins[ind],coins,dp);
		return dp[ind][target]=taken+ntaken;
	}
    int change(int amount, vector<int>& coins) {
		int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return help(n-1,amount,coins,dp);
    }
};
int main(int argc, char **argv)
{
	// here the solution is to be done
	return 0;
}
