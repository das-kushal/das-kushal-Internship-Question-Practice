#include <bits/stdc++.h>
using namespace std;
#define ll long long
// longest increasing subsequence
/**
 * f(ind,prev_ind) -> length of the lis starting at the ind th index whose previous element is prev_ind
 * 
 * */
/**
 * but does not submit properly in any platform
 * 
 * */
int lisHelp(int ind,int prev_ind,vector<int>&nums,vector<vector<int>>&dp)
{
	if(ind==nums.size()) return 0;
	if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1]; 
	int len=0;
	len=lisHelp(ind+1,prev_ind,nums,dp);
	if(prev_ind==-1 or nums[prev_ind]<nums[ind]) len=max(len,1+lisHelp(ind+1,ind,nums,dp));
	return dp[ind][prev_ind+1]=len;
}
int lengthOfLIS(vector<int>& nums) {
	int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return lisHelp(0,-1,nums,dp);
}
// tabulation
int longestIncreasingSubsequence1(int arr[], int n)
{
	vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	for(int ind=n-1;ind>=0;ind--)
	{
		for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
		{
			int len=dp[ind+1][prev_ind+1];
			if(prev_ind==-1 or arr[ind]>arr[prev_ind]) len=max(len,1+dp[ind+1][ind+1]);
			dp[ind][prev_ind+1]=len;
		}
	}
	return dp[0][-1+1];
}
// space optimisation
int longestIncreasingSubsequence2(int arr[], int n)
{
	vector<int>next(n+1,0),cur(n+1,0);
	for(int ind=n-1;ind>=0;ind--)
	{
		for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
		{
			int len=next[prev_ind+1];
			if(prev_ind==-1 or arr[ind]>arr[prev_ind]) len=max(len,1+next[ind+1]);
			cur[prev_ind+1]=len; 
		}
		next=cur;
	}
	return next[0]; // next[-1+1]
}


// tabulation another method TC O(n2)  SC O(n)
int longestIncreasingSubsequence_tabulation_different(int arr[],int n)
{
    // dp[i]=length of the LIS ending at the index i
    // each is 1 because we can always take that element
    vector<int>dp(n+1,1);
    for(int ind=0;ind<n;ind++)
    {
        for(int prev=0;prev<ind;prev++)
        {
            if(arr[ind]>arr[prev])
            {
                dp[ind]=max(dp[ind],1+dp[prev]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int lengthOfLIS_AND_PRINT_IT(vector<int>&nums)
{
    int n = nums.size();
    vector<int>hash(n); // to store the prev index
    vector<int> lis;
    for(int i=0;i<n;i++) hash[i]=i;
    vector<int>dp(n,1);
    for(int ind =0;ind<n;ind++)
    {
        for(int prev=0;prev<ind;prev++)
        {
            if(nums[ind]>nums[prev]) 
            {
                if(dp[ind]<dp[prev]+1)
                {
                    hash[ind]=prev;
                    dp[ind]=1+dp[prev];
                }
            }
        }
    }
    auto maxind=max_element(dp.begin(), dp.end())-dp.begin();
    int ind=maxind;
    while(hash[maxind]!=maxind)
    {
        lis.push_back(nums[maxind]);
        maxind=hash[maxind];
    }
    lis.push_back(nums[maxind]);
    reverse(lis.begin(), lis.end());
    for(auto it:lis)cout<<it<<' ';cout<<endl;
    return dp[ind];
}

/*lis using binary search*/
int longestIncreasingSubsequence(vector<int>&nums)
{
	int n=nums.size();	
	vector<int>temp;
	temp.push_back(nums[0]);
	int len=1;
	for(int i = 1 ;i < n ;i++)
	{
		if(nums[i]>temp.back()) {temp.push_back(nums[i]);len++;}
		else
		{
			// we need to do the binary search of the element here and replace it with the new element
			int ind=lower_bound(temp.begin(), temp.end(),nums[i])-temp.begin();
			temp[ind]=nums[i];
		}
	}
	return len;
}
int main(int argc, char **argv)
{
	// driver code
	return 0;
}
