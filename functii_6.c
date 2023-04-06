
typedef struct Node
{
	char type;
	int num;
	struct Node *right;
	struct Node *left;
}Node;

 Node* createNode(char type, int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type; newNode->num = num;
    newNode->left = 0;
    newNode->right = 0;
    return newNode;
}

Node* createTree(Node *root) {	
	root = createNode('Q',1);
	root->left = createNode('Q',2);
	root->right = createNode('Q',3);
	root->left->left = createNode('Q',4);
	root->left->right = createNode('Q',5);
	root->right->left = createNode('Q',6);
	root->right->right = createNode('C',2);	
	root->left->left->left = createNode('Q',7);
	root->left->left->right = createNode('Q',8);
	root->left->right->left = createNode('Q',9);
	root->left->right->right = createNode('C',3);
	root->right->left->left = createNode('C',4);
	root->right->left->right = createNode('Q',10);
	root->left->left->left->left = createNode('C',1);
	root->left->left->left->right = createNode('C',2);
	root->left->left->right->left = createNode('C',2);
	root->left->left->right->right = createNode('C',4);
	root->left->right->left->left = createNode('C',2);
	root->left->right->left->right = createNode('C',1);
	root->right->left->right->left = createNode('C',1);
	root->right->left->right->right = createNode('C',4);
	
	return root;
}

void afisare(Node *root, char v[], int i)
{
	///printf("SUNT IN FCT! \n");
	if(root->left!=0)
	{
	    ///printf("IN LEFT  \n");
		v[i]='d';
		i++;
		afisare(root->left,v,i);
	}
	if(root->right!=0)
	{
		v[i]=' ';
		v[i+1]=' ';
		i--;
		///v[i]=' ';
		///printf("IN RIGHT \n");
		v[i]='n';
		i++;
		afisare(root->right,v,i);
	}
	if(root->type=='C') printf("%c%d: %s\n",root->type, root->num, v);
}

void numarare_grupulete(Node *root, char v[], int i, int num, int *nr)
{
	///printf("SUNT IN FCT! \n");
	if(root->left!=0)
	{
	    ///printf("IN LEFT  \n");
		v[i]='d';
		i++;
		numarare_grupulete(root->left,v,i,num,nr);
	}
	if(root->right!=0)
	{
		v[i]=' ';
		v[i+1]=' ';
		i--;
		///v[i]=' ';
		///printf("IN RIGHT \n");
		v[i]='n';
		i++;
		numarare_grupulete(root->right,v,i,num,nr);
	}
	if(root->type=='C' && root->num==num) (*nr)++;
}

void afisare_grupulete(Node *root, char v[], int i, int num)
{
	///printf("SUNT IN FCT! \n");
	if(root->left!=0)
	{
	    ///printf("IN LEFT  \n");
		v[i]='d';
		i++;
		afisare_grupulete(root->left,v,i,num);
	}
	if(root->right!=0)
	{
		v[i]=' ';
		v[i+1]=' ';
		i--;
		///v[i]=' ';
		///printf("IN RIGHT \n");
		v[i]='n';
		i++;
		afisare_grupulete(root->right,v,i,num);
	}
	if(root->type=='C' && root->num==num) printf("%s\n",v);
}
