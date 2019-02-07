/*
Author: Lalata Indu Sahu
Problem: Given a head pointer of a linked list, divide the linked list into N number of lists.

*/

#include <iostream>
#include <string>
using namespace std;
typedef struct SLLNODE{
    struct SLLNODE * next;
    int data;
}SLLNODE;

typedef struct MultiSingleLinkedListNode{
    SLLNODE* sllhead;
    struct MultiSingleLinkedListNode *next;
}MSLLNODE;

SLLNODE* CreateSLL(int size){
    SLLNODE *root = NULL;
    SLLNODE *node = NULL, *pnode = NULL;
    int index = 0;
    while(size-- > 0){
        
        if(root == NULL){
            root = new SLLNODE; /* root does not exist, so create the root node */
            node = root; // assign it to node tracker
            
        }
        else{
            /* root alreadt exists, create a new node at the next of this node */
            node->next = new SLLNODE;
            node = node->next; /* change the current node tracker to newly created node */
        }
         
        node->data = ++index; /* update the data in the newly created node */
        node->next = NULL; /* make the NEXT of null for the newly created node */
    }
    
    return root;
}

void PrintSLL(SLLNODE* node){
    while(node != NULL){
        cout << node->data << "\t";
        node = node->next;
    }
    cout << endl;
}

MSLLNODE* DivideTheSLL(SLLNODE* proot, int nparts){
    SLLNODE* node = proot;
    MSLLNODE* mslhead = NULL;
    cout << "Divided lists are as below\n";
    int size = 0;
    
    bool createnewpart = true;
    /* find size of the SLL */
    while(node){
        size++;
        node = node->next;       
    }
    
    node = proot;
    /* Divide the SLL into nparts */
    int minimumlength = size/nparts;
    
    int divider = 0;
    bool createnewmslnode = true;
    MSLLNODE *mslnode = NULL;
    if(minimumlength > 0){
        int parts = 0;
        while(node){
            divider++;
            //for (int parts = 0 ; parts <=nparts){
            if(createnewmslnode){
                parts ++;
                /* create a new MSLLNODE  */
                if(mslhead == NULL){
                    mslhead = new MSLLNODE;
                    mslnode = mslhead;
                }
                else{
                    mslnode->next = new MSLLNODE;
                    mslnode = mslnode->next;
                }
                mslnode->sllhead = node;
                mslnode->next = NULL;
                createnewmslnode = false;
            }
            
            /* logic to de-link */
            
            if(divider == minimumlength && parts < nparts){
                divider = 0;
                SLLNODE* tmpnode = node->next;
                node->next = NULL;
                node = tmpnode;
                createnewmslnode = true;
                
            }
            else{   
                node = node->next;
            }
        }
    }
    
    return mslhead;
    
}
void PrintMSLL(MSLLNODE* mlnode){
    while(mlnode){
        SLLNODE *slnode = mlnode->sllhead;
        while(slnode){
            cout << slnode->data << "\t";
            slnode = slnode->next;
        }
        cout << endl;
        mlnode = mlnode->next;
    }
}
int main()
{
    int nparts = 0;
    int size = 0;
    cout << "Size of the Linked list ?" << endl;
    cin >> size;
    
    cout << "The number of parts you want to divide the linked list is ?\n";
    cin >> nparts;
    
    SLLNODE* root = CreateSLL(size);
    PrintSLL(root);
    
    /* Actual problem solver. Note: problem need to solved as if you don't know the size of the linked list*/
    MSLLNODE* mlhead = NULL;
    mlhead = DivideTheSLL(root, nparts);
    PrintMSLL(mlhead);
    
    return 0;
}
