#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H 

typedef struct{
    char *name;
    char *phone;
}Contact;

typedef struct{
    Contact **contacts;
    int capacity;
    int size;
}List;


// Initialize list

List* initialize_list(int initial_capacity);
// Add element
void add_element(List *list , const char *name,const char *phone);
// Show elements
void show_contacts(List *list);
// Desallocate Memory
List* desallocate_memory(List *list);

#endif