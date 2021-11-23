#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct element{
	char* word;
	int len;
}
*/

typedef struct set{
	char** elements;
	int size;
}set_t;

set_t* set_ctor(){
	set_t *set = malloc(sizeof(set_t));
	if (set != NULL){
		set->size = 0;
		set->elements = NULL;
	}else{
		fprintf(stderr, "error malloc ctor");
	}
    return set;
}

void set_dtor(set_t* set){
	if(set != NULL){
		for(int i = 0; i < set->size; i++){
			if(set->elements[i] != NULL){
				free(set->elements[i]);
			}
		}
		if(set->elements != NULL){
			free(set->elements);
		}
		free(set);
	}
}
/*
set_t* set_resize(set_t* set, int new_size){
	set_t* new_set = realloc(set, new_size * sizeof(char));
	if(new_arr == NULL){
		fprintf(stderr, "error realoc resize");
		free(set);
		return NULL;
	}else{
					
	}
	
}
*/
int main(int argc, char **argv){

	set_t* set = set_ctor();
	set_dtor(set);
	return 0;
}
