#include <iostream>
#include <string>
using namespace std;
//--------------defines--------
//-----------Estructs ----- 
typedef struct node
{
    bool flag;
    int id;
    int temp;
    node *next;
}Node;

typedef struct list
{
    Node *head;
    int tam;
    list(){
        Node *sent;
        sent = new Node();
        head = sent;
        sent->next = NULL;
        sent->id = 0;
    }
}List;

typedef struct queue{
    Node *head;
    Node *tail;
    int tam;
    queue(){
        Node *sent;
        sent = new Node();
        head = sent;
        tail = sent;
        sent->next = NULL;
    }
}Queue;

//----------E.d--------

Node *Dq(Node **n){
    Node *aux = (*n);
    (*n)->next = aux->next;
    return aux;
}

Node *search(Node **no, int id){
    Node *cur = *no;
    while (cur->next !=NULL && cur->next->id != id)
    {
        cur = cur->next;   
    }
    return cur;
}

void listPush(List **l, int id){
    Node *n = new Node();
    n->id = id;
    Node *cur = (*l)->head->next;
    cur = search(&cur, id);
    n->next = cur->next;
    cur->next = n;
}

void NEW(Queue **q, int id){
    Node *a = new Node();
    a->id = id;
    a->flag = false;
    a->temp = 0;
    a->next = NULL;
    if((*q)->head->next == NULL){
        (*q)->head->next = a; 
        (*q)->tail = a;
        (*q)->tam++;
    }else{
        (*q)->tail->next = a;
        (*q)->tam++;
    }
}

void TER(List **l,int id){
    Node *aux = (*l)->head->next;
    while (aux->next != NULL && aux->next->id != id){
        aux = aux->next;
    }
    if( aux->next != NULL ){
        aux->next->flag = true;
    }
}

void C(List **l){
    Node *aux = (*l)->head;
    while(aux->next != NULL){
        if(aux->next->flag == true){
            Node *temp = NULL;
            temp = aux->next;
            aux->next= temp->next;
            cout << temp->id << temp->temp << endl;
            free(temp);
            (*l)->tam ++;
        }
        else aux = aux->next;
    }
}

void I(List **l, Queue **q, int s){
    Node *aux = (*l)->head;
    while(aux->next != NULL){
        if(aux->next->temp%s == 0){
            (*q)->tail->next = aux->next;
            (*q)->tail = aux->next;
            aux->next = aux->next;
            (*q)->tail->next = NULL;
            (*l)->tam++;
        }
        else{
            aux->temp++;
        }
        aux = aux->next;
    }
}

void A(int a){
    cout << a << endl;
}

void D(Queue **q, List **l, int p){
    int count = 0;
    while()Node *aux = Dq(&(*q)->head);
    listPush(&(*l),aux->id);
    count ++;
    free(aux);
}  

int main(){
    Queue *q = new Queue();
    Queue *e = new Queue();
    List *l = new List();
    int p, s, id, ciclo=0;
    int count = 0;
    q->tam = 0;
    string op;
    
    cin >> p >> s ;
    cin >> op >> id;
    
    l->tam = p;

    while(!op.compare("END")){
        if(!op.compare("NEW")){
            NEW(&q, id);
            q->tam++;
            count++;
        }
        else if(!op.compare("TER")){
            TER(&l, id);
        }
        else if(!op.compare("SCH")){
            cout << ciclo << endl;
            ciclo++;
            C(&l);
            I(&l, &q, s);
            A(count);
            D(&q, &l);
            count=0;
        }
        cin >> op >> id;
    }
    return 0;
}
