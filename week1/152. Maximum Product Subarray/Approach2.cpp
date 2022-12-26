int maxProduct(vector<int>& nums) {
        int maxproduct = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int product = nums[i];
            maxproduct = max(maxproduct, product);
            for(int j = i+1; j < nums.size(); j++){
                product *= nums[j];
                maxproduct = max(maxproduct, product);
            }
            maxproduct = max(maxproduct, product);
        }
        return maxproduct;
        
}
