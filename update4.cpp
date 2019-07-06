#include <iostream>
#include <fstream>
#include <algorithm>
#define STUDENT 5
#define JUDGE 7
using namespace std;
struct Student 
{
	string number;
	string name;
	string sex;
	string major; 
	string college; 
	double mark[JUDGE];
	double sum;
};

struct Judge
{
	string name;
	string telephone_number;
	string idfamily;
	double score[STUDENT];
};
 
int decide(Student &p1,Student &p2)
{
    if(p1.sum>p2.sum)
    {
	    return 1;    
    }
    else
    {
	    return 0;
    }	
}

int main()
{
	Student student[STUDENT];
	Judge judge[JUDGE];	
	int n=0,a=1;
	ifstream read_student("D:\lin.txt");
	ofstream outcome("D:\shuchu.txt");
    if (!read_student.is_open())
    {
        cout<<"open error";
    }	
    if( !read_student.eof() )
	{
	for(n=0;n<STUDENT;n++)
	{
		read_student >> student[n].number 
			>> student[n].name
			>> student[n].sex
			>> student[n].major
			>> student[n].college;		
	}
	} 	
	read_student.close();
	n=0;
	ifstream read_teacher("D:\gen.txt");
    if (!read_teacher.is_open())
    {
        cout<<"open error";
    }	
    if( !read_teacher.eof() )
	{
	    for(n=0;n<JUDGE;n++)
		{
		 read_teacher >> judge[n].name
		              >> judge[n].telephone_number
		              >> judge[n].idfamily;
		     for(int i=0;i<STUDENT;i++)
		 read_teacher >>judge[n].score[i];			
		}
	 } 	
 	read_teacher.close();
 	outcome<<"��ʦ���ֻ�����ͼ�ͥסַ��"<<endl; 
	for(int i=0;i<JUDGE;i++)
	{
	 outcome<<judge[i].name<<" " 
			<<judge[i].telephone_number<<" " 
			<<judge[i].idfamily
			<<endl;
	}
	outcome<<endl;	
	outcome<<"��ʦ��ÿλѧ���ķ�����"<<endl; 
	for(int i=0; i<JUDGE; i++)
	{
		outcome<<judge[i].name<<endl;
		for(int j=0; j<STUDENT; j++)
		{
			outcome<<student[j].name;
			outcome<<judge[i].score[j]<<"  ";
		} 
		outcome<<endl;
	}
	outcome<<endl;
 	for(int i=0;i<STUDENT;i++) 
 	{
 		for(int j=0;j<JUDGE;j++)
 		{
 			student[i].mark[j]=judge[j].score[i];
		 }
	 }	
 	for(int i=0;i<STUDENT;i++)
 	{
 		sort( student[i].mark, student[i].mark+JUDGE);
		for( int j=1; j<JUDGE-1; j++ )
		{
			student[i].sum += student[i].mark[j];
		}
			student[i].sum/=5;	
	 }
	sort(student,student+STUDENT,decide);
	outcome<<"ѧ���ĸ�����Ϣ�Լ����ƽ���֣�"<<endl;	
	cout<<"ѧ���ĸ�����Ϣ�Լ����ƽ���֣�"<<endl; 
	for(int i=0;i<STUDENT;i++)
	{
		outcome<<a
	    <<" "<<student[i].college
		<<" "<<student[i].major
		<<" "<<student[i].number
		<<" "<<student[i].name
		<<" "<<student[i].sex
		<<" "<<student[i].sum
		<<endl; 
		a++; 
	} 	
	
	a=1;
	for(int i=0;i<STUDENT;i++)
	{ 
		 cout<<a
	    <<" "<<student[i].college
		<<" "<<student[i].major
		<<" "<<student[i].number
		<<" "<<student[i].name
		<<" "<<student[i].sex
		<<" "<<student[i].sum
		<<endl;
		a++;
	} 	 
	return 0;
} 
