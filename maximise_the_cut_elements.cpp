#include </Users/kushaldas/Desktop/bits/stdc++.h>
using namespace std;

class Solution
{
    int help(int n,int x,int y,int z,vector<int>&dp)
    {
        int xa=0,ya=0,za=0;
        if(n==0) return 0;
        if(n<0) return -1e8;
        if(dp[n]!=-1) return dp[n];
        xa=1+help(n-x,x,y,z,dp);
        ya=1+help(n-y,x,y,z,dp);
        za=1+help(n-z,x,y,z,dp);
        return dp[n]=max({xa,ya,za});
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,-1);
        return max(0,help(n,x,y,z,dp));
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}
