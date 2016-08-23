#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// ���󹤳�ģʽ��������̬�Ĺ���ģʽ����Ϊ���������һ���Եġ�
// ���󹤳�ģʽ������ͻ����ṩһ���ӿڣ�ʹ�ÿͻ����ڲ���ָ����Ʒ�ľ������͵�����£�
// �ܹ����������Ʒ��Ĳ�Ʒ����

// ����ģʽ��Ҫô�����㽶,Ҫô����ƻ��,Ҫô����������.���ǲ���ͬʱ����һ����Ʒ�顣
// ���󹤳�����ͬʱ����һ����Ʒ�塣���󹤳�����ԭ��.

// ��Ҫ����
// ����ģʽֻ������һ����Ʒ����Ҫô�㽶��Ҫôƻ����
// ���󹤳�����һ������һ����Ʒ�壨�����кܶ��Ʒ��ɣ�

// ������ܽӿڣ������������ӿڱ�̡�
class Fruit13 {
public:
  virtual void SayName() = 0;
};

class Factory13 {
public:
  virtual Fruit13* CreateApple() = 0;
  virtual Fruit13* CreateBanana() = 0;
};

// ��Ʒ����
class NorthApple : public Fruit13 {
public:
  void SayName() override {
    cout << "I am north apple!" << endl;
  }
};

class SouthApple : public Fruit13 {
public:
  void SayName() override {
    cout << "I am south apple!" << endl;
  }
};

class NorthBanana : public Fruit13 {
public:
  void SayName() override {
    cout << "I am north banana!" << endl;
  }
};

class SouthBanana : public Fruit13 {
public:
  void SayName() override {
    cout << "I am south banana!" << endl;
  }
};

// ��Ʒ�幤��
class NorthFruitFactory : public Factory13 {
public:
  Fruit13* CreateApple() override {
    return new NorthApple;
  }

  Fruit13* CreateBanana() override {
    return new NorthBanana;
  }
};

class SouthFruitFactory : public Factory13 {
public:
  Fruit13* CreateApple() override {
    return new SouthApple;
  }

  Fruit13* CreateBanana() override {
    return new SouthBanana;
  }
};

int main13() {
  Factory13* factory = NULL;
  Fruit13* fruit = NULL;

  factory = new NorthFruitFactory;
  fruit = factory->CreateApple();
  fruit->SayName();
  delete fruit;

  fruit = factory->CreateBanana();
  fruit->SayName();
  delete fruit;

  delete factory;

  factory = new SouthFruitFactory;
  fruit = factory->CreateApple();
  fruit->SayName();
  delete fruit;

  fruit = factory->CreateBanana();
  fruit->SayName();
  delete fruit;

  delete factory;

  factory = NULL;
  fruit = NULL;

  return 0;
}
