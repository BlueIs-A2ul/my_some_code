// manu_detail.c
#include <stdio.h>
#include <string.h> 
#include "manu_detail.h"
#include "struct.h"
char buffer[1000];
#define MAX_STUDENTS 100
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

void bubble_sort_by_math_score(FILE *file, struct List_student **head)
{
    struct List_student *p;
    struct List_student *q;
    int swapped;

    if (*head == NULL)
        return;

    do
    {
        swapped = 0;
        p = *head;

        while (p->next != NULL)
        {
            if (p->math_score > p->next->math_score)
            {
                // 交换节点
                q = p->next;
                p->next = q->next;
                q->next = p;

                if (p == *head)
                {
                    *head = q; // 更新头指针
                }
                else
                {
                    // 找到prev
                    struct List_student *prev = *head;
                    while (prev->next != p)
                    {
                        prev = prev->next;
                    }
                    prev->next = q; // 正确连接prev
                }
                swapped = 1; // 标记有交换
            }
            else
            {
                p = p->next; // 向前移动
            }
        }
    } while (swapped);

    printf("students have been sorted by math_score\n");
    read_file(file, *head);
}

void bubble_sort_by_english_score(FILE *file, struct List_student **head)
{
    struct List_student *p;
    struct List_student *q;
    int swapped;

    if (*head == NULL)
        return;

    do
    {
        swapped = 0;
        p = *head;

        while (p->next != NULL)
        {
            if (p->english_score > p->next->english_score)
            {
                // 交换节点
                q = p->next;
                p->next = q->next;
                q->next = p;

                if (p == *head)
                {
                    *head = q; // 更新头指针
                }
                else
                {
                    // 找到prev
                    struct List_student *prev = *head;
                    while (prev->next != p)
                    {
                        prev = prev->next;
                    }
                    prev->next = q; // 正确连接prev
                }
                swapped = 1; // 标记有交换
            }
            else
            {
                p = p->next; // 向前移动
            }
        }
    } while (swapped);

    printf("students have been sorted by english_score\n");
    read_file(file, *head);
}

void bubble_sort_by_clanguage_score(FILE * file, struct List_student * *head)
    {
        struct List_student *p;
        struct List_student *q;
        int swapped;

        if (*head == NULL)
            return;

        do
        {
            swapped = 0;
            p = *head;

            while (p->next != NULL)
            {
                if (p->clanguage_score > p->next->clanguage_score)
                {
                    // 交换节点
                    q = p->next;
                    p->next = q->next;
                    q->next = p;

                    if (p == *head)
                    {
                        *head = q; // 更新头指针
                    }
                    else
                    {
                        // 找到prev
                        struct List_student *prev = *head;
                        while (prev->next != p)
                        {
                            prev = prev->next;
                        }
                        prev->next = q; // 正确连接prev
                    }
                    swapped = 1; // 标记有交换
                }
                else
                {
                    p = p->next; // 向前移动
                }
            }
        } while (swapped);

        printf("students have been sorted by clanguage_score\n");
        read_file(file, *head);
    }

void add_student(FILE * file)
    {
        // point the position of the file to the end
        printf("how many students do you want to add?");
        int num_students;
        scanf("%d", &num_students); // the number of students to be added

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
            fprintf(file, "\n");
            fprintf(file, "%d,%s,%d,%d,%.2f,%.2f,%.2f\n", id, name, class, age, math_score, english_score, clanguage_score);
            printf("leave %d students to add\n", num_students - i - 1);
            if (i == num_students - 1)
            {
                printf("all students have been added\n");
            }
        }
        save_List_student(file, List_student);
    }

void search_student(FILE * file, struct List_student * head)
    {
        int id;
        struct List_student *p = head;
        printf("Enter student ID to search:");
        scanf("%d", &id);
        while (p != NULL)
        {
            if (p->id == id)
            {
                printf("student ID: %d\n", p->id);
                printf("student name: %s\n", p->name);
                printf("student class: %d\n", p->class_num);
                printf("student age: %d\n", p->age);
                printf("student math_score: %.2f\n", p->math_score);
                printf("student english_score: %.2f\n", p->english_score);
                printf("student clanguage_score: %.2f\n", p->clanguage_score);
                printf("input 1 to show the details of manu\n");
                printf("or input 10 to exit the system\n");
                return;
            }
            p = p->next;
        }
        printf("not found\n");
        printf("input 1 to show the details of manu\n");
    }

void delete_student(FILE * file, struct List_student * *head)
    {
        printf("Enter student ID to delete:");
        int id;
        scanf("%d", &id);
        struct List_student *p = *head;
        struct List_student *q = NULL;
        while (p != NULL)
        {
            if (p->id == id)
            {
                if (q == NULL)
                {
                    *head = p->next;
                }
                else
                {
                    q->next = p->next;
                }
                free(p);
                printf("student has been deleted\n");
                save_List_student(file, *head);
                printf("input 1 to show the details of manu\n");
                printf("or input 10 to exit the system\n");
                return;
            }
            q = p;
            p = p->next;
        }
        printf("not found\n");
        printf("input 1 to show the details of manu\n");
    }

void modify_student(FILE * file, struct List_student * *head)
    {
        int found = 0; // 用于标记是否找到学生
        int id;
        char name[50];
        int class;
        int age;
        float math_score;
        float english_score;
        float clanguage_score;

        printf("Enter student ID to modify:");
        scanf("%d", &id);

        struct List_student *p = *head;
        while (p != NULL)
        {
            if (p->id == id)
            {
                int choice;
                printf("1.student name\n");
                printf("2.student class\n");
                printf("3.student age\n");
                printf("4.student math_score\n");
                printf("5.student english_score\n");
                printf("6.student clanguage_score\n");
                printf("Enter the number of the attribute to modify:");
                scanf("%d", &choice);

                switch(choice)
                {
                    case 1:
                        printf("Enter new student name:");
                        scanf("%s", name);
                        strcpy(p->name, name);
                        printf("student name has been modified\n");
                        break;
                    case 2:
                        printf("Enter new student class:");
                        scanf("%d", &class);
                        p->class_num = class;
                        printf("student class has been modified\n");
                        break;
                    case 3:
                        printf("Enter new student age:");
                        scanf("%d", &age);
                        p->age = age;
                        printf("student age has been modified\n");
                        break;
                    case 4:
                        printf("Enter new student math_score:");
                        scanf("%f", &math_score);
                        p->math_score = math_score;
                        printf("student math_score has been modified\n");
                        break;
                    case 5:
                        printf("Enter new student english_score:");
                        scanf("%f", &english_score);
                        p->english_score = english_score;
                        printf("student english_score has been modified\n");
                        break;
                    case 6:
                        printf("Enter new student clanguage_score:");
                        scanf("%f", &clanguage_score);
                        p->clanguage_score = clanguage_score;
                        printf("student clanguage_score has been modified\n");
                        break;
                    default:
                        printf("invalid choice\n");
                        break;
                }
                found = 1;
                break;
            }
            p = p->next;
        }

        if (found == 0)
        {
            printf("not found\n");
        }
        else
        {   
            fclose(file);
            file = fopen("data.csv", "w");
            save_List_student(file, *head);
            fclose(file);
            file = fopen("data.csv", "r+");
        }
        printf("input 1 to show the details of manu\n");
        printf("or input 10 to exit the system\n");
}

void read_file(FILE *file, struct List_student *head)
{   
    struct List_student *p = head;   
    while ( p != NULL)
    {
        printf("student ID: %d\n", p->id);
        printf("student name: %s\n", p->name);
        printf("student class: %d\n", p->class_num);
        printf("student age: %d\n", p->age);
        printf("student math_score: %.2f\n", p->math_score);
        printf("student english_score: %.2f\n", p->english_score);
        printf("student clanguage_score: %.2f\n", p->clanguage_score);

        if (p->next != NULL)
        {
            printf("---------------------------------\n");
        }else{
            printf("not found\n");
            printf("input 1 to show the details of manu\n");
        }
        p = p->next;
    } 
}

void sort_by_name(FILE *file, struct List_student **head)
{
    // 利用冒泡排序，以name作为大小对链表进行排序
    struct List_student *p = *head;
    struct List_student *q = NULL;
    struct List_student *prev = NULL;
    int swapped;

    do
    {
        swapped = 0;
        p = *head;
        while (p->next != NULL)
        {
            if (strcmp(p->name, p->next->name) > 0)
            {
                // 交换节点
                q = p->next;
                p->next = q->next;
                q->next = p;
                if (prev == NULL)
                {
                    *head = q;
                }
                else
                {
                    prev->next = q;
                }
                p = q;
                swapped = 1;
            }
            prev = p;
            p = p->next;
        }       
    }
    while (swapped);

    printf("students have been sorted by name\n");
    read_file(file, *head);
}

void sort_by_id(FILE *file, struct List_student **head)
{
    // 利用冒泡排序，以id作为大小对链表进行排序
    struct List_student *p = *head;
    struct List_student *q = NULL;
    struct List_student *prev = NULL;
    int swapped;

    do
    {
        swapped = 0;
        p = *head;
        while (p->next != NULL)
        {
            if (p->id > p->next->id)
            {
                // 交换节点
                q = p->next;
                p->next = q->next;
                q->next = p;
                if (prev == NULL)
                {
                    *head = q;
                }
                else
                {
                    prev->next = q;
                }
                p = q;
                swapped = 1;
            }
            prev = p;
            p = p->next;
        }
    } while (swapped);

    printf("students have been sorted by id\n");
    fclose(file);
    file = fopen("data.csv", "w");
    save_List_student(file, *head);
    fclose(file);
    file = fopen("data.csv", "r");
    read_file(file, *head);
    fclose(file);
    
}

void sort_by_subject(FILE *file, struct List_student **head)
{
    int choice;
    printf("1.math_score\n");
    printf("2.english_score\n");
    printf("3.clanguage_score\n");
    printf("Enter the number of the subject to sort:");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            bubble_sort_by_math_score(file, head);
            break;
        case 2:
            bubble_sort_by_english_score(file, head);
            break;
        case 3:
            bubble_sort_by_clanguage_score(file, head);
            break;
        default:
            printf("invalid choice\n");
            break;
    }
}

void create_List_student(FILE *file, struct List_student **head)
{
    struct List_student *p = NULL, *new_node = NULL;
    *head = NULL; // 初始化链表头指针

    fseek(file, 0, SEEK_SET);
    while (fgets(buffer, sizeof(buffer), file))
    {
        char *tokens[7];
        char *token = strtok(buffer, ",");
        int index = 0;
        while (token != NULL && index < 7)
        {
            tokens[index++] = token;
            token = strtok(NULL, ",");
        }

        if (index < 7)
        {
            printf("Invalid input format in line: %s\n", buffer);
            continue; // 跳过不完整数据
        }

        // 转换数据类型
        int id_int = atoi(tokens[0]);
        int class_int = atoi(tokens[2]);
        int age_int = atoi(tokens[3]);
        float math_score_float = atof(tokens[4]);
        float english_score_float = atof(tokens[5]);
        float clanguage_score_float = atof(tokens[6]);

        // 创建新节点
        new_node = (struct List_student *)malloc(sizeof(struct List_student));
        if (!new_node)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }

        new_node->id = id_int;
        strcpy(new_node->name, tokens[1]);
        new_node->class_num = class_int;
        new_node->age = age_int;
        new_node->math_score = math_score_float;
        new_node->english_score = english_score_float;
        new_node->clanguage_score = clanguage_score_float;
        new_node->next = NULL;

        // 将新节点添加到链表末尾
        if (*head == NULL)
        {
            *head = new_node;
        }
        else
        {
            p = *head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = new_node;
        }
    }
}

void save_List_student(FILE *file, struct List_student *head)
{
    struct List_student *p = head;
    while (p != NULL)
    {
        fprintf(file, "%d,%s,%d,%d,%.2f,%.2f,%.2f\n", p->id, p->name, p->class_num, p->age, p->math_score, p->english_score, p->clanguage_score);
        p = p->next;
    }
}