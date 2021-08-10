class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
   /*   Brute force :
        01. Creating another array and copy num1 and num2 array
        02. sort the new array
        Time: O(m+n log M+n)  space: O(M+n)
    */
    
    /*  optimal approach:
        01. using mergeFunction in merge sort
        02.creating additional array and copying elements using two pointer 
        approach and finally copying addtional array to input array
        03. Time: O(M+n) space: O(m+n)
    */
        
        
        vector<int>v;
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j]) // why <= ? not only  < sign? reason: stablity
            {
                v.push_back(nums1[i]);
                i++;
            } 
            else 
            {
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m)
        {
            v.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            v.push_back(nums2[j]);
            j++;
        }
        nums1=v;
        
        
        //first time solved: 07.13.2021
        //second time : 10.08.2021
        
        
    }
    
};
