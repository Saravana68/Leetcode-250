class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> answer;
        answer.push_back(0);
        stack<int> st;
        st.push(size-1);
        cout<<st.top();
        
        
        for(int i = size-2;i>=0;i--)
        {
            while(st.size() && temperatures[st.top()]<= temperatures[i])
                st.pop();
            
            int value = (st.empty() == true )? 0 : st.top()-i;
            st.push(i);
            answer.push_back(value);
            
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
