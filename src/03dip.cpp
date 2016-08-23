#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Dependence Inversion Principle.
// �߲�ģ�鲻Ӧ�������Ͳ�ģ�飬���߶�Ӧ����������󣻳���Ӧ������ϸ�ڣ�ϸ��Ӧ���������� 

// ��Computer��ܺ;���ĳ��̽��н���ϡ�Computer��������Cpu�ȣ��������������ĳ�����̵�Cpu��
// �������ۻ����ĸ����̵�Cpu������Ӱ��Computer��ܡ�

class Cpu {
public:
  virtual void Work() = 0;
};

class Memory {
public:
  virtual void Work() = 0;
};

class HardDisk {
public:
  virtual void Work() = 0;
};

class Computer3 {
public:
  Computer3(Cpu* cpu, Memory* memory, HardDisk* hard_disk)
    : cpu_(cpu)
    , memory_(memory)
    , hard_disk_(hard_disk) {
  }

  ~Computer3() {
    if (cpu_ != NULL) {
      delete cpu_;
    }

    if (memory_ != NULL) {
      delete memory_;
    }

    if (hard_disk_ != NULL) {
      delete hard_disk_;
    }
  }

  void Work() {
    cpu_->Work();
    memory_->Work();
    hard_disk_->Work();
  }

private:
  Cpu* cpu_;
  Memory* memory_;
  HardDisk* hard_disk_;
};

class IntelCpu : public Cpu {
public:
  void Work() override {
    cout << "I am Intel CPU!" << endl;
  }
};

class XSHardDisk : public HardDisk {
public:
  void Work() override {
    cout << "I am XS Hard Disk!" << endl;
  }
};

class JSDMemory : public Memory {
public:
  void Work() override {
    cout << "I am JSD Memory" << endl;
  }
};

int main03() {
  Computer3 computer(new IntelCpu, new JSDMemory, new XSHardDisk);
  computer.Work();

  return 0;
}
