#include <QCoreApplication>
#include <QTextStream>
#include <QPair>
#include <iostream>
#include <QFile>
#include <QtDebug>
#include <ctime>
#include <cstdlib>
#include "tasks_rk1.h"


using namespace std;

void task_4()
{
    buildTree(5);
    }


void task_1()
{
   WorkWithFile test;
   test.writeStatInfoToFile("result_task1");
}

void task_2()
{
    result(22);

}
void task_3()
{
    char * k = convertBinToHex("0x30 0x31 0x31 0x30 0x30 0x31 0x30 0x31 0x30 0x31 0x31 0x30 0x31 0x30 0x30 0x31 0x30 0x31 0x30 0x31 0x31 0x30 0x31 0x30 0x30 0x31 0x30 0x31 0x30 0x31 0x31 0x31");
    for(int i=0;i<32;i++)
    {
        cout<<k[i];
    }
    WritetoFile3(k,"result_task3");
};
/////////////////


void task_5() {
float arr[12];
RandomFillarray(arr,12);
WritetoFile5(averStr2DArray(arr,3,4));
}


void task_6()
{
    LinkedList test;
    test.push_back("Andre");
    test.push_back("Pavel");
    test.push_back("Timur");
    test.push_back("Kirill");
    test.push_back("Daniil");
    test.push_back("Vladimir");
    test.WriteToFileFromHead();
    test.WriteToFileFromTail();

}

void task_7()
{
    LinkedList test;
    test.push_back("Andre");
    test.push_back("Pavel");
    test.push_back("Timur");
    test.push_back("Kirill");
    test.push_back("Daniil");
    test.push_back("Vladimir");
    cout<<endl;
   // test.getcount();
    test.show();
    cout<<endl;
    test.insert("Vstavka",3);
    cout<<"after insert"<<endl;
    test.show();
}

void task_8()
{
    StudentInfo test("Nedosekin", "Vadim", "2048534 - Number");
    test.addSubj("Russian");
    test.addMark("Russian",5);
     test.addMark("Russian",4);
      test.addMark("Russian",3);
      test.addSubj("Eng");
      test.addMark("Eng",4);
       test.addMark("Eng",4);
        test.addMark("Eng",3);
         test.addMark("Russian",6);
      cout<<endl;
    test.addMark("Eng",5);
     test.printInfoStudent();
     test.writeAllInfoToFile();

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    task_1();
    //cout<<fileData.size();


    task_2();
    //////////
    cout<<"task 3 :  ";
    task_3();
    ////////
     cout<<endl;
cout<<"task_4 :";
cout<<endl;
    task_4();
    ///

task_5();
      ///
      ///
     task_6();

   task_7();

    task_8();
    return 0;
}
