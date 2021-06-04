#pragma once
#include"Student.h"

typedef class Grade01 :public Student//大一学生类，继承学生类
{
public:
	void Show_Info();//显示个人信息
	string Get_Grade();//获取年级名称
	Grade01(int id, string name, int grade, string sex, string m_class, int m_age);//构造函数
}Grade01, * PGrade01;

typedef class Grade02 :public Student//大二学生类，继承学生类
{
public:
	void Show_Info();//显示个人信息
	string Get_Grade();//获取年级名称
	Grade02(int id, string name, int grade, string sex, string m_class, int m_age);//构造函数
}Grade02, * PGrade02;

typedef class Grade03 :public Student//大三学生类，继承学生类
{
public:
	void Show_Info();//显示个人信息
	string Get_Grade();//获取年级名称
	Grade03(int id, string name, int grade, string sex, string m_class, int m_age);//构造函数
}Grade03, * PGrade03;

typedef class Grade04 :public Student//大一学生类，继承学生类
{
public:
	void Show_Info();//显示个人信息
	string Get_Grade();//获取年级名称
	Grade04(int id, string name, int grade, string sex, string m_class, int m_age);//构造函数
}Grade04, * PGrade04;