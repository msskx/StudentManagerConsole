#include"StudentManage.h"
//#include"Grade01.h"
//#include"Grade02.h"
//#include"Grade03.h"
//#include"Grade04.h"
#include"Grade.h"
StudentManager::StudentManager()//
{
	ifstream ifs;//����������
	ifs.open(FILENAME, ios::in);//Ϊ���ļ����ļ�
	//�ļ����������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->Student_Num = 0;//��ʼ������Ϊ��
		this->FileIsEmpty = true;//��־�ļ�Ϊ��
		this->Student_Array = NULL;//ָ������Ϊ��
		ifs.close();//�ر��ļ�
		return;//����������־
	}
	//�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->Student_Num = 0;
		this->FileIsEmpty = true;
		this->Student_Array = NULL;//ָ������Ϊ��
		ifs.close();//�ر��ļ�
		return;//����������־
	}
	int num = this->get_StudentNum();
	//cout << "ѧ������Ϊ��" << num << endl;
	this->Student_Num = num;
	//����ѧ������������
	this->Student_Array = new PSTU[this->Student_Num];
	this->InitStudent();
}//���캯��
void StudentManager::Show_Menu()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~ѧ��ѧ������ϵͳ~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "******************��0���˳�ϵͳ*****************" << endl;
	cout << "******************��1��¼��ѧ��*****************" << endl;
	cout << "******************��2����ʾѧ��*****************" << endl;
	cout << "******************��3��ɾ��ѧ��*****************" << endl;
	cout << "******************��4���޸�ѧ��*****************" << endl;
	cout << "******************��5������ѧ��*****************" << endl;
	cout << "******************��6��ѧ������*****************" << endl;
	cout << "******************��7��������ʾ*****************" << endl;
	cout << "******************��8�����ϵͳ*****************" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void StudentManager::Exit_System()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void StudentManager::Add_Student()
{
	cout << "���������ѧ������" << endl;
	int addnum;
	cin >> addnum;
	if (addnum > 0)
	{
		//�����¿ռ��С
		int newsize = this->Student_Num + addnum;
		//���ٿռ�
		PSTU* newspace = new PSTU[newsize];
		//��Դ�ռ�����ݴ�ŵ��¿ռ���
		if (this->Student_Array != NULL)
		{
			for (int i = 0; i < this->Student_Num; i++)
			{
				newspace[i] = this->Student_Array[i];
			}
		}
		//����������
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int select;
			string sex;
			string m_class;
			int m_age;
			cout << "�������" << i + 1 << "��ѧ��ѧ��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��ѧ������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "��ѧ���꼶���" << endl;
			cout << "1����һ" << endl;
			cout << "2�����" << endl;
			cout << "3������" << endl;
			cout << "4������" << endl;
			cin >> select;
			cout << "�������" << i + 1 << "��ѧ���Ա�" << endl;
			cin >> sex;
			cout << "�������" << i + 1 << "��ѧ���༶" << endl;
			cin >> m_class;
			cout << "�������" << i + 1 << "��ѧ������" << endl;
			cin >> m_age;
			PSTU student = NULL;
			switch (select)
			{
			case 1://��һ
				student = new Grade01(id, name, 1, sex, m_class, m_age);
				break;
			case 2://��2
				student = new Grade02(id, name, 2, sex, m_class, m_age);
				break;
			case 3://��3
				student = new Grade03(id, name, 3, sex, m_class, m_age);
				break;
			case 4://��4
				student = new Grade04(id, name, 4, sex, m_class, m_age);
				break;
			default:
				break;
			}

			newspace[this->Student_Num + i] = student;
		}
		//�ͷ�ԭ�пռ�
		delete[]this->Student_Array;
		//���¿ռ�ָ��
		this->Student_Array = newspace;
		//����ѧ������
		this->Student_Num = newsize;
		//����Ϊ�ձ�־
		this->FileIsEmpty = false;
		//��ʾ
		cout << "��ӳɹ�" << addnum << "��ѧ��" << endl;
		this->Save();//�����ļ�
	}
	else {
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}
void StudentManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//��д�ļ��ķ�ʽ���ļ�
	for (int i = 0; i < this->Student_Num; i++)
	{
		ofs << this->Student_Array[i]->m_id << " "
			<< this->Student_Array[i]->m_name << " "
			<< this->Student_Array[i]->m_grade << " "
			<< this->Student_Array[i]->m_sex << " "
			<< this->Student_Array[i]->m_class << " "
			<< this->Student_Array[i]->m_age << " " << endl;
	}
	ofs.close();
}
int StudentManager::get_StudentNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int grade;
	string sex;
	string m_class;
	int m_age;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> grade && ifs >> sex && ifs >> m_class && ifs >> m_age)
	{
		//��¼����
		num++;
	}
	ifs.close();
	return num;
}
void StudentManager::InitStudent()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int grade;
	int index = 0;
	string sex;
	string m_class;
	int m_age;
	while (ifs >> id && ifs >> name && ifs >> grade && ifs >> sex && ifs >> m_class && ifs >> m_age)
	{
		PSTU student = NULL;//�����꼶����PSTU�Ķ���
		if (id == 1)
		{
			student = new Grade01(id, name, grade, sex, m_class, m_age);
		}
		else if (id == 2)
		{
			student = new Grade02(id, name, grade, sex, m_class, m_age);
		}
		else if (id == 3)
		{
			student = new Grade03(id, name, grade, sex, m_class, m_age);
		}
		else
		{
			student = new Grade04(id, name, grade, sex, m_class, m_age);
		}
		//�����������
		this->Student_Array[index] = student;
		index++;

	}
}
void StudentManager::ShowStudent()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߲�����" << endl;
	}
	else
	{
		for (int i = 0; i < this->Student_Num; i++)
		{
			//���ö�̬���ýӿ�
			this->Student_Array[i]->Show_Info();
		}
	}
	system("pause");
	system("cls");
}
void StudentManager::DeleteStudent()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ѧ��ѧ��" << endl;
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
			this->Save();//ɾ����ͬ�����ݵ��ļ�
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ѧ��" << endl;
		}
	}
	system("pause");
	system("cls");
}
void StudentManager::FindStudent()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1������Ų���" << endl;
		cout << "2������������" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)//����ѧ�Ų���
		{
			int id;
			cout << "��������ҵ�ѧ��" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ѧ����Ϣ����" << endl;
				this->Student_Array[ret]->Show_Info();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)//����������
		{
			string name;
			cout << "��������ҵ�����" << endl;
			cin >> name;
			bool flag = false;//���ҵ��ı�־
			for (int i = 0; i < this->Student_Num; i++)
			{
				if (this->Student_Array[i]->m_name == name)
				{
					cout << "���ҳɹ�����Ϣ����" << endl;
					flag = true;
					this->Student_Array[i]->Show_Info();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴��ˣ���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}
void StudentManager::ModStudent()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڣ����¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ѧ��ѧ��" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->Student_Array[ret];
			int newid = 0;
			string newname = "";
			int select = 0;
			string newsex;
			string newclass;
			int newage;
			cout << "�鵽" << id << "��ѧ������������ѧ��" << endl;
			cin >> newid;
			cout << "������������" << endl;
			cin >> newname;
			cout << "�������꼶" << endl;
			cout << "1����һ" << endl;
			cout << "2�����" << endl;
			cout << "3������" << endl;
			cout << "4������" << endl;
			cin >> select;
			cout << "������༶" << endl;
			cin >> newclass;
			cout << "����������" << endl;
			cin >> newage;
			Student* student = NULL;
			switch (select)
			{
			case 1://��һ
				student = new Grade01(newid, newname, 1, newsex, newclass, newage);
				break;
			case 2://��2
				student = new Grade02(newid, newname, 2, newsex, newclass, newage);
				break;
			case 3://��3
				student = new Grade03(newid, newname, 3, newsex, newclass, newage);
				break;
			case 4://��4
				student = new Grade04(newid, newname, 4, newsex, newclass, newage);
				break;
			default:
				break;
			}
			//�������ݵ�������
			this->Student_Array[ret] = student;
			cout << "�޸ĳɹ�" << endl;
			//�����ļ�
			this->Save();

		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
		system("pause");
		system("cls");
	}
}
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
void StudentManager::SortStudent()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");

	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ѧ�Ž�������" << endl;
		cout << "2����ѧ�Ž��н���" << endl;

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
		cout << "����ɹ�" << endl;
		this->Save();
		system("pause");
		system("cls");
	}
}
void StudentManager::CleanStudent()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽios::trunc������ھ�ɾ���ļ������´���
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
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void StudentManager::ClassifyStudent()
{
	cout << "��һ��" << endl;
	for (int i = 0; i < this->Student_Num; i++)
	{
		if (this->Student_Array[i]->m_grade == 1)
		{
			this->Student_Array[i]->Show_Info();
		}
	}
	cout << endl;
	cout << "�����" << endl;
	for (int i = 0; i < this->Student_Num; i++)
	{
		if (this->Student_Array[i]->m_grade == 2)
		{
			this->Student_Array[i]->Show_Info();
		}
	}
	cout << endl;
	cout << "������" << endl;
	for (int i = 0; i < this->Student_Num; i++)
	{
		if (this->Student_Array[i]->m_grade == 3)
		{
			this->Student_Array[i]->Show_Info();
		}
	}
	cout << endl;
	cout << "���ģ�" << endl;
	for (int i = 0; i < this->Student_Num; i++)
	{
		if (this->Student_Array[i]->m_grade == 4)
		{
			this->Student_Array[i]->Show_Info();
		}
	}
	system("pause");
	system("cls");
}
StudentManager::~StudentManager()
{
	if (this->Student_Array != NULL)
	{
		delete[]this->Student_Array;
	}
}