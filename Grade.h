#pragma once
#include"Student.h"

typedef class Grade01 :public Student//��һѧ���࣬�̳�ѧ����
{
public:
	void Show_Info();//��ʾ������Ϣ
	string Get_Grade();//��ȡ�꼶����
	Grade01(int id, string name, int grade, string sex, string m_class, int m_age);//���캯��
}Grade01, * PGrade01;

typedef class Grade02 :public Student//���ѧ���࣬�̳�ѧ����
{
public:
	void Show_Info();//��ʾ������Ϣ
	string Get_Grade();//��ȡ�꼶����
	Grade02(int id, string name, int grade, string sex, string m_class, int m_age);//���캯��
}Grade02, * PGrade02;

typedef class Grade03 :public Student//����ѧ���࣬�̳�ѧ����
{
public:
	void Show_Info();//��ʾ������Ϣ
	string Get_Grade();//��ȡ�꼶����
	Grade03(int id, string name, int grade, string sex, string m_class, int m_age);//���캯��
}Grade03, * PGrade03;

typedef class Grade04 :public Student//��һѧ���࣬�̳�ѧ����
{
public:
	void Show_Info();//��ʾ������Ϣ
	string Get_Grade();//��ȡ�꼶����
	Grade04(int id, string name, int grade, string sex, string m_class, int m_age);//���캯��
}Grade04, * PGrade04;