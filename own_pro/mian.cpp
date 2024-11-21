#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct ListNode//账单的链表
{
    float moneys;//消费金额
    int class_id;//消费类型
    char time;//消费时间
    struct ListNode *next;
} List_Node[1000];

#define CSV_FILE "data.csv"

using namespace std;

void manu_menu();
void create_List_account(FILE *file, struct ListNode **head);
void add_account(FILE *file, struct ListNode **head);
void delete_account(FILE *file, struct ListNode **head);
void modify_account(FILE *file, struct ListNode **head);
void query_account(FILE *file, struct ListNode **head);

int main()
{
    FILE *file = fopen(CSV_FILE, "r+");
    if(file == NULL){
        printf("文件打开失败！");
        return 0;
    }
    struct ListNode *head = NULL;
    create_List_account(file, &head);

    int choice;
    manu_menu();
    while (1)
    {
        printf("请输入选项：");
        cin >> choice;
        switch (choice)
        {
        case 1:
            create_List_account(file, &head);
            break;
        case 2:
            add_account(file, &head);
            break;
        case 3:
            delete_account(file, &head);
            break;
        case 4:
            modify_account(file, &head);
            break;
        case 5:
            query_account(file, &head);
            break;
        case 6:
            fclose(file);
            return 0;
        default:
            printf("输入错误！");
            break;
        }
    }

    return 0;
}

void manu_menu(){
    printf("1.创建账单\n");
    printf("2.添加账单\n");
    printf("3.删除账单\n");
    printf("4.修改账单\n");
    printf("5.查询账单\n");
    printf("6.退出系统\n");
}

void create_List_account(FILE *file, struct ListNode **head){
    ListNode *p = NULL, *q = NULL;
    *head = NULL;
    char line[1000];
    while (fgets(line, sizeof(line), file))
    {
        p = (ListNode *)malloc(sizeof(ListNode));
        sscanf(line, "%f,%d,%c", &p->moneys, &p->class_id, &p->time);
        p->next = NULL;
        if (*head == NULL)
        {   
            *head = p;
            q = p;
        }
        else
        {
            q->next = p;
            q = p;
        }
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

void add_account(FILE *file, struct ListNode **head){
    printf("请输入记录单数：");
    int num;
    float moneys;
    int class_id;
    char time;
    cin >> num;
    for (int i = 0; i < num; i++){

        printf("请输入消费金额：");
        cin >> moneys;
        List_Node[num].moneys = moneys;

        printf("请输入消费类型：");
        cin >> class_id;
        List_Node[num].class_id = class_id;

        printf("请输入消费时间：");
        cin >> time;
        List_Node[num].time = time;

        fprintf(file , "\n");
        fprintf(file, "%f,%d,%c\n", moneys, class_id, time);
        if( i == num-1){
            printf("记录成功！");
            printf("重启以更新数据");
        }
    }
}

void delete_account(FILE *file, struct ListNode **head){
}

void modify_account(FILE *file, struct ListNode **head){
    }

void query_account(FILE *file, struct ListNode **head){
    }