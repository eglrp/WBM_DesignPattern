#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Proxyģʽ�ֽ�������ģʽ���ǹ����͵����ģʽ֮һ��������Ϊ���������ṩһ�ִ���Proxy���Կ��ƶ��������ķ��ʡ�
// ��ν������ָ�����뱻����Ķ��������ͬ�Ľӿڵ��࣬�ͻ��˱���ͨ�������뱻�����Ŀ���ཻ����
// ������һ���ڽ����Ĺ����У�����ǰ�󣩣�����ĳЩ�ر�Ĵ���

// subject�����������ɫ����
// ��ʵ�������������Ĺ�ͬ�ӿڡ�
// RealSubject����ʵ�����ɫ����
// �����˴����ɫ���������ʵ����
// Proxy�����������ɫ����
// ���ж���ʵ�����ɫ�����ã������ɫͨ���ڽ��ͻ��˵��ô��ݸ���ʵ�������֮ǰ����֮��ִ��ĳЩ�����������ǵ���������ʵ�Ķ���

// �ʺ��ڣ�
// Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ�

// ��ʾ��a�а���b�ࣻa,b��ʵ��Э����protocol

class Subject {
public:
  virtual ~Subject() {}
  virtual void SellBook() = 0;
};

class RealSubjectBook : public Subject {
public:
  void SellBook() override {
    cout << "���飡" << endl;
  }
};

// a������һ����b����bʵ����ĳһ��Э�飨һ�׽ӿڣ���
class DangdangProxy : public Subject {
public:
  DangdangProxy() {
    subject_ = new RealSubjectBook;
  }

  ~DangdangProxy() {
    delete subject_;
  }

  void SellBook() override {
    Discount();  // �����ɫͨ���ڽ��ͻ��˵��ô��ݸ���ʵ�������֮ǰ����֮��ִ��ĳЩ����
    subject_->SellBook();
    Discount();
  }

private:
  void Discount() {
    cout << "���ۣ�" << endl;
  }

private:
  Subject* subject_;
};

// �ô���main��������Ҫ�޸��ˡ�ֻ��Ҫ�޸�Э��ʵ���ࡣ
int main16() {
  DangdangProxy proxy;
  proxy.SellBook();

  return 0;
}
