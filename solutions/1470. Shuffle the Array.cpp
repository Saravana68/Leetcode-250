class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int size = 2*n;
        vector<int> answer(size);
        int ptr = 0;
        for(int i =0,j = n;j<size;j++,i++){
            answer[ptr] = nums[i];
            answer[ptr+1] = nums[j];
                   ptr += 2;
        }
        return answer;
    }
};
