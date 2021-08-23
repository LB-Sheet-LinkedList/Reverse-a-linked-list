/*
Refer apna college video

Iterative method se kiya hai maine

Time Complexity: O(n) 
Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node 
{
    int data;              //node ka data
    struct Node* next;     //node ka next pointer
    
    //Taaki naya node jo bne usme already ek input ho and ek NULL pointer ho
    Node(int data)         //constructor
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList     
{
    struct Node *head;     //head pointer declare kiya of type Node
    
    //jab bhi nayi linked list bnaegi aur chaahe kitni bhi bane. agar usme abbhi tak kuch push nhi kiya hai to vo 
    // head1->NULL  head2->NULL ... isi form me hogi
	
	LinkedList()           //constructor
	{ 
		head = NULL;
		//ab jab bhi ek LL banegi tab ek head pointer automatically bnega alag se bnane ki garaz nhi 
	}
 
    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node *current = head;
        Node *prev = NULL; 
		Node *next = NULL;
 
        while (current != NULL) 
		{
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    /* Function to print linked list */
    void print()
    {
    	cout<<"\n";
        struct Node* temp = head;  //pointer hai jo head ki taraf point karega
        while (temp != NULL) 
		{
            cout << temp->data << "->";
            temp = temp->next;  //next element pe point karo
        }
        cout<<"NULL"<<endl;
    }
 
 	//push function define kiya
    void push(int data)
    {
    	//Node type ka hi iterator bnaya jaise int i bnaate apan
        Node* temp = new Node(data);
        
        temp->next = head;
        head = temp;
    }
};

/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    
    //tail me ek ek bharte jaao
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}
