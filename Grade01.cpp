//��һ�꼶ѧ����ʵ��
#include"Grade01.h"//������һ�꼶ѧ����ͷ�ļ�

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
		<< "�꼶��" << this->Get_Grade() <<" "
		<<"�Ա�"<<this->m_sex<<" "
		<<"�༶��"<<this->m_class<<" "
		<<"���䣺"<<this->m_age<< endl;
}
string  Grade01::Get_Grade()//��ȡ�꼶����
{
	return (string)"��һ";
}


