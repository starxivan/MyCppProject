#include<iostream>
#include<limits>
#include "function.hpp"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    double currentBalance {0.0};
    int choice {-1};
    constexpr int MAX_RECORDS {20};
    Record records[MAX_RECORDS];
    int num{0};
    while(choice!=0)
    {
        showMenu();
        cout<<"请选择操作：";
        if(!(cin>>choice))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"输入字符有误！请输入数字字符!"<<endl;
            continue;
        }
        switch (choice)
        {
            case 1:
            if(num==MAX_RECORDS)
            {
                cout<<"记录数量已经满额！"<<endl;
                break;
            }
            if(addIncome(currentBalance,records,num))
            num++;
            break;

            case 2:
            if(num==MAX_RECORDS)
            {
                cout<<"记录数量已经满额!"<<endl;
                break;
            }
            if(addExpense(currentBalance,records,num))
            num++;
            break;

            case 3:
            checkBalance(currentBalance);
            break;

            case 4:
            printHistory(records,num);
            break;
            
            default:
            break;
        }
        cout<<endl;
    }
    return 0;
}
