            }
        }
        
        cout<<p.first<<endl;
        return mp[p.first];
      
   */
    
   /* 
     EFFICIENT APPROACH 
     ------------------
     01.first store all strings of list1 in map with index
     02.traverse second list if match found check their index sum is minium than current minSum 
     03.if yes clear answer vector and add current string
     04. if index sum is equal to already exisiting minSum then 
     we found another string with same minIndex so just add it to answer vector
     
     TIME COMPLEXITY : 0(N)  SPACE COMPLEXITY : O(N)
     
     */
     
  
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
       unordered_map<string,int> mp;
       vector<string> answer;
       int minSum = INT_MAX;
       for(int i =0;i<list1.size();i++){
          mp[list1[i]] = i;
      }
      for(int i =0;i<list2.size();i++){
          
          if(mp.find(list2[i]) != mp.end()){
              int sum = mp[list2[i]]+i;
              
              if(sum < minSum){
                  answer.clear();
                  minSum = sum;
                  answer.push_back(list2[i]);
              }
              else if(sum == minSum){
                  answer.push_back(list2[i]);
              }
          }
       }
      return answer;
    }
    
};
