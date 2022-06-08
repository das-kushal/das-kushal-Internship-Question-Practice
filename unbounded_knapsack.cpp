#include </Users/kushaldas/Desktop/bits/stdc++.h>
using namespace std;

int help(int ind, int cap, vector<int> profit, vector<int> weight, vector<vector<int>> &dp)
{
	if(ind==0)
	{
		return (int)(cap/weight[ind])*profit[ind];
	}
	if(dp[ind][cap]!=-1) return dp[ind][cap];
	int ntake=help(ind-1,cap,profit,weight,dp);
	int take=0;
	if(weight[ind]<=cap) take=profit[ind]+help(ind,cap-weight[ind],profit,weight,dp);
	return dp[ind][cap]=max(take,ntake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int> (w+1,-1));
    return help(n-1,w,profit,weight,dp);
}
// now tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int> (w+1,0));
    for(int i=weight[0];i<=w;i++)
    {	// it is unbounded knapsack so we can take as many as we like so we take the maximum we can take
		dp[0][i]=(int)(i/weight[0])*profit[0];
	}
	for(int ind=1;ind<n;ind++)
	{
		for(int cap=0;cap<=w;cap++)
		{
			int ntake=dp[ind-1][cap];
			int take=0;
			if(weight[ind]<=cap) take=profit[ind]+dp[ind][cap-weight[ind]];
			dp[ind][cap]=max(take,ntake);
		}
	}
	return dp[n-1][w];
}

// space optimisation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w+1,0),cur(w+1,0);
    for(int i=weight[0];i<=w;i++)
    {	// it is unbounded knapsack so we can take as many as we like so we take the maximum we can take
		prev[i]=(int)(i/weight[0])*profit[0];
	}
	for(int ind=1;ind<n;ind++)
	{
		for(int cap=0;cap<=w;cap++)
		{
			int ntake=prev[cap];
			int take=0;
			if(weight[ind]<=cap) take=profit[ind]+cur[cap-weight[ind]];
			cur[cap]=max(take,ntake);
		}
		prev=cur;
	}
	return prev[w];
}





int main(int argc, char **argv)
{
	// here the solution is to be done
	return 0;
}
