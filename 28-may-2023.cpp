class Solution {
public:
    vector<int> twoSum(vector<int>& a, int k) {
        
        unordered_map<int, int> mp;

        for (int i = 0; i < a.size(); i++) {
            mp[a[i]] = i+1;
        }

        // mp[k] contains the last index i such that a[i-1] == k 

        int i;
        int j;
        for (i = 0; i < a.size(); i++) {
            j = mp[k-a[i]] - 1;
            if (j != -1 && j != i) {
                // assert : there is a j st a[i] + a[j] == k
                break;
            }
        }
        
        // assert : i, j such that a[i] + a[j] == k and i != j

        return {i, j};
    }
};
