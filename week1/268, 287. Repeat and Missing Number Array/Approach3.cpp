vector<int> findMissingDuplicate(vector<int> nums){
    int n = nums.size();
    int r = n * (n+1)/2;
    int s = n* (n+1) * (2*n+1)/6;
    for(int i = 0; i < n; i++){
        r -= nums[i];
        s -= pow(nums[i],2);
    }
    int missing = ((s/r) + r)/2;
    int duplicate = (s/r) - missing;
    return {missing, duplicate};
    
}
