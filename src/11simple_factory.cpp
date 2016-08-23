#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// ˼�룺 ����˼������һ�����������������������������ͬ���࣬Ȼ����ݲ�ͬ���virtual�����õ���ͬ�Ľ����

// �򵥹���ģʽ����ȱ��:
// �����ģʽ�У�������������ģʽ�Ĺؼ����ڡ���������Ҫ���ж��߼���
// �ܹ���������������Ϣ����������Ӧ�ô����ĸ�������Ķ���
// �û���ʹ��ʱ����ֱ�Ӹ��ݹ�����ȥ���������ʵ�����������˽���Щ��������δ����Լ������֯�ġ�
// ���������������ϵ�ṹ���Ż������ѷ��֣��򵥹���ģʽ��ȱ��Ҳ���������乤�����ϣ�
// ���ڹ����༯��������ʵ���Ĵ����߼������ԡ����ھۡ��������Ĳ����á�
// ���⣬��ϵͳ�еľ����Ʒ�಻������ʱ�����ܻ����Ҫ�󹤳���ҲҪ����Ӧ���޸ģ���չ�Բ����ܺá�

// ��Ҫ���ڴ��������������ʱ������Ӱ����ǰ��ϵͳ���롣
// GOOD : �����ڲ�ͬ���������ͬ����ʱ��
// BUG���ͻ��˱���Ҫ֪������͹����࣬����Բ

class Fruit {
public:
  virtual void GetName() = 0;
};

class Apple : public Fruit {
public:
  void GetName() override {
    cout << "I am apple!" << endl;
  }
};

class Pear : public Fruit {
public:
  void GetName() override {
    cout << "I am pear!" << endl;
  }
};

class FruitFactory {
public:
  Fruit* CreateFruit(const string& name) {
    if (name == "apple") {
      return new Apple;
    } else if (name == "pear") {
      return new Pear;
    } else {
      return NULL;
    }
  }
};

int main11() {
  FruitFactory factory;
  Fruit* fruit1 = factory.CreateFruit("apple");
  Fruit* fruit2 = factory.CreateFruit("pear");

  fruit1->GetName();
  fruit2->GetName();

  delete fruit2;
  delete fruit1;

  return 0;
}
