#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char name[50];
    float grade;

}Student;

Student* intit_student(int num){
    return malloc(num*sizeof(Student));
}

void add_student(Student *student, int *count, int capacity){
    int id;
    char name[50];
    float grade;
    if(*count >= capacity){
    printf("Maximum students reached\n");
    return;
}else{
    printf("Enter the id of student: ");
    scanf("%d", &id);
    printf("Enter the name of student: ");
    while(getchar() != '\n');
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter the grade of student: ");
    scanf("%f", &grade);
    student[*count].id = id;
    strcpy(student[*count].name, name);
    student[*count].grade = grade;
    (*count)++;}

    
}

void display_students(Student *student, int count){
    printf("ID  ....... Name:  ....... Grade\n");
    for(int i=0; i<count; i++){
        printf("%d         %s           %.2f\n",
                student[i].id, student[i].name, student[i].grade);

    }
}

void sort_students(Student *student, int count){
    for(int i=0; i<count; i++){
        for(int j=0; j<count-1; j++){
            if(student[j].grade > student[j+1].grade){
            Student temp = student[j];
            student[j] = student[j+1];
            student[j+1] = temp;
        }
        }
        
    }
    printf("Students sorted by grade:\n");
    display_students(student, count);
}

void culculate_average(Student *student, int count){
    float sum = 0;
    for(int i = 0; i<count; i++){
        sum += student[i].grade;
    }
    printf("%.2f\n", sum/count);
}

void find_top_student(Student *student, int count){
    float highest = student[0].grade;
    int highest_index = 0;
    for(int i = 0; i<count; i++){
        if(highest<student[i].grade){
            highest = student[i].grade;
            highest_index = i;
        }
    }
    printf("%s is the top student with the grade of %.2f\n",student[highest_index].name, student[highest_index].grade);
}

void classification(Student *student, int count){
    for(int i = 0; i<count; i++){
        if(student[i].grade>=90){
            printf("%s: Grade A\n", student[i].name);
        }else if (student[i].grade<90 && student[i].grade>=80){
            printf("%s:Grade B\n", student[i].name);
        }else if (student[i].grade<80 && student[i].grade>=70){
            printf("%s:Grade C\n", student[i].name);
        }else if (student[i].grade<70 && student[i].grade>=60){
            printf("%s:Grade D\n", student[i].name);
        }else{
            printf("%s:Grade F\n", student[i].name);
        }
    }

}

void free_memory(Student *student){
    free(student);
}

void (*operation[])(Student*, int) = {
    display_students,
    sort_students,
    culculate_average,
    find_top_student,
    classification
};

int main(){
    int count = 0;
    int capacity = 15;
    int choice;

    Student *students = intit_student(capacity);

    while(1){
        printf("\n");
        printf("=======Student Databse========\n");
        printf("\n");
        printf("Type:\n 1 to add a new students\n 2 to display students \n 3 to sort students\n 4 to calculate the average\n 5 to find the top student\n 6 to classify the students according to grades\n 7 to exit\n");
        if (scanf("%d", &choice) != 1){
            printf("Invalid choice. Enter a valid chioce");
            while(getchar()!= '\n');

            continue;
        }
        if(choice == 1){
            add_student(students, &count, capacity);
        }else if(choice >= 2 && choice <= 6){
            operation[choice-2](students, count);
        }else if (choice == 7){
            break;
        }else{
            printf("Invalid choice\n");
        }
    }

    free_memory(students);

    return 0;
}
