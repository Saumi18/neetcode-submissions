class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
// LargeHeap is minHeap as its top gives us the element at the median junction and has the elements more than or equal to median so store min elements
// Exact oposite is for smallHeap
public:
    MedianFinder() {}
    
    void addNum(int num) {
        smallHeap.push(num);
        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size() == largeHeap.size()){
            return (smallHeap.top() + largeHeap.top())/2.0;
        }
        else if(smallHeap.size() > largeHeap.size()){
            return double(smallHeap.top());
        }
        else{
            return double(largeHeap.top());
        }
    }
};
