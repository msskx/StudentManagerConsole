#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>//�����ļ�
#include"Student.h"
#define FILENAME "empFile.txt"//���ļ����궨�壬���ں���ά��
class StudentManager
{
public:
	//��¼����
	int Student_Num;
	//ѧ�������ָ��
	PSTU* Student_Array;//ָ������������Student* ������(Student*)* Student_Array;
	//���캯��
	StudentManager();
	//��ʾ�˵�
	void Show_Menu();
	//���ѧ��
	void Add_Student();
	//�˳�����
	void Save();
	//�����ļ�
	void Exit_System();
	//�ļ��Ƿ�Ϊ�յı�־
	bool FileIsEmpty;
	//ͳ������
	int get_StudentNum();
	//��ʼ��
	void InitStudent();
	//��ʾѧ��
	void ShowStudent();
	//ɾ��ѧ��
	void DeleteStudent();
	//�ж�ְ���Ƿ����,�����ڷ���λ�ã��������ڷ���-1
	int IsExist(int id);
	//����ѧ��
	void FindStudent();
	//�޸�ѧ��
	void ModStudent();
	//��ѧ������
	void SortStudent();
	//�������
	void CleanStudent();
	//���꼶������ʾ
	void ClassifyStudent();
	//��������
	~StudentManager();
};
