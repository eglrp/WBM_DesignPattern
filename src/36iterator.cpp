#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cassert>

using namespace std;

// IteratorģʽҲ�е���ģʽ������Ϊģʽ֮һ�����Ѷ������а������ڲ�����ķ���ί�ø��ⲿ�࣬ʹ��Iterator����������˳����б������ʵ����ģʽ��
// ��Ӧ��Iteratorģʽ֮ǰ������Ӧ������Iteratorģʽ�������ʲô���⡣����˵�������ʹ��Iteratorģʽ�������ʲô���⡣
// 1.�������Լ�ʵ��˳�������ֱ������������ֱ�����˳���������
// 2.�õ������Լ�ʵ�ֱ�����ֱ�ӱ�¶����ϸ�ڸ��ⲿ��

// ���Ϸ���1�뷽��2������ʵ�ֶԱ����������������أ�
// 1��������е���̫�๦�ܣ�һ������Ҫ�ṩ���ɾ���ȱ���Ӧ�еĹ��ܣ�һ���滹��Ҫ�ṩ�������ʹ��ܡ�
// 2������������ʵ�ֱ����Ĺ����У���Ҫ�������״̬������Ԫ�ص����ɾ���ȹ��ܼ�����һ�𣬺�����������Һͳ������д���ȡ�

// Iteratorģʽ����Ϊ����Ч�ش���˳����б������ʵ�һ�����ģʽ���򵥵�˵��Iteratorģʽ�ṩһ����Ч�ķ�����
// �������ξۼ����󼯺ϵ��������ʵ��ϸ�ڣ����ܶ������ڰ����Ķ���Ԫ�ذ�˳�������Ч�ı������ʡ����ԣ�Iteratorģʽ��Ӧ�ó������Թ���Ϊ�������¼���������
// - ���������а������ڲ�����
// - ��˳�����

// �ô���
// �ṩһ�ַ���˳�����һ����������ĸ���Ԫ�أ����ֲ���¶�ö�����ڲ���ʾ��
// Ϊ������ͬ�ľۼ��ṹ�ṩ�翪ʼ����һ�����Ƿ��������ǰһ���ͳһ�ӿڡ�

//--------------------------------------------

#define SIZE 5

typedef int Object;

class MyIterator {
public:
  virtual ~MyIterator() {}

  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual Object& GetCurrentItem() = 0;
};

class MyAggregate {
public:
  virtual ~MyAggregate() {}

  virtual Object& GetItem(size_t index) = 0;
  virtual size_t Size() const = 0;
  virtual MyIterator* CreateIterator() = 0;
};

//--------------------------------------------------------
// ����������һ�����������ߴ��������Ͻ��а�װ��Ȼ�������з��ʱ����ȡ�

class ConcreteIterator : public MyIterator {
public:
  ConcreteIterator(MyAggregate* aggregate)
    : aggregate_(aggregate)
    , index_(0) {
  }

  void First() override {
    index_ = 0;
  }

  void Next() override {
    assert(index_ < aggregate_->Size());

    index_++;
  }

  bool IsDone() override {
    return index_ == aggregate_->Size();
  }

  Object& GetCurrentItem() override {
    return aggregate_->GetItem(index_);
  }

private:
  size_t index_;
  MyAggregate* aggregate_;
};

class ConcreteAggregate : public MyAggregate {
public:
  ConcreteAggregate() {
    for (size_t i = 0; i < SIZE; i++) {
      objects_[i] = i * 100;
    }
  }

  Object& GetItem(size_t index) override {
    assert(index < SIZE);
    return objects_[index];
  }

  size_t Size() const override {
    return SIZE;
  }

  MyIterator* CreateIterator()  override {  // �õ���������һ�����ϵ����� 
    return new ConcreteIterator(this);
  }

private:
  Object objects_[SIZE];
};

//---------------------------------------------------------

int main36() {
  MyAggregate* aggregate = new ConcreteAggregate;
  MyIterator* iterator1 = aggregate->CreateIterator();

  while (!iterator1->IsDone()) {
    cout << iterator1->GetCurrentItem() << endl;
    iterator1->Next();
  }

  delete iterator1;
  delete aggregate;

  return 0;
}
