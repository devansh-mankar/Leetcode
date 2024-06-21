class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int count = 0;

        // Traverse from bottom to top, ensuring the sums of the left and right subtrees are equal
        for (int i = n / 2 - 1; i >= 0; i--) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            // Find the maximum of left and right child costs
            int maxi = max(cost[left], cost[right]);
            count += (maxi - cost[left]) + (maxi - cost[right]);

            // Update the current node cost to include the larger of its children
            cost[i] += maxi;
        }

        return count;
    }
};
