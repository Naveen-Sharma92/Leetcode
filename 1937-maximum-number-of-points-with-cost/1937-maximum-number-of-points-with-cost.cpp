class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {

        int m = points.size();
        int n = points[0].size();

        vector<long long> prev(n, 0);

        // First row
        for(int j = 0; j < n; j++)
            prev[j] = points[0][j];

        // Remaining rows
        for(int i = 1; i < m; i++) {

            vector<long long> left(n);
            vector<long long> right(n);
            vector<long long> curr(n);

            // Left to right
            left[0] = prev[0];

            for(int j = 1; j < n; j++) {
                left[j] = max(prev[j], left[j-1] - 1);
            }

            // Right to left
            right[n-1] = prev[n-1];

            for(int j = n-2; j >= 0; j--) {
                right[j] = max(prev[j], right[j+1] - 1);
            }

            // Calculate current row
            for(int j = 0; j < n; j++) {
                curr[j] = points[i][j] + max(left[j], right[j]);
            }

            prev = curr;
        }

        long long ans = 0;

        for(int j = 0; j < n; j++)
            ans = max(ans, prev[j]);

        return ans;
    }
};