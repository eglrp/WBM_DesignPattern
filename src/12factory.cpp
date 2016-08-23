#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// ��������ģʽͬ��������Ĵ�����ģʽ�ֱ���Ϊ��̬����ģʽ ��
// ��������ģʽ�������Ƕ���һ��������Ʒ����Ĺ����ӿڣ���ʵ�ʴ��������Ƴٵ����൱�С�
// ���Ĺ����಻�ٸ����Ʒ�Ĵ����������������Ϊһ�����󹤳���ɫ����������幤���������ʵ�ֵĽӿڣ�
// ������һ�����󻯵ĺô���ʹ�ù�������ģʽ����ʹϵͳ�ڲ��޸ľ��幤����ɫ������������µĲ�Ʒ��

// ��������ģʽ�ͼ򵥹���ģʽ�Ƚ�:
// ��������ģʽ��򵥹���ģʽ�ڽṹ�ϵĲ�ͬ���Ǻ����ԡ�
// ����������ĺ�����һ�����󹤳��࣬���򵥹���ģʽ�Ѻ��ķ���һ���������ϡ�
// ��������ģʽ֮������һ�������ж�̬�Թ���ģʽ����Ϊ���幤���඼�й�ͬ�Ľӿڣ������й�ͬ�ĳ����ࡣ
// ��ϵͳ��չ��Ҫ����µĲ�Ʒ����ʱ��������Ҫ���һ����������Լ�һ�����幤������
// ԭ�й���������Ҫ�����κ��޸ģ�Ҳ����Ҫ�޸Ŀͻ��ˣ��ܺõķ����ˡ����ţ���ա�ԭ��
// ���򵥹���ģʽ������²�Ʒ����󲻵ò��޸Ĺ�����������չ�Բ��á���������ģʽ�˻�������ݱ�ɼ򵥹���ģʽ��

class Fruit12 {
public:
  virtual void SayName() = 0;
};

class Apple12 : public Fruit12 {
public:
  void SayName() override {
    cout << "I am apple!" << endl;
  }
};

class Pear12 : public Fruit12 {
public:
  void SayName() override {
    cout << "I am pear!" << endl;
  }
};

class Factory12 {
public:
  virtual Fruit12* CreateFruit() = 0;
};

class AppleFactory : public Factory12 {
public:
  Fruit12* CreateFruit() override {
    return new Apple12;
  }
};

class Pearfactory : public Factory12 {
public:
  Fruit12* CreateFruit() override {
    return new Pear12;
  }
};

// ����²�Ʒ������Ҫ�޸�Factory, ֱ�Ӽ̳м��ɣ����Ͽ��ŷ��ԭ�򡣲��ҹ����Ͳ�Ʒ��������ӿڵġ�

class Banana : public Fruit12 {
public:
  void SayName() override {
    cout << "I am banana!" << endl;
  }
};

class BananaFactory : public Factory12 {
public:
  Fruit12* CreateFruit() override {
    return new Banana;
  }
};

int main12() {
  Factory12* factory = NULL;
  Fruit12* fruit = NULL;

  factory = new AppleFactory;
  fruit = factory->CreateFruit();
  fruit->SayName();
  delete factory;
  delete fruit;

  factory = new BananaFactory;
  fruit = factory->CreateFruit();
  fruit->SayName();
  delete factory;
  delete fruit;

  factory = NULL;
  fruit = NULL;

  return 0;
}
