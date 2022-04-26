#ifndef TASKS_RK1_H
#define TASKS_RK1_H

#endif // TASKS_RK1_H
#include <QVector>
#include <QString>
#include <tuple>
#include <QMap>
#include <QPair>
#include <QList>
char* convertDecToBin(int num) ;
void WritetoFile(char* numb);   ///task2
void result(int i);


char* convertBinToHex( const char* str);
void WritetoFile3(char* numb,const char* filename); /// task3


void buildTree(int height); /// task4


void RandomFillarray(float *arr, int n );
QVector<float>  averStr2DArray(float* ar, int height, int weight);  //task 5
void WritetoFile5(QVector <float> vec);



struct Data
{
    const char* str;
};
struct Node
{
    Node* next;
    Node* prev;
    Data * k;
public:
    Node(const char* d)
    {
       this->k =new Data;
        this->k->str=d;
    }
    ~Node()
    {
        delete k;
    }
};




class LinkedList
{
private:
    Node* head;
       Node* tail;
       int count;
public:
    LinkedList();
    ~LinkedList();
    void getcount();
      void push_back (const char* p);
      void show();
      void insert(const char* p, int position);
       void Writetofilehead();
       void Writetofiletail();
};                                                        //task 6





class WorkWithFile
{
private:
    QByteArray fileData;
    void ReadFromFile(const char* fileName);
     void  prepareTestFile(const char* filename);
     void WriteToFile(int ar[],const char* outFile);
     int randomRange(int low, int high);
public:
    WorkWithFile();
    ~WorkWithFile();
    void writeStatInfoToFile(const char* outFile);
};                                                              //task 1

/////


class StudentInfo{
private:

    std::tuple<QString,QString,const char*> info;
    QMap<QString,QPair<QList<int>,float>> subjMark;
public:
   StudentInfo(QString,QString,const char*);
   ~StudentInfo();
   int addSubj(const QString& subjName);
   int addMark(const QString& subjName, int mark);
   float getAverMark(const QString& subjName);
   void printInfoStudent();
   void writeAllInfoToFile();

};

