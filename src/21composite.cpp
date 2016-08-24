#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// CompositeģʽҲ�����ģʽ���ǹ����͵����ģʽ֮һ��ͨ���ݹ��ֶ����������εĶ���ṹ��������ͨ��һ������������������������

// Component�����νṹ�Ľڵ����
// - Ϊ���еĶ�����ͳһ�Ľӿڣ��������ԣ���Ϊ�ȵĶ��壩��
// - �ṩ�����ӽڵ����Ľӿڷ�����
// - [��ѡ]�ṩ�����ڵ����Ľӿڷ�����

// Leaf �����νṹ��Ҷ�ڵ㣩
// Component��ʵ�����ࡣ

// Composite�����νṹ��֦�ڵ㣩
// Component��ʵ�����ࡣ

// �����ڣ�
// �����������϶����ʹ�þ���һ���ԡ���������ϳ����νṹ�Ա�ʾ������--���塱��

class IFile {
public:
  IFile(const string& name)
    : name_(name) {
  }

  virtual void Display() = 0;
  virtual bool Add(IFile* child) = 0;
  virtual list<IFile*>* GetChildren() = 0;

protected:
  string name_;
};

class Dir : public IFile {
public:
  Dir(const string& name)
    : IFile(name) {
    children_ = new list<IFile*>;
  }

  void Display() override {
    cout << name_ << endl;
  }

  bool Add(IFile* child) override {
    children_->push_back(child);
    return true;
  }

  list<IFile*>* GetChildren() override {
    return children_;
  }

private:
  list<IFile*>* children_;
};

class File :public IFile {
public:
  File(const string& name)
    : IFile(name) {
  }

  void Display() override {
    cout << name_ << endl;
  }

  bool Add(IFile* child) override {
    return false;
  }

  list<IFile*>* GetChildren() override {
    return NULL;
  }
};

void ShowFileTree(IFile* root, int depth) {
  if (root == NULL) {
    return;
  }

  cout << string(depth, '-');
  root->Display();

  list<IFile*>* children = root->GetChildren();
  for (IFile* child : *children) {
    if (child->GetChildren() == NULL) {
      cout << string(depth + 1, '-');
      child->Display();
    } else {
      ShowFileTree(child, depth + 1);
    }
  }
}

int main21() {
  IFile* dir = new Dir("Dir");
  IFile* dir1 = new Dir("Dir1");
  IFile* dir2 = new Dir("Dir2");
  IFile* file = new File("file");

  IFile* dir3 = new Dir("Dir3");
  IFile* file2 = new File("file2");
  IFile* file3 = new File("file3");

  IFile* file4 = new File("file4");
  IFile* file5 = new File("file5");

  dir->Add(dir1);
  dir->Add(dir2);
  dir->Add(file);

  dir1->Add(dir3);
  dir1->Add(file2);
  dir1->Add(file3);

  dir3->Add(file4);
  dir3->Add(file5);

  ShowFileTree(dir, 0);

  delete dir;
  delete dir1;
  delete dir2;
  delete dir3;

  delete file;
  delete file2;
  delete file3;
  delete file4;
  delete file5;

  return 0;
}
