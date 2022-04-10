class Solution {
public:
    int largestInteger(int num) {
        
        
        string str = to_string(num);
        string temp = str;
        
        priority_queue<char> even;
        priority_queue<char> odd;
        
        for(int i =0;i<temp.length();i++){
            
            char curr = temp[i] ;
            if(curr & 1) 
                odd.push(temp[i]) ;
            else 
               even.push(temp[i]) ;
        }
        
        for(int i =0;i<temp.length();i++){
            
            char curr = temp[i] ;
            if(curr &1){ 
                str[i] = odd.top(); odd.pop();}
            else{ 
                str[i] = even.top(); even.pop();}
        }
        int final_value = stoi(str);
        return final_value;
       
    }
};
