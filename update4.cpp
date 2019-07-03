#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct Student
{
string number;
string name;
string sex;
string major; 
string college; 
double mark[7];
double sum;
}Student student[5];;

struct Judge
{
	string name;
	double score[5];
}Judge judge[7];

int lxg(Student &p1,Student &p2)
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
	int n=0;
	ifstream readin("/Users/s20181105305/Desktop/readin.txt");
	ofstream readto("/Users/s20181105305/Desktop/readto.txt");
    if (!readin.is_open())
    {
        cout<<"open error";
    }	
    if(!readin.eof() && n<5)
	{for(n=0;n<5;n++)
	readin  >> student[n].number 
	        >> student[n].name
		>> student[n].sex
		>> student[n].major
		>> student[n].college;
	 } 	
	 readin.close();
	 n=0;
	 ifstream teacher("/Users/s20181105305/Desktop/teacher.txt");
    if (!teacher.is_open())
    {
        cout<<"open error";
    }	
    if(!readin.eof() && n<5)
	{    for(n=0;n<5;n++)
		 teacher >>judge[n].name
			 >>judge[n].score[0]
			 >>judge[n].score[1]
			 >>judge[n].score[2]
			 >>judge[n].score[3]
			 >>judge[n].score[4];
	 } 	
	
 teacher.close();	
 	for(int i=0;i<5;i++) 
 	{
 		for(int j=0;j<7;j++)
 		{
 			student[i].mark[j]=judge[j].score[i];
		 }
	 }	
 	for(int i=0;i<5;i++)
 	{
 		sort( student[i].mark, student[i].mark+7);
		for( int j=1; j<6; j++ )
		{
			student[i].sum += student[i].mark[j];
			}
			student[i].sum/=5;	
	 }
	sort(student,student+5,lxg);	
	for(int i=0;i<5;i++)
	{
	       readto<<student[i].college
		<<" "<<student[i].major
		<<" "<<student[i].number
		<<" "<<student[i].name
		<<" "<<student[i].sex
		<<" "<<student[i].sum
		<<endl;
			  
	} 	
	for(int i=0;i<5;i++)
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
