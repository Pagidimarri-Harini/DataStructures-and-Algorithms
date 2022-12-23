vector<int> findMissingDuplicate(vector<int> nums){
    sort(nums.begin(), nums.end());
    int missing, duplicate;
    for(int i = 0; i < nums.size(); i++){
        int index = abs(nums[i]);
        if(nums[index] < 0){
            duplicate = index;
        }
        nums[index] *= -1;
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0){
            missing = i;
        }
    }
    return {missing, duplicate};
    
}
