#include <iostream>
#include <string> 
//TAMANHO DA LISTA VAI SER DEFINIDA PELA QTD DE CPU 
using namespace std;
//-------StartData----------------
int ciclo = 0;  
int p = 0, s = 0;
int count = 0;
typedef struct node
{
    bool f; // flag para adimission    
    int time;
    int id;
    node *next;
}Node;

typedef struct list
{   
    Node *head;
    int tam;
    list(){
        Node *sent = new Node();
        head = sent;
    }
    
}List;

typedef struct queue
{
    Node *head;
    Node *tail;
    queue(){
        Node *st = new Node();
        
        st->id = 0;
        st->next = NULL;
        
        head = st;
        tail = st;
    }
}Queue;
//------------EndData--------------
Node *newNode(int d){
    
    Node * temp = new Node();
    temp->f = false;
    temp->id = d;
    temp->next=NULL;

    return temp;
}
//--------------QueueFunct---------
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

Node *pop(Queue **q){
    if((*q)->head ->next == NULL){
        cout << "Fila vazia" << endl;
    }
    else{
        Node *aux = (*q)->head->next;
        (*q)->head->next = aux->next;
        if((*q)->head->next == NULL){
            (*q)->tail = NULL;
        }
        return aux;
    }
}
//----------EndQueuefunct-----------------
//----------ListFunct---------------------
Node *search(Node **no, int val){ // return node before the node that we search
    Node *cur = *no;
    while (cur->next !=NULL && cur->next->id != val)
    {
        cur = cur->next;   
    }
    return cur;
}

void popList(Node **n, int id){
    
    Node *aux = *n;
    Node *temp = NULL;
    aux = search(&(aux),id); 
    temp = aux->next;
    aux->next = temp->next;
    free(temp);
}

void pushList(Node **n, List **l){
    Node *aux = (*l)->head;
    while( aux->next!= NULL)
        aux = aux->next;
    aux->next = (*n);
    (*n)->next = NULL;
}

Node *TER(Node **sent, int id){
   
    Node *aux = *sent;
    Node *temp = NULL;

    while (aux->next != NULL && aux->next->id != id)
    {   
        aux = aux->next;   
    }
    if(aux->next != NULL){
        temp = aux->next;
        aux->next = temp->next;
        temp->next = NULL;
        return temp; 
    }
    else{
        
    }
}

void C(Queue **e, List **l){
    if((*e)->head->next == NULL){
        return;
    }
    else{
        while ((*e)->head->next != NULL){
            Node *aux = (*e)->head->next;
            (*e)->head->next = aux->next;
            cout << aux->id << " " << aux->time << endl;
            free(aux);
            (*l)->tam++;
            if((*e)->head->next == NULL )
                (*e)->tail = NULL;
        }
    }
}

void I(List **l, Queue **q){
    Node *aux = (*l)->head;
    Node *aux2 = NULL;
    int qtd = 0;
    while(aux->next != NULL){
        if(aux->next->time % s == 0 && aux->next->time !=0){
            aux2 = aux->next;
            aux->next= aux2->next;
            (*q)->tail->next = aux2;
            aux2->next=NULL;
            qtd++;
        }
        aux = aux->next;
    }
    (*l)->tam += qtd;
    cout << qtd << endl;
}

void A(int a){
    count = 0;
    while( a != p){
        count++;
    }
    cout << count << endl;
}

void D(List **l, Queue **q){
    Queue *Q = (*q);
    int cont = 0;
    List *n = (*l);
    while((*l)->tam !=0){
        Node *aux = pop(&Q);
        pushList(&aux, &n);
        (*l)->tam--;
        cont++;
    }
    cout << cont << endl;
}

int main(){
    int id = 0;
    string op;
    Queue *q = new Queue();
    List *l = new List();
    Queue *e = new Queue();
    cin >> p  >> s;
    cin >> op >> id;
    l->tam = p;
    cout << op << " " << id <<endl;

    while(op.compare("END")){

        if(!op.compare("NEW")){
            push(&q, id);
        }

        else if(!op.compare("TER")){
            
            if(e->head == e->tail){
                e->head->next = TER(&l->head, id);
                e->tail = e->head->next;
                l->tam--;
            }
            else{
                e->tail->next = TER(&l->head, id);
                e->tail = e->tail->next;
                l->tam--;
            }

        }
        else if (!op.compare("SCH")){

            cout << "ciclo " << ciclo << endl;
            ciclo++;
            C(&e,&l);
            //func I
            I(&l, &q);
            //func A
            A(l->tam);
            //func D
            D(&l, &q);
        } 

        cin >> op >> id;
    
    }

    return 0;
}