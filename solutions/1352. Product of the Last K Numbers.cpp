class ProductOfNumbers {
public:
    vector<int> prefix ={1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0)
            prefix = {1};
        else 
            prefix.push_back(prefix.back()*num);
    }
    
    int getProduct(int k) {
        int size = prefix.size()-1;
        if(size < k) return 0;
        return prefix.back() / prefix[size-k];
    }
};
​
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
