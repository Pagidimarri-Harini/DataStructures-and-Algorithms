bool pairInSortedRotated(int arr[], int n, int x)
{
    int start = 0;
    int end = nums.size()-1;
    int  mid;
    while(start < end){
      mid = start + (end - start)/2;
      if(nums[mid] < nums[end]){
        end = mid;
      }else{
        start = mid + 1;
      }
    }
    int l = start;
    int r = (n+l-1)%n;
    while (l != r) {
        if (arr[l] + arr[r] == x)
            return true;
        if (arr[l] + arr[r] < x)
            l = (l + 1) % n;
        else
            r = (n + r - 1) % n;
    }
    return false;
}
