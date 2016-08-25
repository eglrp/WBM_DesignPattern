#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// ��������������������Ҫ�������Ű����̽�����ɡ�������������Ƿֱ�new���������ţ�Ȼ�����ν���Make��һ��Ҫע������˳��
// ����������̸ı��ˣ�����Ҫ�ı�ͻ��ˡ��������е�ҵ���߼���д���ڿͻ��ˡ�������������ģʽ�������������̻������⡣

class CarManufacture {
public:
  virtual void Make() = 0;
};

class CarHeadManufacture :public CarManufacture {
public:
  void Make() override {
    cout << "Make head." << endl;
  }
};

class CarBodyManufacture :public CarManufacture {
public:
  void Make() override {
    cout << "Make body." << endl;
  }
};

class CarTailManufacture :public CarManufacture {
public:
  void Make() override {
    cout << "Make Tail." << endl;
  }
};

int main26() {
  CarManufacture* head = new CarHeadManufacture;
  CarManufacture* body = new CarBodyManufacture;
  CarManufacture* tail = new CarTailManufacture;

  // ҵ���߼�д���ڿͻ����ˡ�
  head->Make();
  body->Make();
  tail->Make();

  delete tail;
  delete body;
  delete head;

  return 0;
}
