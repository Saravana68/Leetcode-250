class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    bool flag = true;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(flag){
            flag = false;
            maxHeap.push(num);
        }
        else{
            if(maxHeap.size() > minHeap.size()){
               if(maxHeap.top() > num){
                   minHeap.push(maxHeap.top());
                   maxHeap.pop();
                   maxHeap.push(num);
               }
               else{ minHeap.push(num);}
            }
            else{
                if(maxHeap.top() >= num) maxHeap.push(num);
                else{
                    minHeap.push(num);
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        
        return (maxHeap.top() + minHeap.top())/2.0;
    }
};
​
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
