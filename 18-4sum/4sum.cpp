class Solution {
public:
    void nsum(vector<int>& nums,
              int n,
              int l,
              int r,
              vector<int>& path,
              vector<vector<int>>& ans,
              long long target)
    {
        // Not enough elements
        if (r - l + 1 < n)
            return;

        // Pruning
        if (1LL * nums[l] * n > target)
            return;

        if (1LL * nums[r] * n < target)
            return;

        // Base case: 2-Sum
        if (n == 2)
        {
            while (l < r)
            {
                long long sum = 1LL * nums[l] + nums[r];

                if (sum == target)
                {
                    path.push_back(nums[l]);
                    path.push_back(nums[r]);

                    ans.push_back(path);

                    path.pop_back();
                    path.pop_back();

                    int leftVal = nums[l];
                    int rightVal = nums[r];

                    while (l < r && nums[l] == leftVal)
                        l++;

                    while (l < r && nums[r] == rightVal)
                        r--;
                }
                else if (sum < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }

            return;   // VERY IMPORTANT
        }

        // Reduce N-Sum -> (N-1)-Sum
        for (int i = l; i <= r - n + 1; i++)
        {
            if (i > l && nums[i] == nums[i - 1])
                continue;

            path.push_back(nums[i]);

            nsum(nums,
                 n - 1,
                 i + 1,
                 r,
                 path,
                 ans,
                 target - nums[i]);

            path.pop_back();
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> path;

        nsum(nums,
             4,
             0,
             nums.size() - 1,
             path,
             ans,
             1LL * target);

        return ans;
    }
};