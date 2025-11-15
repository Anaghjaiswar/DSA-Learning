arr[4] = [1,2,3,45,5]

if we want to add one more element , we can not add becuaes array is of fixed sixze , 

arrays are stored in contiguous location

an array is easy to traverse and at the same time you can not increase and descrease the size.d

# linked list

- it helps to increase and decrease the size
- a linked list the elemnts are not stored in contiguous location

like you store 1, 3, 2, 5 
they are stored in heap memory.

so they can be accessed like increasing index as you do in arrays

their size can increase or decrease at any moment.


so how do we traverse??

we store elemnts at the same time we store something like (next)

so if you somehow now where the address of the next element you can traverse 

1 - m1
2- m3
3- m2
5 - m4

1,3,2 5

head of the linked list is stored at m1 location
for 1 next is m2

so you invisbly creating a link to m1

from 2 you are going to m2 ie. 3 and then m4 i.e. 5 and then null pointer


# where it is used?

- it is used in stack and queues data structure
where is real life ??
we use it in a browser ,

in browser you open a tab , you open google.com then you go to a2z then you go to article 

if you clicks you back , it takes you back , it takes you back , it forward , you go to forward


------------------------------------------------------------
-----------------------------------------------------------

int x = 2;
int y = &x; 
cout << y;


in c++ , you can not directly store a memory location , so you store a pointer to it

we are storing to thing one is the data itself and next is the poniter to the next 

you have to defined a self defined data type 

```
struct Node {
    int data;
    Node* next;
    Node(data1,next1){
        data=data1;
        next=next1;
    }
}
```
### how to initialize 
Node x= Node(2, nullptr);
Node* y = &x;


easist way is Node* y = new Node(2, nullptr);
refer LL.cpp


# memory space


if 32 bit system

- int wil take 4 bytes 
- pointer will take 4 bytes

if 64 bit system

- int will take 4 bytes
- pointer will take 8 bytes


-------------------------------------------------


