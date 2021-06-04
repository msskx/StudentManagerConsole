#include"Grade.h"//包含年级学生的头文件
//大一年级学生的实现
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
		<< "年级：" << this->Get_Grade() << " "
		<< "性别：" << this->m_sex << " "
		<< "班级：" << this->m_class << " "
		<< "年龄：" << this->m_age << endl;
}
string  Grade01::Get_Grade()//获取年级名称
{
	return (string)"大一";
}
//大二年级学生的实现
Grade02::Grade02(int id, string name, int grade, string sex, string m_class, int m_age)
{
	this->m_id = id;//学号
	this->m_name = name;//姓名
	this->m_grade = grade;//年级
	this->m_class = m_class;//班级
	this->m_sex = sex;//性别
	this->m_age = m_age;//年龄

}//实现大二年级类的构造函数,利用拷贝构造函数赋值
void Grade02::Show_Info()//显示个人信息
{
	cout << "学号：" << this->m_id << " "
		<< "姓名：" << this->m_name << " "
		<< "年级：" << this->Get_Grade() << " "
		<< "性别：" << this->m_sex << " "
		<< "班级：" << this->m_class << " "
		<< "年龄：" << this->m_age << endl;
}
string  Grade02::Get_Grade()//获取年级名称
{
	return (string)"大二";
}
//大三年级学生的实现
Grade03::Grade03(int id, string name, int grade, string sex, string m_class, int m_age)
{
	this->m_id = id;//学号
	this->m_name = name;//姓名
	this->m_grade = grade;//年级
	this->m_class = m_class;//班级
	this->m_sex = sex;//性别
	this->m_age = m_age;//年龄

}//实现大三年级类的构造函数,利用拷贝构造函数赋值
void Grade03::Show_Info()//显示个人信息
{
	cout << "学号：" << this->m_id << " "
		<< "姓名：" << this->m_name << " "
		<< "年级：" << this->Get_Grade() << " "
		<< "性别：" << this->m_sex << " "
		<< "班级：" << this->m_class << " "
		<< "年龄：" << this->m_age << endl;
}
string  Grade03::Get_Grade()//获取年级名称
{
	return (string)"大三";
}
//大四年级学生的实现
Grade04::Grade04(int id, string name, int grade, string sex, string m_class, int m_age)
{
	this->m_id = id;//学号
	this->m_name = name;//姓名
	this->m_grade = grade;//年级
	this->m_class = m_class;//班级
	this->m_sex = sex;//性别
	this->m_age = m_age;//年龄

}//实现大四年级类的构造函数,利用拷贝构造函数赋值
void Grade04::Show_Info()//显示个人信息
{
	cout << "学号：" << this->m_id << " "
		<< "姓名：" << this->m_name << " "
		<< "年级：" << this->Get_Grade() << " "
		<< "性别：" << this->m_sex << " "
		<< "班级：" << this->m_class << " "
		<< "年龄：" << this->m_age << endl;
}
string  Grade04::Get_Grade()//获取年级名称
{
	return (string)"大四";
}



