class CustomStack {
public:
    int *nums;
    int mxSize;
    int topIndex;
    
    CustomStack(int maxSize) {
        mxSize = maxSize;
        nums = new int[mxSize];
        topIndex = -1;
    }
    
    ~CustomStack() {
        delete[] nums;
    }
    
    void push(int x) {
        if(topIndex == mxSize - 1)
            return;
        nums[++topIndex] = x;
    }
    
    int pop() {
        if(topIndex == -1)
            return -1;
        return nums[topIndex--];
    }
    

    void increment(int k, int val) {
        for(int i = 0; i < k && i <= topIndex; i++) {
            nums[i] += val;    
        }
    }
};
