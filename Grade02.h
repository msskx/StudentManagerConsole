#pragma once
#include"Student.h"

typedef class Grade02 :public Student//���ѧ���࣬�̳�ѧ����
{
public:
	void Show_Info();//��ʾ������Ϣ
	string Get_Grade();//��ȡ�꼶����
	Grade02(int id, string name, int grade, string sex, string m_class, int m_age);//���캯��
}Grade02, * PGrade02;
