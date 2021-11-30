#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct element{
	char* word;
	int len;
}el_t;

el_t* el_ctor(){
	el_t* el = malloc(sizeof(el_t));
	if(el != NULL){
		el->len = 0;
		el->word = NULL;
	}else{
		fprintf(stderr, "error malloc el_ctor");
	}
	return el;
}

void el_dtor(el_t* el){
	if(el->word != NULL){
		free(el->word);
	}
	free(el);
}

typedef struct set{
	el_t* elements;
	int size;
}set_t;

set_t* set_ctor(){
	set_t *set = malloc(sizeof(set_t));
	if (set != NULL){
		set->size = 0;
		set->elements = NULL;
	}else{
		fprintf(stderr, "error malloc set_ctor");
	}
    return set;
}

void set_dtor(set_t* set){
	if(set != NULL){
		for(int i = 0; i < set->size; i++){
			
			if(set->elements[i].word != NULL){
				free(set->elements[i].word);
			}
		}
		if(set->elements != NULL){
			free(set->elements);
		}
		free(set);
	}
}

el_t* set_resize(el_t* elements, int new_size){	
	el_t* new_elements = realloc(elements, new_size * sizeof(el_t));
	if(new_elements == NULL){
		fprintf(stderr, "error realloc set_size");
		free(elements);
		return NULL;
	}
	return new_elements;
}

int set_append(set_t* set, el_t* el){
	set->elements = set_resize(set->elements, set->size + 1);
	if(set->elements = NULL){
		return 0;
	}
	set->elements[set->size] = *el;
	set->size++;
	return 1;
}

int main(int argc, char **argv){
	el_t* el = el_ctor();
	set_t* set = set_ctor();
	el->word[0] = 'a';
	el->len = 1;
	set_resize(set->elements, 4);
	set_dtor(set);
	el_dtor(el);
	return 0;
}
