class Solution {
public:
    int doBinarySearch(vector<int> &nums,int target){
        int start = 0,end = nums.size() - 1;
        while(start <=end){
            int mid = (start + end)/2;
            cout<<start<<" "<<mid<<" "<<end<<endl;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid-1;
            else start = mid+1;
            
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return doBinarySearch(nums,target);
        
    }
};
