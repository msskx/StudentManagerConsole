# StudentManagerConsole
大一课程设计项目，控制台实现简易学生学籍管理系统

# 操作流程

## 创建文件

## 创建管理类

	管理类负责的内容如下：

* 提供与用户的沟通菜单界面

* 实现对职工增删改查的操作

* 数组数据与文件的读写交互

### 菜单功能实现

在StudentManager.h中定义ShowMenu()函数在StudentManager.cpp中实现显示菜单功能，便于与用户交互，利用序号将所有功能显示出来，便于用户选择以及，进行后期的使用。

代码如下

```cpp
void StudentManager::Show_Menu()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~学生学籍管理系统~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "******************（0）退出系统*****************" << endl;
	cout << "******************（1）录入学生*****************" << endl;
	cout << "******************（2）显示学籍*****************" << endl;
	cout << "******************（3）删除学生*****************" << endl;
	cout << "******************（4）修改学生*****************" << endl;
	cout << "******************（5）查找学生*****************" << endl;
	cout << "******************（6）学生排序*****************" << endl;
	cout << "******************（7）分类显示*****************" << endl;
	cout << "******************（8）清空系统*****************" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
```

### 退出功能

#### 为各种功能提供接口

在main函数中为管理操作的函数提供接口,创建实例对象，调用对象内成员函数

实现代码

```cpp
int main()
{

	StudentManager stu;
	int chioce;
	while (true)
	{
        system("color B1");//美化控制台
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
```

#### 退出功能实现

在StudentManager.h中定义Exit_System()；函数

在StudentManager.cpp中实现函数功能，利用exit(0);实现程序的退出操作

代码实现如下：

```cpp
void StudentManager::Exit_System()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
```

## 创建学生类

### 创建大一类

先创建学生类作为父类，然后定义各种成员属性

大一类继承学生抽象类，并重写父类中的重虚函数

创建头文件Grade01.h和源文件Grade.cpp

代码实现如下

Grade01.h

```cpp
#pragma once
#include"Student.h"

class Grade01:public Student
{
public:
	
	Grade01(int id, string name, int grade);
	void Show_Info();//显示个人信息
	string Get_Grade();//获取年级名称
};
```

Grade01.cpp


```cpp
#include"Grade01.h"

Grade01::Grade01(int id,string name,int grade)
{
	this->m_id = id;
	this->m_name = name;
	this->m_grade = grade;
}
void Grade01::Show_Info()//显示个人信息
{
	cout << "学号：" << this->m_id << " "
		<< "姓名：" << this->m_name << " "
		<< "年级：" << this->Get_Grade() << endl;
}
string  Grade01::Get_Grade()//获取年级名称
{
	return (string)"大一";
}



```

### 创建大二类

与大一类上述代码相同不再赘述

### 创建大三类

与大一类上述代码相同不再赘述

### 创建大四类

与大一类上述代码相同不再赘述

## 添加学生

在StudentManager.h中添加属性以及成员函数

根据学生的人数加上添加后的人数，开辟一块新的空间记录数据

系统整体利用指针数组实现数据的临时保存，最终与文件的操作配合使用，使数据转存到文件中

```cpp
	//记录人数
	int Student_Num;
	//学生数组的指针
	Student** Student_Array;//指针数组用来存Student* 的数组(Student*)* Student_Array;

```

在StudentManager.cpp中构造函数中初始化

```cpp
	//初始化人数
	this->Student_Num = 0;
	//初始化数组指针
	this->Student_Array = NULL;
```

在StudentManager.cpp中实现成员函数

```cpp
void StudentManager::Add_Student()
{
	cout << "请输入添加学生数量" << endl;
	int addnum;
	cin >> addnum;
	if (addnum > 0)
	{
		//计算新空间大小
		int newsize = this->Student_Num + addnum;
		//开辟空间
		Student** newspace = new Student * [newsize];
		//将源空间的内容存放到新空间下
		if (this->Student_Array != NULL)
		{
			for (int i = 0; i < this->Student_Num; i++)
			{
				newspace[i] = this->Student_Array[i];
			}
		}
		//输入新数据
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int select;
			cout << "请输入第" << i + 1 << "个学生学号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个学生姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个学生年级编号" << endl;
			cout << "1、大一" << endl;
			cout << "2、大二" << endl;
			cout << "3、大三" << endl;
			cout << "4、大四" << endl;
			cin >> select;
			Student* student = NULL;
			switch (select)
			{
			case 1://大一
				student = new Grade01(id, name, 1);
				break;
			case 2://大2
				student = new Grade02(id, name, 1);
				break;
			case 3://大3
				student = new Grade03(id, name, 1);
				break;
			case 4://大4
				student = new Grade04(id, name, 1);
				break;
			default:
				break;
			}

			newspace[this->Student_Num + i] = student;
		}
		//释放原有空间
		delete[]this->Student_Array;
		//更新空间指向
		this->Student_Array = newspace;
		//更新学生个数
		this->Student_Num = newsize;
		//提示
		cout << "添加成功" << addnum << "个学生" << endl;
        
	}
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
```

## 保存文件	

```cpp
void StudentManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//以写文件的方式打开文件
	for (int i = 0; i < this->Student_Num; i++)
	{
		ofs << this->Student_Array[i]->m_id << " "
			<< this->Student_Array[i]->m_name << " "
			<< this->Student_Array[i]->m_grade << " " << endl;
	}
	ofs.close();
}
```

## 初始化学生

在初始化学生之前，要判断学生文件状态，分为三种情况

<u>1、第一次使用文件未创建</u>

<u>2、文件存在，但是为空文件</u>

<u>3、文件和数据正常存在</u>

首先在StudentManager.h中添加标志文件是否为空的标志

若为空文件，或者文件不存在，则该bool类型的值返回true

```cpp
bool FileIsEmpty;
```

修改StudentManager.cpp中的构造函数代码

```cpp
StudentManager::StudentManager()
{
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->Student_Num = 0;//初始化人数为零
		this->FileIsEmpty = true;//标志文件为空
		this->Student_Array = NULL;//初始化数组为空
		ifs.close();//关闭文件
		return;
	}
	//文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->Student_Num = 0;
		this->FileIsEmpty = true;
		this->Student_Array = NULL;
		ifs.close();
		return;
	}
	int num = this->get_StudentNum();
	cout << "职工个数为：" << num << endl;
	this->Student_Num = num;
	//根据职工数创建数组
	this->Student_Array = new Student * [this->Student_Num];
	this->InitStudent();
}
```

如果文件不存在，则初始化文件

文件在不存在，或者为空的情况下，判断文件是否为空的标志都为真

成功添加学生信息后更改文件不为空

**初始化文件**

初始化Student* 类型的指针数组，将**Student***类型的地址存到**Student****中

在StudentManager.cpp中实现

```cpp
void StudentManager::InitStudent()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int Grade;
	int index=0;
	while (ifs >> id && ifs >> name && ifs >> Grade)
	{
		Student* student = NULL;//根据年级创建student*的对象
		if (id == 1)
		{
			student = new Grade01(id, name, Grade);
		}else if(id==2)
		{
			student = new Grade02(id, name, Grade);
		}
		else if (id == 3)
		{
			student = new Grade03(id, name, Grade);
		}
		else
		{
			student = new Grade04(id, name, Grade);
		}
		//存放在数组中
		this->Student_Array[index] = student;
		index++;
		
	}
}
```

## 显示学生

```cpp
void StudentManager::ShowStudent()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空或者不存在" << endl;
	}
	else
	{
		for (int i = 0; i < this->Student_Num; i++)
		{
			//利用多态调用接口
			this->Student_Array[i]->Show_Info();
		}
	}
	system("pause");
	system("cls");
}
```

## 删除学生

删除学生之前判断其是否存在

如果为空或者不存在，返回-1，如果存在，返回其下标

在StudentManager.cpp中实现

根据成员属性匹配的到数组的下标，便于后续索引类型的操作进行

```cpp
int StudentManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->Student_Num; i++)
	{
		if (this->Student_Array[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
```

**删除，实现按照学号删除**

```cpp
void StudentManager::DeleteStudent()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入要删除的学生学号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->Student_Num - 1; i++)
			{
				this->Student_Array[i] = this->Student_Array[i + 1];
			}
			this->Student_Num--;
			this->Save();//删除后同步数据到文件
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
```

## 查找学生

按照学生编号，按照学生姓名

```cpp
void StudentManager::FindStudent()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按学号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)//按照学号查找
		{
			int id;
			cout << "请输入查找的学号" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，该学生信息如下" << endl;
				this->Student_Array[ret]->Show_Info();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)//按姓名查找
		{
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;
			bool flag = false;//查找到的标志
			for (int i = 0; i < this->Student_Num; i++)
			{
				if (this->Student_Array[i]->m_name == name)
				{
					cout << "查找成功，信息如下" << endl;
					flag = true;
					this->Student_Array[i]->Show_Info();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人！！" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}
```

## 修改学生信息

按照编号对职工信息保存修改

利用IsExist函数获取学生数组元素下标，然后对应进行修改，记录保存

```cpp
void StudentManager::ModStudent()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在，或记录为空" << endl;
	}
	else
	{
		cout << "请输入要修改的学生学号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->Student_Array[ret];
			int newid = 0;
			string newname = "";
			int select = 0;
			cout << "查到" << id << "号学生，请输入新学号" << endl;
			cin >> newid;
			cout << "请输入新姓名" << endl;
			cin >> newname;
			cout << "请输入年级" << endl;
			cout << "1、大一" << endl;
			cout << "2、大二" << endl;
			cout << "3、大三" << endl;
			cout << "4、大四" << endl;
			cin >> select;
			Student* student = NULL;
			switch (select)
			{
			case 1://大一
				student = new Grade01(newid, newname, 1);
				break;
			case 2://大2
				student = new Grade02(newid, newname, 2);
				break;
			case 3://大3
				student = new Grade03(newid, newname, 3);
				break;
			case 4://大4
				student = new Grade04(newid, newname, 4);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->Student_Array[ret] =student;
			cout << "修改成功" << endl;
			//保存文件
			this->Save();

		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
		system("pause");
		system("cls");
	}
}
```

## 按学号排序

排序采用冒泡排序，前后两两比较，根据排序要求进行交换元素位置，达到排序目的

```cpp
void StudentManager::SortStudent()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");

	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按学号进行升序" << endl;
		cout << "2、按学号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->Student_Num; i++)
		{
			int minOrmax = i;
			for (int j = i + 1; j < this->Student_Num; j++)
			{
				if (select == 1)
				{
					if (this->Student_Array[minOrmax]->m_id > this->Student_Array[j]->m_id)
					{
						minOrmax = j;
					}
				}
				else
				{
					if (this->Student_Array[minOrmax]->m_id < this->Student_Array[j]->m_id)
					{
						minOrmax = j;
					}
				}
			}
			if (i != minOrmax)
			{
				Student* temp = this->Student_Array[i];
				this->Student_Array[i] = this->Student_Array[minOrmax];
				this->Student_Array[minOrmax] = temp;
			}
		}
		cout << "排序成功" << endl;
		this->Save();	
	}
}
```

## 按年级分类查看

遍历数组，匹配相应年级相应代码，然后输出每个年级下面的学生分类

```cpp
void StudentManager::ClassifyStudent()
{
	cout << "大一：" << endl;
	for (int i = 0; i < this->Student_Num; i++)
	{
		if (this->Student_Array[i]->m_grade == 1)
		{
			this->Student_Array[i]->Show_Info();
			 
		}
	}
	cout << endl;
	cout << "大二：" << endl;
	for (int i = 0; i < this->Student_Num; i++)
	{
		if (this->Student_Array[i]->m_grade ==2)
		{
			this->Student_Array[i]->Show_Info();
			 
		}
	}
	cout << endl;
	cout << "大三：" << endl;
	for (int i = 0; i < this->Student_Num; i++)
	{
		if (this->Student_Array[i]->m_grade == 3)
		{
			this->Student_Array[i]->Show_Info();
			 
		}
	}
	cout << endl;
	cout << "大四：" << endl;
	for (int i = 0; i < this->Student_Num; i++)
	{
		if (this->Student_Array[i]->m_grade ==4)
		{
			this->Student_Array[i]->Show_Info();
		 
		}
	}
	system("pause");
	system("cls");
}
```



## 清空数据

首先确认是否清空

然后打开文件

打开模式 ios::trunc 如果存在删除文件并重新创建

关闭文件

判断，如果指针数组不为空，那么将里面的指针释放干净，成员个数更新为零，将指针数组置为空，更新文件为空的标志。

```cpp
void StudentManager::CleanStudent()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式ios::trunc如果存在就删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->Student_Array != NULL)
		{
			for (int i = 0; i < this->Student_Num; i++)
			{
				if (this->Student_Array[i] != NULL)
				{
					delete this->Student_Array[i];
				}
			}
			this->Student_Num = 0;
			delete[] this->Student_Array;
			this->Student_Array = NULL;
			this->FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
```
