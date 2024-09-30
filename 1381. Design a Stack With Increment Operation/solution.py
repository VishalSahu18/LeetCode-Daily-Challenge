class CustomStack:
    def __init__(self, maxSize: int):
        self.nums = []
        self.mxSize = maxSize

    def push(self, x: int) -> None:
        if len(self.nums) == self.mxSize:
            return
        self.nums.append(x)

    def pop(self) -> int:
        if not self.nums:
            return -1
        return self.nums.pop()

    def increment(self, k: int, val: int) -> None:
        for i in range(min(k, len(self.nums))):
            self.nums[i] += val