#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> findSubsequences(vector<int> nums)
{
    set<vector<int>> res;
    vector<int> temp;
    // generic lambda -- NEW
    auto back = [&res, &temp, &nums](int i, auto &&back) -> void
    {
        if (i == nums.size())
        {
            if (temp.size() > 1)
            {
                res.insert(temp);
            }
            return;
        }

        if (temp.empty() or temp.back() <= nums[i])
        {
            temp.push_back(nums[i]);
            back(i + 1, back);
            temp.pop_back();
        }
        back(i + 1, back);
    };

    back(0, back);
    return vector(res.begin(), res.end());
}
int main(int argc, char *argv[])
{
    vector<int> nums = {4, 6, 7, 7};
    auto res = findSubsequences(nums);
    for (auto &v : res)
    {
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}