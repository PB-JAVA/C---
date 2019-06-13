#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>
using namespace std;






class Student;
class Source;
long long ID=1000;

vector<Student> allStudent;


//�ɼ�ģ��   //����ѧ����Ϣʱ�ɼ�Ϊ�� Ҫ����˵��ĳɼ�ģ�������ɾ��� 
class Source
{

		 int english;
		 int chinese;
	     int all;
 	
 public:
 	Source(int i,int j,int a)
 	{
	   english = i;
	   chinese = j;
	   all = a;
	 }
	 
 		int getEnglish()
 		{
		 	return english;
		 }
		 int getChinese()
		 {
 			
 			return chinese;
 		}
 		int getAll()
 		{
		 	return all;
		 }
		 
 		void setEnglish(int e)
 		{
		 	english = e;
		 	all +=e;
		 }
		void setChinese(int c)
		{
			
			chinese = c;
			all +=c;
		}
			
	
};

//ѧ��������Ϣ  ��Ƕ��Source 
class Student
{
	private:
	 string name;
	 string  gender;
	 int age;
	 string tel;
	 long long id;
	Source *source;
	  
	  
	  
	public:
		Student()
		{
			name="null";
			age=0;
			gender="null";
			tel="null";
			id=0;
			source = NULL;
		}
		Student(string n,string t,int a,string g)
		{
			name = n;
			tel = t;
			age = a;
			gender = g;
			id = ID++;
		source = new Source(0,0,0);   //����ѧ����Ϣʱ�ɼ�Ϊ�� Ҫ����˵��ĳɼ�ģ�������ɾ��� 
		}
		
		void printSimple() //�򵥴�ӡѧ��������Ϣ 
		{
			cout<<"ID: "<<id<<"     ";
			cout<<"Name:  "<<name<<"    ";
			
			cout<<endl;
		}
		//ȫ����Ϣ��ӡ ���ǲ������ɼ� ����ɼ� ��Ҫ����ɼ�ģ�� 
		void printAll()
		{
			cout<<"ID: "<<id<<" ";
			cout<<"Name:  "<<name<<" ";
			cout<<"Age:   "<<age<<" ";
			cout<<"Gender: "<<gender<<" ";
			cout<<"Tel: "<<tel<<" ";
			cout<<endl;
			
		}
		
		void printSource()
		{
			cout<<"ID: "<<id<<" ";
			cout<<"Name:  "<<name<<" ";
			cout<<"English: "<<source->english<<" ";
			cout<<"Chinese: "<<source->chinese<<" ";
			cout<<"All: "<<source->all<<endl; 
		} 
		
		int getID()
		{
			return id;
		}
		string getName()
		{
			return name;
		}
		string getTel()
		{
			return tel;
		}
		Source getSource()
		{
			return source;
		}
		
		
		void setName(string name)
		{
			this->name = name;
		}
		void setTel(string tel)
		{
			this->tel = tel;
		}
		void setAge(int age)
		{
			this->age = age;
		}
		void setGender(string gender)
		{
			this->gender = gender;
		 } 
		 void setSource(Source s)
		 {
 			source = s;
 		}
};

void Menu();
void AddUser();
void Simple();
void printAll();
void deleteS();
void Consult();
void Change();
void StudentSource();

long long ContainId(long long id);  //���ID�Ƿ���� 

int main(void)
{
	
	
	allStudent.clear();
	while(1)
	{
		int flag=1; 
		system("cls");
		Menu();
		int choose;
		cout<<"\n����Ҫʲôҵ��   �����룺";
		cin>>choose;
		
		if(choose>6 || choose<0)
		{
			system("cls");
			cout<<"��Ч��������ԣ�";
			Sleep(400);
			continue;
		}
		
		switch(choose)
		{
			system("cls");
			case 7:flag=0;break;  //flag�Ƿ��˳�ϵͳ��� 
			case 0:Simple();break;
      	    case 1:printAll();break;
      	    case 2:AddUser();break;
      	    case 3:deleteS();break;
      	    case 4:Consult();break;
      	    case 6:Change(); break;
      	    case 5:StudentSource();break; 
		}
		
		if(!flag)
		{
			system("cls"); 
			cout<<"***************��ӭ�ٴ�ʹ�ã�*************"; //������ʾ�� 
			Sleep(50);
			 break;
		}
	}
		
	
}


void Menu()
{
	cout<<"                _________________________________________________\n\n";
	cout<<"                                 ѧ������ϵͳ1.0��@PB��           \n";      
	cout<<"                _________________________________________________ \n";
	cout<<"\n 		 		(1) ��ʾѧ����ϸ��Ϣ\n\n";
	cout<<" 		 		(0) ��ʾѧ����Լ��Ϣ\n";
	cout<<"\n";
	cout<<" 		 		(2)   ���ѧ����Ϣ\n";
	cout<<"\n";
	cout<<" 				(3)   ɾ��ѧ����Ϣ\n";
	cout<<"\n";
	cout<<" 				(4)       ��ѯ\n";
	cout<<"\n";
	cout<<" 				(6)   �޸�ѧ����Ϣ\n";
	cout<<"\n";
	cout<<" 				(5)       �ɼ�ϵͳ\n";
	cout<<"\n";
	cout<<" 				(7)       �˳�\n";  
    cout<<"                _________________________________________________\n"; 
}


void AddUser()
{
	system("cls"); 
	int time=0;
	string n,t,g;
	int a=0;
	cout<<endl;
	cout<<"�� "<<ID<<" ��ѧ����������  ";
	cin>>n;
	cout<<endl;
	cout<<"�� "<<ID<<" ��ѧ�������䣺  ";
	cin>>a;
	cout<<endl; 
	cout<<"�� "<<ID<<" ��ѧ�����Ա�  ";
	cin>>g;
	cout<<endl;
	cout<<"�� "<<ID<<" ��ѧ���ĵ绰��  ";
	cin>>t;
	cout<<endl;
	system("cls");
	cout<<"��Ϣ����¼����";            
	while(time++<20)  //����Ч�� 
	{
		cout<<".";
		Sleep(50);
	 }
	 system("cls");
	 cout<<"\n                    ��Ϣ¼��ɹ���" ;
	 Sleep(1000);
	 Student student(n,t,a,g);
	 allStudent.push_back(student);   
	
}



//��Լ��Ϣ 
void  Simple()
{
	system("cls");
	for(int i=0;i<allStudent.size();i++)
	{
			allStudent[i].printSimple();
			cout<<endl;
	}
	if(allStudent.size()!=0)
	cout<<"��A������.....";
	else
	cout<<"ѧ����ϢΪ�� ϵͳ��δ��¼ѧ����Ϣ����A������.....";
	char ch;
	cin>>ch;
	cout<<endl; 
}



//��ϸ��ϸ 
void printAll()
{
	system("cls");
	for(int i=0;i<allStudent.size();i++)
	{
			allStudent[i].printAll();
			cout<<endl;
	}
	if(allStudent.size()!=0)
	cout<<"��A������.....";
	else
	cout<<"ѧ����ϢΪ�� ϵͳ��δ��¼ѧ����Ϣ����A������.....";
	char ch;
	cin>>ch;
	cout<<endl; 
	
}



//ɾ��ģ�� 
void deleteS()
{
	
	int rt = 1; //ѭ����־
	 
	while(rt)   //����ѭ��  �������Ҳ���ID���������������id 
	{
		int flag=0;
		
		system("cls");
		cout<<"������Ҫɾ��ѧ����Ϣ��ID ��ע�⣺ɾ����ID��ID���ɸ��á�:  ";
		long long  id;
		cin>>id;
	 cout<<endl; 
		
	for(int i=0;i<allStudent.size();i++)
	 {
	 	
	 	int time=0;
		system("cls");    //����   
		if(allStudent[i].getID()==id)
		{	
				flag=1;
				
				cout<<"����ɾ��";            
				while(time++<20)  //����Ч�� 
				{
					cout<<".";
					Sleep(50);
				 }
			system("cls");
				 
			cout<<"�ɹ�ɾ��ѧ�� "<<allStudent[i].getID()<<": "<<allStudent[i].getName()<<" ����Ϣ��"; 
			allStudent.erase(allStudent.begin()+i);    //��������ɾ��  ���������һ������ ���ڸ��� ��erase������� ��ȫ ��ֹ�� 
			char choose;
			cout<<" \n �Ƿ����ɾ������Y/N�� "; 
			cin>>choose; 
			if(choose!='Y')
			rt=0;
			break; 
		}
		
	 } 
	 	if(!flag)  //û�����id 
		{
			
            char choose;
			cout<<"\nϵͳ�Ҳ�����ѧ�����Ƿ��������룿(Y/N) : "; 
			cin>>choose;
			
			if(choose!='Y')
				rt = 0;  //�˳�ѭ����־ 
			
			break;
		} 	 
   }  //while 
	
	
}


//��ѯģ��
long long ContainId(long long id)  //���ڷ���id  �����ڷ���-1 
{
	int flag=0;
	for(int i=0;i<allStudent.size();i++)
	{
		if(allStudent[i].getID()==id)
		{
			flag=1;
			return i;
		}
	}
	if(!flag)
	return -1;
}
void Consult()
{
	
	int rt=1;
	while(rt)
	{
		int flag=0;  //�Ƿ��ҵ���id��־ 
				system("cls");
				cout<<"������Ҫ��ѯ��ID :"; 
				long long  id=0;
				cin>>id;
			 cout<<endl; 
			 	
			 
			 	for(int i=0;i<allStudent.size();i++)
			   {
				system("cls");    //����   
				if(allStudent[i].getID()==id)
				{	
				    flag=1;
					 
					system("cls");	 
					allStudent[i].printAll();  //��ӡ��ѯ��ϸ��Ϣ
					 
					 cout<<"\n\n"<<endl;
					 cout<<"Ҫ�Ը�ѧ������ʲô��������Dɾ��|N����������";
						char ch;
						cin>>ch;
						if(ch=='D')  //ɾ�� 
						{
							int time=0;
									cout<<"����ɾ��";            
								while(time++<20)  //����Ч�� 
								{
									cout<<".";
									Sleep(50);
								 }
							system("cls");
								 
							cout<<"�ɹ�ɾ��ѧ�� ";
							allStudent.erase(allStudent.begin()+i); 
						}
						else
						{
							system("cls");
							allStudent[i].printAll();
						} 
		
					char choose;
					cout<<" \n\n �Ƿ������ѯ����Y/N�� "; 
					cin>>choose; 
					if(choose!='Y')
					rt=0;
					break; 
				}
					
			 } 
			  
			  if(!flag)  //û�����id 
				{
					
		            char choose;
					cout<<"\nϵͳ�Ҳ�����ѧ�����Ƿ��������룿(Y/N) : "; 
					cin>>choose;
					
					if(choose!='Y')
						rt = 0;  //�˳�ѭ����־ 
					
					break;
				} 
	 
	}//while	
		
	
} 

//�޸�ģ��
void Change()
{
	int rt=1;
	while(rt)
	{
		system("cls");
				cout<<"������Ҫ�޸ĵ�ID :"; 
				long long  id=0;
				cin>>id;
			 cout<<endl;
			 if(ContainId(id)==-1)  //id������ 
			 {
			 		char choose;
					cout<<" \n\n�Ҳ���ID  �Ƿ������ѯ����Y/N�� "; 
					cin>>choose; 
					if(choose!='Y')
					rt=0;
					
			  }
			  else{
			  	
			  	 int cg;
			  	 
			  	 
			  	 
				   cout<<"�޸��ĸ����ԣ���1������ ��2������ ��3���Ա� ��4���绰 ��ID���ɸ� ID��Ψһ�ģ�"<<endl; 
			  	cin>>cg;
			  	string s = "";
			  	system("cls");
			  	switch(cg)
			  	{
			  		
			  	   	  case 1:cout<<"�������µ�������  ";cin>>s;allStudent[ContainId(id)].setName(s);s =""; break;
					  case 2:cout<<"�������µ����䣺  ";cin>>cg;allStudent[ContainId(id)].setAge(cg);break;
					  case 3:cout<<"�������µ��Ա�  ";cin>>s;allStudent[ContainId(id)].setGender(s);s ="";break;
					  case 4:cout<<"�������µĵ绰��  ";cin>>s;allStudent[ContainId(id)].setTel(s);s ="";break;
					  default:cout<<"��Ч���"<<endl;continue;
				  }
			  	
			  	int time=0;
				cout<<"���ڸ���";            
				while(time++<20)  //����Ч�� 
				{
					cout<<".";
					Sleep(50);
				 }
				system("cls");
								 
					cout<<"�ɹ�����ѧ��:"<<endl;
					allStudent[ContainId(id)].printAll();
					
			  	cout<<" \n\n �Ƿ������ѯ����Y/N�� "; 
			  	char choose;
					cin>>choose; 
					if(choose!='Y')
					rt=0;
			  } 
	}
 } 



//�ɼ�ģ�� ���� 

bool compareAll(Student i,Student j);
bool compareEnglish(Student i,Student j);
bool compareChinese(Student i,Student j);

void Sort_All(); //�ܳɼ� 
void Sort_E();   //Ӣ������ 
void Sort_C();   //���� 

void inputSource();


void StudentSource()
{
	int rt=1;
		system("cls");
		while(rt)
		{
						cout<<"\n------------------------> ��ӭ����PB�ɼ�����ϵͳ <-----------------------------\n\n\n\n"; 
			int id=0;
			cout<<"--------------* ��1��ѧ���ܳɼ�����\n\n";
			cout<<"--------------* ��2��ѧ�����ĳɼ�����\n\n";
			cout<<"--------------* ��3��ѧ��Ӣ��ɼ�����\n\n";
			cout<<"--------------* ��4��¼��ѧ���ɼ�\n\n";
			cout<<"--------------* ��5���޸�ѧ���ɼ�\n\n";
			cout<<"--------------* ��0���˳��ɼ�����ϵͳ\n\n";
			cout<<"����Ҫʲôҵ��:   ";
			int choose=0;
			cin>>choose;
			
			switch(choose)
			{
				case 1:Sort_All();break;
				case 2:Sort_C();break;
				case 3:Sort_E();break;
				case 4:inputSource();break; 
				case 5:cout<<"��ʱ��ԭ�� ͬʱ�������� �������ﲻд�ˣ�";break;
				case 0:	rt=0;break;
			}
			
		} 

	 
	
	
} 



//����ȽϺ���  ���� 
bool compareAll(Student i,Student j)
{
	return i.source.all>j.source.all;
}
bool compareChinese(Student i,Student j)
{
	return i.source.chinese>j.source.chinese;
}
bool compareEnglish(Student i,Student j)
{
	return i.source.english>j.source.english;
}



void Sort_All()
{
	vector<Student> copyStudent(allStudent);
	sort()
	system("cls");
	cout<<"______________________________________\n\n";
	sort(copyStudent.begin(),copyStudent.end(),compareAll);   //��ָ���ֶ�����
	for(int i=0;i<copyStudent.size();i++)
	{
		cout<<"|  "<<i<<"  | "<<Student.printSource()<<endl;
	}	
}
void Sort_E()
{
	vector<Student> copyStudent(allStudent);
	sort()
	system("cls");
	cout<<"______________________________________\n\n";
	sort(copyStudent.begin(),copyStudent.end(),compareEnglish);   //��ָ���ֶ�����
	for(int i=0;i<copyStudent.size();i++)
	{
		cout<<"|  "<<i<<"  | "<<Student.printSource()<<endl;
	}	
} 
void Sort_C()
{
	vector<Student> copyStudent(allStudent);
	sort()
	system("cls");
	cout<<"______________________________________\n\n";
	sort(copyStudent.begin(),copyStudent.end(),compareChinese);   //��ָ���ֶ�����
	for(int i=0;i<copyStudent.size();i++)
	{
		cout<<"|  "<<i<<"  | "<<copyStudent[i].printSource()<<endl;
	}	



void inputSource()
{
	int rt=1;
	while(rt)
	{
		
		system("cls");
		cout<<"������Ҫ¼���ѧ��ID�� ";
		long long id=0;
		cin>>id;
		
		 if(ContainId(id)==-1)  //id������ 
			 {
			 		char choose;
					cout<<" \n\n�Ҳ���ID  �Ƿ������ѯ����Y/N�� "; 
					cin>>choose; 
					if(choose!='Y')
					rt=0;
					
			  }
		  else
		  {
		  	int  c;
		  	int  e;
  			cout<<"���ģ�"; 
  			cin>>c;
  			cout<<endl;
  			cout<<"Ӣ�"; 
  			cin>>e;
  			cout<<endl;
  			
  			//����  �ֻܷ��Զ����� 
  			allStudent[ContainId[id]].source.english = e;
  			allStudent[ContainId[id]].source.chinese = c;
  			
  			
  			int time=0;
  			system("cls"); 
				cout<<"����¼��";            
				while(time++<20)  //����Ч�� 
				{
					cout<<".";
					Sleep(50);
				 }
				system("cls");
								 
					cout<<"¼��ɹ���"<<endl;
					allStudent[ContainId(id)].printSource();
					
			  	cout<<" \n\n �Ƿ������ѯ����Y/N�� "; 
			  	char choose;
					cin>>choose; 
					if(choose!='Y')
					rt=0;
  		  }	  
  		  
	}
}
	
