#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// MediatorģʽҲ���н���ģʽ������GoF�����23��������ģʽ��һ�֡�Mediatorģʽ����Ϊģʽ֮һ��
// ��Mediatorģʽ�У���֮��Ľ�����Ϊ��ͳһ����Mediator�Ķ����У�����ͨ��Mediator����ͬ�������󽻻���Mediator�������ſ����������á�

// �ŵ㣺��һ���н��������װһϵ�еĶ��󽻻����н���ʹ��������Ҫ��ʾ���໥���ã��Ӷ�������ϣ����ҿ��Զ����ظı�����֮��Ľ�����

// �����ڣ�
// ��һ���н���󣬷�װһЩ�ж���ͬ�£��Ľ������н����Ǹ���������Ҫ��ʾ���໥���ã��Ӷ�ʵ���������ɢ�����ҿ��Զ����ĸı�����֮��Ľ�����

// ģʽ�ŵ�:
// 1.��ϵͳ�����ָܷ�ɸ�С�Ķ��󣬷��������С���ԭ��
// 2.�Թ�������ļ��п���
// 3.��С�����ϳ̶ȣ���ȷ��֮����໥��ϵ������֮��Ĺ�ϵ���ڸ���ʱ�������κ�һ������޸Ķ���Ӱ�쵽�����࣬�����������ƵĿ���ԭ��
// ��Mediatorģʽ��ԭ���໥����Ķ�Զ����֮��Ĺ�ϵ��ΪMediator�������������������һ�Զ�Ĺ�ϵ��������һ�����޸�ʱ��
// ���Զ����������಻����Ӱ�죨��ʹ���޸ģ�Ҳ������Mediator�����ࣩ��
// 4.�����������������ԡ�

namespace mediator2 {

class Mediator;

class Person {
public:
  Person(const string& name, const string& sex, int condition, Mediator* mediator)
    : name_(name)
    , sex_(sex)
    , condition_(condition)
    , mediator_( mediator) {
  }

  virtual ~Person() {}

  string name() const { return name_; }
  string sex() const { return sex_; }
  int condition() const { return condition_; }

  virtual void GetPartner(Person* person) = 0;

protected:
  Mediator* mediator_;
  string name_;
  string sex_;
  int condition_;
};

class Mediator {
public:
  void set_man(Person* man) { man_ = man; }
  void set_woman(Person* woman) { woman_ = woman; }

  void GetPartner() const {
    if (man_->sex() == woman_->sex()) {
      cout << man_->name() << " and " << woman_->name() << " is Homosexual!" << endl;
      return;
    }

    if (man_->condition() == woman_->condition()) {
      cout << man_->name() << " and " << woman_->name() << " is Well-matched!" << endl;
    } else {
      cout << man_->name() << " and " << woman_->name() << " is Non-matched!" << endl;
    }
  }

private:
  Person* man_;
  Person* woman_;
};

class Man : public Person {
public:
  Man(const string& name, const string& sex, int condition, Mediator* mediator)
    : Person(name, sex, condition, mediator) {
  }

  void GetPartner(Person* person) override {
    mediator_->set_man(this);
    mediator_->set_woman(person);
    mediator_->GetPartner();
  }
};

class Woman : public Person {
public:
  Woman(const string& name, const string& sex, int condition, Mediator* mediator)
    : Person(name, sex, condition, mediator) {
  }

  void GetPartner(Person* person) override {
    mediator_->set_man(person);
    mediator_->set_woman(this);
    mediator_->GetPartner();
  }
};

}  // namespace mediator2

using namespace mediator2;

int main30() {
  Mediator* mediator = new Mediator;
  Person* zhang_san = new Man("ZhangSan", "male", 1000, mediator);
  Person* li_si = new Man("LiSi", "male", 2000, mediator);
  Person* wang_wu = new Woman("WangWu", "female", 2000, mediator);

  zhang_san->GetPartner(li_si);
  zhang_san->GetPartner(wang_wu);
  li_si->GetPartner(wang_wu);

  delete wang_wu;
  delete li_si;
  delete zhang_san;
  delete mediator;

  return 0;
}
