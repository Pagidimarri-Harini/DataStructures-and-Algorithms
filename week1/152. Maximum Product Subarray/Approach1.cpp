 int maxProduct(vector<int>& nums) {
        int maxproduct = INT_MIN;
        int minproduct = 1;
        int product = 1;
        for(int i = 0; i < nums.size(); i++){
            int temp = product;
            product = max(nums[i], max(minproduct*nums[i],product*nums[i]));
            minproduct = min(nums[i],min(temp*nums[i], minproduct*nums[i]));
            maxproduct = max(maxproduct, product);
        }
        return maxproduct;
        
}
