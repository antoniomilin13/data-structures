
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

        void insert (string name, string problem) 
        {
            Node *newnode = create();
            newnode->client.name = name;
            newnode->client.problem = problem;

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
        void display () {
            Node *current = head;
            int i = 1;

            while (current != NULL) {
                cout << i <<  ". " <<  current->client.name << " -> " << current->client.problem << endl;
                current = current->next;
                i++;
            }
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

    return 0;
}









