#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *rlink;
	struct node *llink;
};

typedef struct node* NODE;

NODE getnode();
NODE insert_front(NODE , int);
NODE delete_front(NODE);
void display(NODE);


int main()
{
	NODE first;

	int item, choice;

	while(1)
	{
		printf("\n");
		printf("1. Insert front\n");
		printf("2. Delete front\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter item to be inserted\t");
				scanf("%d", &item);
				
				first = insert_front(first, item);
				
				break;
				
			case 2:
				first = delete_front(first);
				
				break;
			
			case 3:
				display(first);

		                break;

			default:
				exit(0);
		}
	}
}

NODE getnode()
{

	NODE x;

	x = (NODE) malloc(sizeof(struct node));

	if(x == NULL)
	{
		printf("Unable to create node\n");
		return 0;
	}

	return x;

}


NODE insert_front(NODE first, int item)
{

	NODE temp;

	temp = getnode();
	temp->info = item;
	temp->llink = NULL;
	
	if(first == NULL)
		return temp;	

	temp->rlink = first;
	first->llink = temp;

	return temp;
}

 
NODE dpos(NODE root,int pos)

{

    NODE temp,curr;

    int n=1;

    if(root==NULL)

    {

        printf("list empty\n");

        return root;

    }

    if(pos==1)

    {

        temp=root;

        root=root->right;

        if(root!=NULL)

            root->left=NULL;

        printf("deleted element is %d \n",temp->data);

        free(temp);

        return root;

    }

    curr=root;

    while(curr!=NULL && n<pos)

    {

        temp=curr;

        curr=curr->right;

        n++;

    }

    if(curr==NULL)

    {

        printf("position out of range\n");

        return root;

    }

    temp->right=curr->right;

    if(curr->right!=NULL)

    (curr->right)->left=temp;

    printf("deleted element is %d \n",curr->data);

    free(curr);

    return root;

}

void display(NODE first)
{
	NODE temp;
	
	if(first == NULL)
		printf("List is empty\n");

	printf("Contents of linked list:\n");

	temp = first;

	while(temp != NULL)
	{
		printf("%d\n", temp->info);
		temp = temp->rlink;
	}
}

