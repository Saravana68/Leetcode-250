class Solution {
public:
  /*  
    Idk whether current solution is best or not
    but I solved this without seeing hints & discussion forum    
    My Intution :
    
    Step  1
    by seeing diagram I thought counting extra edges in each component while traversing edge list
    if two vertex is already in same component then curr edge is extra edge
    to find two vertex is in same component or not I've used Union & Find method. 
    
    Step 2
    then find no of components present in given graph.  how ?
    each component will have one root that root will have parent as -1 
    so count no fo vertex which has parent -1
    
    reduce component count by 1. why ? 
    Assume  3 component present in graph
    then one is going to be stable & we're going two merge other two with this.
    so if reduce count by one then component count will be 2 right ?
    two connect two component I need two edges. you can connect them anyway
    */
    
    /*
    -> Ways to connecting two component  B and C with stable component A
            Method 1    Method 2     Method 3
            A - B       C - A- B     A - B - C
            |
            C
    -> see to connect two disconnected component we need two edges for sure. 
    -> so if extra edges >= components we can simply return components value 
    -> else if means extra edges not sufficient to connect disconnected components so return -1
    
    */
    int findParent(int i, vector<int> &parent){
        if(parent[i] == -1) return i;
        return parent[i] = findParent(parent[i],parent);
    }
    bool doUnion(int u,int v,vector<int> &parent,vector<int> &rank){
        
        int uPar = findParent(u,parent);
        int vPar = findParent(v,parent);
        
        if(uPar == vPar) return true;
        
        if(rank[uPar] < rank[vPar]) { parent[uPar] = vPar;}
        else if(rank[vPar] < rank[uPar]) { parent[vPar] = uPar;}
        else { parent[uPar] = vPar; rank[vPar]++;}
        return false;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
       
        int extraEdges = 0;
        int components = 0;
        
       
        vector<int> parent(n);
        vector<int> rank(n);
        
        for(int i =0;i<n;i++){ 
            rank[i]=0; 
            parent[i] = -1; 
            }
        
        for(vector<int> it : connections){
