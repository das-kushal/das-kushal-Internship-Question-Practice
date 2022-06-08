#include <bits/stdc++.h>
using namespace std;
int help(int ind, int prev, vector<int> vec, vector<vector<int>> &dp)
{
    if (ind == vec.size())
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    // not take
    int len = 0 + help(ind + 1, prev, vec, dp);
    // take
    if (prev != -1 or vec[ind] > vec[prev])
        len = max(len, 1 + help(ind + 1, ind, vec, dp));
    return dp[ind][prev + 1] = len;
}
int lengthOfLIS(vector<int> &vec)
{
    int n = vec.size();
    // dp[ind][prev_ind];
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return help(0, -1, vec, dp);
}

int lengthOfLIS2(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            // not take go to the next index
            int len = dp[ind + 1][prev + 1];
            // take
            if (prev == -1 and nums[ind] > nums[prev])
                len = max(len, 1 + dp[ind + 1][ind]);
            dp[ind][prev] = len;
        }
    }
    return dp[0][-1 + 1];
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev=ind-1;prev>=-1;prev--)
        {
            // not take
            int len=0+dp[ind+1][prev+1];
            // take
            if(prev==-1 or arr[ind]>arr[prev]) len=max(len,1+dp[ind+1][ind+1]);
            dp[ind][prev+1]=len;
        }
    }
    return dp[0][0];
}

int longestIncreasingSubsequence2(int arr[],int n)
{
    vector<int>next(n+1,0),cur(n+1,0);
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev=ind-1;prev>=-1;prev--)
        {
            // not take
            int len=next[prev+1];
            // take
            if(prev==-1 or arr[ind]>arr[prev]) len=max(len,1+next[ind+1]);
            cur[prev+1]=len;
        }
        next=cur;
    }
    return next[0];
}

// tabulation another method
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
int main(int argc, char const *argv[])
{

    return 0;
}
