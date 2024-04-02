#ifndef _NO
#define _NO
#include<iostream>
#include<string>
#define NUM 6

class Node  //存储学生信息
{
private:
    std::string m_name;
    std::string m_ID;
    double m_grade[NUM];
    int m_index;
public:
    Node* previous;
    Node* latter;

public:
    Node();
    Node(std::string name, std::string ID, double score[NUM]);
   // ~Node();
    std::string GetName();
    std::string GetID();
    double* GetScore();
    int GetIndex();
    Node *GetPrevious();
    Node *GetLatter();
    friend int ModifyIndex();
};

class List
{
private:
    static int m_size;
    static Node* pmove;  //记录最新的节点
public:
    int GetSize();
    Node *GetPmove();
    void AddData();
    void DeleteScore();
    void EndAll();
    void ShowAll();
    void ShowScore();
    friend Node::Node(std::string name, std::string ID, double score[NUM]);
    friend int ModifyIndex();
};

#endif