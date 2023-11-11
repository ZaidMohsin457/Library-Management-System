#include<iostream>
#include<fstream> // for files handling
#include<conio.h> // compiler wait for any key input from user
using namespace std;
void add();
void search();
void delette();
void booklist();
int main()
{
    system("cls");
    int a;
    cout<<"\n\t**********Library Management System Project**********\n";
    cout<<"\n\t\t*** CS101 Lab Project***\n\n\n";
    cout<<"\t1.View the Booklist\n\n";
    cout<<"\t2.Search for a book\n\n";
    cout<<"\t3.Add a book\n\n";
    cout<<"\t4.Delete a book\n\n";
    cout<<"\t5.Exit program\n\n\t";
    cin>>a;
    if(a==1)
    booklist();
    else if(a==2)
    search();
    else if(a==3)
    add();
    else if(a==4)
    delette();
    else if(a==5)
    exit(0);

}
void add()
{   
    system("cls");
    string bookname1,bookname;
    int p,q,y=0;
    fflush(stdin);
    cout<<"\n\t\tEnter the details :-\n";
    cout<<"\n\t\tEnter Book's Name : ";
    getline(cin,bookname);
    cout<<"\n\t\tEnter Shelf number : ";
    cin>>q;
    if(q>10 || q==0)//shelf no. limited to 10
    {
    cout<<"\n\tError Please Enter Shelf Number from 1-10\n";
    cout<<"\n\t\tEnter Shelf number Again: ";
    cin>>q;
    }
    ifstream intf("Booksdata.txt");
    while(!intf.eof())
    {       
        getline(intf,bookname1);
        if(bookname==bookname1)//searching book if already present in file
        {   
            y++;
            break;
        }
    }
    intf.close();//file is closing
    
    if(y==1)
    cout<<"\n\tBook already existed...";

    else
    {
    ofstream out("Booksdata.txt",ios::app);
    out<<bookname<<endl;
    out<<q<<endl;
    out.close();

    cout<<"\n\t\tBook added Successfully.\n";
    }
    cout<<"\n\n\t\tPress Any key to continue......";
    getch();
    system("cls");

    cout<<"\n\t1.Add new book.\n";
    cout<<"\n\t2.Main menu:\n";
    cout<<"\n\t3.Exit the program.\n\t";
    cin>>p;
    if(p==1)
    add();
    else if(p==2)
    main();
    else if(p==3)
    exit(0);
    
}
void search()
{
    string bookname,ch;
    int q,y=0,p;
    system("cls");
    fflush(stdin);
    cout<<"\n\t\tEnter Book's Name : ";
    getline(cin,ch); //allows for spaces between words

    ifstream intf("Booksdata.txt"); //for opening a file
    for(int j=1;intf.eof()==0;j++) // loop runs till end of file is achieved
    {       
        getline(intf,bookname); //transfering of data from file to program 
        if(ch==bookname)
        {   
            y++; //if book found then y=1
            break;
        }
    }
    intf>>p; // transfering shelf number from file to program
    intf.close(); // file closed
    
    if(y!=0)
    {
        cout<<"\n\t\tBook is available :)"<<endl;
        cout<<"\n\t\tShelf number is: "<<p;
    }
    else
    cout<<"\n\t\tBook not found :(";
    cout<<"\n\n\t\tPress Any key to Continue.....";
    getch(); // compiler waiting for entering of any key
    system("cls"); //new interface

    cout<<"\n\n\t1.Search new book.\n";
    cout<<"\n\t2.Main menu:\n";
    cout<<"\n\t3.Exit the program.\n\t";
    cin>>q;
    if(q==1)
    search();
    else if(q==2)
    main();
    else if(q==3)
    exit(0);
}

void delette()
{
    string a,b;
    int p;
    system("cls");
    
    for(int i=1;i<=10;i++)
    {
        cout<<"***** Shelf Number : "<<i<<" ********"<<endl;
        ifstream books("Booksdata.txt"); // file is opening to trasfer data from file to program
        while(!books.eof())
        {
            getline(books,a);// gets first line of file
            getline(books,b);// gets second line of file
            if(!a.empty() && !b.empty())//checking if strings are not empty
            {
            int num=stoi(b);// coverting string into integer
            if(num==i)// num is equal to i
            {
                cout<<"Book Name : "<<a<<"\n";
            }
            }
        }
        cout<<endl;
        books.close();
    }
    int c=1,i=0,q;
    string delet,bookname,tru;
    fflush(stdin); // take both inputs
    cout<<"\nEnter Book Name : ";
    getline(cin,delet);

    ifstream intf("Booksdata.txt");
    while(!intf.eof())
    {       
        getline(intf,bookname);
        if(delet==bookname)
        {   
            i++;
            break;
        }
        c++; //line number in file
    }
    intf.close();
    if(i!=0)
    {
        ifstream tr("Booksdata.txt"); //data transfering from file to program
        ofstream temp("temp.txt",ios::app); // data trasfering from program to file
        int z=1;
        while(!tr.eof())
        {
            getline(tr,tru); // input from file to string tru
            if(z!=c && z!=c+1)
            {
            temp<<tru<<endl; //tru is transfering to temp
            }
            z++;
        }
        temp<<endl;
        tr.close();
        temp.close();
        remove("Booksdata.txt");
        rename("temp.txt","Booksdata.txt");
        cout<<"\n\t\tDeletion Succesfull...\n";
    }
    else
    cout<<"\n\tBook not found:(\n";

    cout<<"\n\tPress Any key to Continue...\n";
    getch();
    system("cls");

    cout<<"\n\n\t1.Delete other book.\n";
    cout<<"\n\t2.Main menu:\n";
    cout<<"\n\t3.Exit the program.\n\t";
    cin>>q;
    if(q==1)
    delette();
    else if(q==2)
    main();
    else if(q==3)
    exit(0);
}
void booklist()
{
    string a,b;
    int p;
    system("cls");
    
    for(int i=1;i<=10;i++)
    {
        cout<<"***** Shelf Number : "<<i<<" ********"<<endl;
        ifstream books("Booksdata.txt"); // file is opening to trasfer data from file to program
        while(!books.eof())
        {
            getline(books,a);// gets first line of file
            getline(books,b);// gets second line of file
            if(!a.empty() && !b.empty())//checking if strings are not empty
            {
            int num=stoi(b);// coverting string into integer
            if(num==i)// num is equal to i
            {
                cout<<"Book Name : "<<a<<"\n";
            }
            }
        }
        cout<<endl;
        books.close();
    }
    
    cout<<"Press Any key to Continue......";
    getch();

    system("cls");
    cout<<"\n\t1.Main Menu";
    cout<<"\n\t2.Exit the program\n\t";
    cin>>p;
    if(p==1)
    main();
    else if(p==2)
    exit(0);
}
