#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// FacadeģʽҲ�����ģʽ������GoF�����23�����ģʽ�е�һ�֡�
// FacadeģʽΪһ��������ƹ��ܵ���Ⱥ��������⣬��ϵͳ�ȵȣ��ṩһ��һ�µļ򵥵Ľ��档���һ�µļ򵥵Ľ��汻����facade��

// �����ڣ�
// Ϊ��ϵͳ��ͳһһ�׽ӿڣ�����ϵͳ��������ʹ�á�

class SystemA {
public:
  void Run() {
    cout << "SystemA runs" << endl;
  }
};

class SystemB {
public:
  void Run() {
    cout << "SystemB runs" << endl;
  }
};

class SystemC {
public:
  void Run() {
    cout << "SystemC runs" << endl;
  }
};

class Facade {
public:
  Facade() {
    system_a_ = new SystemA;
    system_b_ = new SystemB;
    system_c_ = new SystemC;
  }

  ~Facade() {
    delete system_c_;
    delete system_b_;
    delete system_a_;
  }

  void Run() {
    system_a_->Run();
    system_b_->Run();
    system_c_->Run();
  }

private:
  SystemA* system_a_;
  SystemB* system_b_;
  SystemC* system_c_;
};

int main22() {
  Facade facade;
  facade.Run();

  return 0;
}
