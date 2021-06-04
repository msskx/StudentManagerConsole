//大一年级学生的实现
#include"Grade01.h"//包含大一年级学生的头文件

Grade01::Grade01(int id, string name, int grade, string sex, string m_class, int m_age)
{
	this->m_id = id;//学号
	this->m_name = name;//姓名
	this->m_grade = grade;//年级
	this->m_class = m_class;//班级
	this->m_sex = sex;//性别
	this->m_age = m_age;//年龄

}//实现大一年级类的构造函数,利用拷贝构造函数赋值
void Grade01::Show_Info()//显示个人信息
{
	cout << "学号：" << this->m_id << " "
		<< "姓名：" << this->m_name << " "
		<< "年级：" << this->Get_Grade() <<" "
		<<"性别："<<this->m_sex<<" "
		<<"班级："<<this->m_class<<" "
		<<"年龄："<<this->m_age<< endl;
}
string  Grade01::Get_Grade()//获取年级名称
{
	return (string)"大一";
}


