//meet in middle pattern not able to do and understand
class Solution {
public:

    void generate(int index, int end, vector<int>& nums,
                  int count, long long sum,
                  vector<vector<long long>>& store) {

        if(index == end) {
            store[count].push_back(sum);
            return;
        }

        // not pick
        generate(index + 1, end, nums, count, sum, store);

        // pick
        generate(index + 1, end, nums, count + 1,
                 sum + nums[index], store);
    }

    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int half = n / 2;

        long long total = 0;

        for(int i = 0; i < n; i++)
            total += nums[i];

        vector<vector<long long>> left(half + 1);
        vector<vector<long long>> right(half + 1);

        // generate all subset sums of left half
        generate(0, half, nums, 0, 0, left);

        // generate all subset sums of right half
        generate(half, n, nums, 0, 0, right);

        // sort so that we can binary search
        for(int i = 0; i <= half; i++) {
            sort(left[i].begin(), left[i].end());
            sort(right[i].begin(), right[i].end());
        }

        long long ans = LLONG_MAX;

        // choose i elements from left
        for(int i = 0; i <= half; i++) {

            // need half-i elements from right
            int need = half - i;

            for(auto leftSum : left[i]) {

                long long target = total / 2 - leftSum;

                // find closest value >= target
                auto it = lower_bound(
                    right[need].begin(),
                    right[need].end(),
                    target
                );

                // candidate 1
                if(it != right[need].end()) {

                    long long chosenSum = leftSum + *it;

                    ans = min(ans,
                              llabs(total - 2 * chosenSum));
                }

                // candidate 2: value just smaller than target
                if(it != right[need].begin()) {

                    --it;

                    long long chosenSum = leftSum + *it;

                    ans = min(ans,
                              llabs(total - 2 * chosenSum));
                }
            }
        }

        return ans;
    }
};