class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int start = 0;
        int shortage = 0;
        int petrol = 0;
        for(int i = 0;i<cost.size();i++){
            petrol += gas[i] - cost[i];
            if(petrol < 0){
                shortage += petrol;
                petrol = 0;
                start = i+1;
            }
        }
        cout<<petrol<<" "<<shortage<<endl;
        if(petrol+shortage >=0) return start;
        return -1;
    }
};
