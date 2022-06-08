#include <bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums) {
	int n = nums.size();
    std::vector<int> dp(n,1);
    sort(nums.begin(), nums.end());
    std::vector<int> hash(n);
    for(int i=0;i<n;i++)hash[i]=i;
    int maxlen=0;int lastind=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((nums[i]%nums[j])==0) {
                if(dp[i]<dp[j]+1)
                {
                    hash[i]=j;
                    dp[i]=1+dp[j];
                }
            }
        }
        if(maxlen<dp[i])
        {
            lastind=i;
            maxlen=dp[i];
        }
    }
    std::vector<int> lds;
    lds.push_back(nums[lastind]);
    while(hash[lastind]!=lastind)
    {
        lastind=hash[lastind];
        lds.push_back(nums[lastind]);
    }
//     reverse(lds.begin(),lds.end());
    return lds;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}