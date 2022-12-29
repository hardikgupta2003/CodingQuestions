#include <bits/stdc++.h> 
class Queue {
    int size;
    int *arr;
    int f;
    int r;
public:
    Queue() {
       size=100001;
        arr= new int[size];
        f=0;
        r=0;
    }

  

    bool isEmpty() {
       if(f==r){
           return true;
       }
        else {
            return false;
        }
    }

    void enqueue(int data) {
       if(f==size){
           return;
           
       }
        else {
            arr[r]=data;
            r++;
        }
    }

    int dequeue() {
       if(f==r){
          return -1;
           
       }
        else{
            int ans=arr[f];
           arr[f] =-1;
            f++;
            if(f==r){
                f=0;
                r=0;
            }
            return ans;
        }
    }

    int front() {
        if (f==r){
            return -1;
        }else{
        return arr[f];
        }
    }
};
