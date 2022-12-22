vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        for(int i = 1; i < nums.size(); i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int last_prod = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            ans[i] *= last_prod; 
            last_prod *= nums[i];
        }
        return ans;
        
 }
