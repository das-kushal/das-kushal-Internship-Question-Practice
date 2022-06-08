/* * 
 * 1130. Minimum Cost Tree From Leaf Values
 * 
 * 
 * not understood
 * */


#include </Users/kushaldas/Desktop/bits/stdc++.h>
using namespace std;
#define endl '\n'




class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
       vector<int> stack={INT_MAX};
       int res=0;
       for(int a:arr)
       {
		   while(stack.back()<=a)
		   {
			   int mid=stack.back(); // stack.top()
			   stack.pop_back();
			   res+=mid*(min(stack.back(),a));
		   }
		   stack.push_back(a); 
	   }
	   for(int i=2;i<stack.size();i++) res+=(stack[i]*stack[i-1]);
	   return res;
    }
};


int32_t main(int argc, char **argv)
{
	// driver code
	return 0;
}
