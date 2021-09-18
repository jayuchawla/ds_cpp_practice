#include <iostream>
using namespace std;

class Node {
    public:
        int key, data;
        Node *next;

        Node (int k) {
            key = k;
            data = -1;
            next = NULL;
        }

        Node(int k, int d) {
            key = k;
            data = d;
            next = NULL;
        }
};

class CSLL {
    private:
        Node *head;
    public: 
        CSLL() {
            head = NULL;
        }

        Node* nodeWithKeyExists(int k) {
            Node *tr = head;
            // this wont work for last node: hence check it explicitly
            while(tr->next != head) {
                if(tr->key == k) {
                    return tr;
                }
                tr = tr->next;
            }
            if (tr->key == k)
                return tr;
            return NULL;
        }

        void appendNode(Node *n) {
            if(head == NULL) {
                head = n;
                head->next = head;
            } else if(nodeWithKeyExists(n->key) != NULL) {
                cout<<"Node with key: "<<n->key<<" already exists!"<<endl;
            } else {
                Node *tr = head;
                while(tr->next != head) {
                    tr = tr->next;
                }
                tr->next = n;
                n->next = head;
            }
        }

        void prependNode(Node *n) {
            // the only difference between prepend and append is: prepend requires head to be pointed to latest inserted node
            appendNode(n);
            head = n;
        }

        void insertNode(int k, Node* n) {
            if(head == NULL) {
                head = n;
                head->next = head;
            } else if(nodeWithKeyExists(n->key) != NULL) {
                cout<<"Node with key: "<<n->key<<" already exists!"<<endl;
            } else {
                Node *tr = nodeWithKeyExists(k);
                if(tr != NULL) {
                    n->next = tr->next;
                    tr->next = n;
                } else {
                    cout<<"Node with key: "<<k<<" does not exists!"<<endl;
                }               
            }
        }

        void updateNode(int k, int d) {
            if(head == NULL) {
                cout<<"Blank csll!"<<endl;
            } else {
                Node *tr = nodeWithKeyExists(k);
                if(tr == NULL) {
                    cout<<"Node with key: "<<k<<" does not exists!"<<endl;
                } else {
                    tr->data = d;
                }
            }
        }

        void deleteNode(int k) {
            if(head == NULL) {
                cout<<"Blank csll!"<<endl;
            } else {
                Node *tr = nodeWithKeyExists(k);
                if(tr != NULL) {
                    if(tr == head) {
                        if(tr->next == head) {
                            head = NULL;
                            return;
                        } else {
                            head = head->next;
                        }
                    }
                    // making required pointer modifications: prev is required to point to a node previous to node to be deleted
                    Node *prev = tr;
                    while(prev->next != tr)
                        prev = prev->next;                    
                    prev->next = tr->next;
                    delete tr;
                } else {
                    cout<<"Node with key: "<<k<<" does not exists!"<<endl;
                }
            }
        }

        void display() {
            if(head == NULL) {
                cout<<"Blank csll!"<<endl;
            } else {
                cout<<"CSLL: "<<endl;
                Node *tr = head;
                // this wont work for last node: hence check it explicitly
                while(tr->next != head) {
                    cout<<tr->key<<":"<<tr->data<<"--->";
                    tr = tr->next;
                }
                cout<<tr->key<<":"<<tr->data<<"--->"<<endl;
            }
        }
};

int main() {
    Node *n1 = new Node(1,2), *n2 = new Node(3,4), *n3 = new Node(3,5), *n4 = new Node(4,45);
    CSLL csll;
    csll.appendNode(n2);
    csll.deleteNode(3);
    csll.display();

    csll.appendNode(n3);
    csll.insertNode(3, n4);
    csll.display();
    
    csll.prependNode(n1);
    csll.display();

    csll.insertNode(31, n4);
    csll.display();

    csll.updateNode(4, 67);
    csll.updateNode(1, 45);
    csll.display();

    csll.insertNode(1, n4);
    csll.deleteNode(34);
    csll.deleteNode(1);
    csll.display();   
    return 0;
}