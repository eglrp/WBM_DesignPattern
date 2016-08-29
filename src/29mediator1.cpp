#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// ���������� ����GetPartner�����ĺ�����Ҫ�������󽻻�ʱ��������Ҫ�໥����Է������ã����ж������ʱ����Ҫÿ�����󣬶����и��ӵ��ж���ȷ��
// ���ĸ����񣬽������������������е�һ������ı��ˣ���ô���ж���ĸ÷�������Ҫ�ı䡣

class Person {
public:
  Person(const string& name, const string& sex, int condition)
    : name_(name)
    , sex_(sex)
    , condition_(condition) {
  }

  virtual ~Person() {}

  string name() const { return name_; }
  string sex() const { return sex_; }
  int condition() const { return condition_; }

  virtual void GetPartner(Person* person) const = 0;

protected:
  string name_;
  string sex_;
  int condition_;
};

class Man : public Person {
public:
  Man(const string& name, const string& sex, int condition)
    : Person(name, sex, condition) {
  }

  void GetPartner(Person* person) const override {
    if (sex_ == person->sex()) {
      cout << name_ << " and " << person->name() << " is Homosexual!" << endl;
      return;
    }

    if (condition_ == person->condition()) {
      cout << name_ << " and " << person->name() << " is Well-matched!" << endl;
    } else {
      cout << name_ << " and " << person->name() << " is Non-matched!" << endl;
    }
  }
};

class Women : public Person {
public:
  Women(const string& name, const string& sex, int condition)
    : Person(name, sex, condition) {
  }

  void GetPartner(Person* person) const override {
    if (sex_ == person->sex()) {
      cout << name_ << " and " << person->name() << " is Homosexual!" << endl;
      return;
    }

    if (condition_ == person->condition()) {
      cout << name_ << " and " << person->name() << " is Well-matched!" << endl;
    } else {
      cout << name_ << " and " << person->name() << " is Non-matched!" << endl;
    }
  }
};

int main29() {
  Person* zhang_san = new Man("ZhangSan", "male", 1000);
  Person* li_si = new Man("LiSi", "male", 2000);
  Person* wang_wu = new Women("WangWu", "female", 2000);

  zhang_san->GetPartner(li_si);
  zhang_san->GetPartner(wang_wu);
  li_si->GetPartner(wang_wu);

  delete wang_wu;
  delete li_si;
  delete zhang_san;

  return 0;
}
