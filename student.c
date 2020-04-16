#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int printMenu() {
    printf("Choose one of the below options, by inserting a number from 1-7:\n");       
    printf("\n");
    printf("1. Insert a new student and assign a unique id\n");           
    printf("2. Delete a student by id\n");
    printf("3. Search a student by id\n");
    printf("4. Change a student's data\n");
    printf("5. Print a student's data\n");
    printf("6. Print all student's data\n");
    printf("7. Exit the program\n");
    printf("\n");
    
    int choice;
    do{  
        int res=0;                       
        printf("Choose one of the below options, by inserting a number from 1-7:\n");
        res = scanf("%d", &choice);
        if( res != 1 ) {
            printf("Please try again, by inserting a number from 1-7\n");                  
            exit(1);
        }
    }while( choice<1 || choice>7 );
    return choice;
}    
   
//create a linked list
struct listR* list_create() {
    struct listR *l;
    l = (struct listR*) malloc(sizeof(struct listR));
    if ( l==NULL ) {
        printf("No available address space\n");
        exit(1);
    }
    l->head = NULL;
    l->size = 0;
    return l;
}

//create a new node
struct nodeR* entry_node(student data) {
    struct nodeR *new;
    new = (struct nodeR*) malloc(sizeof(struct nodeR));
    if( new == NULL ) {
        printf("No available address space\n");
        exit(1);
    }
    new->data=data;
    new->next = NULL;
    return new;
}

//inserts a node at the beggining of the list
void first_node_list( struct listR* l, struct nodeR *new ) {
    if( l==NULL )
    printf("No available address space\n");
    if( new==NULL )
    printf("No available address space\n");
    new->next = l->head;
    l->head = new;
    l->size++;
}

//inserts a node after the first node
void insert_nodeafter( struct listR *l,  struct nodeR *new) {
    if( l==NULL ) 
    printf("No available address space\n");
    if( new==NULL )
    printf("No available address space\n");
    struct nodeR* tmp = l->head;
    while( (tmp->next)!=NULL ) {
        tmp = tmp->next;
    }
    tmp->next = new;
    l->size++;
    return;
}

//delete first node from list
void first_node_delete( struct listR *l) {
    struct nodeR *tmp=l->head;
    tmp = tmp->next;
    free(tmp);
    l->size--;
    return;
}

//returns size of list
int list_size( struct listR *l) {
    if( l==NULL )
    printf("No available address space\n");
    return l->size;
}

//print all student's data
void printstudents(struct listR *l, char *filename) {
    printf("\n");
    struct nodeR *tmp = l->head;
        if( list_size(l)==0 ) {
            printf("List is empty\n");
        }
        if( list_size(l)!=0 ) {
            while( tmp!=NULL ) {
            printf("id:%d\tname:%s\n", tmp->data.id, tmp->data.name);
            tmp = tmp->next;
            }
        }
        
        printf("\n");
        save(filename, l->head);
        return;
}

//insert student
student addStudent(student data, struct listR *l, char *filename) {
    struct nodeR *tmp=l->head;
    if( list_size(l)==0 ) {
        first_node_list( l, entry_node(data) );
        printf("\n");
        printf("Student was succesfully inserted\n");
    }else {
        insert_nodeafter(l, entry_node(data));
        printf("\n");
        printf("Student was succesfully inserted\n");
    }
    
    save(filename,l->head);
    printf("\n");
    return data;
}

//search a student in the list by id 
student* findStudent(student data, struct listR *l, struct nodeR *new, int ida, char *filename, int user_choice) {
    printf("\n");
    int counter=0;
    int cho;
    struct nodeR *tmp2=l->head;
    if( list_size(l)==0 ) {
        printf("List is empty\n");
        printf("\n");
    } else {
        struct nodeR *tmp = l->head;
        int found_id = 0;
        int neoid;
        char newname[MAXSTRING];
    
        while( tmp!=NULL ) {
            ++counter;
            if( ida==tmp->data.id ) {
                if( user_choice==3 )
                printf("id:%d\tname:%s\nposition:%d\n", tmp->data.id, tmp->data.name, counter);
                if( user_choice==5 )
                printf("id:%d\tname:%s\n", tmp->data.id, tmp->data.name);
                if( user_choice==4 ) {
                    printf("Student's current data:\nid:%d\tname:%s\n", tmp->data.id, tmp->data.name);
                    printf("\n");
                    do{
                        printf("Insert 1 to change both id and name\n");
                        printf("Insert 2 to change only the id\n");
                        printf("Insert 3 to change only the name\n");
                        if(scanf("%d", &cho)!=1) {
                            printf("Please try again. Insert only numbers\n");
                            exit(1);
                        }
                        printf("\n");
                    }while( cho<1 || cho>3 );

                    if( cho==1 ) {
                        printf("Insert new student's id\n");
                        if((scanf("%d", &neoid))!=1) {
                            printf("Please try again. Insert only numbers\n");
                            exit(1);
                        }                        
                        while( tmp2!=NULL ) {      
                            if((tmp2->data.id) == neoid) {
                        
                            do{
                                printf("\n");
                                printf("This id is already in use\n");
                                printf("\n");
                                printf("Insert student's id\n");
                                if((scanf("%d", &neoid))!=1) {
                                    printf("Please try again. Insert only numbers\n");
                                    exit(1);
                                }       
                                tmp2 = l->head;
                            }while(neoid == (tmp2->data.id));
                            }
                            tmp2 = tmp2->next;
                        }          
                        tmp->data.id = neoid;                
                        printf("Insert new student's name\n");
                        fgets(newname,sizeof(newname),stdin);
                        fgets(newname,sizeof(newname),stdin);
                        strcpy(tmp->data.name, newname);  
                    }else if( cho==2 ) {
                        printf("Insert new student's id\n");
                        if((scanf("%d", &neoid))!=1) {
                            printf("Please try again. Insert only numbers\n");
                            exit(1);
                        }
                        while( tmp2!=NULL ) {      
                            if((tmp2->data.id) == neoid) {
                        
                            do{
                                printf("\n");
                                printf("This id is already in use\n");
                                printf("\n");
                                printf("Insert student's id\n");
                                if((scanf("%d", &neoid))!=1) {
                                    printf("Please try again. Insert only numbers\n");
                                    exit(1);
                                }       
                                tmp2 = l->head;
                            }while(neoid == (tmp2->data.id));
                            }
                            tmp2 = tmp2->next;
                        }          
                        tmp->data.id = neoid;   
                    }else if( cho==3 ) {  
                        printf("Insert new student's name\n");
                        fgets(newname,sizeof(newname),stdin);
                        fgets(newname,sizeof(newname),stdin);
                        strcpy(tmp->data.name, newname);  
                    }
                    printf("\n");
                    printf("Student's data were succesfully changed\n");
                }
                found_id = 1;
            }
            tmp = tmp->next;
        }
        if( found_id==0 ) {
            printf("This id is not matching to any student\n");
        }
        printf("\n");

        save(filename, l->head);
        return &new->data;
    }
}

//print a student's data
void print(student data , int idb, char *filename, int user_choice) {
    findStudent(data,l,new, idb,filename, user_choice);
    save(filename, l->head);
    return;
}

//change student's data by id
student* updateStudent(student data, struct listR *l, struct nodeR *new, int idc, char *filename, int user_choice) {
    
    findStudent(data,l,new,idc,filename,user_choice);
    save(filename, l->head);
    return &new->data;
}

//delete a student from list 
void deleteStudent(student data, struct listR *l, int idd, char *filename) {
    struct nodeR* temp = l->head;
    struct nodeR *prev;
    int found=0;

    printf("\n");
    if( list_size(l)==0 ) {
        printf("List is empty\n");
    }else {
        if( temp!=NULL && (temp->data.id)==idd ) {
            l->head = temp->next;
            found=1;
            free(temp);
            l->size--;
            printf("Student was succesfully deleted\n");
            save(filename, l->head);
            printf("\n");
            return;
        }

        while( (temp->next)!=NULL && (temp->data.id)!=idd ) {
            prev = temp;
            temp = temp->next;
        }
        if(temp!=NULL && (temp->data.id)==idd) {
            prev->next = temp->next;
            found=1;
            free(temp);
            l->size--;
            printf("Student was succesfully deleted\n");
            temp = prev->next;
            save(filename, l->head);
        }

        if( found==0 ) {
        printf("This id is not matching to any student\n");
        printf("\n");
        }
    }
    save(filename, l->head);
    printf("\n");
    return;
}

struct listR load(char *name) {
    struct listR list;

    list.size = 0;
    list.head=NULL;
    FILE *stream;
    stream = fopen(name, "r");

    if( stream==NULL ) {
        printf("File does not exist\n");
        printf("\n");
        return list;
    }

    student st;
    struct nodeR *tail=NULL;
    while( fscanf(stream,"%d\t",&st.id) && fgets(st.name,sizeof(st.name),stream) ) {
        if( tail!=NULL ) {      
            tail->next= entry_node(st);
            tail = tail->next;
            list.size++;
        }else{
            tail=entry_node(st);
            list.head=tail;
            list.size++;
        }
    }

    fclose(stream);
    return list;
}

void save(char *filename, struct nodeR *head) {
    struct nodeR *tmp=head;

    FILE *stream;
    stream = fopen(filename,"w");
    if( stream==NULL ) {
        printf("File does not exist\n");
        printf("\n");
        return;
    }

    while( tmp!=NULL ) {      
        fprintf(stream, "%d\t%s\n", tmp->data.id, tmp->data.name);
        tmp = tmp->next;
    }
    
    fclose(stream);
    return;
}

 

