#include "lanPartyLib.h"

int main (int argc, char* argv[]) {
    printf("Number of input files: %d\n", argc);
    printf("Exec name: %s\n", argv[0]);
    printf("File1: %s\n", argv[1]);
    printf("File2: %s\n", argv[2]);
    printf("File3: %s\n", argv[3]);

    FILE *c_in = fopen(argv[1],"r");
    FILE *f_in = fopen( argv[2], "r" );
    FILE *f_out = fopen(argv[3],"w");

if(!c_in){
    printf("Fisierul cu date despre optiuni nu a putut fi deschis!!!");
    exit(-1);
}
if(!f_in){
    printf("Fisierul cu date de intrare nu a putut fi deschis!!!");
    exit(-1);
}
if(!f_out){
    printf("Fisierul cu date de iesire nu a putut fi deschis!!");
    exit(-1);
}

   Player p;
   Team t;
   List *l;
   Queue *q;
   Stack *win,*lose;
   BNode *root=NULL;
   ANode *root2=NULL;
   Evidence *e;

   int nrEchipe,nrInit,i,j,pct,op1,op2,op3,op4,op5;
   char bfN1[100],bfN2[100],bfEc[100]; // buffere pentru a stoca datele in structuri prin alocare dinamica

   initList(&l);
   initQueue(&q);
   fscanf(f_in,"%d",&nrEchipe);
   nrInit=nrEchipe;
   fscanf(c_in,"%d%d%d%d%d",&op1,&op2,&op3,&op4,&op5);
   addData(f_in,&nrEchipe,&l,&e);
          if(op2==1)
          delTillPow2(&l,&nrEchipe);
          if(op1==1)
          printList(f_out,l);
          addListToQueue(&l,&q); //Se efectueaza si stergerea (dealocarea) listei
            if(op3==1){
             matchMaking(f_out,&q,&win,&lose,&root,&root2);
            }
            if(op4==1){
            fprintf(f_out,"\nTOP 8 TEAMS:\n");
            rightInOrder(root,f_out);
            }
            if(op5==1){
            fprintf(f_out,"\nTHE LEVEL 2 TEAMS ARE: \n");
            rightInOrderAVL(root2,f_out);
            }
           if(op3==1){
           deleteAVL(root2); //stergere arbore AVL
           deleteBST(root);  //stergere arbore BST
           }
           deleteQueue(&q);
           deleteEvidence(&e,nrInit); // stergere coada
           fclose(c_in);
           fclose(f_in);
           fclose(f_out);
        return 0;
 }