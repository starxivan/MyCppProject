#pragma once
#include<string>
void showMenu();
//显示主菜单
struct Record
{
    double amount {0.0};
    std::string type {""};//交易类型收入或支出
    std::string category {""};//分类标签，工资，交通
    std::string note{""};//备注说明
};
bool addIncome(double& balance,Record records[],int currentnum);
//处理收入
bool addExpense(double& balance,Record records[],int currentnum);
//处理支出
void checkBalance(const double& balance);
//查询余额，仅要读取，不修改


void printHistory(const Record records[],int currentnum);
//查看历史明细