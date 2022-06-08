#include <bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int>& nums) {
	int n=nums.size();
	int maxlen=0,res=0;
	// dp[{i,j}] => length , number of LIS of that length
    vector<pair<int,int>> dp(n,{1,1});
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<i;j++)
    	{
    		if(nums[i]>nums[j])
    		{
    			if(dp[i].first==dp[j].first+1) dp[i].second+=dp[j].second;
    			if(dp[i].first<dp[j].first+1) dp[i]={dp[j].first+1,dp[j].second};
    		}
    	}
    	if(maxlen==dp[i].first) res+=dp[i].second;
    	if(maxlen<dp[i].first){
    		maxlen=dp[i].first;res=dp[i].second;
    	}
    }
    return res;


}
int main(int argc, char const *argv[])
{
	
	return 0;
}