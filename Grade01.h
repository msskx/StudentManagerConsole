#pragma once
#include"Student.h"

typedef class Grade01 :public Student//大一学生类，继承学生类
{
public:
	void Show_Info();//显示个人信息
	string Get_Grade();//获取年级名称
	Grade01(int id, string name, int grade,string sex,string m_class,int m_age);//构造函数
}Grade01,*PGrade01;
