class Solution {
public:
    static int beautifulSubsets(vector<int>& nums, const int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        const int M = nums.back();
        const int q = (M + k) / k; // ceil((M+1)/k)
        
        // Initialize the frequency array
        char freq[k][q+1];
        memset(freq, 0, sizeof(freq));
        
        for (auto x : nums) {
            auto [i, r] = div(x, k);
            freq[r][i]++;
        }
        
        int ans = 1; // Start with 1 fpr the product
        int cnt[q+1];
        for (int r = 0; r < k; r++) {
            fill(cnt, cnt+(q+1), 1);
        //    cnt[q] = 1;
            
            for (int i = q-1; i>=0; i--) {
                int take = (1 << freq[r][i])-1;
                if (i+1<q) take *= cnt[i+2];
                else take *= cnt[i+1];
                cnt[i] = cnt[i+1] + take; // skip=cnt[i+1]
            }
            
            ans*= cnt[0];
        }
        
        return ans-1; //exclude the empty set
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();