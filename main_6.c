#include "functii_6.h"

int main()
{
	Node *head;
	int i=0, nr=0, j;
	char v[6]={" "};
	head=createTree(head);
	///afisare(head, v, i);
	printf("Gata ! \n");
	for(j=0;j<5;j++)
	{i=0;
	nr=0;
	numarare_grupulete(head, v, i, j, &nr);
	if(nr>1)
	  printf("C%d : %d cai\n",j, nr);
	else if(nr==1)
	     printf("C%d : %d cale\n",j, nr);
	else printf("C%d : nicio cale\n",j);
	afisare_grupulete(head,v,i,j);
    }    
}
