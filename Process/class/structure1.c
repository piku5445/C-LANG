#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// struct student
// {
//     char *name;
//     int roll;
//     double marks;
// };
// typedef struct student STUDENT;

typedef struct student
{
    char *name;
    int roll;
    double marks;
}STUDENT;


// int main()
// {
//     STUDENT s1;
//     char buffer[1000];

//     printf("Enter Name: ");
//     gets(buffer);
    // s1.name = (char *)malloc(strlen(buffer)+1);
//     strcpy(s1.name,buffer);
//     printf("Enter Roll: ");
//     scanf("%d",&s1.roll);
//     printf("Enter Marks: ");
//     scanf("%lf",&s1.marks);

//     printf("Displaying Contents\n");
//     printf("Name: %s\n",s1.name);
//     printf("Roll: %d\n",s1.roll);
//     printf("Marks: %.2lf\n",s1.marks);
//     return 0;
// }


// int main()
// {
//     STUDENT s[3];
//     char buffer[1000];

//     for(int i=0;i<3;i++){
//         printf("Enter Name for %d Student: ",i+1);
//         gets(buffer);
//         s[i].name = (char *)malloc(strlen(buffer)+1);
//         strcpy(s[i].name,buffer);
//         printf("Enter Roll: ");
//         scanf("%d",&s[i].roll);
//         printf("Enter Marks: ");
//         scanf("%lf",&s[i].marks);
//     }
//     for(int i=0;i<3;i++){
//         printf("Displaying Contents for student %d.\n",i+1);
//         printf("Name: %s\n",s[i].name);
//         printf("Roll: %d\n",s[i].roll);
//         printf("Marks: %.2lf\n",s[i].marks);
//     }
//     return 0;
// }

void display(STUDENT);
void getdata(STUDENT *);
int main()
{
    STUDENT *s;
    int n;
    printf("Enter the student streanth: ");
    scanf("%d",&n);
    s = (STUDENT*)malloc(n*sizeof(STUDENT));
    for(int i=0;i<n;i++){
        printf("Enter Informtion for %d Student:\n",i+1);
        getdata(&s[i]);
    }

    for(int i=0;i<n;i++){
        printf("Displaying Contents for student %d.\n",i+1);
        display(s[i]);
    }
    return 0;
}

void display(STUDENT s){
    printf("Name: %s\n",s.name);
    printf("Roll: %d\n",s.roll);
    printf("Marks: %.2lf\n",s.marks);
}
void getdata(STUDENT *s){
    char buffer[1000];
    printf("Enter Name: ");
    gets(buffer);
    (*s).name = (char *)malloc(strlen(buffer)+1);
    strcpy(s->name,buffer);
    printf("Enter Roll: ");
    scanf("%d",&(*s).roll);
    printf("Enter Marks: ");
    scanf("%lf",&s->marks);
}