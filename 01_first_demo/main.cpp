#include <iostream>
using namespace std ;

class Student{
public:
    Student();
    Student(char *name,int age);
    ~Student();

    char*  get_name(){
        return this->name;
    }
    int get_age(){
        return this->age;
    }
    void set_name(char* name){
        this->name=name;
    }
    void set_age(int age){
        this->age=age;
    }

    void to_string(){
        cout<<"姓名"<<this->name<<",年龄"<<this->age<<endl;
    }
    virtual void have_classing(){};
private:
    char* name;
    int age;
};
Student::Student()
{
    cout<<"无参构造函数"<<endl;
}

Student::Student(char *name,int age)
{
    this->name=name;
    this->age=age;
    cout<<"有参构造函数"<<endl;
}



Student::~Student()
{
    cout<<"析构函数"<<endl;
}


class MStudent:public Student{
private:
    char *sex="M";
public:
    void set_sex(char *sex){
        this->sex=sex;
    }
    char* get_sex(){
        return this->sex;
    }
    void to_string(){
        cout<<"姓名"<<this->get_name()<<",年龄"<<this->get_age()<<",性别"<<this->sex<<endl;
    }
    void have_classing(){
        cout<<this->get_sex()<<"正在上课"<<endl;
    }
};
class FStudent:public Student{
private:
      char *sex="F";
public:
    void set_sex(char *sex){
        this->sex=sex;
    }
    char* get_sex(){
        return this->sex;
    }
    void to_string(){
        cout<<"姓名"<<this->get_name()<<",年龄"<<this->get_age()<<",性别"<<this->sex<<endl;
    }
    void have_classing(){
        cout<<this->get_sex()<<"正在上课"<<endl;
    }

};

int main(){

    cout<<"************************"<<endl;
    Student *my1=new Student("my1",18);
    my1->to_string();
    my1->set_age(20);
    my1->to_string();
    cout<<"************************"<<endl;
    MStudent *m=new MStudent();
    m->set_age(22);
    m->set_name("mm");
    m->to_string();
    m->have_classing();

    cout<<"************************"<<endl;
    FStudent *f=new FStudent();
    f->set_age(22);
    f->set_name("ff");
    f->to_string();
    f->have_classing();


    delete my1;



}
