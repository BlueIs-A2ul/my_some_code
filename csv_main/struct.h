#ifndef STRUCT_H
#define STRUCT_H

struct List_student // 链表结构体定义
{
    int id;                    // 学号
    char name[20];             // 姓名
    int class_num;             // 班级
    int age;                   // 年龄
    float math_score;            // 数学成绩
    float english_score;         // 英语成绩
    float clanguage_score;       // 计算机语言成绩
    struct List_student *next; // 指向下一个节点的指针
} List_student[100];

#endif // STRUCT_H