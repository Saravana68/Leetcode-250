class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     
        
              
/*  first time solving. Date: 08.08.2021
    brute force approach will be generating all subarray sum & check divisible by k
    if yes increment count and finally return count
        
    optimal approach whenever we divide value by k it will yield remainder from 0 to k-1;
    example : 7 % 5 = 2 ;  anyvalue % 5 can't more than 0 to 4
    suppose first subarray sum has rem : 4 
        
    Origin ------4---------4 ------4 
     A ----------B---------C-------D
    now A to B has rem :4 
    A to C  has rem :4 
    A to D has also rem: 4
    it clearly says that from B to C , B to D, C to D has values which are % by k
    considering points no of indices having rem = 4 is 3 
    from 3 we need to take all two indices which form subarray which surely % by k
    Ncr = 3C2 = 3*2/2 = 3  answer = 3 subarrays sum present from A to D which are divisble by k
    since we are taking NCR if will yield 0 if rem is 0 
    so handle the special case if rem  = 0;   */
        
    int n = nums.size();
    unordered_map<int ,int> mp;
    int count =0;
    int prefix = 0;
    int rem =0;
    mp[0] =1;
    
    for( int i=0;i<n;i++)
    {
        prefix += nums[i];
        rem = (prefix % k + k ) % k;
        if(mp.find(rem)!= mp.end())
            count += mp[rem];
        
        mp[rem]++;
    }
    return count;
    
        
    }
};
