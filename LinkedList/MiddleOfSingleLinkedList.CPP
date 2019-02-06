// Example program
#include <iostream>
#include <string>
using namespace std;
typedef struct SLLNODE{
    struct SLLNODE * next;
    int data;
}SLLNODE;

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
        
SLLNODE* FindMiddleOfSLL(SLLNODE* proot){
    int finder = 0;
    SLLNODE* pmiddle = NULL, *pforwarder = NULL;
    pmiddle = proot;
    pforwarder = proot;
    while( pforwarder){
        finder ++;
        pforwarder = pforwarder->next;
    }
    finder = finder/2 + 1;
    
    while(--finder){
        pmiddle = pmiddle->next;
    }
    return pmiddle;
}

int main()
{
    SLLNODE* root = CreateSLL(4);
    PrintSLL(root);
    SLLNODE* pmiddlenode = FindMiddleOfSLL(root);
    if(pmiddlenode){
        cout << "\nMiddle node = " << pmiddlenode->data << endl;
    }
    else{
        cout << "NO NODE" << endl;
    }
    
    return 0;
}
