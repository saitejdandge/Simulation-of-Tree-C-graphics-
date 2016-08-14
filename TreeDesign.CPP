#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
int SIZE=6;
void check(int  );
int flag2=0;
void display();
class tree
{

	public :
	int x,y;
char name;
tree *l,*r;
int index;
tree()

{
	x=0;
	y=0;

	l=NULL;
	r=NULL;


}
}
;
void fun(tree *);
void fun2(tree *);
void fun3(tree *);
tree ob[100];
int main()
{
	int gm,gd=DETECT;
	initgraph(&gm,&gd,"C:\\turboc3\\bgi");
	int flag=0;
	char key;

for(int abc=0;abc<100;abc++)
{

ob[abc].name='0';
}
	ob[0].name='a';
	ob[1].name='b';
	ob[2].name='c';
	ob[3].name='d';
	ob[4].name='e';
	ob[5].name='f';
	ob[1].l=&ob[5];
	ob[2].l=&ob[3];
	ob[2].r=&ob[4];
	ob[0].l=&ob[1];
	ob[0].r=&ob[2];
	
	    ob[0].x=300;ob[0].y=50;

 for(int i=0;i<SIZE;i++)

 {
  for(int j=0;j<SIZE;j++)
  {
   if(i==j)
   continue;
   else
   {
    if(ob[i].l==&ob[j])
    {
      ob[j].x=ob[i].x-50;
	    ob[j].y=ob[i].y+50;


    }
    else  if(ob[i].r==&ob[j])
    {
   ob[j].x=ob[i].x+50;
   ob[j].y=ob[i].y+50;

    }
   }
  }

 }




display();

	char user='y';
    while(user!='n')


    {

	cout<<"\nENTER THE NAME OF THE OBJECT TO PLACE NEW ELEMENT :\n";
	cin>>key;
	for(int i=0;i<SIZE;i++)
	{

		if(ob[i].name==key )
		{
			flag=1;
			label:
			cout<<"\nenter l for left pointer and r for right pointer \n";
			char ch;
			cin>>ch;
			if(ch=='l')
			{
				if(!(ob[i].l==NULL))
				{
				cout<<"\nLEFT POINTER OF "<<ob[i].name<<"PREOCCUPIED\n";
				getch();
				break;
				}
				else
				{
					cout<<endl;
					cout<<"\nENTER THE NAME OF THE NEW OBJECT TO BE ADDED \n";

					cin>>ob[SIZE].name;
					ob[SIZE].l=NULL;
					ob[SIZE].r=NULL;
					ob[SIZE].x=ob[SIZE].y=0;

					ob[i].l=&ob[SIZE];

					SIZE++;
					break;
				}
			}
			else if(ch=='r')
			{







				if(!(ob[i].r==NULL))
				{
				cout<<"\nRIGHI POINTER OF "<<ob[i].name<<" PREOCCUPIED\n";
				getch();
				break;

				}
				else
				{
					cout<<"\nENTER THE NAME OF THE NEW OBJECT TO BE ADDED \n";

					cin>>ob[SIZE].name;
					ob[SIZE].l=NULL;
					ob[SIZE].r=NULL;

					ob[SIZE].x=ob[SIZE].y=0;
					ob[i].r=&ob[SIZE];
					SIZE++;
					break;
				}
			}
			else
			{
			 cout<<"\nenter either l or r :\n";
			 goto label;
			}
			}









		}

	if(flag==0)
	{
		cout<<"\nelement not found try agian :\n";
		getch();
	}
      //	ob[0].p=&ob[0];
       //	tree *base=&ob[0];
 display();
	cout<<"\nenter n to exit :\n";
	cin>>user;

  }
       //	fun(base);


       //	fun((m->p)->r);
cout<<endl<<endl<<endl;


return 0;
}
void display()

{
		    clrscr();

			    char *p ;
 for(int i=0;i<SIZE;i++)

 {
  for(int j=0;j<SIZE;j++)
  {
   if(i==j)
   continue;
   else
   {
    if(ob[i].l==&ob[j])
    {
 //   cout<<"left of "<<ob[i].name<<"is "<<ob[j].name<<endl;
	if(ob[j].x==0&&ob[j].y==0)
	{
	    ob[j].x=ob[i].x-50;
	    ob[j].y=ob[i].y+50;
	}
	check(j);
	setbkcolor(BLACK);
   //	cout<<ob[j].x<<ob[j].y<<endl;
if(j==RED||j==BLACK||j==BLUE||j==GREEN||j==CYAN||j==MAGENTA||j==BROWN)
   setcolor(j);
   line(ob[i].x,ob[i].y,ob[j].x,ob[j].y);

    }
    else  if(ob[i].r==&ob[j])
    {


	    if(ob[j].x==0&&ob[j].y==0)
	    {
	    ob[j].x=ob[i].x+50;
	    ob[j].y=ob[i].y+50;
	    }
	    check(j);
	    setbkcolor(BLACK);
	    if(j==RED||j==BLACK||j==BLUE||j==GREEN||j==CYAN||j==MAGENTA||j==BROWN)
	    setcolor(j);
	     line(ob[i].x,ob[i].y,ob[j].x,ob[j].y);


    }

   }
  }

 }

cout<<"\nAVAILABLE OBJECTS ARE :\n";
	 for(int v=0;v<SIZE;v++)
	 cout<<ob[v].name<<endl;
	 setcolor(BLACK);
		    for( v=0;v<SIZE;v++)
			      {
			     *p=ob[v].name;
			     putpixel(ob[v].x,ob[v].y,RED);
		    circle(ob[v].x,ob[v].y,10);
		    outtextxy(ob[v].x,ob[v].y,p);
		    }

	   cout<<endl<<"PREORDER :";
	   fun(&ob[0]);

	   cout<<endl<<"POSTORDER :";
	   fun2(&ob[0]);



	   cout<<endl<<"INORDER :";
	   fun3(&ob[0]);
}


void check(int a)
{



for(int yz=0;yz<SIZE;yz++)
{
if(a==yz)
continue;

else if(ob[a].x==ob[yz].x&&ob[a].y==ob[yz].y)
 {
 ob[a].x-=30;
 ob[a].y-=30;
 }

}
}

void fun(tree *ptr)
{

 if(ptr->l!=NULL&&ptr->r!=NULL)
 {
  if(ptr->name!='0')
  cout<<ptr->name;

  fun(ptr->l);

  fun(ptr->r);
 }
 else
 {

 if(ptr->l==NULL&&ptr->r==NULL)
 {
 if(ptr->name!='0')
  cout<<ptr->name;


 }
 else if(ptr->l==NULL||ptr->r==NULL)
 {
  if(ptr->l==NULL)
  {
  if(ptr->name!='0')
  cout<<ptr->name;
  fun(ptr->r);
  }
 else
 {
 if(ptr->name!='0')
cout<<ptr->name;
 fun(ptr->l);
 }
  }
 //}
 }

}

void fun2(tree *ptr)
{

 if(ptr->l!=NULL&&ptr->r!=NULL)
 {
  if(ptr->name!='0')


  fun2(ptr->l);

  fun2(ptr->r);
  cout<<ptr->name;
 }
 else
 {

 if(ptr->l==NULL&&ptr->r==NULL)
 {
 if(ptr->name!='0')
  cout<<ptr->name;


 }
 else if(ptr->l==NULL||ptr->r==NULL)
 {
  if(ptr->l==NULL)
  {

  fun2(ptr->r);
  if(ptr->name!='0')
  cout<<ptr->name;
  }
 else
 {
 fun2(ptr->l);


 if(ptr->name!='0')
cout<<ptr->name;
 }
  }
 //}
 }

}

void fun3(tree *ptr)
{

 if(ptr->l!=NULL&&ptr->r!=NULL)
 {
  fun3(ptr->l);
  cout<<ptr->name;
  fun3(ptr->r);

 }
 else
 {

 if(ptr->l==NULL&&ptr->r==NULL)
 {
 if(ptr->name!='0')
  cout<<ptr->name;


 }
 else if(ptr->l==NULL||ptr->r==NULL)
 {
  if(ptr->l==NULL)
  {
     cout<<ptr->name;
  fun3(ptr->r);

  }
 else
 {






 fun3(ptr->l);

 cout<<ptr->name;
 }
  }

 }

}