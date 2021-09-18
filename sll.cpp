#include <iostream>
using namespace std;

class Node {
    public:
        int key,data;
        Node* next;
        
        Node(int k) {
            key = k;
            next = NULL;
        }
        Node(int k, int v) {
            key = k;
            data = v;
            next = NULL;
        }
};

class SLL {
    private:
        Node* head;
    public:
        SLL() {
            head = NULL;
        }

        Node* nodeWithKeyExists(int k) {
            Node* tr = head;
            while(tr != NULL) {
                if(tr->key == k) {
                    return tr;
                }
                tr = tr->next;
            }
            return NULL;
        }

        void prependNode(Node* n) {
            if(head == NULL) {
                head = n;      
            } else if(nodeWithKeyExists(n->key) != NULL) {
                cout<<"Node with key: "<<n->key<<" already in sll!"<<endl;
            } else {
                n->next = head;
                head = n;
            }
        }

        void appendNode(Node* n) {
            if(head == NULL) {
                head = n;      
            } else if(nodeWithKeyExists(n->key) != NULL) {
                cout<<"Node with key: "<<n->key<<" already in sll!"<<endl;
            } else {
                Node* tr = head;
                while(tr->next != NULL) {
                    tr = tr->next;
                }
                tr->next = n;
            }
        }

        void insertNode(int k, Node* n) {
            if(head == NULL) {
                cout<<"SLL is blank!"<<endl;
                return;
            } else if(nodeWithKeyExists(n->key) != NULL) {
                cout<<"Node with key: "<<n->key<<" already in sll!"<<endl;
            } else {
                Node* tr = nodeWithKeyExists(k);
                if(tr != NULL) {
                    n->next = tr->next;
                    tr->next = n;    
                }
                else
                    cout<<"SLL does not contains key: "<<k<<endl;
            }
        }

        void updateNode(int k, int d) {
            if(head == NULL) {
                cout<<"SLL is blank!"<<endl;
                return;
            }
            Node* tr = nodeWithKeyExists(k);
            if(tr != NULL) {
               tr->data = d;
            } else
                cout<<"SLL does not contains key: "<<k<<endl;
        }

        void deleteNode(int k) {
            if(head == NULL) {
                cout<<"SLL is blank!"<<endl;
                return;
            }
            Node* tr = nodeWithKeyExists(k);
            if(tr != NULL) {
               if(head->key == k) {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                } else {
                    Node* tr = head;
                    while(tr->next != NULL && tr->next->key != k) {
                        tr = tr->next;
                }
                Node* temp = tr->next;
                tr->next = tr->next->next;                
                delete temp;
            }
            } else
                cout<<"SLL does not contains key: "<<k<<endl;
        }

        void display() {
            if(head == NULL) {
                cout<<"SLL is blank!"<<endl;               
            } else {
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
    Node n1(1,2);
    Node n2(2,3);
    Node n3(3,44);
    Node n4(3,59);
    SLL sll;
    sll.prependNode(&n2);
    sll.appendNode(&n3);
    sll.insertNode(2, &n1);
    sll.insertNode(3,&n4);
    sll.display();
    sll.deleteNode(2);
    sll.deleteNode(3);
    sll.display();
    sll.updateNode(11, 99);
    sll.display();
    return 0;
}