#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Chain of Responsibility��CoR��ģʽҲ��ְ����ģʽ����ְ������ģʽ������Ϊģʽ֮һ��
// ��ģʽ����һϵ�зֱ𵣵���ͬ��ְ�����Ķ�������ͬ���һ��������Щ��Ķ���֮��������һ���������������Ա�����ְ����ģʽ��

// ��1������ͻ�ClientҪ���һ����������������a, b, c, d�ĸ����֡�
// ���ȿͻ�Client�����񽻸�A��A���a����֮�󣬰����񽻸�B��B���b���֣�...��ֱ��D���d���֡�

// ��2�������������ֵ�ĳ�����������������Լ��ܴ���Ĳ��֣����ܴ���Ĳ��ֽ���ʡ������ʡ����������Լ�ְ��Χ�ڵĲ��֣����ܴ���Ĳ��ֽ��������������������������ɸ������

// ��3��������ڵ���Ϣ������

// ��4��SERVLET�����Ĺ�������Filter�����ʵ�֡�

// �ŵ㣺
// 1.���εķֵ���ÿ����ֻ��Ҫ�����Լ��ô���Ĺ��������ô���Ĵ��ݸ���һ��������ɣ�����ȷ��������η�Χ�����������С��װԭ��
// 2.���Ը�����Ҫ������Ϲ������̡��繤�����̷����仯������ͨ�����·�������������Ӧ�µĹ������̡�
// 3.������֮�����������ϵ���ʽ������֯��

// ȱ�㣺
// ��Ϊ����ʱ��������ʽ�ڶ���䴫����Ϣ������ʵ�ַ�ʽ��ͬ���п��ܻ�Ӱ�촦����ٶȡ�

// �����ڣ�
// ����ʽ�������顣�������̻�����Ϣ�������̻����������̻���

namespace cof {

class CarManufacture {
public:
  CarManufacture(CarManufacture* car_manufacture)
    : car_manufacture_(car_manufacture) {
  }

  virtual void Make() = 0;

protected:
  CarManufacture* car_manufacture_;
};

// ÿ�����Ű��Լ���������ɺ󴫵ݸ���һ�����Ž��й�����

class CarHeadManufacture : public CarManufacture {
public:
  CarHeadManufacture(CarManufacture* car_manufacture)
    : CarManufacture(car_manufacture) {
  }

  void Make() override {
    cout << "Make head!" << endl;
    if (car_manufacture_ != NULL) {
      car_manufacture_->Make();
    }
  }
};

class CarBodyManufacture : public CarManufacture {
public:
  CarBodyManufacture(CarManufacture* car_manufacture)
    : CarManufacture(car_manufacture) {
  }

  void Make() override {
    cout << "Make body!" << endl;
    if (car_manufacture_ != NULL) {
      car_manufacture_->Make();
    }
  }
};

class CarTailManufacture : public CarManufacture {
public:
  CarTailManufacture(CarManufacture* car_manufacture)
    : CarManufacture(car_manufacture) {
  }

  void Make() override {
    cout << "Make tail!" << endl;
    if (car_manufacture_ != NULL) {
      car_manufacture_->Make();
    }
  }
};

}  // namespace cof

using namespace cof;

int main27() {
  CarManufacture* tail = new CarTailManufacture(NULL);
  CarManufacture* body = new CarBodyManufacture(tail);
  CarManufacture* head = new CarHeadManufacture(body);

  head->Make();

  delete head;
  delete body;
  delete tail;

  return 0;
}
