class Solution {
public:
    string longestPalindrome(string s) {
         if (s.empty()) return "";
        
        // Step 1: Preprocess the string
        string processed = preprocess(s);
        int n = processed.size();
        
        // Step 2: Initialize arrays and variables
        vector<int> P(n, 0);  // P[i] = radius of palindrome centered at i
        int center = 0;       // center of rightmost palindrome
        int right = 0;        // right boundary of rightmost palindrome
        
        int maxLen = 0;       // length of longest palindrome found
        int centerIndex = 0;  // center of longest palindrome
        
        // Step 3: Main Manacher's algorithm
        for (int i = 0; i < n; i++) {
            // Use previously computed values if possible
            if (i < right) {
                int mirror = 2 * center - i;  // mirror of i with respect to center
                P[i] = min(right - i, P[mirror]);
            }
            
            // Try to expand palindrome centered at i
            while (i + P[i] + 1 < n && 
                   i - P[i] - 1 >= 0 && 
                   processed[i + P[i] + 1] == processed[i - P[i] - 1]) {
                P[i]++;
            }
            
            // If palindrome centered at i extends past right, update center and right
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
            
            // Update longest palindrome if current one is longer
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        
        // Step 4: Extract the longest palindrome from original string
        int start = (centerIndex - maxLen) / 2;  // start index in original string
        return s.substr(start, maxLen);
    }

    private:
    // Preprocess string: "abc" -> "^#a#b#c#$"
    // ^ and $ are sentinels to avoid boundary checks
    string preprocess(string s) {
        string result = "^#";
        for (char c : s) {
            result += c;
            result += '#';
        }
        result += '$';
        return result;
    }
};