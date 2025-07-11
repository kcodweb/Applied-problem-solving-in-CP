class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue;

            current.push_back(candidates[i]);
            // not i + 1 because we can reuse same element
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};
