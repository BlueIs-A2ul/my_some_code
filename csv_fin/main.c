#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_students 1000

struct List_student // 链表结构体定义
{
    int id;                    // 学号
    char name[20];             // 姓名
    int class_num;             // 班级
    int age;                   // 年龄
    float math_score;          // 数学成绩
    float english_score;       // 英语成绩
    float clanguage_score;     // 计算机语言成绩
    struct List_student *next; // 指向下一个节点的指针
} List_student[MAX_students];

int n = 0; // 学生数量

void menu_detail();
void add_student();
void delete_student();
void modify_student();
void search_student();
void sort_student_byid();
void sort_student_byclass();
void sort_student_byscore();
void print_student_byid();
void save_student();
void swap(struct List_student *a, struct List_student *b);  
int main()
{
    int choice = 0;
    while(choice = 0){
        menu_detail();
        printf("请输入您的选择：");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                modify_student();
                break;
            case 4:
                search_student();
                break;
            case 5:
                print_student_byid();
                break;
            case 6:
                print_student_bycalss();
                break;
            case 7:
                print_student_byscore();
                break;
            case 8:
                save_student();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("输入错误，请重新输入！\n");
                break;
        }
        system("pause");
    }
    return 0;   
}

void menu_detail(){ // 菜单界面
    printf("学生信息管理系统\n");
    printf("1.添加学生信息\n");
    printf("2.删除学生信息\n");
    printf("3.修改学生信息\n");
    printf("4.查询学生信息\n");
    printf("5.按学号查询学生信息\n");
    printf("6.按班级查询学生信息\n");
    printf("7.按成绩查询学生信息\n");
    printf("8.保存学生信息\n");
    printf("9.退出系统\n");
}

void save_student(){ // 保存学生信息
    FILE *fp;
    fp = fopen("student.txt", "w");
    if(fp == NULL){
        printf("文件打开失败！\n");
        return;
    }
    struct List_student *p = List_student;
    while(p!= NULL){
        fprintf(fp, "%d,%s,%d,%d,%.2f,%.2f,%.2f\n", p->id, p->name, p->class_num, p->age, p->math_score, p->english_score, p->clanguage_score);
        p = p->next;
    }
    fclose(fp);
    printf("保存成功！\n");
}

void add_student(){ // 添加学生信息
    if(n >= MAX_students){
        printf("学生数量已达上限！\n");
        return;
    }
    struct List_student *p = List_student;
    int num = 0;
    printf("\n请输入增加的学生数量：");
    scanf("%d", &num);
    while(num--){
        printf("请输入学生信息：\n");
        printf("学号：");
        scanf("%d", &p->id);
        printf("姓名：");
        scanf("%s", p->name);
        printf("班级：");
        scanf("%d", &p->class_num);
        printf("年龄：");
        scanf("%d", &p->age);
        printf("数学成绩：");
        scanf("%f", &p->math_score);
        printf("英语成绩：");
        scanf("%f", &p->english_score);
        printf("计算机语言成绩：");
        scanf("%f", &p->clanguage_score);
        p->next = (struct List_student*)malloc(sizeof(struct List_student));
        p = p->next;
        n++;
    }
    printf("添加成功！\n");
}

void sort_student_byid(){ // 按学号排序
    struct List_student *p = List_student;
    struct List_student *q = NULL;
    struct List_student *r = NULL;
    int i, j, k;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(p[i].id > p[j].id){
                q = p[i].next;
                p[i].next = p[j].next;
                p[j].next = q;
                r = p[i].id;
                p[i].id = p[j].id;
                p[j].id = r;
            }
        }
    }
    printf("按学号排序成功！\n");
}

void delete_student(){ // 删除学生信息
    int id;
    printf("请输入要删除的学生学号：");
    scanf("%d", &id);
    struct List_student *head = List_student;
    struct List_student *p = head;
    struct List_student *q = NULL;
    while(p!= NULL){
        if(p->id == id){
            if(q == NULL){
                head = p->next;
            }else{
                q->next = p->next;
            }
            free(p);
            n--;
            printf("删除成功！\n");
            return;
        }
        q = p;
        p = p->next;
    }
    printf("没有找到该学生！\n");
}

void modify_student(){ // 修改学生信息
    int id;
    printf("请输入要修改的学生学号：");
    scanf("%d", &id);
    struct List_student *p = List_student;
    while(p!= NULL){
        if(p->id == id){
            printf("请输入修改后的学生信息：\n");
            printf("姓名：");
            scanf("%s", p->name);
            printf("班级：");    
            scanf("%d", &p->class_num);
            printf("年龄：");
            scanf("%d", &p->age);
            printf("数学成绩：");
            scanf("%f", &p->math_score);
            printf("英语成绩：");
            scanf("%f", &p->english_score);
            printf("计算机语言成绩：");
            scanf("%f", &p->clanguage_score);
            printf("修改成功！\n");
            return;
        }
        p = p->next;
    }
    printf("没有找到该学生！\n");
}

void search_student(){ // 查询学生信息
    int id;
    printf("请输入要查询的学生学号：");
    scanf("%d", &id);
    struct List_student *p = List_student;
    while(p!= NULL){
        if(p->id == id){
            printf("学号：%d\n", p->id);
            printf("姓名：%s\n", p->name);
            printf("班级：%d\n", p->class_num);
            printf("年龄：%d\n", p->age);
            printf("数学成绩：%.2f\n", p->math_score);
            printf("英语成绩：%.2f\n", p->english_score);
            printf("计算机语言成绩：%.2f\n", p->clanguage_score);
            return;
        }
        p = p->next;
    }
    printf("没有找到该学生！\n");
}

void sort_student_byclass(){ // 按班级排序
    struct List_student *p = List_student;
    struct List_student *q = NULL;
    struct List_student *r = NULL;
    int i, j, k;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(p[i].class_num > p[j].class_num){
                q = p[i].next;
                p[i].next = p[j].next;
                p[j].next = q;
                r = p[i].class_num;
                p[i].class_num = p[j].class_num;
                p[j].class_num = r;
            }
        }
    }
    printf("按班级排序成功！\n");
}

void sort_student_byscore(){ // 按成绩排序
    struct List_student *p = List_student;
    struct List_student *q = NULL;
    struct List_student *r = NULL;
    int choice;
    printf("按哪个成绩排序？\n");
    printf("1.数学成绩\n");
    printf("2.英语成绩\n");
    printf("3.计算机语言成绩\n");
    printf("请输入您的选择：");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            for(int i = 0; i < n; i++){
                for(int  j = i + 1; j < n; j++){
                    if(p[i].math_score > p[j].math_score){  
                        q = p[i].next;
                        p[i].next = p[j].next;
                        p[j].next = q;
                        swap(&p[i], &p[j]);
                    }
                }
            }
    }
}

void print_student_byid(){ // 按学号打印学生信息
    sort_student_byid;
    struct List_student *p = List_student;
    while(p != NULL){
        printf("学号：%d\n", p->id);
        printf("姓名：%s\n", p->name);
        printf("班级：%d\n", p->class_num);
        printf("年龄：%d\n", p->age);
        printf("数学成绩：%.2f\n", p->math_score);
        printf("英语成绩：%.2f\n", p->english_score);
        printf("计算机语言成绩：%.2f\n", p->clanguage_score);
        printf("\n");
        p = p->next;
    }
}

void swap(struct List_student *a, struct List_student *b){ // 交换两个学生信息
    struct List_student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}