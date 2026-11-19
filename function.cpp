#include<iostream>
#include "function.hpp"
#include<limits>
using std::cin;
using std::cout;
using std::endl;

void showMenu()
{
    cout<<"===个人智能记账系统v0.1==="<<endl;
    cout<<"1.记录收入 2.记录支出 3.查询余额 4.查看历史明细 0.退出"<<endl;
}
bool addIncome(double& balance,Record records[],int currentnum)
{
    double amount {0.0};
    cout<<"请输入收入金额：";
    if(!(cin>>amount))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout<<"输入字符有误！请输入数字！"<<endl;
        return 0;
    }
    if(amount<=0)
    {
        cout<<"[失败]输入的收入应该为正数!"<<endl;
        return false;
    }
    records[currentnum].amount=amount;
    records[currentnum].type="收入";
    cout<<"请输入分类标签（如：工资/奖金）:";
    cin>>records[currentnum].category;
    cout<<"请输入备注：";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(cin,records[currentnum].note);
    
    cout<<"[成功]已入账"<<amount<<"元！"<<endl;
    balance+=amount;
    return true;
    
}
bool addExpense(double& balance,Record records[],int currentnum)
{
    double amount {0.0};
    cout<<"请输入支出金额:";
    if(!(cin>>amount))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout<<"输入字符有误！请输入数字！"<<endl;
        return false;
    }
    if(amount<=0)
    {
        cout<<"[失败]输入支出应为正数！"<<endl;
        return false;
    }else if(amount>balance)
    {
        cout<<"[警告]余额不足！当前可用余额仅为"<<balance<<"元！"<<endl;
        return false;
    }
    records[currentnum].amount=amount;
    records[currentnum].type="支出";
    cout<<"请输入分类标签（如：餐饮/交通):";
    cin>>records[currentnum].category;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout<<"请输入备注：";
    std::getline(cin,records[currentnum].note);

    cout<<"[成功]已支出"<<amount<<"元！"<<endl;
    balance-=amount;
    return true;

}
void checkBalance(const double& balance)
{
    cout<<"[账户状态]当前总余额为："<<balance<<"元"<<endl;
}
void printHistory(const Record records[],int currentnum)
{   
    int i{0};
    if(currentnum==0)
    {
        cout<<"[提示] 当前暂无任何记账记录！"<<endl;
        return;
    }
    cout<<"===历史记账明细（共"<<currentnum<<"笔"<<")==="<<endl;
    for(i=0;i<currentnum;++i)
    {
        cout<<i+1<<".["<<records[i].type<<" | "<<records[i].category<<"] 金额："
        <<records[i].amount
        <<"元 | 备注："
        <<records[i].note
        <<endl;
    }
}