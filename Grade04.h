#pragma once
#include"Student.h"

typedef class Grade04 :public Student//��һѧ���࣬�̳�ѧ����
{
public:
	void Show_Info();//��ʾ������Ϣ
	string Get_Grade();//��ȡ�꼶����
	Grade04(int id, string name, int grade, string sex, string m_class, int m_age);//���캯��
}Grade04, * PGrade04;
