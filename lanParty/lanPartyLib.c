#include "lanPartyLib.h"

int isStackEmpty(Stack *s){
    return (s->top==NULL);
}

void initList(List **l){
    L=(List*)malloc(sizeof(List));
    L->head=(Node*)malloc(sizeof(Node));
    L->tail=(Node*)malloc(sizeof(Node));
    if(!L){
        printf("Lista nu a putut fi creata!!!");
        exit(-1);
    }
    if(!L->head){
    free(L);
    exit(-1);
    }
    if(!L->tail){
    free(L->head);
    free(L);
    exit(-1);
    }
    L->head->next=L->tail;
    L->tail->prev=L->head;
    L->tail->next=L->tail;
    L->head->prev=L->head;
}


void push(Stack **s, Team t){
    SElem *newElem;
    newElem=(SElem*)malloc(sizeof(SElem));
    if(!newElem)
        exit(-1);
    newElem->t=t;
    if(!S->top) {
        newElem->next=NULL;
        S->top = newElem;
    }
    else {
        newElem->next = S->top;
        S->top = newElem;
    }
}

int isListEmpty(List *l)
{
    return (l->head->next==l->tail);
}

void addToHead(List **l, Team t){
    Node *n=(Node*)malloc(sizeof(Node));
    if(!n)
    {
        printf("Alocarea pentru un nod din lista a esuat!!");
        exit(-1);
    }
    n->t=t;
    n->next=L->head->next;
    n->prev=L->head;
    L->head->next->prev=n;
    L->head->next=n;
    }


Team extractHead(List **l){
    TeamNULL
    if(isListEmpty(L)){
        printf("Lista este goala!!!!");
        return tNULL;
    }
    else
    {
        Team aux;
        Node *aux2;
        aux=L->head->next->t;
        aux2=L->head->next;
        L->head->next=L->head->next->next;
        free(aux2);
        return aux;
    }
}

void delNode(List **l,Node *n){

    if(!isListEmpty(L)&&n!=NULL)
    {
         n->next->prev=n->prev;
         n->prev->next=n->next;
         free(n);
    }
    else exit(-1);
}

void freeT(Team *t){
    int i;
    for(i=0;i<T.nrJucatori;i++)
    {
        free(T.p[i].firstName);
        free(T.p[i].secondName);
    }
    free(T.p);
    free(T.numeEchipa);
}

Node * findLowestPoints(List *l){
    Node* cur,*minx;
    float min;
    if(!isListEmpty(l))
    {
        min=l->head->next->t.punctaj;
        for(cur=l->head->next->next;cur!=l->tail;cur=cur->next)
        if(cur->t.punctaj<min)
        {
            min=cur->t.punctaj;
            minx=cur;
        }
        return minx;
    }
    else
    return NULL;
}

Team pop(Stack **s){
    TeamNULL
    if(!isStackEmpty(S)){
        SElem *aux;
        Team aux2;
        aux2=S->top->t;
        aux=S->top;
        S->top=S->top->next;
        free(aux);
        return aux2;
    }
    else {
        printf("Stiva este goala!!!");
        return tNULL;
    }
}

void calculPunctajEchipa(Team *t){
    float s=0;
    int i;
    for(i=0;i<t->nrJucatori;i++)
    s+=t->p[i].points;
    t->punctaj=(float)s/t->nrJucatori;
}


void addData(FILE *f_in,int *nrEchipe, List **l, Evidence **e){
    Team t;
    int i,j,pct,nrJucatori,k;
    char bfN1[100],bfN2[100],bfEc[100];
    (*e)=(Evidence*)malloc((*nrEchipe)*sizeof(Evidence));
    if(!(*e)) exit(-1);
    for(i=0;i<(*nrEchipe);i++){
    fscanf(f_in,"%d",&nrJucatori);
        t.nrJucatori=nrJucatori;
        fscanf(f_in," %[^\n]s",bfEc);
        t.numeEchipa=(char*)malloc((strlen(bfEc)+1)*sizeof(char));
        if(!t.numeEchipa)
        {
            printf("Numele pentru echipa a fost alocat eronat!!!");
            exit(-1);
        }
        strcpy(t.numeEchipa,bfEc);
        t.numeEchipa[strlen(t.numeEchipa)-1]='\0';
        deleteTrailing(t.numeEchipa);
        t.p=(Player*)malloc(nrJucatori*sizeof(Player));
        if(!t.p)
        {
            printf("Numarul de jucatori pentru o echipa a fost alocat eronat!!");
            exit(-1);
        }
        for(j=0;j<nrJucatori;j++)
        {
            fscanf(f_in," %s",bfN1);
            fscanf(f_in," %s",bfN2);
            t.p[j].firstName=(char*)malloc((strlen(bfN1)+1)*sizeof(char));
            if(!t.p[j].firstName)
            {
                printf("Primul nume al persoanei a %d-a din echipa cu numarul %d a fost alocat eronat!!!",j,i);
                exit(-1);
            }
            strcpy(t.p[j].firstName,bfN1);
            deleteTrailing(t.p[j].firstName);
             t.p[j].secondName=(char*)malloc((strlen(bfN2)+1)*sizeof(char));
            if(!t.p[j].secondName)
            {
                printf("Cel de-al doilea nume al persoanei din echipa cu numarul %d a fost alocat eronat!!!",i);
                exit(-1);
            }
            strcpy(t.p[j].secondName,bfN2);
            deleteTrailing(t.p[j].secondName);
            fscanf(f_in,"%d",&pct);
            t.p[j].points=pct;
        }
       calculPunctajEchipa(&t);
       (*e)[i].t=t;
       addToHead(&L,t);
}
}

void deleteTrailing(char *s){
    int i;
    for(i=strlen(s)-1;i>=0&&s[i]==' ';i--);
    s[i+1]='\0';
}

void deleteEvidence(Evidence **e, int nrInit){
    int i;
    for(i=0;i<nrInit;i++)
    {
        freeT(&((*e)[i].t));
    }
    free((*e));
    (*e)=NULL;
}

void initStack(Stack **s){
    S=(Stack*)malloc(sizeof(Stack));
    if(!S){
        printf("Stiva nu s-a putut initializa cu succes!!!");
        exit(-1);
    }
    S->top=NULL;
}

int isPowerOf2(int val){
    int aux,k=0,i;
    aux=val;
    while(aux!=1){
        aux/=2;
        k++;
    }
    for(i=0;i<k;i++)
    {
        aux*=2;
    }
    return (aux==val);
}

void printList(FILE *f_out,List *l){
    Node *cur;
    for(cur=l->head->next;cur!=l->tail;cur=cur->next)
    {
        fprintf(f_out,"%s\n",cur->t.numeEchipa);
    }
}

void delTillPow2(List **l, int *nrEchipe){
    Node *cur,*aux;
    float min;
    int i;
    while(!isListEmpty(L)&&!isPowerOf2(*nrEchipe)){
    min=L->head->next->t.punctaj;
    aux=L->head->next;
    for(cur=L->head->next;cur!=L->tail;cur=cur->next)
    {
        if(cur->t.punctaj<min)
        {
            min=cur->t.punctaj;
            aux=cur;
        }
    }
    if(aux!=NULL)
    {delNode(&L,aux);
    (*nrEchipe)--;
    }
    }
}


void deleteQueue(Queue **q){
    CElem *cur,*aux;
    cur=Q->front;
    int i;
    while(cur!=NULL){
        aux=cur;
        cur=cur->next;
        free(aux);
    }
    free(Q);
    Q=NULL;
}

void initQueue(Queue **q){
    Q=(Queue*)malloc(sizeof(Queue));
    if(!Q) exit(-1);
    Q->front=Q->rear=NULL;
    Q->count=0;
}

void initAVQueue(AVQueue **q){
    Q=(AVQueue*)malloc(sizeof(AVQueue));
    if(!Q)exit(-1);
    Q->front=Q->rear=NULL;
}

void deleteAVQueue(AVQueue **q){
    AVLElem *cur,*aux;
    cur=Q->front;
    while(cur!=NULL){
        aux=cur;
        cur=cur->next;
        free(aux);
    }
    free(Q);
    Q=NULL;
}

void enqueue(Queue **q, Team t){
    CElem *newElem;
    newElem=(CElem*)malloc(sizeof(CElem));
    if(!newElem)
    exit(-1);
    newElem->t=t;
    newElem->next=NULL;
    if(Q->rear==NULL)
    Q->rear=newElem;
    else{
    Q->rear->next=newElem;
    Q->rear=newElem;
    }
    if(Q->front==NULL)
    Q->front=Q->rear;
    (Q->count)++;
}

void AVEnqueue(AVQueue **q, ANode *node){
    AVLElem *newElem;
    newElem=(AVLElem*)malloc(sizeof(AVLElem));
    if(!newElem)
    exit(-1);
    newElem->node=node;
    newElem->next=NULL;
    if(Q->rear==NULL)
    Q->rear=newElem;
    else{
    Q->rear->next=newElem;
    Q->rear=newElem;
    }
    if(Q->front==NULL)
    Q->front=Q->rear;
}

Team dequeue(Queue **q){
    Team val;
    TeamNULL
    CElem *aux;
    if(!isQueueEmpty(Q))
    {   val=Q->front->t;
        aux=Q->front;
        Q->front=Q->front->next;
        free(aux);
        if(Q->front==NULL)
        Q->rear=NULL;
        (Q->count)--;
        return val;}
        else {
            return tNULL;
        }
}

ANode * AVDequeue(AVQueue **q){
        ANode *aux;
        AVLElem *aux2;
        if(!isAVQueueEmpty(Q)){
        aux=Q->front->node;
        aux2=Q->front;
        Q->front=Q->front->next;
        free(aux2);
        if(Q->front==NULL)
        Q->rear=NULL;
        return aux;}
        else {
            return NULL;
        }
}

void freeQueue(Queue **q){
    CElem *cur,*aux;
    cur=Q->front;
    while(cur!=NULL)
    {
        aux=cur;
        cur=cur->next;
        free(aux);
    }
    Q=NULL;
}

int isQueueEmpty(Queue *q){
    return (q->front==NULL);
}

int isAVQueueEmpty(AVQueue *q){
    return (q->front==NULL);
}

void freeStack(Stack **s){
    SElem *cur,*aux;
    cur=S->top;
    while(cur!=NULL){
        aux=cur;
        cur=cur->next;
        free(aux);
    }
    free(S);
    S=NULL;
}

BNode *newNode(Team t){
    BNode *n;
    n=(BNode*)malloc(sizeof(BNode));
    if(!n){
        printf("Alocarea pentru nodul din BST a esuat!!!");
        exit(-1);
    }
    n->t=t;
    n->left=n->right=NULL;
    return n;
}

BNode* addToBST(BNode* n,Team t){
    if(n==NULL) return newNode(t);
    if(t.punctaj<n->t.punctaj)
        n->left=addToBST(n->left,t);
        else if(t.punctaj==n->t.punctaj)
                if(strcmp(t.numeEchipa,n->t.numeEchipa)<0)
                n->left=addToBST(n->left,t);
                   else
                n->right=addToBST(n->right,t);
         else if(t.punctaj>n->t.punctaj)
                 n->right=addToBST(n->right,t);
      return n;
}

void deleteBST(BNode *root){
    if(!root)
    return;
    deleteBST(root->left);
    deleteBST(root->right);
    free(root);
}

void deleteAVL(ANode *root2){
    if(!root2)
    return;
    deleteAVL(root2->left);
    deleteAVL(root2->right);
    free(root2);
    root2=NULL;
}

int treeHeight(ANode *node){
    if(node==NULL) return -1;
    else return node->height;
}

ANode *rightRot(ANode *z){
    ANode *y=z->left;
    ANode *T3=y->right;
    y->right=z;
    z->left=T3;
    z->height=max(treeHeight(z->left),treeHeight(z->right))+1;
    y->height=max(treeHeight(y->left),treeHeight(y->right))+1;
    return y;
}

ANode *leftRot(ANode *z){
    ANode *y=z->right;
    ANode *T2=y->left;
    y->left=z;
    z->right=T2;
    z->height=max(treeHeight(z->left),treeHeight(z->right))+1;
    y->height=max(treeHeight(y->left),treeHeight(y->right))+1;
    return y;
}

ANode *LRRot(ANode *z){
    z->left=leftRot(z->left);
    return rightRot(z);
}

ANode *RLRot(ANode *z){
    z->right=rightRot(z->right);
    return leftRot(z);
}

ANode *addToAVL(ANode *n, Team t){
    if(!n){
        n=(ANode*)malloc(sizeof(ANode));
        if(!n)
        {
            printf("Alocarea nodului din AVL a esuat!!!");
            exit(-1);
        }
        n->t=t;
        n->height=0;
        n->left=n->right=NULL;
        return n;
    }
    if(t.punctaj<n->t.punctaj)
        n->left=addToAVL(n->left,t);
    else if(t.punctaj>n->t.punctaj)
          n->right=addToAVL(n->right,t);
         else if(t.punctaj==n->t.punctaj)
                if(strcmp(t.numeEchipa,n->t.numeEchipa)<0)
                n->left=addToAVL(n->left,t);
                else
                n->right=addToAVL(n->right,t);
    n->height=1 + max(treeHeight(n->left),treeHeight(n->right));
    int k=(treeHeight(n->left)-treeHeight(n->right));
    if (k>1)
    {if(t.punctaj<n->t.punctaj)
            return rightRot(n);
    else if(t.punctaj>n->t.punctaj)
            return LRRot(n);   
            else if(t.punctaj==n->t.punctaj)
                 if(strcmp(t.numeEchipa,n->t.numeEchipa)<0)
                 return rightRot(n);
                 else
                 return LRRot(n);
    }
    if(k<-1)
    {if(t.punctaj>n->t.punctaj)
            return leftRot(n);
    else if(t.punctaj<n->t.punctaj)
            return RLRot(n);
            else if(t.punctaj==n->t.punctaj)
            if(strcmp(t.numeEchipa,n->t.numeEchipa)>0)
            return leftRot(n);
            else
            return RLRot(n);
    }
    return n;
}

int max(int a, int b){
    if(a>b)
    return a;
    else return b;
}

void rightInOrder(BNode *node,FILE *f_out){
    if(node!=NULL){
        rightInOrder(node->right,f_out);
        fprintf(f_out,"%-34s-  %.2f\n",node->t.numeEchipa,node->t.punctaj);
        rightInOrder(node->left,f_out);
    }
}

void rightInOrderAVL(ANode *node,FILE *f_out){
    AVQueue *q;
    ANode *cur;
    int k=0;
    initAVQueue(&q);
    AVEnqueue(&q,node);
    while(!isAVQueueEmpty(q)){
         cur=AVDequeue(&q);
         if(cur->right)
         AVEnqueue(&q,cur->right);
         if(cur->left)
         AVEnqueue(&q,cur->left);
         if(k>=3&&k<7)
         fprintf(f_out,"%s\n",cur->t.numeEchipa);
         k++;
    }
    deleteAVQueue(&q);
}


void incrementPoints(Team *t){
    int i;
    for(i=0;i<t->nrJucatori;i++)
    t->p[i].points++;
    calculPunctajEchipa(&T);
}

void matchMaking(FILE *f_out,Queue **q, Stack **win, Stack **lose,BNode **root, ANode **root2){
    Team t1,t2,winner;
    int k=1;
    while(!isQueueEmpty(Q)&&Q->count>1){
    initStack(&W);
    initStack(&Lo);
    fprintf(f_out,"\n--- ROUND NO:%d",k);
    while(!isQueueEmpty(Q)&&Q->count>1){
        t1=dequeue(&Q);
        t2=dequeue(&Q);
        fprintf(f_out,"\n%-32s - %32s",t1.numeEchipa,t2.numeEchipa);
        if(t1.punctaj>t2.punctaj){
            incrementPoints(&t1);
             push(&W,t1);
             push(&Lo,t2);
        }
        else
        {
            incrementPoints(&t2);
            push(&W,t2);
            push(&Lo,t1);
        }
    }
               fprintf(f_out,"\n\nWINNERS OF ROUND NO:%d",k);
               while(!isStackEmpty(W)){
                winner=pop(&W); // se asigura si eliberarea stivei cu castigatori
                enqueue(&Q,winner);
                fprintf(f_out,"\n%-34s-  %.2f",winner.numeEchipa,winner.punctaj);
               }
               if(Q->count==8)
               {
                CElem *aux2;
                aux2=Q->front;
                while(aux2!=NULL)
                {
                    R=addToBST(R,aux2->t);
                    aux2=aux2->next;
                }
               }
               freeStack(&Lo);// eliberarea stivei pierzatorilor
               freeStack(&W);
               fprintf(f_out,"\n");
               k++;
    }
    fromBSTToAVL(R,&R2);
}

void deleteList(List **l){
    Node *cur,*aux;
    cur=L->head->next;
    while(cur!=L->tail)
    {
        aux=cur;
        cur=cur->next;
        free(aux);
    }
    free(L->head);
    free(L->tail);
    free(L);
    L->head=NULL;
    L->tail=NULL;
    L=NULL;

}

void *fromBSTToAVL(BNode *root,ANode **root2){
    if(root!=NULL){
        fromBSTToAVL(root->right,&R2);
        R2=addToAVL(R2,root->t);
        fromBSTToAVL(root->left,&R2);
    }
}

void addListToQueue(List **l,Queue **q){
    Node *cur,*aux;
    cur=L->head->next;
    while(cur!=L->tail)
    {
        enqueue(&Q,cur->t);
        aux=cur;
        cur=cur->next;
        free(aux);
    }
    free(L->head);
    free(L->tail);
    free(L);
    L=NULL;
}




