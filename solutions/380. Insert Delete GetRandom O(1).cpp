class RandomizedSet {
    
    
    
  /* different Data structure approaches :
  
                  Insertion   Deletion     getRand
             
  vector       :  O(1)        O(N)            O(1) 
  set          :  O(1)        O(1)            O(N)
Doubly llist   :  O(1)        O(N)            O(N)
    
    */
    
    /* Best approach : arrays + Map;  */
     

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
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!myMap.count(val))
            return false;
        
        myMap[v.back()] = myMap[val];
        swap(v.back(),v[myMap[val]]);
        v.pop_back();
        myMap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
           return v[rand() % v.size()];
    }
};
