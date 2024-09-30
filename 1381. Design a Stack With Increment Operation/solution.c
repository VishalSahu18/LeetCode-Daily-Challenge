typedef struct {
    int *nums;
    int mxSize;
    int topIndex;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    CustomStack* obj = (CustomStack*)malloc(sizeof(CustomStack));
    obj->mxSize = maxSize;
    obj->nums = (int*)malloc(maxSize * sizeof(int));
    obj->topIndex = -1;
    return obj;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->topIndex == obj->mxSize - 1)
        return;
    obj->nums[++(obj->topIndex)] = x;
}

int customStackPop(CustomStack* obj) {
     if (obj->topIndex == -1)
        return -1;
    return obj->nums[(obj->topIndex)--];
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    for (int i = 0; i < k && i <= obj->topIndex; i++) {
        obj->nums[i] += val;
    }
}

void customStackFree(CustomStack* obj) {
    free(obj->nums);
    free(obj);
}

