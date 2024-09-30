class CustomStack {
    private int[] nums;
    private int mxSize;
    private int topIndex;

    public CustomStack(int maxSize) {
        this.mxSize = maxSize;
        this.nums = new int[mxSize];
        this.topIndex = -1;
    }
    
    public void push(int x) {
        if (topIndex == mxSize - 1) return;
        nums[++topIndex] = x;
    }
    
    public int pop() {
        if (topIndex == -1) return -1;
        return nums[topIndex--];
    }
    
    public void increment(int k, int val) {
        for (int i = 0; i < k && i <= topIndex; i++) {
            nums[i] += val;
        }
    }
}