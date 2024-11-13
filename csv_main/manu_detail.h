// manu_detail.h
#ifndef MANU_DETAIL_H
#define MANU_DETAIL_H
#include "struct.h"
void manu_detail();

void add_student(FILE *file);

void search_student(FILE *file, struct List_student *head);

void delete_student(FILE *file, struct List_student **head);

void modify_student(FILE *file, struct List_student **head);

void read_file(FILE *file,struct List_student *head);

void sort_by_name(FILE *file, struct List_student **head);

void sort_by_id(FILE *file, struct List_student **head);

void sort_by_subject(FILE *file, struct List_student **head);

void create_List_student(FILE *file, struct List_student **head);

void save_List_student(FILE *file, struct List_student *head);
#endif // MANU_DETAIL_H
