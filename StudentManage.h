#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>//操作文件
#include"Student.h"
#define FILENAME "empFile.txt"//给文件名宏定义，便于后期维护
class StudentManager
{
public:
	//记录人数
	int Student_Num;
	//学生数组的指针
	PSTU* Student_Array;//指针数组用来存Student* 的数组(Student*)* Student_Array;
	//构造函数
	StudentManager();
	//显示菜单
	void Show_Menu();
	//添加学生
	void Add_Student();
	//退出程序
	void Save();
	//保存文件
	void Exit_System();
	//文件是否为空的标志
	bool FileIsEmpty;
	//统计人数
	int get_StudentNum();
	//初始化
	void InitStudent();
	//显示学生
	void ShowStudent();
	//删除学生
	void DeleteStudent();
	//判断职工是否存在,若存在返回位置，若不存在返回-1
	int IsExist(int id);
	//查找学生
	void FindStudent();
	//修改学生
	void ModStudent();
	//按学号排序
	void SortStudent();
	//清空数据
	void CleanStudent();
	//按年级分类显示
	void ClassifyStudent();
	//析构函数
	~StudentManager();
};
