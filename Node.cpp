#include"adm.h"
Node::Node()
{
    ;
}
Node::Node(std::string name, std::string ID, double score[NUM])
{
    Node *tmp = new Node();
    //
    tmp->m_name = name;
    tmp->m_ID = ID;
    for (int i = 0; i < NUM; ++i)
    {
        tmp->m_grade[i] = score[i];
    }
    //
    tmp->m_index = List::m_size + 1;
    ++List::m_size;
    tmp->previous = List::pmove;
    tmp->latter = nullptr;
    if(List::pmove)
        List::pmove->latter = tmp;
    List::pmove = tmp;
}

std::string Node::GetName()
{
    return this->m_name;
}
std::string Node::GetID()
{
    return this->m_ID;
}
double* Node::GetScore()
{
    return this->m_grade;
}
int Node::GetIndex()
{
    return m_index;
}


Node* Node::GetPrevious()
{
    return previous;
}
Node* Node::GetLatter()
{
    return latter;
}