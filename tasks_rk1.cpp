#include "tasks_rk1.h"
#include "QFile"
#include <QCoreApplication>
#include <QTextStream>
#include <QPair>
#include <iostream>
#include <QFile>
#include <QtDebug>
#include <ctime>
#include <cstdlib>
#include <tuple>
using namespace std;
void WorkWithFile::WriteToFile(int ar[],const char* outFile)
{
    QFile ff (outFile);
    if(ff.open(QIODevice::WriteOnly))
    {
    QTextStream out (&ff);
    for ( int i =0;i<=255;i++)
    out << char(i)<< "\t"<<ar[i]<<"\n";
    }
    ff.close();
}
void WorkWithFile::ReadFromFile(const char *fileName)
{
    QFile f(fileName);
    if(f.open(QIODevice::ReadOnly))
    {

     fileData = f.readAll();
}

    f.close();
}
//void WorkWithFile::prepareTestFile(const char *filename)
//{
//    QFile f2(filename);
//    if(f2.open(QIODevice::WriteOnly))
//    {
//        QTextStream out(&f2);
//        for(int i =0; i<100;i++)
//        {
//            const char ch = randomRange('a', 'z');
//                    out << ch;
//        }
//    }
//    f2.close();
//}
//int WorkWithFile::randomRange(int low, int high)
//{
//    return rand() % (high - low + 1) + low;
//}
void WorkWithFile::writeStatInfoToFile(const char *outFile)
{
    //prepareTestFile("sourceFile_task1.txt");
    ReadFromFile("sourceFile_task1");

    int ar[256];
    memset(&ar[0], 0x00, sizeof(int) * 256);

    for (int i = 0; i < fileData.size(); i++) {
        ar[int(fileData[i])]++;
    }

    WriteToFile(ar, outFile);
}

WorkWithFile::WorkWithFile()
{

}
WorkWithFile::~WorkWithFile()
{

}
////////////////////

char binNumb[32];
char* convertDecToBin(int num) {
   memset(binNumb, 0x00, 32 * sizeof(int));

   for (int i = 0; i < 32; i++) {
       binNumb[i] = ((num & 1 << i)) ? 0x31 : 0x30;
   }
   int count = 31;
   char temp[32];
   for(int i=0;i<32;i++,count--)
   {

       temp[i]=binNumb[count];

   }
   for(int i=0;i<32;i++)
   {

       binNumb[i]=temp[i];

   }

   return binNumb;
}
void writeToFile(char* numb,const char* filename){
   QFile f(filename);
   if(f.open(QIODevice::WriteOnly))
   {
       QTextStream out (&f);
       for(int i =0;i<32;i++)
       {
          out << numb[i];
       }

   }
   f.close();
}

void result(int i) {
   convertDecToBin(i);
   writeToFile(binNumb,"result_task2");
   qDebug() << "task 2 :" <<binNumb;

}

/////////////////////

char* convertBinToHex( const  char* binNum)
{
    int k=0;
    int temp[32];
    char* tempforcheck = new  char[4];
    tempforcheck[0]='2';
    tempforcheck[1]='2';
    tempforcheck[2]='2';
    tempforcheck[3]='2';
    for(int i=0;i<159;i++)
    {
        for(int j=0;j<4;j++)
        {
           tempforcheck[j]=binNum[i];

           if(tempforcheck[0] == '0' && tempforcheck[1] == 'x'&& tempforcheck[2] == '3'&& tempforcheck[3] == '1')
           {

               temp[k]=1;
           }
           if(tempforcheck[0] == '0' && tempforcheck[1] == 'x'&& tempforcheck[2] == '3'&& tempforcheck[3] == '0')
           {

               temp[k]=0;
           }

           if(j==3)
           {
              i = i+1;
              k++;
              tempforcheck[0]='2';
              tempforcheck[1]='2';
              tempforcheck[2]='2';
              tempforcheck[3]='2';
           }
           else
           {
           i++;
           }

        }
    }
    int summ=0;
    int up =31;
    char* resulttask3= new char[32];
    for(int i=0;i<32;i++)
    {
        resulttask3[i]='0';
    }
    int count=0;
    int c;
    char* albeforeten= new char[10]{'0','1','2','3','4','5','6','7','8','9'};
    char* alafterten= new char[6]{'A','B','C','D','E','F'};
    for(int i=0 ;i<32;i++,up--,count++)
    {
       summ +=  temp[i] * pow(2,up);
    } 
   count =0;
    while(summ!=0)
    {

         c = abs(summ % 16);
         if(c<10)
         {
             resulttask3[count]= albeforeten[c];
         }
         else
         {
             resulttask3[count]= alafterten[c-10];
         }
        summ/=16;
        count++;
    }
    char tmp[32];
    count=31;
    for(int i=0;i<32;i++,count--)
    {
        tmp[i]=resulttask3[count];
    }
    for(int i=0;i<32;i++,count--)
    {
        resulttask3[i]= tmp[i];
    }
    delete [] albeforeten;
    delete [] alafterten;
    delete [] tempforcheck;
    return resulttask3;

}
void WritetoFile3(char* numb,const char* filename){
    QFile f(filename);
    if(f.open(QIODevice::WriteOnly))
    {
        QTextStream out (&f);
        for(int i =0;i<32;i++)
        {
           out << numb[i];
        }

    }
    f.close();
}


/////////////////////////

void buildTree(int height)
{
    for (int i = 0; i < height; i++)
        {
            for (int j = 1; j < height - i; j++)
            {
                cout << ' ';
            }

            for (int j = height - 2 * i; j <= height; j++)
            {
                cout << '*';
            }
            cout << endl;
        }
    }

/////////////////////////////

void RandomFillarray (float *arr, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
}

QVector<float>  averStr2DArray(float* ar, int height, int weight) {
QVector<float> averStr;

for (int i = 0; i < height; i++) {
float averStr_temp = 0;
for (int j = 0; j < weight; j++) {
averStr_temp += ar[i*weight + j] / weight;
}

averStr.push_back(averStr_temp);
}


return averStr;
}
void WritetoFile5(QVector <float> vec)
{
QFile f("result_task5");
if(f.open(QIODevice::WriteOnly))
{
    QTextStream out (&f);
    for(int i =0;i<vec.size();i++)
    {
       out << i+1<< "\t"  << vec[i]<<"\n";
    }

}
f.close();
}
///////////////////

void LinkedList:: push_back (const char* p)
         {
              count++;
             Node* temp = new Node(p);

             temp->next= nullptr;
             temp->prev= tail;
             if(tail!=nullptr)
             {
                 tail->next = temp;
            }
            if(head==nullptr)
                  head = tail = temp;
            else
                tail = temp;

         }

void LinkedList:: show ()
   {
       Node* tempnode= head;
       while(tempnode!=nullptr)
       {
           cout<<tempnode->k->str<<"\n";
           tempnode=tempnode->next;

       }
       delete tempnode;
   }

void LinkedList:: WriteToFileFromHead()
    {
    int i=1;
        Node* tempnode = head;
        QFile f("result_task6HEAD");
        if(f.open(QIODevice::WriteOnly))
        {
            QTextStream out (&f);
            while (tempnode!=nullptr)
            {
                out<< i <<"\t" << tempnode->k->str<<"\n";
                tempnode = tempnode->next;
                i++;
            }
        }
f.close();
    }

void LinkedList:: WriteToFileFromTail()
    {
    int i=1;
        Node* tempnode = tail;
        QFile f("result_task6TAIL");
        if(f.open(QIODevice::WriteOnly))
        {
            QTextStream out (&f);
            while (tempnode!=nullptr)
            {
                out<< i <<"\t" << tempnode->k->str<<"\n";
                tempnode = tempnode->prev;
                i++;
            }
        }
f.close();
    }

void LinkedList :: insert(const char* p, int position)
{
    if(position<=1)
    {
        count++;
        Node* temp = new Node(p);
        temp->prev=nullptr;
        temp->next = head;
        head= temp;
    }
    else
    {
    if(position>count)
    {
        push_back(p);
    }
    else
    {
        count++;
        Node* temp = new Node(p);
        if(head==nullptr)
{
            head =temp;
            tail=head;
            temp->next=nullptr;
        }
        else
        {
            Node* tmp;
            Node* temp = new Node(p);
            Node* search = head;
        for(int i=1;i<position;i++)
        {
          search = search->next;
        }
        tmp=search->prev;
        search->prev->next=temp;
        search->prev=temp;
        temp->next=search;
        temp->prev= tmp;
        }
    }
    }
}
 void LinkedList::getcount()
{
    cout<<count;
}
LinkedList::LinkedList()
{
    head=nullptr;
    tail=nullptr;

    count=0;
}
LinkedList::~LinkedList()
{
    while (head)
        {
            tail = head->next;
            delete head;
            head = tail;
}
}
                               /////////// task7



///

StudentInfo::StudentInfo(QString f,QString n,const char* number)
{
  info = tie(f,n,number) ;
}
StudentInfo::~StudentInfo()
{

}
int  StudentInfo::addSubj(const QString &subjName)
{
    QMap<QString,QPair<QList<int>,float>>::iterator i;
    for(i=subjMark.begin();i!=subjMark.end();i++)
    {
        if(subjName==i.key())
        {
        return 1;
        }
    }

    QPair<QList<int>,float> lst;
    this->subjMark.insert(subjName,lst);
    return 0;
}

int StudentInfo::addMark(const QString &subjName, int mark)
{
    QMap<QString,QPair<QList<int>,float>>::iterator i;
    for(i=subjMark.begin();i!=subjMark.end();i++)
    {
        if(subjName==i.key())
        {
          i.value().first.push_back(mark);
          //cout<<"Dobavil";
           return 0;
        }
    }
    //cout<< "net takogo";
    return 1;

}


float StudentInfo::getAverMark(const QString &subjName)
{
    QMap<QString,QPair<QList<int>,float>>::iterator i;
    for(i=subjMark.begin();i!=subjMark.end();i++)
    {
        if(subjName==i.key())
        {

           QList<int>::Iterator k;
           float average=0;
            for(k=i.value().first.begin();k!=i.value().first.end();k++)
            {
                average+= *k;


            }
            average/=i.value().first.size();
            i.value().second=average;
            return average;

        }
    }
    return 1;
}
void StudentInfo::printInfoStudent()
{
    QString fam = get<0>(info);
    QString name = get<1>(info);
    QString numberbook = get<2>(info);
    cout<<fam.toStdString()<<"\t"<<name.toStdString()<<"\t"<<numberbook.toStdString()<<endl;
    QMap<QString,QPair<QList<int>,float>>::iterator i;
    for(i=subjMark.begin();i!=subjMark.end();i++)
    {
        QString pr = i.key();
        cout<<pr.toStdString()<<"\t";
        foreach(int value,i.value().first)
        {
            cout <<"\t"<< value;
        }
        getAverMark(i.key());
        cout<<" average - "<<i.value().second;
        cout<<endl;

    }

}
void StudentInfo::writeAllInfoToFile()
{
    QFile f("result_task8");
    if(f.open(QIODevice::WriteOnly))
    {
        QTextStream out (&f);
        out<<get<0>(info)<<"\t"<<get<1>(info)<<"\t"<<get<2>(info)<<"\n";
          QMap<QString,QPair<QList<int>,float>>::iterator i;
        for(i=subjMark.begin();i!=subjMark.end();i++)
        {
            out<<i.key()<<"\t";
            foreach(int value,i.value().first)
            {
                out <<"\t"<< value;
            }
            getAverMark(i.key());
            out<<" average - "<<i.value().second;
            out<<"\n";

        }

    }
    f.close();
}


