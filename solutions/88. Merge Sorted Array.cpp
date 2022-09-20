class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start = 0;
        int end = m;
        while(m > 0 && start<n){
            if(nums1[m-1] >nums2[start]){
                swap(nums1[m-1],nums2[start]);
                m--;
                start++;
            }
            else break;
        }
        sort(nums1.begin(),nums1.begin()+end);
        sort(nums2.begin(),nums2.end());
        for(auto x : nums1) cout<<x<<" ";
        for(int i =0;i<n;i++){
            nums1[i+end] = nums2[i];
        }
        
    }
};
