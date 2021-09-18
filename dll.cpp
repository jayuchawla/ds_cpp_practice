#include <iostream>
using namespace std;

class Node {
    public:
        int key;
        int data;
        Node *next, *prev;

        Node(int k) {
            key = k;
            data = -1;
            next = prev = NULL;
        }

        Node(int k, int d) {
            key = k;
            data = d;
            next = prev = NULL;
        }        
};

class DLL {
    private :
        Node *head;
    public:
        DLL() {
            head = NULL;
        }

        Node* nodeWithKeyExists(int k) {
            Node *tr = head;
            while(tr!=NULL) {
                if(tr->key == k) {
                    return tr;
                }
                tr = tr->next;
            }
            return NULL;
        }

        void appendNode(Node *n) {
            if(head == NULL) {
                head = n;
            } else if(nodeWithKeyExists(n->key) != NULL) {
                cout<<"Another node with same key already exists!"<<endl;
            } else {
                Node *tr = head;
                while(tr->next != NULL)
                    tr = tr->next;
                tr->next = n;
                n->prev = tr;
            }
        }

        void prependNode(Node *n) {
            if(head == NULL) {
                head = n;
            } else if(nodeWithKeyExists(n->key) != NULL) {
                cout<<"Another node with same key already exists!"<<endl;
            } else {
                n->next = head;
                head->prev = n;
                head = n;
            }
        }

        void insertNode(int k, Node *n) {
            if(head == NULL) {
                cout<<"DLL blank!"<<endl;
            } else if(nodeWithKeyExists(n->key) != NULL) {
                cout<<"Another node with same key already exists!"<<endl;
            } else {
                Node *tr = nodeWithKeyExists(k);
                if(tr != NULL) {
                    // handling the case when k is key for last node
                    if(tr->next == NULL) {
                        tr->next = n;
                        n->prev = tr;
                    } else {
                        n->next = tr->next;
                        n->prev = tr;
                        tr->next->prev = n;
                        tr->next = n;
                    }
                } else {
                    cout<<"Key: "<<k<<" not found in dll!"<<endl;
                }
            }
        }

        void updateNode(int k, int d) {
            if(head == NULL) {
                cout<<"DLL blank!"<<endl;
            } else{
                Node *tr = nodeWithKeyExists(k);
                if(tr != NULL) {
                    tr->data = d;
                } else {
                    cout<<"Key: "<<k<<" not found in dll!"<<endl;
                }
            }
        }

        void deleteNode(int k) {
            if(head == NULL) {
                cout<<"DLL blank!"<<endl;
            } else {
                Node *tr = nodeWithKeyExists(k);
                if(tr != NULL) {
                    if(head->key == k) {
                        Node *t = head;
                        head = head->next;
                        delete t;
                    } else {
                        tr->prev->next = tr->next;
                        // when node to be deleted is not last node
                        if(tr->next != NULL)
                            tr->next->prev = tr->prev;
                        // the case : when above if is ignored -> for last node -> directly delete last node
                        delete tr;
                    }
                } else {
                    cout<<"Key: "<<k<<" not found in dll!"<<endl;
                }
            }
        }

        void display() {
            if(head == NULL) {
                cout<<"DLL blank!"<<endl;
            } else {
                cout<<"DLL is:"<<endl;
                Node* tr = head;
                while(tr != NULL) {
                    cout<<tr->key<<":"<<tr->data<<"--->";
                    tr = tr->next;
                }
                cout<<endl;               
            }           
        }
};

int main() {
    Node *n1 = new Node(1,2), *n2 = new Node(3,4), *n3 = new Node(3,5), *n4 = new Node(4,45);
    DLL dll;
    dll.appendNode(n3);
    dll.prependNode(n2);
    dll.appendNode(n1);
    dll.display();
    dll.insertNode(3,n4);
    dll.insertNode(31,n4);
    dll.display();
    dll.updateNode(1,59);
    // dll.updateNode(11,69);
    // dll.display();
    return 0;
}