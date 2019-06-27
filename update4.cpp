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
};

struct Judge
{
	string name;
	double score[5];
};

int lxg(Student &p1,Student &p2)
{
	if(p1.sum>p2.sum)
	{
		return 1 ;
		
	}else
	{
		return 0;
	}
}

int main()
{   
	Student student[5];
	Judge judge[7];	
	int n=0;
	ifstream lin("D:\lin.txt");
	ofstream shuchu("D:\shuchu.xl");
    if (!lin.is_open())
    {
        cout<<"open error";
    }
    while(!lin.eof() && n<5)
	{
	lin >> student[n].number 
		>> student[n].name
		>> student[n].sex
		>> student[n].major
		>> student[n].college; 
		n++;
	 } 
	 lin.close();
	 n=0;
	 ifstream gen("D:\gen.txt");
    if (!gen.is_open())
    {
        cout<<"open error";
    }
    while(!gen.eof() && n<7)
	{
		gen >>judge[n].name 
			>>judge[n].score[0]
			>>judge[n].score[1]
			>>judge[n].score[2]
			>>judge[n].score[3]
			>>judge[n].score[4];
		    n++;
	 } 
	 
    gen.close();
    int i=0,j=0;
 	for(i=0;i<5;i++) 
 	{
 		for(j=0;j<7;j++)
 		{
 			student[i].mark[j]=judge[j].score[i];
		 }
	 }
 	for(i=0;i<5;i++)
 	{
 		sort(student[i].mark,student[i].mark+7);
		for( j=1; j<6; j++ )
		{
			student[i].sum += student[i].mark[j];
			}
			student[i].sum/=5;	
	 }
    sort(student,student+5,lxg);
    for(int i=0;i<5;i++)
	{
		shuchu<<student[i].college
		      <<student[i].major
			  <<student[i].number
			  <<student[i].name
			  <<student[i].sex
			  <<student[i].sum
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
