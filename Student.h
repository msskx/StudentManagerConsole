#pragma once
#include<iostream>
using namespace std;
#include<string>
class Student;
typedef class Student
{
public:
	virtual void Show_Info()=0;//��ʾ������Ϣ
	virtual string Get_Grade()=0;//��ȡ�꼶����
	int m_id;//ѧ��
	string m_name;//����
	string m_sex;//�Ա�
	int  m_grade;//�����꼶���
	string m_class;//�༶
	int m_age;//����
	
}STU, * PSTU;
