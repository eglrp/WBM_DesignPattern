#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car1;
class Hand1;
class Head1;
class Interface1 {
};

// 1.����(Dependency)
// ���߼�ͷ��һ��������һ����ĺ����������ߺ�������ֵ��
// ����������Զ����Ķ��󣬵�һ������������һ�������ʵ��������������һ������ķ���ʱ������������֮����Ҫ����Ϊ������ϵ��
class Person1 {
public:
  Car1* GetCar();
  void SetCar(Car1* car);
};

// 2.����(Association)
// ʵ�߼�ͷ��һ��������һ����ĳ�Ա����������������Զ����Ķ���
// ��һ�������ʵ������һ�������һЩ�ض�ʵ�����ڹ̶��Ķ�Ӧ��ϵʱ������������֮��Ϊ������ϵ��
class Person11 {
public:
private:
  Car1* car_;
};

// 3.�ۺ�(Aggregation)
// ��������ʵ�ߣ��ۺ��ǹ�����ϵ��һ�֣��ǽ�ǿ�Ĺ�����ϵ��ǿ�����������벿��֮��Ĺ�ϵ��
class CarShop {
private:
  vector<Car1*> cars_;
};

// 4.���(Composition)
// ʵ������ʵ��,��������Ķ���������ֶ�����������ڡ�
class Person12 {
private:
  Head1* head_;
  Hand1* hand_;
};

// 5.�������̳У�(Generalization)
// ��������ʵ��
class Student1 : public Person1 {
};

// 6.ʵ��(Realization)
// ������������
class Person13 : public Interface1 {
};


int main01() {
  return 0;
}
