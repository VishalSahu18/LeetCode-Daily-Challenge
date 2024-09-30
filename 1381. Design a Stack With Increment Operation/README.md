## Problem Link

https://leetcode.com/problems/design-a-stack-with-increment-operation/description/?envType=daily-question&envId=2024-09-30

## Description

Design a stack that supports increment operations on its elements.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.

void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.

int pop() Pops and returns the top of the stack or -1 if the stack is empty.

void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.

#### Example 1:

## Input:
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]

[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]

## Output:
[null,null,null,2,null,null,null,null,null,103,202,201,-1]

