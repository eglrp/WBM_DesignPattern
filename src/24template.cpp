#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Template MethodģʽҲ��ģ�巽��ģʽ������Ϊģʽ֮һ��
// ���Ѿ����ض������㷨�е�ĳЩ��Ҫ�Ĵ���ί�ø����󷽷���
// ͨ������̳жԳ��󷽷��Ĳ�ͬʵ�ָı������㷨����Ϊ��

// Ӧ�ó���
// Template Methodģʽһ��Ӧ���ھ�����������:
// - ����ͳһ�Ĳ���������������;
// - ���в�ͬ�Ĳ���ϸ��;
// - ���ڶ������ͬ�����������Ӧ�ó�������ĳЩ����Ĳ���ϸ��ȴ������ͬ��

// �ܽ᣺
// �ڳ�������ͳһ�������裬���涨�ýӿڣ�������ʵ�ֽӿڡ��������԰Ѹ������������Ͳ����������ϡ�

class MakeCar {
public:
  void Make() {  // ģ�庯������ҵ���߼����á��Ѿ����ʵ���Ƴٵ����ࡣ
    MakeHead();
    MakeBody();
  }

protected:
  virtual void MakeHead() = 0;
  virtual void MakeBody() = 0;
};

class Jeep : public MakeCar {
protected:
  void MakeBody() override {
    cout << "I am jeep body." << endl;
  }

  void MakeHead() override {
    cout << "I am jeep head." << endl;
  }
};

class Bmw : public MakeCar {
protected:
  void MakeBody() override {
    cout << "I am bmw body." << endl;
  }

  void MakeHead() override {
    cout << "I am bmw head." << endl;
  }
};

int main24() {
  Jeep jeep;
  jeep.Make();

  Bmw bmw;
  bmw.Make();

  return 0;
}
