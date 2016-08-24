#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Prototypeģʽ��һ�ֶ��󴴽���ģʽ������ȡ����ԭ�Ͷ���ķ��������������ʵ����ʹ��Prototypeģʽ������ʵ����������ԭ��һ�������ݡ�
// 1����ԭ�Ͷ���������Ŀ�����Ҳ����˵�����󴴽���һ��������ԭ�Ͷ�����
// 2��Ŀ�������ԭ�Ͷ����һ����¡��Ҳ����˵��ͨ��Prototypeģʽ�����Ķ��󣬲�������ԭ�Ͷ��������ͬ�Ľṹ������ԭ�Ͷ��������ͬ��ֵ��
// 3�����ݶ����¡��Ȳ�εĲ�ͬ����ǳ�ȿ�¡����ȿ�¡��

// ԭ��ģʽ��Ҫ��Ե������ǣ���ĳЩ�ṹ���ӵĶ��󡱵Ĵ�����������������ı仯����Щ���󾭳������ž��ҵı仯����������ȴӵ�бȽ��ȶ�һ�µĽӿڡ�
// ���������
// һ�����Ӷ��󣬾������Ҹ��ƹ��ܣ�ͳһһ�׽ӿڡ�

class Person {
public:
  virtual Person* Clone() = 0;
  virtual void Show() = 0;
};

class Programmer : public Person {
public:
  Programmer(const string& name, int age)
    : age_(age)
    , name_(name)
    , resume_(NULL) {
  }

  ~Programmer() {
    if (resume_ != NULL) {
      delete resume_;
    }
    resume_ = NULL;
  }

  Programmer(const Programmer& programmer) {
    age_ = programmer.age_;
    name_ = programmer.name_;

    resume_ = new char[strlen(programmer.resume_) + 1];
    strcpy(resume_, programmer.resume_);
  }

  void set_resume(const char* resume) {
    // ��ֹ�ڴ�й©��setһ���µ�ֵ֮ǰһ��Ҫ��ԭ����ֵdelete����
    if (resume_ != NULL) {
      delete resume_;
      resume_ = NULL;
    }

    if (resume == NULL) {
      return;
    }

    resume_ = new char[strlen(resume) + 1];
    strcpy(resume_, resume);
  }

// �ص�һ��
  Person* Clone() override {
    // Person* person = new Programmer("", 0);
    // ������ظ���ָ��person����ô*person = *this��һ���ͻ�������⣬��Ϊ��ֵֻ��ֵ�˸���ı������������û�г�Ա������
    // ������һ���൱��û����

    Programmer* person = new Programmer("", 0);
    *person = *this;  //ǳ����
    // Programmer* person = new Programmer(*this);  // ���
    return person;
  }

  void Show() override {
    if (resume_ == NULL) {
      resume_ = new char[1];
      resume_[0] = 0;
    }
    cout << name_ << " : " << age_ << " : " << resume_ << endl;
  }

private:
  string name_;
  int age_;
  char* resume_;
};

int main15() {
  Person* person1 = new Programmer("Miki", 16);
  ((Programmer*)person1)->set_resume("ABC");
  person1->Show();

  Person* person2 = person1->Clone();
  person2->Show();

// �ص����
  ((Programmer*)person1)->set_resume("ABCD");
  person1->Show();  // person1��resumeָ���µ��ڴ�ռ䣬ԭ�����Ѿ�delete�ˡ�
  person2->Show();  // person2����ָ��ԭ��person1ָ����ǿ��ڴ棬���Գ������롣

  delete person1;  // delete person1֮��resumeָ��գ�����ǳ��������person2��resumeָ���ΪҰָ�롣
  person2->Show();
  delete person2;

  return 0;
}
