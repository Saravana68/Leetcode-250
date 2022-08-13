            mp[last_val].erase(arr.size() - 1);
            
            arr.pop_back();
            
            // if there is no occurance of val is present then erase it from map
            
            if(mp[val].size() == 0)
            {
                mp.erase(val);
            }
            
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        
        // generate the random index
        
        int rand_idx = rand() % arr.size();
        
        return arr[rand_idx];
    }
};
