#include "adm.h"

void Menu();
void GetChoice();

int main()
{
    List list;
    //test
    list.AddData();
    list.AddData();
    //

    return 0;
}
void Menu()
{
    std::cout << "***************学生成绩管理系统***************\n";
    std::cout << "*输入选项对应字母（大小写均可）以执行相应操作。**\n";
    std::cout << "************(A).添加学生成绩信息。*************\n";
    std::cout << "************(B).查看学生信息。*****************\n";
    std::cout << "************(C).删除指定学生所有信息。**********\n";
    std::cout << "************(D).清除所有学生的全部信息.*********\n";
    std::cout << "************(E).查看学生成绩详细成绩。**********\n";
    std::cout << "************(F).退出程序***********************\n";
}

void GetChoice()
{

}