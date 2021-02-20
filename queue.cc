#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
}Node;

typedef struct queue
{
    Node *head;
    Node *tail;
    queue(){
        Node *st = new Node();
        
        st->data = 0;
        st->next = NULL;
        
        head = st;
        tail = st;
    }
}Queue;

Node *newNode(int d){
    
    Node * temp = new Node();
    
    temp->data = d;
    temp->next=NULL;

    return temp;
}

void push(Queue **q, int d){
    Node *temp = newNode(d);
    if((*q)->head == (*q)->tail){
        (*q)->head->next = temp;
        (*q)->tail = temp;
    }
    else{
        (*q)->tail->next = temp;
        (*q)->tail = temp;
    }
}

void pop(Queue **q){
    if((*q)->head ->next == NULL){
        cout << "Fila vazia" << endl;
    }
    else{
        Node *aux = (*q)->head->next;
        (*q)->head->next = aux->next;
        free(aux);
        if((*q)->head->next == NULL){
            (*q)->tail = NULL;
        }
    }
}

int main(){
    Queue *q = new Queue();
    pop(&q);
    push(&q, 5);
    push(&q, 6);
    push(&q, 7);
    pop(&q);
    pop(&q);
    pop(&q);
    cout << q->head->data << endl;
    return 0;
}