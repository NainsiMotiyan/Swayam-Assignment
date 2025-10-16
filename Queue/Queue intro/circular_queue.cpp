#include <iostream>
using namespace std;

// Circular queue implementation
class CircularQueue{
    int arr[100];
    int front, rear, capacity, count;
public:
    CircularQueue(int size){
        capacity = size;
        front = 0; rear = -1; count = 0;
    }

    void enqueue(int x){
        if(count == capacity) return; // full
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    void dequeue(){ if(count>0){ front = (front+1)%capacity; count--; } }
    int getFront(){ return arr[front]; }
    bool empty(){ return count==0; }
};

int main(){
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    cout << q.getFront() << endl; // 10
}
