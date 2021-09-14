class StockSpanner {
public:
   
    stack<pair<int,int>> st;
    
    int next(int price) {
       int count = 0;
        while(st.size() && st.top().first<=price)
        {
            count++;
            count+= st.top().second;
            st.pop();
        }
        st.push({price,count});
        return count+1;
            
    }
};
​
