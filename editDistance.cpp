/**
 * 
 * KUSHAL DAS
 * DP ON STRINGS
 *
 */

#include </Users/kushaldas/Desktop/bits/stdc++.h>
using namespace std;


/**
 * EDIT DISTANCE LEETCODE HARD IMPORTANT
 * we have 3 options
 * 
 * * insert the same character
 * * delete and try finding the character somewhere else
 * * replace and match
 *  try all ways -> recursion
 *  express in term of i and j f(i,j)
 * explore all paths
 * return min of all paths 
 * base case
 * 
 * f(n-1,m-1)->f(i,j) signifies that min number of operations to convert from s1[0...i] to s2[0...j] 
 * if (s[i]==t[j]) return 0+f(i-1,j-1)
 * insert 1+f(i,j-1) as the character gets inserted ahead of the string s so i remains in the same place but the s2 string j gets reduced by 1
 * delete 1+f(i-1,j)
 * replace 1+f(i-1,j-1)
 * now take min of them
 **/ 
 
int help(int i,int j,string s,string t,vector<vector<int>> &dp)
{
	if(i<0) return j+1; // j+1 number of insertions need to be done is s is exhausted
	if(j<0) return i+1; // i+1 delete operations are needed
	if(dp[i][j]!=-1) return dp[i][j];
	if(s[i]==t[j]) return dp[i][j]=help(i-1,j-1,s,t,dp);
	else
	{
		int insert=1+help(i,j-1,s,t,dp);
		int deletes=1+help(i-1,j,s,t,dp);
		int replace=1+help(i-1,j-1,s,t,dp);
		return dp[i][j]=min({insert,deletes,replace});
	}
}
int minDistance(string s, string t) {
	int n=word1.size();
	int m=word2.size();
	vector<vector<int>> dp(n,vector<int> (m,-1));
	return help(n-1,m-1,s,t,dp);	
}

// space optimised
int minDistance(string s, string t)
{
	int n=word1.size();
	int m=word2.size();
	vector<int>prev(m+1,0),cur(m+1,0);
	for(int i=0;i<=n;i++)prev[i][0]=i;
	for(int i=1;i<=n;i++)
	{
		cur[0]=i;
		for(int j=1;j<=m;j++)
		{
			if(word1[i-1]==word2[j-1]) cur[j]=prev[j-1];
			else
			{
				cur[j]=1+min({cur[j-1],prev[j],prev[j-1]});
			}
		}
		prev=cur;
	}
	return prev[m];
}



int main(int argc, char **argv)
{
	// driver code
	return 0;
}

