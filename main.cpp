#include<iostream>
#include"StudentManage.h"
#include"Grade.h"
#include"Student.h"
using namespace std;

int main()
{
	system("color B1");//��������̨

	StudentManager stu;
	int chioce;
	while (true)
	{
		//��ʾ�˵�
		stu.Show_Menu();
		cout << "����������ѡ��";
		cin >> chioce;
		switch (chioce)
		{
		case 0:stu.Exit_System();//�˳�ϵͳ
			break;
		case 1:stu.Add_Student();//¼��ѧ��
			break;
		case 2:stu.ShowStudent();//��ʾѧ��
			break;
		case 3:stu.DeleteStudent();//ɾ��ѧ��
			break;
		case 4:stu.ModStudent();//�޸�ѧ��
			break;
		case 5:stu.FindStudent();//����ѧ��
			break;
		case 6:stu.SortStudent();//ѧ������
			break;
		case 7:stu.ClassifyStudent();//������ʾ
			break;
		case 8:stu.CleanStudent();//���ϵͳ
			break;
		default://
			system("cls");
			break;
		}
		system("pause");

	}

	return 0;
}