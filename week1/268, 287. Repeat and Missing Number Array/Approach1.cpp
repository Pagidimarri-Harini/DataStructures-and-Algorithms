vector<int> findMissingDuplicate(vector<int> nums){
    sort(nums.begin(), nums.end());
    int missing, duplicate;
    for(int i = 0; i < nums.size()-1; i++){
        if(nums[i] == nums[i+1]){
            duplicate = nums[i];
        }
        else if(nums[i+1] - nums[i] > 1){
            missing = nums[i]+1;
        }
    }
    return {missing, duplicate};
    
}
