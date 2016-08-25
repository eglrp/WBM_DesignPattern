#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// MementoģʽҲ�б���¼ģʽ������Ϊģʽ֮һ�����������Ǳ��������ڲ�״̬��������Ҫ��ʱ��undo/rollback���ָ�������ǰ��״̬��

// �����ڣ�
// �ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬�������Ϳ��Խ��Ժ�Ķ���״̬�ָ�����ǰ�����״̬��
// �����ڹ��ܱȽϸ��ӵģ�����Ҫ��¼��ά��������ʷ���ࣻ������Ҫ���������ֻ���ڶ������е�һС����ʱOriginator���Ը��ݱ����Memo��ԭ��ǰһ״̬��

class Memento {
public:
  Memento(const string& name, int age)
    : name_(name)
    , age_(age) {
  }

  int age() const { return age_; }
  string name() const { return name_; }

private:
  string name_;
  int age_;
};

class Character {
public:
  Character(const string& name, int age)
    : name_(name)
    , age_(age) {
  }

  void ChangeInfo(const string& name, int age) {
    name_ = name;
    age_ = age;
  }

  void Show() const {
    cout << name_ << " : " << age_ << endl;
  }

  void RestoreMemento(Memento* memento) {
    name_ = memento->name();
    age_ = memento->age();
  }

  Memento* SaveMemento() const {
    return new Memento(name_, age_);
  }

private:
  string name_;
  int age_;
};

class Caretaker {
public:
  Caretaker(Memento* memento)
    : memento_(memento) {
  }

  ~Caretaker() {
    if (memento_ != NULL) {
      delete memento_;
    }
  }

  Memento* memento() const { return memento_; }

private:
  Memento* memento_;
};

int main32() {
  Character character("A", 10);
  character.Show();

  Caretaker caretaker(character.SaveMemento());
  character.ChangeInfo("B", 20);
  character.Show();

  character.RestoreMemento(caretaker.memento());
  character.Show();

  return 0;
}
