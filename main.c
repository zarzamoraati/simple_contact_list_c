#include "contact_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int init_size=2;
    char name[100];
    char phone[100];
    // Initialize List 
    List *list=initialize_list(init_size);
    // Add elements
    for(int i=0;i<init_size; i++){
        printf("Type the name of the contact:\n");
        scanf("%99s",name);
        printf("Type the phone osf the contact:\n");

        scanf("%99s",phone);
        add_element(list,name,phone);
    }
    // Show elements
    show_contacts(list);

    // Liberate memory 
    desallocate_memory(list);

    return 0;
}