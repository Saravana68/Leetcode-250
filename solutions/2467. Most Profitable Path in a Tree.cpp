                ans = max(ans,dfs2(v,node,adjM,amount));
            }
        }
        
        if(ans == INT_MIN){
            return amount[node];
        }
        return ans + amount[node];
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();   // Number Of Nodes
        vector<int> parent(n,-1);  // Needed to Move Bob from node B to node 0
        vector<int> distance(n,0); // Needed to decide whether Alice moves first or Bob to current Node
        vector<vector<int>> adjM(n);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];  
            int v = edges[i][1];
            adjM[u].push_back(v);
            //Undirected Given in ques
            adjM[v].push_back(u);
​
        }
        
        //Fill parent and distance , to help in Bob traversal , starting from node 0
        dfs1(0,-1,0,distance,parent,adjM);
        
        //Travel from Bob to 0
        int cur = bob ,curDisOfBob = 0;
        while(cur != 0){
            //Note: distance[cur] here denotes How away Alice in right now from Bob
            if(curDisOfBob < distance[cur]){
                //Bob already traversed , so gate open for ALice
                amount[cur] = 0;
            }
            else if(curDisOfBob == distance[cur]){
                //Both reaches simultaneously , divide equally (price(-) or reward(+))
                amount[cur] = amount[cur]/2;
            }
​
​
            cur = parent[cur];
            curDisOfBob++;
        }
        
        
        //Maximum sum from node 0 till leaf Node
       
        return dfs2(0,-1,adjM,amount);
    
    }
};
