#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

// FlyweightģʽҲ����Ԫģʽ���ǹ�����ģʽ֮һ����ͨ�����������ƶ�������������С�ڴ�ռ�á�

// ������Ԫ��ɫ��
// ���о�����Ԫ��ĸ��࣬�涨һЩ��Ҫʵ�ֵĹ����ӿڡ�
// ������Ԫ��ɫ��
// ������Ԫ��ɫ�ľ���ʵ���࣬��ʵ���˳�����Ԫ��ɫ�涨�ķ�����
// ��Ԫ������ɫ��
// ���𴴽��͹�����Ԫ��ɫ��

// ʹ�ó�����
// ���Թ���ķ�ʽ����Ч��֧�ִ�����ϸ���ȵĶ���

class Teacher {
public:
  Teacher(const string& name, int age, const string& id)
    : name_(name)
    , id_(id)
    , age_(age) {
  }

  void Show() {
    cout << name_ << " : " << id_ << " : " << age_ << endl;
  }

private:
  string name_;
  string id_;
  int age_;
};

class FlyweightFactory {
public:
  FlyweightFactory() {}
  ~FlyweightFactory() {
    map<string, Teacher*>::iterator it;
    for (it = teachers_.begin(); it != teachers_.end(); it++) {
      delete it->second;
    }
    teachers_.clear();
  }

  Teacher* GetTeacher(const string& id) {
    map<string, Teacher*>::iterator it;
    it = teachers_.find(id);
    if (it != teachers_.end()) {
      return it->second;
    } else {
      string name;
      int age = 0;

      cout << "Name: ";
      cin >> name;
      cout << "Age: ";
      cin >> age;

      Teacher* teacher = new Teacher(name, age, id);
      teachers_[id] = teacher;
      return teacher;
    }
  }

private:
  map<string, Teacher*> teachers_;
};

int main23() {
  FlyweightFactory factory;
  factory.GetTeacher("1")->Show();
  factory.GetTeacher("2")->Show();
  factory.GetTeacher("1")->Show();

  return 0;
}
