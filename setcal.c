#include<stdio.h>
#include<stdlib.h>




 // relation representation
typedef struct {
         char *items ;
        unsigned int size ;
} relation_t;


int *resize ( int *arr, unsigned int newsize) 
{
	int *newarr = ( int *)realloc(arr ,newsize * sizeof(int));
	if( newarr == NULL) 
	{
		free(arr);
		return NULL;
	}
	return newarr ;
}


relation_t *relation() 
{

	relation_t *rel = (relation_t *) malloc (sizeof(relation_t));
	if( rel != NULL) 
	{
		rel->size = 0;
		rel->items = NULL;
	}
	return rel;
}

/*
int reladd(relation_t *rel , int value) 
{
	rel->items = resize(rel->items , rel->size + 1);
	if(rel->items == NULL) 
	{
		return 0;
	}
	rel->items[rel->size] = value;
	rel->size += 1 ;
	return 1 ;
}
*/
// relations destructor
void reldestor(relation_t *rel)
{
        if(rel == NULL)
        {
                return ;
        }

        if((rel->items) != NULL)
        {
                free(rel->items);
        }
        free(rel) ;
}



int main(void)//int argc, char *argv[])
{
	FILE *relace;
	int c;
	relace = fopen("rel.txt","r");
	if((relace = fopen("rel.txt", "r")) == NULL)
		printf("subor rel.txt sa nepodarilo otevrit");
	while((c = getc(relace)) != EOF)
	{
		putchar(c);
	/*	if(c=='\n')
			printf("\n");
	*/}
	
	if(fclose(relace)==EOF)
	{
		printf("subor rel.txt sa nepodarilo otevrit");
		return 1;
	}
	return 0;
}
