class Solution {
public:
   int minimumEffortPath(vector<vector<int>>& heights) {
    int left = 0, right = 1000000;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canReach(heights, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

bool canReach(vector<vector<int>>& heights, int maxEffort) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    return dfs(heights, 0, 0, maxEffort, visited);
}

bool dfs(vector<vector<int>>& heights, int row, int col, 
         int maxEffort, vector<vector<bool>>& visited) {
    if (row == heights.size()-1 && col == heights[0].size()-1) return true;
    
    visited[row][col] = true;
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i], nc = col + dc[i];
        
        if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() 
            && !visited[nr][nc]) {
            
            int effort = abs(heights[nr][nc] - heights[row][col]);
            if (effort <= maxEffort && dfs(heights, nr, nc, maxEffort, visited)) {
                return true;
            }
        }
    }
    return false;
}
};