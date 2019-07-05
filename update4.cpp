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
	int n=0;
	ifstream read_student("D:\lin.txt");
	ofstream outcome("D:\shuchu.xl");
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
 	cout<<"老师的手机号码和家庭住址："<<endl; 
	for(int i=0;i<JUDGE;i++)
	{
	    cout<<judge[i].name<<" " 
			<<judge[i].telephone_number<<" " 
			<<judge[i].idfamily
			<<endl;
	}
	cout<<endl;	
	cout<<"老师给每位学生的分数："<<endl; 
	for(int i=0; i<JUDGE; i++)
	{
		cout<<judge[i].name<<endl;
		for(int j=0; j<STUDENT; j++)
		{
			cout<<student[j].name;
			cout<<judge[i].score[j]<<"  ";
		} 
		cout<<endl;
	}
	cout<<endl;
	cout<<"学生的个人信息以及最后平均分："<<endl; 
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
			student[i].sum/=(JUDGE-2);	
	 }
	sort(student,student+STUDENT,decide);	
	for(int i=0;i<STUDENT;i++)
	{
		outcome<<student[i].college
		       <<student[i].major
			   <<student[i].number
			   <<student[i].name
			   <<student[i].sex
			   <<student[i].sum
			   <<endl;	  
	} 	
	
	for(int i=0;i<STUDENT;i++)
	{
		 cout<<student[i].college
		<<" "<<student[i].major
		<<" "<<student[i].number
		<<" "<<student[i].name
		<<" "<<student[i].sex
		<<" "<<student[i].sum
		<<endl;
	} 	 
	return 0;
}
