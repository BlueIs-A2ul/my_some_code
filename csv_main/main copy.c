#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manu_detail copy.c" //具体的函数实现
#include "struct.h"      //结构体的定义实现

#define MAX_LINE_LENGTH 1024
#define BUFFER_SIZE 1024
#define MAX_STUDENTS 100

int main()
{
    FILE *file = fopen("data.csv", "r+");
    // fprintf(file, "id,name,class,age,math,english,clanguage\n");

    if (file == NULL)
    {   
        perror("打开文件失败");
        printf("请尝试创建一个有效文件data.csv");
        return EXIT_FAILURE;
    }
    struct List_student *head = NULL;
    create_List_student(file, &head);
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

    int choice;
    while (scanf("%d", &choice) == 1)
    {
        switch (choice)
        {
        case 10:
            printf("退出系统\n");
            fclose(file);
            return EXIT_SUCCESS;
        default:
            printf("无效的选择\n");
            break;
        case 1:
            manu_detail();
            break;
        case 2:
            fclose(file);
            file = fopen("data.csv", "a");
            add_student(file);
            fclose(file);
            file = fopen("data.csv", "r+");
            break;
        case 3:
            search_student(file, head);
            break;
        case 4:
            fclose(file);
            file = fopen("data.csv", "w");
            delete_student(file,&head);
            break;
        case 5:
            modify_student(file, &head);
            break;
        case 6:
            read_file(file, head);
            break;
        case 7:
            sort_by_name(file, &head);
            break;
        case 8:
            sort_by_id(file, &head);
            break;
        case 9:
            sort_by_subject(file, &head);
            break;
        }
    }
    fclose(file);
    return 0;
}
