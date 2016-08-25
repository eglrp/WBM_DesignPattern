#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// StateģʽҲ��״̬ģʽ������Ϊ���ģʽ��һ�֡�Stateģʽ����ͨ���ı������ڲ�״̬���ı�������Ϊ��
// ���������ֵþͺ����޸���������һ����
// ״̬ģʽ��Ҫ������ǵ�����һ������״̬ת�����������ʽ���ڸ���ʱ�������
// ��״̬���ж��߼�ת�뵽���ֲ�ͬ״̬��һϵ���൱�У����԰Ѹ��ӵ��ж��߼��򻯡�

// �����ڣ�
// �������Ϊ���������������ĵ�ǰ״̬����Ϊ��״̬�ı���ı�ĳ�����
// �����ڣ�ͨ���û���״̬���ı�������Ϊ��

// ������������ʵ�֡�
// Worker���DoSomething�д����˴���������״̬�жϣ�ÿ�θı䶼��Ҫ��Worker������ӵ��ж�����ȥ�޸ġ�
// ����������ǽ���Щ�жϷ����ȥ����ÿ��״̬���ж��󻯡�ÿ��״̬����һ���жϣ���������Լ���������
// ����д�����������ϣ��������Worker����һ��״̬�����жϣ��Դ����ơ�
// ��������Worker�в�û�п����ı��Լ�״̬�Ĵ��룬���������ȴ��Ϊ����Ĳ�ͬ��������ͬ���������Ϊ
// Worker��DoSomething��ʱ���Լ�����State����State������Worker״̬�ĸı䡣

class Worker;

class State {
public:
  virtual ~State() {}

  virtual void DoSomething(Worker* worker) = 0;
};

class Worker {
public:
  Worker();

  ~Worker() {
    if (state_ != NULL) {
      delete state_;
    }
  }

  void set_hour(int hour) { hour_ = hour; }
  int hour() const { return hour_; }

  State* state() const { return state_; }
  void set_state(State* state) { state_ = state; }

  void DoSomething() {
    if (state_ != NULL) {
      state_->DoSomething(this);
    }
  }

private:
  State* state_;
  int hour_;
};

class State1 : public State {
public:
  void DoSomething(Worker* worker) override;
};

class State2 : public State {
public:
  void DoSomething(Worker* worker) override;
};

void State1::DoSomething(Worker* worker) {
  if (worker->hour() > 6 && worker->hour() < 9) {  // ״̬1 ������ Ҫת��״̬2
    cout << "breakfast" << endl;
  } else {
    delete worker->state();
    worker->set_state(new State2);
    worker->DoSomething();
  }
}

void State2::DoSomething(Worker* worker) {
  if (worker->hour() > 9 && worker->hour() < 12) {  // ״̬2������,Ҫת��״̬3 ���߻ָ�����ʼ��״̬��
    cout << "work" << endl;
  } else {
    delete worker->state();
    worker->set_state(new State1);  // �ָ�������״̬��
    cout << "current time: " << worker->hour() << ". Unknown state!" << endl;
  }
}

Worker::Worker() {
  hour_ = 0;
  state_ = new State1;
}

int main34() {
  Worker worker;
  worker.set_hour(7);
  worker.DoSomething();

  worker.set_hour(11);
  worker.DoSomething();

  worker.set_hour(1);
  worker.DoSomething();

  return 0;
}
