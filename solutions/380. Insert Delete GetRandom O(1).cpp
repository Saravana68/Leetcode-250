class RandomizedSet {
    
    
    
  /* different Data structure approaches :
  
                  Insertion   Deletion     getRand
             
  vector       :  O(1)        O(N)            O(1) 
  set          :  O(1)        O(1)            O(N)
Doubly llist   :  O(1)        O(N)            O(N)
    
    */
    
    /* Best approach : arrays + Map;  */
     
​
public:
    vector<int> v;
    unordered_map<int,int> myMap;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if(myMap.find(val)!= myMap.end())
            return false;
        v.push_back(val);
        myMap[val] = v.size()-1;
        return true;
    
    }
