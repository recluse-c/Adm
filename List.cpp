#include"adm.h"
#ifndef _TEST_
#define _TEST_
Node * List::pmove = nullptr;
int List::m_size = 0;
#endif
int List::GetSize()
{

    return m_size;
}
Node * List::GetPmove()
{
    return pmove;
}

int ModifyIndex()
{
    Node *tmp = List::pmove;
    int ct = 1;
    while(tmp)
    {
        tmp->m_index = ct;
        tmp = tmp->GetPrevious();
        ++ct;
    }
}

void List::AddData()
{
    std::cout << "请输入学生姓名：\n";
    std::string name;
    std::cin >> name;

    std::cout << "请输入学生学号：\n";
    std::string ID;
    std::cin >> ID;

    std::cout << "请输入语文、数学、英语、物理、化学、生物的分数(以空格分隔):\n";
    double score[NUM];
    std::cin >> score[0] >> score[1] >> score[2] >> score[3] >> score[4] >> score[5];
    //test
    
    for (int i = 0; i < NUM; ++i)
    {
        std::cout << score[i] << std::endl;
        
    }//
    Node(name, ID, score);
}
void List::DeleteScore()
{
    std::cout << "请输入你要删除的学生的编号:\n";
    int findex;
    std::cin >> findex;
    if(m_size == 1)
    {
        delete pmove;
        m_size--;
        pmove = nullptr;
    }else{
        Node *tmp;
        tmp = pmove;
        while(true)
        {
            if(tmp->GetIndex() == findex) //find focus
            {   
                if(tmp->GetPrevious()) //previous exist
                {
                    if(tmp->GetLatter())//latter exist
                    {
                        tmp->GetPrevious()->latter = tmp->GetLatter();
                        tmp->GetLatter()->previous = tmp->GetPrevious();
                        delete tmp;
                        m_size--;
                        ModifyIndex();
                        break;
                    }else{//latter not
                        tmp->GetPrevious()->latter = nullptr;
                        pmove = tmp->GetPrevious();
                        delete tmp;
                        m_size--;
                        ModifyIndex();
                        break;
                    }              
                }else{//previous not
                    if(tmp->GetLatter())//latter exist
                    {
                        tmp->GetLatter()->previous = nullptr;
                        delete tmp;
                        m_size--;
                        ModifyIndex();
                        break;
                    }
                    
                }
                    
            }           
            tmp = tmp->GetPrevious();
        }
       
    }
}
void List::EndAll()
{
    Node *tmp;
    while(true)
    {
        if(!tmp || !pmove)
            break;
        tmp = pmove->GetPrevious();
        delete pmove;
        pmove = tmp->GetPrevious();
        delete tmp;

    }
    std::cout << "内容为空。\n";
}

void List::ShowAll()
{
    Node *tmp = pmove;
    while(tmp)
    {
        std::cout << tmp->GetIndex() << ". " << tmp->GetName() << " "<< tmp->GetID() << std::endl;
        tmp = tmp->GetPrevious();
    }
 
}

void List::ShowScore()
{
    std::cout << "请输入你要查看的学生成绩对应编号：\n";
    int findex = 0;
    std::cin >> findex;
    Node *tmp = pmove;
    while(tmp)
    {
        if(tmp->GetIndex() == findex)
        {
            std::cout << tmp->GetIndex() << ". " << tmp->GetName() << ":\n";
            double *tscore = tmp->GetScore();
            for (int i = 0; i < NUM; ++i)
            {
                std::cout << tscore[i] << " ";
            }
            std::cout << std::endl;
        }
        tmp = tmp->GetPrevious();
    }
   
}