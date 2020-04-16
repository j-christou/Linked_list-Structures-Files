#define MAXSTRING 150 

typedef struct {
    char name[MAXSTRING];                  
    int id;
}student;

extern int choice;                         



struct nodeR {                             
    student data;                           
    struct nodeR *next;
};

struct listR {
    struct nodeR *head;                     
    int size;                               
    
};

void first_node_delete( struct listR *l);
struct listR* list_create();
void first_node_list( struct listR*, struct nodeR*);
struct nodeR* entry_node(student data);
struct listR *l;
struct nodeR *new;
int list_size(struct listR *l);

int printMenu();

void insert_student(student data, struct listR *l,char *argv[]);

int student_identification();

void print(student data, int idb, char *filename, int user_choice);

void printstudents(struct listR*, char *filename);

struct listR load(char *name);         

void save(char *filename, struct nodeR *head);    

student addStudent(student data, struct listR *l, char *filename);    

student* findStudent(student data, struct listR *l, struct nodeR *new, int ida, char *filename, int user_choice);   

void deleteStudent(student data, struct listR *l, int idd, char *filename);   

student* updateStudent(student data, struct listR *l, struct nodeR *new, int idc, char *filename, int user_choice);   
