#include<iostream>
#include<queue>

using namespace std;

class kQueue{
    private:
    int *arr;
    int *next;
    int *front;
    int *rear;
    int index;
    int freespot;
    
    public:
    
    kQueue(int n, int k){
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        
        next = new int[n];
        for(int i = 0 ; i < k; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        
        for(int i = 0; i < n; i++) {
            next[i] = i+1;
        }
        next[n-1] = -1;
        
        freespot = 0;
    }
    
    void push(int x, int qn) {
        //check for overflow
        if(freespot == -1){
            cout << " NO space is available in the Queue !!! " << endl;
        }
        
        //find index where we want to insert
        index = freespot;
        
        //update the free index
        freespot = next[index];
        //first element
        if(front[qn-1] == -1) {
            front[qn-1] = index;
        }
        else {
            next[rear[qn-1]] = index;
        }
        
        next[index] = -1;
        
        //point rear to the index
        rear[qn-1] = index;
        
        arr[index] = x;
    }
    
    int pop(int qn) {
        //check for underflow
        if(front[qn-1] == -1){
            cout << " Queue Underflow !!! " << endl;
        }
        //find index
        index = front[qn-1];
        
        //update front
        front[qn-1] = next[index];
        
        //next update
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main() {
    
    kQueue kq(10, 2);
    
    kq.push(15, 1);
    kq.push(15, 2);
    kq.push(13, 2);
    kq.push(55, 2);
    
    cout << " 1st element viz popped out is  : " << kq.pop(2) << endl;
    cout << " 2nd element viz popped out is  : " << kq.pop(2) << endl;
    cout << " 3rd element viz popped out is  : " << kq.pop(2) << endl;
    
    return 0;
}