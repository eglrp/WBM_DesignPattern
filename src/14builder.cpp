#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Builderģʽ��Ϊ����Ĵ�������Ƶ�ģʽ��
// ��������һ�����϶��󣺱������Ķ���Ϊһ�����и������Եĸ��϶���
// ��ע���󴴽��ĸ����ֵĴ������̣���ͬ�Ĺ���������ָbuilder���������Բ�Ʒ�����в�ͬ�Ĵ���������

// ���������
// һ������Ĺ����Ƚϸ��ӣ���һ������Ĺ����Ͷ���ı�ʾ���з��롣

// ������ģʽ�͹���ģʽ������
// Factoryģʽ�У�
// 1.��һ������Ĺ�����
// 2.ʵ��һ������Ĺ���������������
// 3.������������A���õ�������ƷA��
// 4.������������B���õ�������ƷB��
// ��������ʵ���˹����ߺ������ߵĸ��룬ǿ�����ǽ����

//Builderģʽ��
// 1�����湤�����������Ʒ���õ���������A��
// 2����̥�����������Ӳ�Ʒ���õ���������B��
// 3�����̹������������Ʒ���õ���������C��
// 4������Щ�����ŵ�һ���γɸպ��ܹ���װ��һ�����������塣
// 5������������͵�������װ�������õ�һ��������Ʒ��
// ��������Ŀ����Ϊ��ʵ�ָ��Ӷ��������ߺ��䲿���Ľ��ǿ�����ǹ���

// ���ߵ��������ڣ�
// Factoryģʽ�����Ƕ������װ���̣���ֱ������һ������Ҫ�Ķ���
// Builderģʽ��һ�����Ĵ��������ÿһ����������ͳһ��װ��һ������
// Factoryģʽ������������ǣ�����������Ʒ��
// ��Builderģʽ������������ǹ������Ʋ�Ʒ��������װ���������Ĺ��̣�Ȼ��Ӳ�Ʒ�������еõ���Ʒ��
// Builderģʽ���Ǻܳ��á�ģʽ�������һ��˼�롣֪���˾Ϳ����ˡ�

// ������
class House {
public:
  House() {}

  void set_door(const string& door) { door_ = door; }
  void set_wall(const string& wall) { wall_ = wall; }

  void Show() {
    cout << "Wall: " << wall_ << "  Door: " << door_ << endl;
  }

private:
  string wall_;
  string door_;
};

// ���̶�
class Builder {
public:
  Builder() {
    house_ = new House;
  }

  virtual void BuildWall() = 0;
  virtual void BuildDoor() = 0;
  House* GetHouse() { return house_; }

protected:
  House* house_;
};

// ��Ԣ���̶�
class FlatBuidler : public Builder {
public:
  void BuildDoor() override {
    house_->set_door("flat door");
  }

  void BuildWall() override {
    house_->set_wall("flat wall");
  }

  void BuildAll() {  // ʡȥ��ָ����
    BuildDoor();
    BuildWall();
  }
};

// �������̶�
class villaBuilder : public Builder {
public:
  void BuildDoor() override {
    house_->set_door("villa door");
  }

  void BuildWall() override {
    house_->set_wall("villa wall");
  }

  void BuildAll() {  // ʡȥ��ָ����
    BuildDoor();
    BuildWall();
  }
};

// ָ����
class Director {
public:
  Director(Builder* builder)
    : builder_(builder) {
  }

  void Construct() {
    builder_->BuildWall();
    builder_->BuildDoor();
  }

private:
  Builder* builder_;
};


int main14() {
  House* house = new House;

  // 1.�ͻ��Լ��칫Ԣ��
  house->set_wall("flat wall");
  house->set_door("flat door");
  house->Show();
  delete house;
  house = NULL;

  // 2.�빤�̶��������
  Builder* builder = new villaBuilder;
  builder->BuildWall();
  builder->BuildDoor();
  house = builder->GetHouse();
  house->Show();
  delete builder;
  builder = NULL;
  delete house;
  house = NULL;

  // 3.ָ����ָ�ӹ��̶��칫Ԣ��
  builder = new FlatBuidler;
  Director director(builder);
  director.Construct();
  house = builder->GetHouse();
  house->Show();
  delete house;
  house = NULL;
  delete builder;
  builder = NULL;

  return 0;
}
