
/*
 
Creating a linked list for a wait line in a police department.

Person:
-number ID
    -waiting number issued at the machine
-problem
    -passport
    -driving license
    - renew passport/ID
 
 */

#include <iostream>

using namespace std;

// struct is public by default
struct ClientInfo
{
    string name;
    string problem;
    int queue_number;
};

// here I declare variables for each node
// should have a pointer to the next node as well as info for client
struct Node
{
    ClientInfo client;
    Node *next;
};

class VisitList
{
    private:
        Node *head;
        
        Node *create() {
            Node *newnode;
            try {
                newnode = new Node;
            }
            catch(bad_alloc) {
                newnode = NULL;
            }
            return newnode;
        }

    public:
        
        VisitList() : head(NULL){}
        
        int queue_number = 0;
        void insert (string name, string problem) 
        {
            queue_number++;
            Node *newnode = create();
            newnode->client.name = name;
            newnode->client.problem = problem;
            newnode->client.queue_number = queue_number;

            if (head == NULL) {
                head = newnode;
                newnode->next = NULL;
            }
            else {
                Node *temp1 = head;
                while (temp1->next != NULL) {
                    temp1 = temp1->next;
                }
                temp1->next = newnode;
                newnode->next = NULL;
            }
        }

        void delete_node (int queue_number) {
            Node *current = head;
            Node *previous = head;

            if (head->client.queue_number == queue_number) {
                head = head->next;
                delete current;
                return;
            }
            
            while (current->client.queue_number != queue_number && current != NULL) {
                previous = current;
                current = current->next;
            }
            if (current != NULL) {
                previous->next = current->next;
                delete current;
                return;
            } else{
                cout << "There is noone with thyat number" << endl;
            }
            
        }

        void display () {
            Node *current = head;
            
            cout << "------------------ - - - -  -  -  -" << endl;
            
            while (current != NULL) {
                cout << current->client.queue_number <<  ". " <<  current->client.name << " -> " << current->client.problem << endl;
                current = current->next;
            }
            cout << "------------------ - - - -  -  -  -" << endl;
        }
};

int main()
{
    VisitList upotreba_kupona;
    
    while (true) {
        string name;
        string problem;

        cout << "Enter your problem: ";
        cin >> problem;

        cout << "Enter your name: ";
        cin >> name;

        upotreba_kupona.insert(name, problem);

        string flag;
        cout << "Were you the last customer? ('y' for yes | 'n' for no)";
        cin >> flag;

        if (flag == "y") {
            break;
        }
    }

    upotreba_kupona.display();

    // part where person can leave the queue and delete his number

    string queue_flag;
    int queue_number;

    cout << "did anyone leave the queue? ";
    cin >> queue_flag;

    if (queue_flag == "y") {
        cout << "what is his queue number? ";
        cin >> queue_number;

        upotreba_kupona.delete_node(queue_number);
    }

    upotreba_kupona.display();
    
    return 0;
}









