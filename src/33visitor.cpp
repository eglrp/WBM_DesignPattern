#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// VisitorģʽҲ�з�����ģʽ������Ϊģʽ֮һ���������������ݺ���Ϊ��ʹ��Visitorģʽ�����Բ��޸������������£������µĲ�����ɫ��ְ��

// �����ڣ�
// �����ݽṹ �� ���������ݽṹ�ϵĲ��� ���н����;
// ���������ݽṹ�Ƚ��ȶ��ĳ���
// ������ģʽ�ܽ᣺
// ������ģʽ�ŵ��������µĲ��������ף���Ϊ�����µĲ�������ζ������һ���µķ����ߡ�������ģʽ���йص���Ϊ���е�һ�������߶����С�
// �Ƿ�����ģʽ��ȱ�����������µ����ݽṹ���������

// ��ȱ��

// ������ģʽ�����µ��ŵ㣺
// 1��������ģʽʹ�������µĲ�����ú����ס����һЩ����������һ�����ӵĽṹ����Ļ�����ôһ����ԣ������µĲ�����ܸ��ӡ�
// ��ʹ�÷�����ģʽ�������µĲ�������ζ������һ���µķ������࣬��ˣ���ú����ס�
// 2��������ģʽ���йص���Ϊ���е�һ�������߶����У������Ƿ�ɢ��һ�����Ľڵ����С�
// 3��������ģʽ���Կ��������ĵȼ��ṹ�������ڲ�ͬ�ĵȼ��ṹ�ĳ�Ա�ࡣ������ֻ�ܷ�������ͬһ�����͵ȼ��ṹ�ĳ�Ա����
// �����ܷ������ڲ�ͬ�ȼ��ṹ�Ķ��󡣷�����ģʽ����������һ�㡣
// 4������״̬��ÿһ�������ķ����߶��󶼼�������ص���Ϊ���Ӷ�Ҳ�Ϳ����ڷ��ʵĹ����н�ִ�в�����״̬�������Լ��ڲ���
// �����Ƿ�ɢ���ܶ�Ľڵ�����С�����������ϵͳά�����ŵ㡣

// ������ģʽ�����µ�ȱ�㣺
// 1�������µĽڵ����ú����ѡ�ÿ����һ���µĽڵ㶼��ζ��Ҫ�ڳ�������߽�ɫ������һ���µĳ������������ÿһ���������������������Ӧ�ľ��������
// 2���ƻ���װ��������ģʽҪ������߶�����ʲ�����ÿһ���ڵ����Ĳ�������������һ�������нڵ�����Ҫ��
// ���Ǳ��뱩¶һЩ�Լ��Ĳ������ڲ�״̬����Ȼ�������ߵķ��ʾͱ��û�����塣���ڷ����߶����Լ�����۷��ʲ��������״̬��
// �Ӷ�ʹ��Щ״̬���ٴ洢�ڽڵ�����У���Ҳ���ƻ���װ�ġ�

//--------------------------------------------------------
// ��������
// ������һ����԰����һ�������ͬ����ɲ��֣��ù�԰���ڶ�������ߣ���๤A�����ɨ��԰��A���֣���๤B�����ɨ��԰��B���֣�
// ��԰�Ĺ����߸�������������Ƿ���ɣ��ϼ��쵼�����Ӳ칫԰�ȵȡ�Ҳ����˵������ͬһ����԰����ͬ�ķ������в�ͬ����Ϊ������
// ���ҷ����ߵ�����Ҳ������Ҫ����ʱ������ƶ��仯����Ϊ����չ�ԣ���
// ���������ƵĿ���ԭ�򣨶��޸Ĺرգ�����չ���ţ���������ô��ʵ�����������أ�

namespace visitor {

class Visitor;

class ParkElement {
public:
  ParkElement(const string& name)
    : name_(name) {
  }

  string name() const { return name_; }

  virtual void Accept(Visitor* visitor) = 0;

protected:
  string name_;
};

class Visitor {
public:
  virtual void Visit(ParkElement* park_element) = 0;
};

//----------------------------------------------------------

class ParkPartA : public ParkElement {
public:
  ParkPartA(const string& name)
    : ParkElement(name) {
  }

  void Accept(Visitor* visitor) override {
    visitor->Visit(this);
  }
};

class ParkPartB : public ParkElement {
public:
  ParkPartB(const string& name)
    : ParkElement(name) {
  }

  void Accept(Visitor* visitor) override {
    visitor->Visit(this);
  }
};

class Park : public ParkElement {
public:
  Park(const string& name)
    : ParkElement(name) {
  }

  void AddPart(ParkElement* park_part) {
    park_parts_.push_back(park_part);
  }

  void Accept(Visitor* visitor) override {
    for (ParkElement* park_part : park_parts_) {
      park_part->Accept(visitor);
    }
  }

private:
  list<ParkElement*> park_parts_;
};

//---------------------------------------------------

class VisitorA : public Visitor {
public:
  void Visit(ParkElement* park_element) override {
    cout << "VisitorA visits " << park_element->name() << endl;
  }
};

class VisitorB : public Visitor {
  void Visit(ParkElement* park_element) override {
    cout << "VisitorB visits " << park_element->name() << endl;
  }
};

class VisitorManager : public Visitor {
  void Visit(ParkElement* park_element) override {
    cout << "VisitorManager visits all parts" << endl;
  }
};

}  // namespace visitor

//----------------------------------------------------

using namespace visitor;

int main33() {
  ParkElement* part_a = new ParkPartA("Part A");
  ParkElement* part_b = new ParkPartA("Part B");
  Park* park = new Park("All parts");

  Visitor* visitor_a = new VisitorA;
  Visitor* visitor_b = new VisitorB;
  Visitor* visitor_manager = new VisitorManager;

  part_a->Accept(visitor_a);
  part_b->Accept(visitor_b);

  park->AddPart(part_a);
  park->AddPart(part_b);
  park->Accept(visitor_a);

  delete visitor_manager;
  delete visitor_b;
  delete visitor_a;
  delete park;
  delete part_b;
  delete part_a;

  return 0;
}
