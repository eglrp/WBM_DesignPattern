#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// AdapterģʽҲ��������ģʽ���ǹ�����ģʽ֮һ��ͨ��Adapterģʽ���Ըı������ࣨ���ⲿ�ࣩ�Ľӿ���ʽ��

// �����ڣ�
// �ǽ�һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڡ�ʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ������

// ����ӿڱ�̣� �������Լ���õĽӿڡ�AdapterֻҪ�̳�����ӿڣ�ʵ������Լ���ĺ����ӿڼ��ɡ�

class Voltage5V {
public:
  virtual void Use5V() = 0;
};

class Voltage220V {
public:
  void Use220V() {
    cout << "I am 220V!" << endl;
  }
};

class Adapter : public Voltage5V {
public:
  Adapter(Voltage220V* voltage_220v)
    : voltage_220v_(voltage_220v) {
  }

  void Use5V() override {  // Adapter ����Proxy�������ܸı亯���ӿڣ����ܼӹ�ԭ�����������ݡ�
    voltage_220v_->Use220V();
    cout << "Adapter converts 220V to 5V!" << endl;
  }

private:
  Voltage220V* voltage_220v_;
};

int main18() {
  Voltage220V* v220 = new Voltage220V;
  Voltage5V* v5 = new Adapter(v220);
  v5->Use5V();

  delete v5;
  delete v220;

  return 0;
}
