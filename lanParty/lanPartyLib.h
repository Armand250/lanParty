#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Player.h"
#include <math.h>
#define S (*s)
#define L (*l)
#define T (*t)
#define Q (*q)
#define W (*win)
#define Lo (*lose)
#define R (*root)
#define R2 (*root2)
#define TeamNULL Team tNULL; tNULL.nrJucatori=-999; tNULL.numeEchipa=NULL; tNULL.punctaj=-999; tNULL.p=NULL;
    
typedef struct node{
    Team t;
    struct node* next;
    struct node* prev;
}Node;

typedef struct list{
    Node *head,*tail;
}List;

typedef struct stiva{
    struct stiva *next;
    Team t;
}SElem;

typedef struct stack{
    SElem *top;
}Stack;

typedef struct coada{
    struct coada *next;
    Team t;
}CElem;

typedef struct queue{
    CElem *front;
    CElem *rear;
    int count;
}Queue;

typedef struct BNode{
    struct BNode *left;
    struct BNode *right;
    Team t;
}BNode;

typedef struct avl{
    struct avl *left;
    struct avl *right;
    Team t;
    int height;
}ANode;

typedef struct avlQueue{
    struct avlQueue *next;
    ANode *node;
}AVLElem;

typedef struct AVQueue{
    AVLElem *front;
    AVLElem *rear;
}AVQueue;


int isPowerOf2(int val);
int isListEmpty(List *l);
void addToHead(List **l, Team t);
void initList(List **l);
Team extractHead(List **l);
void calculPunctajEchipa(Team *t);
void printList(FILE *f_out,List *l);
void delNode(List **l,Node *n);
Node * findLowestPoints(List *l);
void delTillPow2(List **l, int *nrEchipe);
void initQueue(Queue **q);
void enqueue(Queue **q, Team t);
Team dequeue(Queue **q);
void freeQueue(Queue **q);
void initStack(Stack **s);
int isQueueEmpty(Queue *q);
void freeStack(Stack **s);
BNode *newNode(Team t);
BNode* addToBST(BNode* n,Team t);
void incrementPoints(Team *t);
void matchMaking(FILE *f_out,Queue **q, Stack **win, Stack **lose, BNode **root, ANode **root2);
void addListToQueue(List **l,Queue **q);
void rightInOrder(BNode *node,FILE *f_out);
void deleteBST(BNode *root);
int treeHeight(ANode *node);
ANode *rightRot(ANode *z);
ANode *leftRot(ANode *z);
ANode *LRRot(ANode *z);
ANode *RLRot(ANode *z);
ANode *addToAVL(ANode *n, Team t);
void deleteAVL(ANode *root2);
void rightInOrderAVL(ANode *node,FILE *f_out);
int max(int a, int b);
int isAVQueueEmpty(AVQueue *q);
void *fromBSTToAVL(BNode *root,ANode **root2);
void addData(FILE *f_in,int *nrEchipe, List **l,Evidence **e);
void deleteQueue(Queue **q);
void deleteAVQueue(AVQueue **q);
void freeT(Team *t);
void deleteList(List **l);
void deleteEvidence(Evidence **e,int nrInit);
void deleteTrailing(char *s);



