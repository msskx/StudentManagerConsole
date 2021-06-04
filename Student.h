#pragma once
#include<iostream>
using namespace std;
#include<string>
class Student;
typedef class Student
{
public:
	virtual void Show_Info()=0;//显示个人信息
	virtual string Get_Grade()=0;//获取年级名称
	int m_id;//学号
	string m_name;//姓名
	string m_sex;//性别
	int  m_grade;//所在年级编号
	string m_class;//班级
	int m_age;//年龄
	
}STU, * PSTU;
