#include"Grade.h"//�����꼶ѧ����ͷ�ļ�
//��һ�꼶ѧ����ʵ��
Grade01::Grade01(int id, string name, int grade, string sex, string m_class, int m_age)
{
	this->m_id = id;//ѧ��
	this->m_name = name;//����
	this->m_grade = grade;//�꼶
	this->m_class = m_class;//�༶
	this->m_sex = sex;//�Ա�
	this->m_age = m_age;//����

}//ʵ�ִ�һ�꼶��Ĺ��캯��,���ÿ������캯����ֵ
void Grade01::Show_Info()//��ʾ������Ϣ
{
	cout << "ѧ�ţ�" << this->m_id << " "
		<< "������" << this->m_name << " "
		<< "�꼶��" << this->Get_Grade() << " "
		<< "�Ա�" << this->m_sex << " "
		<< "�༶��" << this->m_class << " "
		<< "���䣺" << this->m_age << endl;
}
string  Grade01::Get_Grade()//��ȡ�꼶����
{
	return (string)"��һ";
}
//����꼶ѧ����ʵ��
Grade02::Grade02(int id, string name, int grade, string sex, string m_class, int m_age)
{
	this->m_id = id;//ѧ��
	this->m_name = name;//����
	this->m_grade = grade;//�꼶
	this->m_class = m_class;//�༶
	this->m_sex = sex;//�Ա�
	this->m_age = m_age;//����

}//ʵ�ִ���꼶��Ĺ��캯��,���ÿ������캯����ֵ
void Grade02::Show_Info()//��ʾ������Ϣ
{
	cout << "ѧ�ţ�" << this->m_id << " "
		<< "������" << this->m_name << " "
		<< "�꼶��" << this->Get_Grade() << " "
		<< "�Ա�" << this->m_sex << " "
		<< "�༶��" << this->m_class << " "
		<< "���䣺" << this->m_age << endl;
}
string  Grade02::Get_Grade()//��ȡ�꼶����
{
	return (string)"���";
}
//�����꼶ѧ����ʵ��
Grade03::Grade03(int id, string name, int grade, string sex, string m_class, int m_age)
{
	this->m_id = id;//ѧ��
	this->m_name = name;//����
	this->m_grade = grade;//�꼶
	this->m_class = m_class;//�༶
	this->m_sex = sex;//�Ա�
	this->m_age = m_age;//����

}//ʵ�ִ����꼶��Ĺ��캯��,���ÿ������캯����ֵ
void Grade03::Show_Info()//��ʾ������Ϣ
{
	cout << "ѧ�ţ�" << this->m_id << " "
		<< "������" << this->m_name << " "
		<< "�꼶��" << this->Get_Grade() << " "
		<< "�Ա�" << this->m_sex << " "
		<< "�༶��" << this->m_class << " "
		<< "���䣺" << this->m_age << endl;
}
string  Grade03::Get_Grade()//��ȡ�꼶����
{
	return (string)"����";
}
//�����꼶ѧ����ʵ��
Grade04::Grade04(int id, string name, int grade, string sex, string m_class, int m_age)
{
	this->m_id = id;//ѧ��
	this->m_name = name;//����
	this->m_grade = grade;//�꼶
	this->m_class = m_class;//�༶
	this->m_sex = sex;//�Ա�
	this->m_age = m_age;//����

}//ʵ�ִ����꼶��Ĺ��캯��,���ÿ������캯����ֵ
void Grade04::Show_Info()//��ʾ������Ϣ
{
	cout << "ѧ�ţ�" << this->m_id << " "
		<< "������" << this->m_name << " "
		<< "�꼶��" << this->Get_Grade() << " "
		<< "�Ա�" << this->m_sex << " "
		<< "�༶��" << this->m_class << " "
		<< "���䣺" << this->m_age << endl;
}
string  Grade04::Get_Grade()//��ȡ�꼶����
{
	return (string)"����";
}



