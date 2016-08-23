#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// ʹ�ó�����
// ��Ӧ��ϵͳ�����У����ǳ�������������
// - �ڶ���߳�֮�䣬�����ʼ��һ��socket��Դ������servlet����������ͬһ����Դ���߲���ͬһ������
// - ����������ռ�ʹ��ȫ�ֱ�����������Դ
// - ���ģϵͳ�У�Ϊ�����ܵĿ��ǣ���Ҫ��ʡ����Ĵ���ʱ��ȵȡ�
// ��ΪSingletonģʽ���Ա�֤Ϊһ����ֻ����Ψһ��ʵ������������Щ�����Singletonģʽ�������ó��ˡ�

// ���裺
// 1. ���캯��˽�л�
// 2. �ṩһ��ȫ�ֵľ�̬������ȫ�ַ��ʵ㣩
// 3. �����ж���һ����ָ̬�룬ָ����ı����ľ�̬����ָ��

// ---------------------------------------------------------

// ����ʽ

class Singleton1 {
public:
  static Singleton1* GetInstance() {
    if (singleton_ == NULL) {
      singleton_ = new Singleton1;
    }
    return singleton_;
  }

  static void DestreyInstance() {
    if (singleton_ != NULL) {
      delete singleton_;
    }
  }

private:
  // ��ֹ�ⲿ���졣
  Singleton1() {}

  // ��ֹ�����͸�ֵ��
  Singleton1& operator=(const Singleton1&);
  Singleton1(const Singleton1& singleton1) {}

private:
  static Singleton1* singleton_;
};

Singleton1* Singleton1::singleton_ = NULL;

// ---------------------------------------------------------

// ����ʽ
class Singleton2 {
public:
  static Singleton2* GetInstance() {
    return singleton_;
  }

  static void DestreyInstance() {
    if (singleton_ != NULL) {
      delete singleton_;
    }
  }

private:
  // ��ֹ�ⲿ���졣
  Singleton2() {}

  // ��ֹ�����͸�ֵ��
  Singleton2& operator=(const Singleton2&);
  Singleton2(const Singleton2& singleton2) {}

private:
  static Singleton2* singleton_;
};

Singleton2* Singleton2::singleton_ = new Singleton2;

int main08() {
  Singleton1* s11 = Singleton1::GetInstance();
  Singleton1* s12 = Singleton1::GetInstance();

  if (s11 == s12) {
    cout << "s11 : " << s11 << "  s12 : " << s12 << endl;
    cout << "s11 == s12" << endl;
  }

  Singleton2* s21 = Singleton2::GetInstance();
  Singleton2* s22 = Singleton2::GetInstance();

  if (s21 == s22) {
    cout << "s21 : " << s21 << "  s22 : " << s22 << endl;
    cout << "s21 == s22" << endl;
  }

  Singleton1::DestreyInstance();
  Singleton2::DestreyInstance();
  return 0;
}