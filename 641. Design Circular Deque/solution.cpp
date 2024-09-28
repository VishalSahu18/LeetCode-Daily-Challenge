class Node{
public:
    int val;
    Node* next,*prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyCircularDeque {
public:
    int currSize,totalSize;
    Node *front,*back;

    MyCircularDeque(int k) {
        totalSize = k;
        currSize = 0;
        front = NULL;
        back = NULL;
    }
    
    bool insertFront(int value) {

        if(currSize==totalSize)
            return false;

        if(currSize==0){
            front = new Node(value);
            back = front;
            ++currSize;
            return true;
        }

        Node* tmp = new Node(value);
        tmp->next = front;
        front->prev = tmp;
        front = tmp;
        currSize++;
        return true;
    }
    
    bool insertLast(int value) {

        if(currSize==totalSize)
            return false;

        if(currSize==0){
            front = new Node(value);
            back = front;
            currSize++;
            return true;
        }

        Node* tmp = new Node(value);
        back->next = tmp;
        tmp->prev = back;
        back = back->next;
        currSize++;
        return true;  
    }
    
    bool deleteFront() {

        if(currSize==0)
            return false;

        Node* tmp = front;
        front = front->next;
        tmp->next = NULL;

        if(front!=NULL)
            front->prev = NULL;
        else
            back = NULL;
        

        delete(tmp);
        currSize--;
        return true;

    }
    
    bool deleteLast() {

        if(!currSize)
            return false;

        Node* tmp = back;
        back = back->prev;

        if(back!=NULL)
            back->next = NULL;
        else
            front = NULL;

        delete(tmp);
        currSize--;
        return true;
    }
    
    int getFront() {
       return currSize==0 ? -1 : front->val;
    }
    
    int getRear() {
       return currSize==0 ? -1 : back->val;
    }
    
    bool isEmpty() {
        return currSize==0;
    }
    
    bool isFull() {
        return currSize==totalSize;
    }
};