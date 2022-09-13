// C or C++ program for insertion and
// deletion in Circular Queue
#include<bits/stdc++.h>
using namespace std;
 
class Queue
{
  public:
    // Initialize front and rear
    int rd, wr;
    // Circular Queue
    int size;
    int *arr;
    bool BufferFull;

    Queue(int s)
    {
       rd = wr = 0;
       size = s;
       arr = new int[s];
       BufferFull=false;
    }
 
    void enQueue(int value){
      if(bufferFull()){printf("\nBuffer is Full\n"); return;}
      arr[wr]=value;
      wr=(wr+1)%size;
      if (wr==rd) BufferFull=true;
      return;
    }
    bool bufferFull(){
      return BufferFull;
    }
    int deQueue(){
        int temp=arr[rd];
        rd=(rd+1)%size;
        if(BufferFull)BufferFull=false;
        return temp;
    } 
    void displayQueue(){
      int temp=rd;
      printf("\n");
      while(true){
        printf("%d~", arr[temp]);
        temp=(temp+1)%size;
        if(temp==wr)break;
      }
    }
};
 
 
/* Driver of the program */
int main()
{
    Queue q(5);
 
    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);
 
    // Display elements present in Circular Queue
    q.displayQueue();
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());
 
    q.displayQueue();
 
    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);
 
    q.displayQueue();
 
    q.enQueue(20);
    return 0;
}
