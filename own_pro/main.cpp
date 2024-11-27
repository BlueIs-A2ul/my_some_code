#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
struct account
{
    char time[100];   // 时间
    char money[100];  // 金额
    char cclass[100]; // 分类
};

vector<account> accounts;
void bubble_sort(vector<account> &accounts);
void read_file(string filename)
{ // 读取文件，将每行数据存入account结构体中，存入vector中
    ifstream file(filename);
    string line;
    int flag = 0;
    while (getline(file, line))
    {
        account acc;
        stringstream ss(line);
        ss >> acc.time >> acc.money >> acc.cclass;
        accounts.push_back(acc);
        flag = 1;
    }
    if (flag == 0)
    {
        cout << "File is empty" << endl;
    }
}

void sort_accounts_time()
{ // 按时间排序
    sort(accounts.begin(), accounts.end(), [](account a, account b)
         { return a.time < b.time; });
}

void sort_accounts_money()
{ // 按金额排序
    sort(accounts.begin(), accounts.end(), [](account a, account b)
         { return stof(a.money) < stof(b.money); });
}

void sort_sum_money_by_class()
{ // 按分类和金额排序
    int class_num = 0;
    cout << "Enter the number of classes: ";
    cin >> class_num;
    float sum = 0;
    for (int i = 0; i < accounts.size(); i++)
    {
        sum += stof(accounts[i].money);
    }
    cout << "The sum of money is " << sum << endl;
}

void print_accounts()
{
    printf("\ttime \t\tmoney \t\tclass\n");
    for (auto acc : accounts)
    {
        printf("\t%s \t\t%s \t\t%s\n", acc.time, acc.money, acc.cclass);
    }
}

void write_file(string filename)
{ // 写入文件，将vector中的数据写入文件
    ofstream file(filename);
    for (auto acc : accounts)
    {
        file << acc.time << " " << acc.money << " " << acc.cclass << endl;
    }
}

void add_account(account acc)
{ // 向vector中添加account结构体
    accounts.push_back(acc);
}

void sum_money(account acc)
{
    float sum = 0;
    for (int i = 0; i < accounts.size(); i++)
    {
        sum += stof(accounts[i].money);
    }
    std::cout << "The sum of money in  is " << sum << endl;
}
int main()
{
    string filename = "date.csv";
    read_file(filename);
    int choice;
    cout << "1. Read file" << endl;
    cout << "2. Sort accounts by time" << endl;
    cout << "3. Sort accounts by money" << endl;
    cout << "4. Sort accounts by class and money" << endl;
    cout << "5. Print accounts" << endl;
    cout << "6. Add account" << endl;
    cout << "7. Exit" << endl;
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
        {
            string filename = "date.csv";
            read_file(filename);
            break;
        }
        case 2:
            bubble_sort(accounts);
            print_accounts();
            break;
        case 3:
            sort_accounts_money();
            print_accounts();
            break;
        case 4:
            sort_sum_money_by_class();
            print_accounts();
            break;
        case 5:
            print_accounts();
            sum_money(accounts[0]);
            break;
        case 6:
        {
            int num;
            cout << "Enter the number of accounts to add: ";
            cin >> num;
            for (int i = 0; i < num; i++)
            {
                account acc;
                cout << "Enter time: ";
                cin >> acc.time;
                cout << "Enter money: ";
                cin >> acc.money;
                cout << "Enter cclass: ";
                cin >> acc.cclass;
                add_account(acc);
            }
            write_file("date.csv");
            break;
        }
        case 7:
            return 0;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << "1. Read file" << endl;
        cout << "2. Sort accounts by time" << endl;
        cout << "3. Sort accounts by money" << endl;
        cout << "4. Sort accounts by class and money" << endl;
        cout << "5. Print accounts" << endl;
        cout << "6. Add account" << endl;
        cout << "7. Exit" << endl;
        cin >> choice;
    }

    return 0;
}

void bubble_sort(vector<account> &accounts)
{ // 冒泡排序
    int n = accounts.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (accounts[j].time > accounts[j + 1].time)
            {
                swap(accounts[j], accounts[j + 1]);
            }
        }
    }
}