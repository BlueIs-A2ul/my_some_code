// manu_detail.c
#include <stdio.h>
#include <string.h> 
#include "manu_detail.h"
#include "struct.h"
char buffer[1000];
void manu_detail()
{
    printf("1.菜单详细\n");
    printf("2.增加学生信息\n");
    printf("3.查询学生信息\n");
    printf("4.删除学生信息\n");
    printf("5.修改学生信息\n");
    printf("6.读取文件\n");
    printf("7.显示所有学生信息(按照姓名排序)\n");
    printf("8.显示所有学生信息(按照学号排序)\n");
    printf("9.学科详情（按照分数排序）\n");
    printf("10.退出系统\n");
    printf("请输入选项对应的数字：");
}

void add_student(FILE *file)
{
    //point the position of the file to the end
    printf("how many students do you want to add?");
    int num_students;
    scanf("%d", &num_students); // the number of students to be added

    struct List_student List_student[num_students]; // array to store the students

    for (int i = 0; i < num_students; i++)
    {

        printf("Enter student ID:");
        int id;
        scanf("%d", &id);
        List_student[i].id = id;

        printf("Enter student name:");
        char name[50];
        scanf("%s", name);
        strcpy(List_student[i].name, name);

        printf("Enter student class:");
        int class;
        scanf("%d", &class);
        List_student[i].class_num = class;

        printf("Enter student age:");
        int age;
        scanf("%d", &age);
        List_student[i].age = age;

        printf("Enter student math_score:");
        float math_score;
        scanf("%f", &math_score);
        List_student[i].math_score = math_score;

        printf("Enter student english_score:");
        float english_score;
        scanf("%f", &english_score);
        List_student[i].english_score = english_score;

        printf("Enter student clanguage_score:");
        float clanguage_score;
        scanf("%f", &clanguage_score);
        List_student[i].clanguage_score = clanguage_score;
        
        printf("the student has been added\n");
        // 用户输入完成后，将学生信息写入文件
        fprintf(file, "%d,%s,%d,%d,%.2f,%.2f,%.2f\n", id, name, class,age, math_score, english_score, clanguage_score);
        printf("input 1 to show the details of manu\n");
        printf("or input 10 to exit the system\n");
        printf("leave %d students to add\n", num_students - i - 1);
        // write the student details to the file
    }
}

void search_student(FILE *file)
{
    printf("Enter student ID to search:");
    int id;
    scanf("%d", &id);

    fseek(file, 0, SEEK_SET);
    int found = 0; // 用于标记是否找到学生

    while (fgets(buffer, sizeof(buffer), file))
    {
        char *id_str = strtok(buffer, ",");
        char *name_str = strtok(NULL, ",");
        char *class_str = strtok(NULL, ",");
        char *age_str = strtok(NULL, ",");
        char *math_score_str = strtok(NULL, ",");
        char *english_score_str = strtok(NULL, ",");
        char *clanguage_score_str = strtok(NULL, "\n");

        int id_int = atoi(id_str);
        int class_int = atoi(class_str);
        int age_int = atoi(age_str);
        float math_score_float = atof(math_score_str);
        float english_score_float = atof(english_score_str);
        float clanguage_score_float = atof(clanguage_score_str);

        if (id_int == id)
        {
            printf("ID: %d\n", id_int);
            printf("Name: %s\n", name_str);
            printf("Class: %d\n", class_int);
            printf("Age: %d\n", age_int);
            printf("Math score: %.2f\n", math_score_float);
            printf("English score: %.2f\n", english_score_float);
            printf("C language score: %.2f\n", clanguage_score_float);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("not found\n");
        printf("input 1 to show the details of manu\n");
        printf("or input 10 to exit the system\n");
    }
}

// void delete_student(FILE *file)
// {
//     if (file == NULL)
//     {
//         fprintf(stderr, "文件未打开。\n");
//         return;
//     }

//     printf("Enter student ID to delete:");
//     int id;
//     if (scanf("%d", &id) != 1)
//     {
//         fprintf(stderr, "输入无效，请输入一个整数。\n");
//         return;
//     }

//     fseek(file, 0, SEEK_SET);
//     int found = 0;

//     FILE *temp_file = fopen("temp_file.csv", "w");
//     if (temp_file == NULL)
//     {
//         fprintf(stderr, "无法创建临时文件。\n");
//         return;
//     }

//     while (fgets(buffer, sizeof(buffer), file))
//     {
//         char *id_str = strtok(buffer, ",");
//         if (id_str == NULL)
//             continue; 

//         int id_int = atoi(id_str);

//         if (id_int == id)
//         {
//             found = 1;
//             printf("student %d has been deleted\n", id_int);
//             continue;
//         }

//         fputs(buffer, temp_file);
//     }

//     fclose(temp_file);
//     fclose(file);

//     remove("data.csv");                  
//     rename("temp_file.csv", "data.csv"); 

//     if (!found)
//     {
//         printf("未找到学生 ID %d\n", id);
//     }
// }

void delete_student(FILE *file)
{
    printf("Enter student ID to delete:");
    int id;
    scanf("%d", &id);

    fseek(file, 0, SEEK_SET);

    while (fgets(buffer, sizeof(buffer), file))
    {
        char *id_str = strtok(buffer, ",");
        char *name_str = strtok(NULL, ",");
        char *class_str = strtok(NULL, ",");
        char *math_score_str = strtok(NULL, ",");
        char *english_score_str = strtok(NULL, ",");
        char *clanguage_score_str = strtok(NULL, "\n");

        int id_int = atoi(id_str);
        int class_int = atoi(class_str);
        float math_score_float = atof(math_score_str);
        float english_score_float = atof(english_score_str);
        float clanguage_score_float = atof(clanguage_score_str);

        if (id_int == id)
        {
            fseek(file, -strlen(buffer), SEEK_CUR);
            fputs("\n", file);
            printf("student %d has been deleted\n", id_int);
            printf("input 1 to show the details of manu\n");
            printf("or input 10 to exit the system\n");
            return;
        }   
    }
    printf("not found\n");
    printf("input 1 to show the details of manu\n");
    printf("or input 10 to exit the system\n");
}

void modify_student(FILE *file)
{
}

void read_file(FILE *file)
{
}

void sort_by_name(FILE *file)
{
}

void sort_by_id(FILE *file)
{
}

void sort_by_subject(FILE *file)
{
}
