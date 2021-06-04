#include<iostream>
#include"StudentManage.h"
#include"Grade.h"
#include"Student.h"
using namespace std;

int main()
{
	system("color B1");//美化控制台

	StudentManager stu;
	int chioce;
	while (true)
	{
		//显示菜单
		stu.Show_Menu();
		cout << "请输入您的选择：";
		cin >> chioce;
		switch (chioce)
		{
		case 0:stu.Exit_System();//退出系统
			break;
		case 1:stu.Add_Student();//录入学生
			break;
		case 2:stu.ShowStudent();//显示学籍
			break;
		case 3:stu.DeleteStudent();//删除学生
			break;
		case 4:stu.ModStudent();//修改学生
			break;
		case 5:stu.FindStudent();//查找学生
			break;
		case 6:stu.SortStudent();//学生排序
			break;
		case 7:stu.ClassifyStudent();//分类显示
			break;
		case 8:stu.CleanStudent();//清空系统
			break;
		default://
			system("cls");
			break;
		}
		system("pause");

	}

	return 0;
}