#include <stdio.h>
#include <stdlib.h>
typedef struct n{
int data;
struct n * next;
}node;
node * ekle(node *liste,int data){
if(liste ==NULL){
    liste = (node *)malloc(sizeof(node));
    liste->data = data;
    liste->next = NULL;
    return liste;
}
node * iter = liste;
while(iter->next != NULL)
    iter = iter->next;
node * temp = (node *)malloc(sizeof(node));
temp->data = data;
iter->next = temp;
temp->next = NULL;
return liste;

}

node * tersCevir(node * liste){
if(liste->next == NULL){
    return liste;
}
node * geriKalan = tersCevir(liste->next);
liste->next->next = liste;
liste->next = NULL;
return geriKalan;
}

void listele(node * liste){
node * iter = liste;
while(iter->next != NULL){
    printf(" %d ",iter->data);
    iter = iter->next;
}
printf(" %d ",iter->data);
}

int main()
{
    node * liste = NULL;
    liste = ekle(liste,10);
    liste = ekle(liste,20);
    liste = ekle(liste,30);
    liste = ekle(liste,40);
    liste = ekle(liste,50);
    listele(liste);
    printf("\n");
    liste = tersCevir(liste);
    listele(liste);

    return 0;
}
