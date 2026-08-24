// Longest Increasing Subsequence (LIS) - O(n log n) solution
int LIS(vector<int>& nums)
{
    if (nums.empty())
        return 0;

    vector<int> tails;
    for (int x : nums)
    {
        // --- UPDATE THIS SECTION BASED ON THE TYPE ---
        // 1. Strictly Increasing: lower_bound(tails.begin(), tails.end(), x)
        // 2. Non-Decreasing:      upper_bound(tails.begin(), tails.end(), x)
        // 3. Strictly Decreasing: lower_bound(tails.begin(), tails.end(), x, greater<int>())
        // 4. Non-Increasing:      upper_bound(tails.begin(), tails.end(), x, greater<int>())
        auto it = lower_bound(tails.begin(), tails.end(), x);
        // ----------------------------------------------
        if (it == tails.end())
        {
            tails.push_back(x);
        }
        else
        {
            *it = x;
        }
    }
    return tails.size();
}
