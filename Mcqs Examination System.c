#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>



int isnegative=0;
float neg_phy=0,neg_chem=0,neg_bio=0,neg_math=0;
float total_phy=0,total_chem=0,total_bio=0,total_maths=0;
void delay()
{
		int i;
				for(i=0; i<100000000; i++)			// screen delay 
				{
					
				}
}
void maindisplay()
{
	int j;
	printf("\n \n \n \n \t \t \t .......WELCOME TO MCQS EXAMINATION SYSTEM....\n \n \n \n ");
    	
		printf("\t \t \t LOADING.....PLEASE WAIT");
 		for(j=0; j<15; j++)
		 {
		 	
		 	printf("!");
			delay();	
}
}
void menudisplay()
{
		   	
    	
           
        	
printf("\t \t  \t 1 - LOG-IN AS ADMIN \n");
		
printf("\t \t  \t 2 - LOG_IN AS USER \n");

printf("\t \t  \t 3-EXIT \n");

printf("\t \t  \t Enter OPTION [1-3] \n");

}
struct student
{
	int id;
	char name[100];
	int age;
	int semester;
	char gender;
	
};
struct result
{
	int s_id;
	int total_attempted;
	int correct_physics;
	int correct_chemistry;
	int correct_maths;
	int correct_biology;
	int total_correct;
	int wrong;
	float total_score;
	float percentage;
	int status;
	
	
};
struct mcq
{
	
	char q[200];
	char a[50];
	char b[50];
	char c[50];
	char d[50];
	char subject[50];
	char correct;
};



int search_student(int id)
{
	FILE *fp;

int found=0;
fp=fopen("student.dat","rb");
if(fp==NULL)
{
	return 0;
}
struct student temp;

while(1)
{
fread(&temp,sizeof(struct student),1,fp);

if(feof(fp))
{
break;
}
if(temp.id==id)
{
return -1;
}
}
if(found==0)
{
return 0;
}
fclose(fp);
	
}
int loginstudent(int id)
{
	if(search_student(id)==-1)
	{
		return 0;
	}
	else return -1;
}

void register_student(struct student s)

{


int i=0,flag=0;
	FILE *f;
	

if(search_student(s.id)!=-1)
{
	
	
	   f = fopen("student.dat", "ab");
	 fwrite (&s, sizeof(struct student), 1, f); 
		
    
    if(f != 0)  
        printf("Student Added sucefully !\n"); 



	fclose(f);
}
else
{
	printf("Student Already Exist");
}
}
void add_mcq()


{
	
	
	printf("Note : Assume You Can Add Only Maths, Physics,Chemistry,Biology as a Subject For a Question");
	struct mcq temp;
	
	fflush(stdin);
	puts("Enter The Mcqs Question \n");
		fflush(stdin);
	gets(temp.q);

	puts("Enter The Option A \n");
		fflush(stdin);
	gets(temp.a); 
	puts("Enter The Option B \n");
		fflush(stdin);
	gets(temp.b);
	puts("Enter The Option C \n");
		fflush(stdin);
	gets(temp.c);
	puts("Enter The Option D \n");
		fflush(stdin);
	gets(temp.d);
	puts("Enter The Subject To Which Mcqs Belong \n");
		fflush(stdin);


	gets(temp.subject);
	if(strcmp(temp.subject,"physics")==0)
		{
		
		total_phy++;;
			
		}
		else if(strcmp(temp.subject,"chemistry")==0) 
		{

		total_chem++;
		}
		else if(strcmp(temp.subject,"biology")==0)  
		{
	total_bio++;
		;
		}
		else if(strcmp(temp.subject,"maths")==0) 
		{
	total_maths++;
		}

	puts("Enter the correct option (a / b / c /d ) " );
	fflush(stdin);
	scanf("%c",&temp.correct);
	
	
	FILE *f;
	   f = fopen("mcqs.dat", "ab");
	 fwrite (&temp, sizeof(struct mcq), 1, f); 

 
    if(f != 0)  
        printf("Mcqs Added Sucefully !\n Press Any Key!...."); 
        getche();



	fclose(f);	 
	
	
}
void display_mcqs()
{
	FILE *fp;
struct mcq t;

fp=fopen("mcqs.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
puts(t.q);
printf("a - ");

puts(t.a);
printf("b - ");
puts(t.b);
printf("c - ");
puts(t.c);
printf("d - ");
puts(t.d);
printf("The subject is ");
puts(t.subject);
printf("\n");

}

}
	void display_students()
	{
		FILE *fp;
struct student t;

fp=fopen("student.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
printf("\n ID is = %d \n",t.id);
printf(" Name is = ");
puts(t.name);
printf("Age is %d \n",t.age);
printf("Semster is %d \n",t.semester);
printf("Gender is = %c \n",t.gender);


}
	}
	
	
void display_specific()
{
FILE *fp;
struct student t;
int id,found=0;

fp=fopen("student.dat","rb");

printf("\nEnter the Student ID:");
scanf("%d",&id);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.id==id)
{
found=1;
printf("\n========================================================\n\n");
printf("\t\t  Student Details of %d\n\n",t.id);
printf("========================================================\n\n");

printf(" ID is = %d \n",t.id);
printf(" Name is = ");
puts(t.name);
printf("Age is %d \n",t.age);
printf("Semster is %d \n",t.semester);
printf("Gender is = %c \n",t.gender);
printf("\n");

}
}
if(found==0)
{
printf("\nSorry No Record Found");
}
fclose(fp);
}	
	
	
	
	
	
	
	
	

void update_record()
{
	
	FILE *fp,*fp1;
struct student t,t1;
int id,found=0,count=0;

fp=fopen("student.dat","rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter the Emp ID you want to Modify:");
scanf("%d",&id);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.id==id)
{
found=1;
	system("cls");
			printf(" \n \t \t  \t Enter id : ");
			
			scanf("%d",&t.id);
		;
			printf(" \n \t \t  \t Enter name :");
					fflush(stdin);
					gets(t.name);
			printf(" \n \t \t  \t Enter age : ");
			
			fflush(stdin);
			scanf("%d",&t.age);
			printf(" \n \t \t  \t Enter semester : ");
					fflush(stdin);
		scanf("%d",&t.semester);
			printf(" \n \t \t  \t Enter gender M or F :");
				fflush(stdin);
			scanf("%c",&t.gender);
		
fwrite(&t,sizeof(t),1,fp1);
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen("student.dat","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}

}
fclose(fp);
fclose(fp1);
}

void delete_record()
{
FILE *fp,*fp1;
struct student t,t1;
int id,found=0,count=0;

fp=fopen("student.dat","rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter the Student ID you want to Delete:");
scanf("%d",&id);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.id==id)
{
found=1;
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen("student.dat","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}
}
fclose(fp);
fclose(fp1);
}

void welcome_screen(int id)
{
	
	system("cls");
	
	printf("\n========================================================\n\n");
		
	printf("\n========================================================\n\n");
printf("\t\t  Welcome %d \n",id);

printf("========================================================\n\n");
	printf("\n========================================================\n\n");
printf("\n There will be mcqs consisting of Biology,Maths,Physics,Maths");
if(isnegative==0)
{
	printf("\n There will be no Negative marking");
}
else 
{
	printf("\n There will be  Negative marking");
	printf(" \n The negative marking for physics is %f",neg_phy);
		printf(" \n The negative marking for chemisrty is %f",neg_chem);
		printf(" \n The negative marking for maths is %f",neg_math);
	printf(" \n The negative marking for biology is %f \n",neg_bio);

	
	
}


	printf(" \nPress any key to continue");
	getche();
}



char  print_mcqs(char question[],char a[],char b[],char c[],char d[],char subject[],int id,int qno)
{
	printf("====================== ID  ==  %d ==================== \n",id);
		printf("====================== QNO  ==  %d ==================== \n",qno);
	puts(question);
	printf("\n \n a-");
	puts(a);
	printf("\n \n b-");
	puts(b);
	printf("\n \n c-");
	puts(c);
	printf("\n \n d-");
	puts(d);
	printf("\n \n e- To Skip ");
	
	printf("===============================================");
	printf("\n \n");
	char choice=getche();
	
	
	system("cls");
		return choice;

}

void generate_result(struct result r)
{
printf("\n The total attempeted mcqs are  %d:",r.total_attempted);
printf("\n The total correct mcqs are %d ",r.total_correct);
printf("\n The total wrong mcqs are %d",r.wrong);
printf("\n The total correct in biology %d",r.correct_biology);
printf("\n The total correct in chemistry %d",r.correct_chemistry);
printf("\n The total correct in physics %d",r.correct_physics);
printf("\n The total correct in maths %d",r.correct_maths);
float phy=(total_phy-r.correct_physics)*neg_phy;
float chem=(total_chem-r.correct_chemistry)*neg_chem;
float bio=(total_bio-r.correct_biology)*neg_bio;
float maths=(total_maths-r.correct_maths)*neg_math;
float total_neg=phy+chem+bio+maths;

if(isnegative==0)
{
	r.total_score=r.total_correct*10;

}
else if(isnegative==1)
{
		r.total_score=(r.total_correct*10)-total_neg;
		
		

}

printf("\n The total score is %f ",r.total_score);
r.percentage=r.total_score;
printf("\n The total percentage is %f ",r.percentage);
if(r.total_score>=50)
{
	r.status=1;
}
if(r.status==1)
{
	printf(" \n Pass");
}
else
{
	printf(" \n Fail");
}

	FILE *f;
	   f = fopen("result.dat", "ab");
	 fwrite (&r, sizeof(struct result), 1, f); 

fclose(f);
getche();







}

void search_result()
{
	
	FILE *fp;
struct result r;
int id,found=0;

fp=fopen("result.dat","rb");

printf("\nEnter the Student ID:");
scanf("%d",&id);

while(1)
{
fread(&r,sizeof(r),1,fp);

if(feof(fp))
{
break;
}
if(r.s_id==id)
{
found=1;
printf("\n The total attempeted mcqs are  %d:",r.total_attempted);
printf("\n The total correct mcqs are %d ",r.total_correct);
printf("\n The total wrong mcqs are %d",r.wrong);
printf("\n The total correct in biology %d",r.correct_biology);
printf("\n The total correct in chemistry %d",r.correct_chemistry);
printf("\n The total correct in physics %d",r.correct_physics);
printf("\n The total correct in maths %d",r.correct_maths);

printf("\n The total score  is %f",r.total_score);
printf("\n The total percentage is %f",r.percentage);
if(r.status==1)
{
	printf(" \n Pass");
}
else
{
	printf(" \n Fail");
}


}
}
if(found==0)
{
printf("\nSorry No Record Found");
}
fclose(fp);


		
	
	
	
	
	
	
	
	
}
void attempt_test(int id)
{
	
	
	struct result r={0};
	r.s_id=id;
	
	
	welcome_screen(id);
	
	FILE *fp;
struct mcq m;
int p=0,c=0,b=0,ma=0,i=0;
int qu_no=1;

while(1)
{

system("cls");
printf("%d",i);
printf("Please Enter The Subject Which you want to attempt \n Physics \n Maths \n Biology \n Chemisrty \n press e to go back  ");

printf("\n Enter the subject name : ");
fflush(stdin);
char sub[50];
gets(sub);

if(sub[0]=='e')
{
	break;
}
		if(strcmp(sub,"physics")==0 && p==0)
		{
		
		p=1;
			
		}
		else if(strcmp(sub,"chemistry")==0 && c==0) 
		{

		c=1;
		}
		else if(strcmp(sub,"biology")==0 && b==0)  
		{
		b=1
		;
		}
		else if(strcmp(sub,"maths")==0 && ma==0) 
		{
	ma=1;
		}



else
{
	
	system("cls");
	printf("Subject Already Attempted or Doesnt Exist");
	getche();

	continue;
	
	
	
}


fp=fopen("mcqs.dat","rb");

while(1)
{
fread(&m,sizeof(m),1,fp);

if(strcmp(m.subject,sub)==0)
{
	system("cls");
char correct=print_mcqs(m.q,m.a,m.b,m.c,m.d,m.subject,id,qu_no++);
	
	if(correct!='e')
	{
		r.total_attempted++;
	}
	if(correct==m.correct)
	{
		if(strcmp(m.subject,"physics"))
		{
			
			r.correct_physics++;
			
		}
		else if(strcmp(m.subject,"chemistry"))
		{
			r.correct_chemistry++;
		}
		else if(strcmp(m.subject,"biology"))
		{
			r.correct_biology++;
		}
		else if(strcmp(m.subject,"maths"))
		{
			r.correct_maths++;
		}
		r.total_correct++;
		
	}
	
	if(correct!=m.correct)
	{
		r.wrong++;
	}
}
if(feof(fp))
{
break;
}
}
fclose(fp);
printf("\n \n ");

printf("\n The test For  this subject ends here");
printf("\n Press any key to continue");
getche();
system("cls");





;

if(p==1 && ma==1 && c==1 && b==1)
{
break;
	
	
}

	
	
	
}

system("cls");

	printf("The Test has been ended");
	printf("\n \n press any key to generate result");
getche();
generate_result(r);	

}
	
	
	
	
	


	

int main()
{
maindisplay();	
int index_s=0;	

	struct student temp;
	
	while(1)
	{
system("cls");		
printf("\n \n \n \n \n ");

		menudisplay();

	char choice=getche();

	
	if(choice=='1')
	{
		
system("cls");
		printf("\n \n \n \n \n \t \t");
	printf("Please Enter The Password To Login : ");
	char pass[]={'a','d','m','i','n'};
	char s[50];
	gets(s);
	if(strcmp(s,pass)==0)
	{
while(1)
{
		
		system("cls");
		printf("\n \n \n \n \n \t \t \n ");
		printf(" 1 - Add MCQS \n ");
		printf(" 2 - Set Paper Pattern \n ");
		printf(" 3 - View All Students Records \n ");
		printf(" 4 - View Specific Record \n ");
		printf(" 5 - Update Record \n ");
		printf(" 6 - Delete Record \n ");
		printf(" 7 - View All Mcqs \n ");
				printf(" 8- View Result of Student \n");
				
		printf("  9 - Log Off \n ");
char c=getche();
system("cls");

	if(c=='1')
	{
		add_mcq();
		printf("MCQS ADDED ! \n Press Any Key!...");
	getche();
	}
	else if(c=='2')
	{
		
		system("cls");
		printf("\n \n \n \n \t");
		printf("Set The Exam pattern");
		printf("\n Is there any negative marking (y/n)");
		char c=getche();
		if(c=='y' || c=='Y')
		{
			isnegative=1;
printf("\n Please enter the negative marking for physics for per mcqs \n ");
scanf("%f",&neg_phy);
printf("Please enter the negative marking for chemisrty for per mcqs \n ");
scanf("%f",&neg_chem);
printf("Please enter the negative marking for biology for per mcqs  \n");
scanf("%f",&neg_bio);
printf("Please enter the negative marking for maths for per mcqs \n");
scanf("%f",&neg_math);
	
			
			
			
			
			
			
			
		}
		printf(" \n Press Any Key!...");
	getche();
	}
	else if(c=='3')
	{
		system("cls");
	display_students();	
		printf("\n Press Any Key!...");
	getche();

	}
	else if(c=='4')
	{
	
		system("cls");
	display_specific();
	printf("\n Press Any Key!...");
	getche();
	}
	else if(c=='5')
	{
		update_record();
			printf("\n Record Updated ! \n Press Any Key!...");
	getche();
	}
	else if(c=='6')
	{
		delete_record();
		printf("\n Record Delted \n Press Any Key!...");
	getche();
		
	}
	else if(c=='7')
	{
	display_mcqs();
	printf("\n Press Any Key!...");
	getche();
	
	}
	else if(c=='8')
	{
		search_result();
		getche();
	}
	else if(c=='9')
	{
		int k;
			printf("LOGGING OFF");
				for( k=0; k<6; k++)
				{
					printf("!");
					delay();
				}
		break;
		
	}
	
}
		
		
		
		
		
		
		
		
		
	}
	else
	{
		puts("Wrong password");
		printf("\n Press Any Key!..");
		getche();
	}
	
	
	
	
	
	
	
	}
	else if(choice=='2')
	{
		while(1)
		{
			
		
		system("cls");
			printf(" \n \t \t  \t 1-Register \n  ");
	printf(" \n \t \t  \t 2-Login \n ");
			printf(" \n \t \t  \t 3-Exit \n  ");	
	char c=getche();
	if(c=='1')
	{
		
		system("cls");
			printf(" \n \t \t  \t Enter id : ");
			
			scanf("%d",&temp.id);
		;
			printf(" \n \t \t  \t Enter name :");
					fflush(stdin);
					gets(temp.name);
			printf(" \n \t \t  \t Enter age : ");
			
			fflush(stdin);
			scanf("%d",&temp.age);
			printf(" \n \t \t  \t Enter semester : ");
					fflush(stdin);
		scanf("%d",&temp.semester);
			printf(" \n \t \t  \t Enter gender M or F :");
				fflush(stdin);
			scanf("%c",&temp.gender);
		register_student(temp);
	
		getche();
	}
	else if(c=='2')
	{
		system("cls");
		
		int id;
		printf("Enter the id to login :  ");
		scanf("%d",&id);
		
		if(loginstudent(id)==0)
		{
			printf("Login Sucesfful");
			getche();
printf("\n Press Any Key!...");
	 		attempt_test(id);
		}
		else
		{
			printf("Account Doesnt Exist \n Press Any To Continue");
			getche();
			
		}
	}
	
	else if(c=='3')
	{
break;		
	}
}
	}
	else if(choice=='3')
	{
		exit(0);
	}
	
	
	
}
}
