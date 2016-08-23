#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "windows.h"
#include "process.h"

using namespace std;

// ˫�ؼ��������ƽ������ģʽ�Ķ��߳����⡣
// ���μ������ã��ڲ��������instance��ûnew����ʱ�������̶߳�ͨ�����ⲿ��飬������lockλ�ô���Ȼ��
// ����һ���߳̽����ڲ�����new����instance����ʱ�ڲ�����ֹ�ڶ����̼߳���new��instance��
// instance�Ѿ�new�����Ժ����û������жϣ�GetInstanceʱÿ�ζ�Ҫ����lock����ʱ���������������������һ���жϣ�
// ��ֹ����lock��

class Locker {
public:
  Locker() { m_hMutex = CreateMutex(NULL, FALSE, NULL); }
  ~Locker() { CloseHandle(m_hMutex); }
  void lock() { WaitForSingleObject(m_hMutex, INFINITE); }
  void unlock() { ReleaseMutex(m_hMutex); }

private:
  HANDLE m_hMutex;
};

class Singleton5 {
public:
  static Singleton5* GetInstance() {
    if (singleton_ == NULL) {
      locker_.lock();
      if (singleton_ == NULL) {
        singleton_ = new Singleton5;
      }
      locker_.unlock();
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
  Singleton5() {
    Sleep(1000);
    count_++;
  }

  // ��ֹ�����͸�ֵ��
  Singleton5& operator=(const Singleton5&);
  Singleton5(const Singleton5& singleton5) {}

private:
  static Singleton5* singleton_;
  static int count_;
  static Locker locker_;
};

Singleton5* Singleton5::singleton_ = NULL;
Locker Singleton5::locker_;
int Singleton5::count_ = 0;

void PrintSingleton5(void*) {
  cout << Singleton5::GetInstance()->count() << endl;
}

int main10() {
  HANDLE thread[10];
  for (int i = 0; i < 3; i++) {
    thread[i] = (HANDLE)_beginthread(PrintSingleton5, 0, NULL);
  }

  for (int i = 0; i < 3; i++) {
    WaitForSingleObject(thread[i], INFINITE);
  }

  Singleton5::DestreyInstance();
  return 0;
}