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
NODE insert_rear(NODE , int);
NODE delete_rear(NODE);
void display(NODE);

int main()
{
	NODE first;

	int item, choice;

	while(1)
	{
	        printf("1. Insert rear\n");
	        printf("2. Delete rear\n");
	        printf("3. Display\n");
	        printf("4. Exit\n");
			scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter item to be inserted:\t");
				scanf("%d", &item);
				
				first = insert_rear(first, item);
				
				break;
				
			case 2:
				
				first = delete_rear(first);
				
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
		printf("Node creation error\n");
		return 0 ;
	}

	return x;
}

 NODE ipos(NODE root,int ele,int pos)

{

    NODE temp,prev,curr;

    int n=1;

    temp=getnode();

    temp->data=ele;

    temp->left=temp->right=NULL;

    if(root==NULL)

        return temp;

    if(pos==1)

    {

      temp->right=root;

      root->left=temp;

      return temp;

    }

    curr=root;

    while(curr!=NULL && n<pos)

      {

       prev=curr;

       curr=curr->right;

       n++;

      }

    temp->left=prev;

    temp->right=curr;

    prev->right=temp;

    if(curr!=NULL)

        curr->left=temp;

    return root;

}


NODE delete_rear(NODE first)
{

	NODE cur, prev;

	if(first == NULL)
	{
		printf("List is empty\n");
		return first;
	}

	if(first->rlink == NULL)
	{
		printf("Item deleted is %d\n", first->info);
		free(first);

		return NULL;
	}

	cur = first;

	while(cur->rlink != NULL)
	{
		prev = cur;
		cur = cur->rlink;
	}

	prev->rlink = NULL;

	printf("Element deleted : %d\n", cur->info);

	free(cur);

	return first;
}

void display(NODE first)
{
	NODE temp;

	if(first == NULL)
	{
		printf("No elements in the list\n");
		return;
	}

	printf("Your linked list is:\n");

	temp = first;

	while(temp != NULL)
	{
		printf("%d\n",temp->info);
		temp = temp->rlink;
	}
}
