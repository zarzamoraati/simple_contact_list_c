#include "contact_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// TODO Initialize List
List* initialize_list(int initial_capacity){
    // set up the contact 
    List *list=(List*)malloc(sizeof(List));
    list->contacts=(Contact**)malloc(initial_capacity*sizeof(Contact*));
    list->capacity=initial_capacity;
    list->size=0;
}


// TODO Add element
void add_element(List *list, const char *name, const char *phone){
    // check if size is filled
    if(list->size==list->capacity){
        //reallocate memory
        list->capacity*=2;
        list->contacts=(Contact**)realloc(list->contacts,list->capacity*sizeof(Contact*));
        
    }

    // define structue and add the element

    Contact *new_contact=(Contact*)malloc(sizeof(Contact));
    new_contact->name=strdup(name);
    new_contact->phone=strdup(phone);
    list->contacts[list->size]=new_contact;
    list->size+=1;
    
}

// TODO Show Contacts
void show_contacts(List *list){
    if(list->size==0){
        printf("List is empty, no contacts to show...");
    }else{
        for(int i=0; i<list->size; i++){
            printf("Contact %d\n", i+1);
            printf("Name: %s\n", list->contacts[i]->name);
            printf("Phone: %s\n", list->contacts[i]->phone);
        }
    }

}
// TODO liberate memory 
List* desallocate_memory(List *list){
    if(list->size>0){
        for(int i=0;i<list->size;i++){
            free(list->contacts[i]->name);
            free(list->contacts[i]->phone);
            free(list->contacts[i]);
        }
    }
    free(list->contacts);
    free(list);
    return list;
}






