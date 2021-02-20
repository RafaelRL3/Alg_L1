/*
//    Made by : Rafael Dos reis De Labio , RRL3
//    Linked-list ou Lista encadeada , Estrutura está funcionando, pelomenos o básico
*/
#include <iostream>
using namespace std;

typedef struct node
{
    int v;
    node *next;
}Node;

Node *start(Node **no){
    Node *sent = new Node();
    sent->next = NULL;
    *no = sent;
    return *no;
}

Node *search(Node **no, int val){
    Node *cur = *no;
    while (cur->next !=NULL && cur->next->v != val)
    {
        cur = cur->next;   
    }
    return cur;
}


void push(Node **no, int v, int j){
    Node *n = new Node();
    n->v = v;
    Node *cur = (*no);
    cur = search(&cur, j);
    n->next = cur->next;
    cur->next = n;
}

void print(Node *head){
    Node *cur = (*head).next;
    while(cur !=NULL){
        cout << cur->v  << " ";
        cur = cur->next;
    }
    cout << endl;
}

void pop(Node **head, int v){
    Node *temp = NULL;
    Node *aux = (*head);
    aux = search(&aux, v);
    temp = aux->next;
    aux->next = temp->next;
    delete(temp);
}  

int main(){
    
    Node *head;
    int v = 10;
    int j = 20;
    head = start(&head);
    push(&head, 10, 20);
    push(&head, 20, 10);
    print(head);
    pop(&head, 10);
    pop(&head, 20);
    
    
    return 0;
}