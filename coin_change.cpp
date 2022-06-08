#include </Users/kushaldas/Desktop/bits/stdc++.h>
using namespace std;

class Solution{
    long long count1(int arr[],int m,int n,vector<vector<int>>&dp)
    {
        // m is the size of the arr and we have to make a change of n cents
        if(n==0) return 1;// choose no coin so 1 way
        if(m==0 and n>=1) return 0;// if no coins and we have to make a change
        // of more than or equal to 1 cent then no ways
        if(dp[m][n]!=-1) return dp[m][n];
        // may take or not take 
        if(arr[m-1]<=n)
        return dp[m][n]= count1(arr,m-1,n,dp)+count1(arr,m,n-arr[m-1],dp);
        // else do not take 
        else return dp[m][n]=count1(arr,m-1,n,dp);
    }
public:
    long long int count(int S[], int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return count1(S,m,n,dp);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
