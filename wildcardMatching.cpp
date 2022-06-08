/**
 * 
 * KUSHAL DAS
 * DP ON STRINGS
 *
 */

#include </Users/kushaldas/Desktop/bits/stdc++.h>
using namespace std;


/**
 * 
 * WILDCARD MATCHING LEETCODE HARD IMPORTANT
 * 
 * */
 
class Solution {
public:
	bool help(int i,int j,string s,string t,vector<vector<int>> &dp)
	{
		// if string s is exhaousted then for them to match string t should also be exhausted
		if(i<0) return j<0;
		if(j<0)
		{
			// if the string t is exhausted but the string s is still left then they will match iff s is all '*'
			for(int k=i;k>=0;k--) if(s[k]!='*') return false;
			return true;
		}
		if(dp[i][j]!=-1) return dp[i][j];
		// match
		if(s[i]==t[j] or s[i]=='?') return dp[i][j]=help(i-1,j-1,s,t,dp);
		else if(s[i]=='*') return dp[i][j]=help(i-1,j,s,t,dp) or help(i,j-1,s,t,dp);
		// not match
		else return dp[i][j]=false;
	}
    bool isMatch(string t, string s) {
		int n=s.size();
		int m=t.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return help(n-1,m-1,s,t,dp);
    }
    
    // TABULATION
    bool isAllStar(string s,int ind)
    {
		for(int i=0;i<ind;i++) if(s[i]!='*') return false;
		return true;
	}
    bool isMatch2(string t,string s)
    {
		int n=s.size();
		int m=t.size();
		vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
		dp[0][0]=true;
		for(int i=0;i<=n;i++)
		{
			dp[i][0]=isAllStar(s,i);
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(s[i-1]==t[j-1] or s[i-1]=='?') dp[i][j]=dp[i-1][j-1];
				else if(s[i-1]=='*') dp[i][j]=dp[i-1][j] or dp[i][j-1];
				else dp[i][j]=false;
			}
		}
		return dp[n][m];
	}
};

int main(int argc, char **argv)
{
	// driver code
	string t="aab";
	string s="*b*";
	Solution sol;
	cout<<sol.isMatch2(t,s)<<endl;
	return 0;
}

