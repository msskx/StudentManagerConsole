#pragma once
#include"Student.h"

typedef class Grade03 :public Student//����ѧ���࣬�̳�ѧ����
{
public:
	void Show_Info();//��ʾ������Ϣ
	string Get_Grade();//��ȡ�꼶����
	Grade03(int id, string name, int grade, string sex, string m_class, int m_age);//���캯��
}Grade03, * PGrade03;
