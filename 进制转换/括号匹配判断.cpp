#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define LEN 80 
typedef struct list{ 
 char node; 
 struct list* next; 
}list,*plist; 
 
void iniList(plist); 
int isEmpty(plist); 
int listAppend(plist,char); 
int delBracketsFormList(plist); 
 
int main(int argc,char* argv[]){ 
 char test[LEN]; 
 int i; 
 list a; 
 plist p; 
 p=&a; 
 iniList(p); 
 scanf("%80s",test); 
 for (i=0;i<LEN;i++){ 
  switch(test[i]){ 
   case '[': case']': case'{': case'}': case'(': case')': 
    listAppend(p,test[i]); 
    break; 
   default:continue; 
  } 
 } 
 delBracketsFormList(p); 
 if (isEmpty(p)){ 
  printf("À¨ºÅÆ¥Åä!\n"); 
 } 
 else 
  printf("À¨ºÅ²»Åä¶Ô!\n"); 
 return 0; 
} 
 
void iniList(plist aplist){ 
 aplist->next=NULL; 
 aplist->node='\0'; 
} 
 
int isEmpty(plist aplist){ 
 return aplist->next==NULL?1:0; 
} 
 
int listAppend(plist aplist,char a){ 
 plist bplist=aplist,anode; 
 while (bplist->next){ 
  bplist=bplist->next; 
 } 
 anode=(plist)malloc(sizeof(list)); 
 if (!anode)exit(-1); 
 anode->node=a; 
 anode->next=NULL; 
 bplist->next=anode; 
 return 0; 
} 
int delBracketsFormList(plist aplist){ 
 plist temp; 
 int has=1; 
 if (isEmpty(aplist)) 
  return 0; 
 while(has){ 
  has=0; 
  temp=aplist; 
  while (temp->next){ 
   if(temp->next->next){ 
    if((temp->next->next->node - temp->next->node == 1)||(temp->next->next->node - temp->next->node == 2)){ 
     temp->next = temp->next->next->next; 
     has=1; 
 
    } 
    else 
     temp = temp->next;  
   } 
   else 
    temp =temp->next; 
   if(!has)break; 
  } 
 
 } 
 return 0; 
}
