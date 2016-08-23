#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "windows.h"
#include "process.h"

using namespace std;

// ����ģʽ�Ķ��߳����⡣
// ���������̰߳�ȫ���⣬�����������̰߳�ȫ���⣬���������Դ�˷ѡ�

// ����ʽ
// 1"����"ģʽ��Ȼ���ŵ㣬����ÿ�ε���GetInstance()��̬����ʱ�������ж�
// NULL == m_instance��ʹ������Կ�������
// 2.���߳��лᵼ�¶��ʵ���Ĳ������Ӷ��������д��벻��ȷ�Լ��ڴ��й¶��
// 3.�ṩ�ͷ���Դ�ĺ���

// C++�Ĺ��캯�����̲߳���ȫ�ġ�
// C++�еĹ��캯������˵��������
// ��һ�����ڴ����
// �ڶ�������ʼ����Ա����

class Singleton3 {
public:
  static Singleton3* GetInstance() {
    if (singleton_ == NULL) {
      Sleep(1000);
      singleton_ = new Singleton3;
    }
    return singleton_;
  }

  static int count() { return count_; }

  static void DestreyInstance() {
    if (singleton_ != NULL) {
      delete singleton_;
    }
  }

private:
  // ��ֹ�ⲿ���졣
  Singleton3() {
    count_++;
  }

  // ��ֹ�����͸�ֵ��
  Singleton3& operator=(const Singleton3&);
  Singleton3(const Singleton3& singleton3) {}

private:
  static Singleton3* singleton_;
  static int count_;
};

Singleton3* Singleton3::singleton_ = NULL;
int Singleton3::count_ = 0;

void PrintSingleton3(void*) {
  cout << Singleton3::GetInstance()->count() << endl;
}

//-------------------------------------------------------
// ����ʽ
class Singleton4 {
public:
  static Singleton4* GetInstance() {
    return singleton_;
  }

  static int count() { return count_; }

  static void DestreyInstance() {
    if (singleton_ != NULL) {
      delete singleton_;
    }
  }

private:
  // ��ֹ�ⲿ���졣
  Singleton4() {
    Sleep(1000);
    count_++;
  }

  // ��ֹ�����͸�ֵ��
  Singleton4& operator=(const Singleton4&);
  Singleton4(const Singleton4& singleton4) {}

private:
  static Singleton4* singleton_;
  static int count_;
};

Singleton4* Singleton4::singleton_ = new Singleton4;
int Singleton4::count_ = 0;

void PrintSingleton4(void*) {
  cout << Singleton4::GetInstance()->count() << endl;
}

int main09() {
  HANDLE thread[10];
  for (int i = 0; i < 3; i++) {
    thread[i] = (HANDLE)_beginthread(PrintSingleton3, 0, NULL);
  }

  for (int i = 0; i < 3; i++) {
    WaitForSingleObject(thread[i], INFINITE);
  }

  for (int i = 0; i < 3; i++) {
    thread[i] = (HANDLE)_beginthread(PrintSingleton4, 0, NULL);
  }

  for (int i = 0; i < 3; i++) {
    WaitForSingleObject(thread[i], INFINITE);
  }

  Singleton4::DestreyInstance();
  Singleton3::DestreyInstance();

  return 0;
}