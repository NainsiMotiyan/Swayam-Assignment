#include <iostream>
using namespace std;

// Simple queue using array
class QueueArray {
    int arr[1000];
    int frontIndex, rearIndex, size;
public:
    QueueArray(){ frontIndex=0; rearIndex=-1; size=0; }

    void enqueue(int x){
        arr[++rearIndex] = x;
        size++;
    }

    void dequeue(){ if(size>0){ frontIndex++; size--; } }

    int front(){ return arr[frontIndex]; }
    bool empty(){ return size==0; }
};

int main(){
    QueueArray q;
    q.enqueue(10);
    q.enqueue(20);
    cout << q.front() << endl; // 10
    q.dequeue();
    cout << q.front() << endl; // 20
}
