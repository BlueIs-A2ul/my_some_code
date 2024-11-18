// manu_detail.c
#include <stdio.h>
#include <string.h>
#include "manu_detail.h"
#include "struct.h"
char buffer[1000];
#define MAX_STUDENTS 100
#include <stdio.h>

void manu_detail()
{
    printf("\n\n");
    printf("***********************************************************\n");
    printf("*                      学生信息管理系统                   *\n");
    printf("***********************************************************\n");
    printf("**********************系统功能菜单**************************\n");
    printf("--------------------------     ----------------------------\n");
    printf("**********************************************************\n");
    printf("*     1、菜单详细              *      2、增加学生信息      *\n");
    printf("*     3、查询学生信息          *      4、删除学生信息      *\n");
    printf("*     5、修改学生信息          *      6、展示学生信息      *\n");
    printf("**********************************************************\n");
    printf("*     7、排序学生信息(姓名)    *      8、排序学生信息(学号)*\n");
    printf("*     9、排序学生信息(分数)    *      10、退出系统         *\n");
    printf("***********************************************************\n");
    printf("--------------------------     ----------------------------\n");
    printf("*********************请输入您的选择(1-10)*******************\n");
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

    printf("已经按照数学分数排序   \n");
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

    printf("已将按照英语分数排序   \n");    
    read_file(file, *head);
}

void bubble_sort_by_clanguage_score(FILE *file, struct List_student **head)
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

    printf("已经按照c语言分数排序   \n");
    read_file(file, *head);
}

void add_student(FILE *file)
{
    // point the position of the file to the end
    printf("需要添加多少学生信息？");
    int num_students;
    scanf("%d", &num_students); // the number of students to be added

    for (int i = 0; i < num_students; i++)
    {

        printf("请输入学生id：");
        int id;
        scanf("%d", &id);
        List_student[i].id = id;

        printf("请输入学生姓名：");
        char name[50];
        scanf("%s", name);
        strcpy(List_student[i].name, name);

        printf("请输入学生班级：");
        int class;
        scanf("%d", &class);
        List_student[i].class_num = class;

        printf("请输入学生年龄：");
        int age;
        scanf("%d", &age);
        List_student[i].age = age;

        printf("请输入学生数学分数：");
        float math_score;
        scanf("%f", &math_score);
        List_student[i].math_score = math_score;

        printf("请输入学生英语分数 ");
        float english_score;
        scanf("%f", &english_score);
        List_student[i].english_score = english_score;

        printf("请输入学生c语言分数：");
        float clanguage_score;
        scanf("%f", &clanguage_score);
        List_student[i].clanguage_score = clanguage_score;

        printf("学生信息添加成功！  \n");
        // 用户输入完成后，将学生信息写入文件
        fprintf(file, "\n");
        fprintf(file, "%d,%s,%d,%d,%.2f,%.2f,%.2f\n", id, name, class, age, math_score, english_score, clanguage_score);
        printf("还有%d个学生信息需要添加\n", num_students - i - 1);
        if (i == num_students - 1)
        {
            printf("所有学生信息添加完成！\n");
        }
    }
    save_List_student(file, List_student);
}

void search_student(FILE *file, struct List_student *head)
{
    int id;
    struct List_student *p = head;
    printf("请输入学号");
    scanf("%d", &id);
    while (p != NULL)
    {
        if (p->id == id)
        {
            printf("学号\t\t姓名\t\t班级\t\t年龄\t\t数学\t\t英语\t\tc语言\n");
            printf("%d\t\t%s\t\t%d\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", p->id, p->name, p->class_num, p->age, p->math_score, p->english_score, p->clanguage_score);
            return;
        }
        p = p->next;
    }
    printf("未找到该学生信息\n");
    printf("输入1呼出菜单，输入10退出系统\n");
}

void delete_student(FILE *file, struct List_student **head)
{
    printf("请输入要删除的学生学号");
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
            printf("学号为%d的学生信息已删除\n", id);
            save_List_student(file, *head);
            printf("输入1呼出菜单，输入10退出系统\n");
            return;
        }
        q = p;
        p = p->next;
    }
    printf("未找到该学生信息\n");
    printf("输入1呼出菜单，输入10退出系统\n");
}

void modify_student(FILE *file, struct List_student **head)
{
    int found = 0; // 用于标记是否找到学生
    int id;
    char name[50];
    int class;
    int age;
    float math_score;
    float english_score;
    float clanguage_score;

    printf("输入要修改学生的学号");
    scanf("%d", &id);

    struct List_student *p = *head;
    while (p != NULL)
    {
        if (p->id == id)
        {
            int choice;
            printf("1.学生姓名\n");
            printf("2.学生班级\n");
            printf("3.学生年龄\n");
            printf("4.数学分数\n");
            printf("5.英语分数\n");
            printf("6.c语言分数\n");
            printf("请输入要修改的项(1-6)");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("现在的学生姓名是 %s\n", p->name);
                printf("输入新的学生姓名:");
                scanf("%s", name);
                strcpy(p->name, name);
                printf("修改完成\n");
                break;
            case 2:
                printf("现在班级是 %d\n", p->class_num);
                printf("输入新的学生班级:");
                scanf("%d", &class);
                p->class_num = class;
                printf("修改完成\n");
                break;
            case 3:
                printf("现在年龄是 %d\n", p->age);
                printf("输入新的学生年龄:");
                scanf("%d", &age);
                p->age = age;
                printf("修改完成\n");
                break;
            case 4:
                printf("现在数学成绩是 %.2f\n", p->math_score);
                printf("输入新的学生数学成绩:");
                scanf("%f", &math_score);
                p->math_score = math_score;
                printf("修改完成\n");
                break;
            case 5:
                printf("现在英语成绩是 %.2f\n", p->english_score);
                printf("输入新的学生英语成绩:");
                scanf("%f", &english_score);
                p->english_score = english_score;
                printf("修改完成\n");
                break;
            case 6:
                printf("现在C语言成绩是 %.2f\n", p->clanguage_score);
                printf("输入新的学生C语言成绩:");
                scanf("%f", &clanguage_score);
                p->clanguage_score = clanguage_score;
                printf("修改完成\n");
                break;
            default:
                printf("无效选择\n");
                break;
            }
            found = 1;
            break;
        }
        p = p->next;
    }

    if (found == 0)
    {
        printf("未找到该学生信息\n");
    }
    else
    {
        fclose(file);
        file = fopen("data.csv", "w");
        save_List_student(file, *head);
        fclose(file);
        file = fopen("data.csv", "r+");
    }
    printf("输入1呼出菜单，输入10退出系统\n");
}

void read_file(FILE *file, struct List_student *head)
{
    struct List_student *p = head;
    int num = 1;
    printf("\t\t学号\t\t姓名\t\t班级\t\t年龄\t\t数学\t\t英语\t\tc语言\n");
    while (p != NULL)
    {
        printf("%d\t\t%d\t\t%s\t\t%d\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", num, p->id, p->name, p->class_num, p->age, p->math_score, p->english_score, p->clanguage_score);
        num++;
        p = p->next;
    }
    printf("输入1呼出菜单，输入10退出系统\n");
    printf("\n");

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
    } while (swapped);

    printf("已按照姓名排序   \n");
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

    printf("已按照学号排序   \n");
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
    printf("1.数学分数\n");
    printf("2.英语分数\n");
    printf("3.c语言分数\n");
    printf("输入要排序的科目(1-3)");
    scanf("%d", &choice);

    switch (choice)
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
        printf("无效选择\n");
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