#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;


// ������������ͬ�ĳ���װ��ͬ�����档

// ��ͬ�ĳ��ͣ���ͬ�ͺţ���װ��ͬ���͵ķ�����������������ķ��ġ�
// ����������ÿ�ַ�����ֻ����һ�ֳ����ã����ܸ��á�

// �Žӵ����������ǽ���������������������������������������������������ͷ�������
// ���߾���������ϡ�ʵ�ִ���ĸ��á�
// �Ž�ģʽ���ǽ�����װ�����������Ϊ����

class Car {
public:
  virtual void InstallEngine() = 0;
};

class Jeep1 : public Car {
public:
  void InstallEngine() override {
    cout << "Jeep1 3300cc" << endl;
  }
};

class Jeep2 : public Car {
public:
  void InstallEngine() override {
    cout << "Jeep2 4300cc" << endl;
  }
};

class Bmw1 : public Car {
public:
  void InstallEngine() override {
    cout << "Bmw1 4400cc" << endl;
  }
};

class Bmw2 : public Car {
public:
  void InstallEngine() override {
    cout << "Bmw2 5300cc" << endl;
  }
};

int main19() {
  Jeep1 jeep1;
  jeep1.InstallEngine();

  Jeep2 jeep2;
  jeep2.InstallEngine();

  return 0;
}
