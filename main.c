#include "student.h"
#include <stdio.h>
#include <stdlib.h>

void insert_student(student data, struct listR *l,char *argv[]) {
    struct nodeR *tmp2;

    if( list_size(l)==0 ) {
        printf("\n");
        printf("Insert student's id\n");
        if((scanf("%d", &data.id))!=1) {
            printf("Please try again. Insert only numbers\n");
            exit(1);
        }
        printf("Insert student's name\n");
        fgets(data.name,sizeof(data.name),stdin);
        fgets(data.name,sizeof(data.name),stdin);
        addStudent(data, l,argv[1]);                
    }else{
        tmp2 = l->head;
        printf("\n");
        printf("Insert student's id\n");
        if((scanf("%d", &data.id))!=1) {
            printf("Please try again. Insert only numbers\n");
            exit(1);
        }
        while( tmp2!=NULL ) {      
            if((tmp2->data.id) == data.id) {                    
                do {                          
                    printf("\n");
                    printf("This id is already in use\n");
                    printf("\n");
                    printf("Insert student's id\n");
                    if((scanf("%d", &data.id))!=1) {
                        printf("Please try again. Insert only numbers\n");
                        exit(1);
                    }
                    tmp2 = l->head;
                }while(data.id == (tmp2->data.id));
            }
                    
            tmp2 = tmp2->next;
        }          
        printf("Insert student's name\n");
        fgets(data.name,sizeof(data.name),stdin);
        fgets(data.name,sizeof(data.name),stdin);
        addStudent(data, l,argv[1]);
    }
    save(argv[1], l->head);
}

int student_identification() {
    int id;
    printf("Insert student's id\n");
    if((scanf("%d", &id))!=1) {
        printf("Please try again. Insert only numbers\n");
        exit(1);
    }
    return id;
}



int main( int argc, char *argv[]) {    
         
    student data;
    l = list_create();
    
    if(argc!=2) {
        printf("Create a file and insert it as a parameter\n");
        exit(1);
    } 
    *l=load(argv[1]);
    
    struct nodeR *tmp2;
    int choice;
    int id;
    
    do{
        choice = printMenu();
        if( choice==1 ) {

            insert_student(data,l,argv);
            
        }else if( choice==6 ) {

            printstudents(l,argv[1]);
            
        }else if( choice == 7 ) {

            save(argv[1], l->head);
            while( (list_size(l))!=0 ) {
                first_node_delete(l);
            }
            free(l);
            exit(1);
        
        }else if( choice == 3 ) {

            id = student_identification();
            findStudent(data,l,new,id,argv[1],choice);

        }else if( choice==5 ) {

            id = student_identification();
            print(data,id,argv[1],choice);

        }else if( choice == 2 ) {
            
            id = student_identification();
            deleteStudent(data,l,id,argv[1]);
            
        }else if( choice == 4 ) {
            
            id = student_identification();
            updateStudent(data,l,new, id, argv[1],choice);
            
        }
    
    }while( choice!=7 );

    return 0;
}
    
