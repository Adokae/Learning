#include "workerManager.h"

WorkerManger::WorkerManger()
{
    // 1 �ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);// ���ļ�

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		// ��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	// �ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		// �ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	// �ļ����� ���ݲ�Ϊ��
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ: " << num << endl;
	this->m_EmpNum = num;

	// ���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// ���ļ��е����ݴ浽������
	this->init_Emp();
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ�����: " << this->m_EmpArray[i]->m_ID
			<< "������" << this->m_EmpArray[i]->m_Name
			<< "���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	}

}

// չʾ�˵�
void WorkerManger::Show_Menu()
{
	cout << "*******************************************" << endl;
	cout << "*******  ��ӭʹ��ְ������ϵͳ *************" << endl;
	cout << "*******  0 �˳�������� *******************" << endl;
	cout << "*******  1 ����ְ����Ϣ *******************" << endl;
	cout << "*******  2 ��ʾְ����Ϣ *******************" << endl;
	cout << "*******  3 ɾ����ְְ�� *******************" << endl;
	cout << "*******  4 �޸�ְ����Ϣ *******************" << endl;
	cout << "*******  5 ����ְ����Ϣ *******************" << endl;
	cout << "*******  6 ���ձ������ *******************" << endl;
	cout << "*******  7 ��������ĵ�********************" << endl;
	cout << "*********************************" << endl;
}

// �˳�ϵͳ
void WorkerManger::ExitSystem()
{
	cout << "��ӭ�´μ���ʹ��" << endl;
	system("pause");
	exit(0);
}


// ���ְ����Ϣ
void WorkerManger::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;
		// �����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		// ��ԭ���ռ��е����� �������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		// �������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ�����:" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "��ְ����λ:" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employer(id, name, dSelect);
				break;
			case 2:
				worker = new Manger(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			// ������ְ��ְ�� ���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		// �ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		// �����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		// ����ְ������
		this->m_EmpNum = newSize;
		// ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;
		// ��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		// �������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "������������" << endl;
	}
	// ��������� �����ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}
// ͳ������
int WorkerManger::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dID;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		// ͳ����������
		num++;
	}
	return num;
}


// �����ļ�
void WorkerManger::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); // ��д�ļ���ʽ���ļ�
	// ������д���ļ�
	for (int i = 0;i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << " " << endl;
	}
	// �ر��ļ�
	ofs.close();
}

void WorkerManger::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dID;
	int index = 0;
	// id name dId�ڶ�ȡʱ���� �����ݸ���ض���
	while (ifs>>id && ifs>>name && ifs>>dID)
	{
		Worker* worker = NULL;
		if (dID == 1)
		{
			worker = new Employer(id, name, dID);
		}
		else if (dID == 2)
		{
			worker = new Manger(id, name, dID);
		}
		else if (dID == 3)
		{
			worker = new Boss(id, name, dID);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
// ��ʾְ��
void WorkerManger::Show_Emp()
{
	// �ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// ���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	// ���������
	system("pause");
	system("cls");
}
// ɾ��ְ��
void WorkerManger::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		// ����ְ�����ɾ��ְ��
		cout << "������Ҫɾ����ְ����ţ� " << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				// ����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;// ���������м�¼��Ա����
			// ����ͬ�����µ��ļ���
			this->save();
		}
		else
		{
			cout << "δ�ҵ���ɾ��ʧ��" << endl;
		}
	}
	system("pause");
	system("cls");
}



// �ж�ְ���Ƿ����
int WorkerManger::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

// �޸�
void WorkerManger::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		// �޸�ְ��
		cout << "������Ҫ�޸ĵ�ְ����ţ� " << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newID = 0;
			string newName = "";
			int dSelect = 0;
			cout << "���ҵ���" << id << "��ְ������������ְ����: " << endl;
			cin >> newID;
			cout << "��������������" << endl;
			cin >> newName;
			cout << "�������µĸ�λ��" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employer(newID, newName, dSelect);
				break;
			case 2:
				worker = new Manger(newID, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newID, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			// ����ͬ�����µ��ļ���
			this->save();
		}
		else
		{
			cout << "δ�ҵ����޸�ʧ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

// ����
void WorkerManger::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų��� " << endl;
		cout << "2����ְ���������� " << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			// ����Ų�
			int id;
			cout << "������Ҫ���ҵ�ְ�����:" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ����:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ��" << endl;
			}
		}
		else if (select == 2)
		{
			// ��������
			// ����Ų�
			string name;
			cout << "������Ҫ���ҵ�ְ������:" << endl;
			cin >> name;

			// �����ж��Ƿ�鵽�ı�־
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�����ְ����Ϣ����:" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ��" << endl;
			}
				
		}
	}
	system("pause");
	system("cls");
}
// ����
void WorkerManger::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "ѡ������ʽ��" << endl;
		cout << "1����ְ���Ž�����������" << endl;
		cout << "2����ְ���Ž��н�������" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minMax = i;// ������Сֵ�����ֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					// ����
					if (this->m_EmpArray[minMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minMax = j;
					}

				}
				else if (select == 2)
				{
					// ����
					if (this->m_EmpArray[minMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minMax = j;
					}
				}
			}
			if (i != minMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minMax];
				this->m_EmpArray[minMax] = temp;
			}
		}
	}
	cout << "����ɹ�,�����Ľ��Ϊ��" << endl;
	this->save();
	this->Show_Emp();

}

// ����ļ�
void WorkerManger::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ�����" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		// ����ļ�
		ofstream ofs(FILENAME, ios::trunc); // ɾ���ļ������´���
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_FileIsEmpty; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			// ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManger::~WorkerManger()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}