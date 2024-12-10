#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string.h>
using namespace std;
struct account
{
    char time[100];   // 时间
    char money[100];  // 金额
    char cclass[100]; // 分类
    // cclass主要是这几个：
    // 1.food：食品
    // 2.clothing：衣服
    // 3.trans：交通
    // 4.entertainment：娱乐
    // 5.shopping：购物
    // 6.naicha；奶茶
    // 7.wash：洗衣
    // 8.idol：偶像
    // 9.vip：会员
    // 10.other：其他
};

vector<account> accounts;

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
         { return stof(a.time) < stof(b.time); });
}

void sort_accounts_money()
{ // 按金额排序
    sort(accounts.begin(), accounts.end(), [](account a, account b)
         { return stof(a.money) < stof(b.money); });
}

void sort_sum_money_by_class()
{ // 按分类和金额排序
    char cclass[100];
    cout << "请输入分类: ";

    cin >> cclass;
    float sum = 0;
    for (int i = 0; i < accounts.size(); i++)
    {
        if (strcmp(accounts[i].cclass, cclass) == 0)
        {
            sum += stof(accounts[i].money);
        }
    }
    cout << "对应总金额为: " << sum << endl;
}

void print_accounts()
{
    printf("\t时间 \t\t金额 \t\t类\n");
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

void delete_account(account acc)
{ // 从vector中删除account结构体
}
void sum_money(account acc)
{
    float sum = 0;
    for (int i = 0; i < accounts.size(); i++)
    {
        sum += stof(accounts[i].money);
    }
    cout << "\t";
    std::cout << "金额总数是 " << sum << endl;
}
int main()
{
    string filename = "date.csv";
    read_file(filename);
    int choice;
    std::cout << std::left;
    std::cout << std::setw(3) << " "
              << std::setw(20) << "功能选项"
              << std::setw(30) << "描述" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << std::setw(3) << "2."
              << std::setw(17) << "\t按时间前后排序"
              << std::setw(30) << "" << std::endl;
    std::cout << std::setw(3) << "3."
              << std::setw(17) << "\t按金额大小排序"
              << std::setw(30) << "" << std::endl;
    std::cout << std::setw(3) << "4."
              << std::setw(17) << "\t查询某一类总和"
              << std::setw(30) << "" << std::endl;
    std::cout << std::setw(3) << "5."
              << std::setw(17) << "\t打印账户信息"
              << std::setw(30) << "" << std::endl;
    std::cout << std::setw(3) << "6."
              << std::setw(17) << "\t添加消费记录"
              << std::setw(30) << "" << std::endl;
    std::cout << std::setw(3) << "7."
              << std::setw(17) << "\t退出系统"
              << std::setw(30) << "" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "请输入功能选项: ";
    cin >> choice;
    while (choice != 199)
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
            sort_accounts_time();
            print_accounts();
            break;
        case 3:
            sort_accounts_money();
            print_accounts();
            break;
        case 4:
            sort_sum_money_by_class();
            break;
        case 5:
            print_accounts();
            sum_money(accounts[0]);
            break;
        case 6:
        {
            int num;
            cout << "请输入要添加的记录数量: ";
            cin >> num;
            for (int i = 0; i < num; i++)
            {
                account acc;
                cout << "输入时间：";
                cin >> acc.time;
                cout << "输入金额：";
                cin >> acc.money;
                cout << "输入分类：";
                cin >> acc.cclass;
                add_account(acc);
                cout << endl;
            }
            // 循环完成再写入文件
            write_file("date.csv");
            break;
        }
        case 7:
            return 0;
            break;
        default:
            cout << "无效的选项" << endl;
            break;
        }
        std::cout << std::left;
        std::cout << std::setw(3) << " "
                  << std::setw(20) << "功能选项"
                  << std::setw(30) << "描述" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << std::setw(3) << "2."
                  << std::setw(17) << "\t按时间前后排序"
                  << std::setw(30) << "" << std::endl;
        std::cout << std::setw(3) << "3."
                  << std::setw(17) << "\t按金额大小排序"
                  << std::setw(30) << "" << std::endl;
        std::cout << std::setw(3) << "4."
                  << std::setw(17) << "\t查询某一类总和"
                  << std::setw(30) << "" << std::endl;
        std::cout << std::setw(3) << "5."
                  << std::setw(17) << "\t打印账户信息"
                  << std::setw(30) << "" << std::endl;
        std::cout << std::setw(3) << "6."
                  << std::setw(17) << "\t添加消费记录"
                  << std::setw(30) << "" << std::endl;
        std::cout << std::setw(3) << "7."
                  << std::setw(17) << "\t退出系统"
                  << std::setw(30) << "" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "请输入功能选项: ";
        cin >> choice;
    }

    return 0;
}
