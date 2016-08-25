#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Observerģʽ����Ϊģʽ֮һ�����������ǵ�һ�������״̬�����仯ʱ���ܹ��Զ�֪ͨ�������������Զ�ˢ�¶���״̬��
// Observerģʽ�ṩ����������һ��ͬ��ͨ�ŵ��ֶΣ�ʹĳ������������������������֮�䱣��״̬ͬ����

// ����Ӧ��
// - �����¼�������������е��ⲿ�¼���
// - ����/����ĳ�������״̬�仯��
// - ������/������(publisher / subscriber)ģ���У���һ���ⲿ�¼����µĲ�Ʒ����Ϣ�ĳ��ֵȵȣ�������ʱ��֪ͨ�ʼ��б��еĶ����ߡ�

// �����ڣ�
// ��������һ��һ�Զ��������ϵ��ʹ��ÿһ������ı�״̬�����������������ǵĶ��󶼻�õ�֪ͨ��
// ʹ�ó�����������һ��һ�Զ�Ĺ�ϵ���ö���۲���󣨹�˾Ա����ͬʱ����һ������������飩���������״̬�����仯ʱ����֪ͨ���еĹ۲��ߣ�ʹ�����ܹ������Լ���

class Observer {
public:
  virtual void Update(const string&) = 0;
};

class Employee :public Observer {
public:
  Employee(const string& name)
    : name_(name) {
  }

  void Update(const string& action) {
    cout << name_ << ": received " << action << endl;
  }

private:
  string name_;
};

class Secretary {
public:
  Secretary() {}
  ~Secretary() {
    for (Observer* observer : observers_) {
      delete observer;
    }
    observers_.clear();
  }

  void Notify(const string& action) {
    for (Observer* observer : observers_) {
      observer->Update(action);
    }
  }

  void Attach(Observer* observer) {
    observers_.push_back(observer);
  }

private:
  list<Observer*> observers_;
};

int main31() {
  Secretary secretary;
  secretary.Attach(new Employee("A"));
  secretary.Attach(new Employee("B"));
  secretary.Attach(new Employee("C"));

  secretary.Notify("Boss is on the way.");

  return 0;
}
