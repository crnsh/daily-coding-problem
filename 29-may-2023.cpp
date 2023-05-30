// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> createPrefix(vector<int> &a) {
        int n = a.size();

        vector<int> prefix(n);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prefix[i] = a[i];
            }
            else {
                prefix[i] = a[i]*prefix[i-1];
            }
        }

        // assert : prefix[i] = a[0]*a[1]*...*a[i], 0<=i<n

        return prefix;
    }

    vector<int> createSuffix(vector<int> &a) {
        int n = a.size();

        vector<int> suffix(n);

        for (int i = n-1; i > -1; i--) {
            if (i == n-1) {
                suffix[i] = a[i];
            }
            else {
                suffix[i] = a[i]*suffix[i+1];
            }
        }

        // assert : suffix[i] = a[i]*a[i+1]*...*a[n-1], 0<=i<n

        return suffix;
    }
    
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();

        vector<int> suffix = createSuffix(a);
        vector<int> prefix = createPrefix(a);

        vector<int> prod(n);

        for (int i = 0; i < n; i++) {
            // assert : suffix[i] contains a[i]*a[i+1]*...*a[n-1]
            if (i == 0) {
                prod[i] = suffix[i+1];
            }
            else if (i == n-1) {
                prod[i] = prefix[i-1];
            }
            else {
                prod[i] = suffix[i+1] * prefix[i-1];
            }
        }

        // assert : prod[] such that prod[i] = suffix[i+1] * prefix[i-1], 0<=i<n, where
        //          prefix[-1] = 1 and suffix[n] = 1

        return prod;
    }
};
