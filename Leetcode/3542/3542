class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;

        int res = 0;
        int n = nums.size();
         for (int x : nums) {

            if (x == 0) {
                while (!st.empty()) st.pop();
                continue;
            }

            while (!st.empty() && st.top() > x) st.pop();
            
            if (st.empty() || st.top() < x) {
                st.push(x);
                res++;
            }
        }

        return res;
    }
};


class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> help;

        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if(nums[i]==0){
                while (!help.empty()) {
                    help.pop();
                }
                continue;
            }
            if (help.empty()) {
                help.push(nums[i]);
                res++;
                continue;
            }

            if (help.top() < nums[i]) {
                help.push(nums[i]);
                res++;
            } else if (help.top() > nums[i]) {
                while (!help.empty() && help.top() > nums[i]  ) {
                    help.pop();
                }
                if(help.empty()){
                    help.push(nums[i]);
                    res++;
                    continue;
                }
                if (help.top() == nums[i])
                    continue;

                if (help.top() < nums[i]) {
                    res++;
                    help.push(nums[i]);
                }
            }
        }

        return res;
    }
};