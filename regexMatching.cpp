#include </Users/kushaldas/Desktop/bits/stdc++.h>
using namespace std;


/**
 * REGULAR EXPRESSION MATCHING LEETCODE HARD
 * do again
 * */
class Solution {
public:
    bool isMatch(string t, string s) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++)
        {
			for(int j=0;j<=m;j++)
			{
				if(j==0)
				{
					if(s[i-1]=='*')
						dp[i][j]=dp[i-2][j];
					else
						dp[i][j]=false;
				}
				else
				{
					if(s[i-1]==t[j-1] or s[i-1]=='.') dp[i][j]=dp[i-1][j-1];
					else if(s[i-1]=='*')
					{
						dp[i][j]=dp[i-2][j];
						// tough part
						if(s[i-2]==t[j-1] or s[i-2]=='.') dp[i][j]=dp[i][j] or dp[i][j-1];
					}
					else dp[i][j]=false;
				}
			}
		}
		return dp[n][m];
    }
};
int main(int argc, char **argv)
{
	// driver code
	return 0;
}
