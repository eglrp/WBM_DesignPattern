#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// �Ž�ģʽ�ǽ���Ϊ�������Ϊʵ�ַ��롣
// ������ģʽ�����ݽṹ����Ϊ���з��롣

// visitor������Ϊ��BlogList�������ݽṹ��Blog����Ϊû�����Լ������������ʵ�֣�����ͨ��Accept���շ�����������������ʵ����Ϊ,
// ���ҽ��Լ������ô��������ߣ��������Դ˵õ�Blog�����ݡ�

// ʵ��˼·�������ṹ�������Ԫ�أ�Ȼ������ַ����ߣ�ʹ�ö���ṹ��ȥ���ܷ����߼��ɡ�

//----------------------------------------------------
// �û�����ͨ�������ϵ�Web��ʽ�������ߣ������ֻ�Wap��ʽ�������ߣ�ȥ���ʲ��ͣ�ÿƪ������һ��Ԫ�أ�Ȼ�󲩿��б���һ������ṹ�ࡣ
class Visitor;

class BlogElement {
public:
  BlogElement(const string& name)
    : name_(name) {
  }
  virtual ~BlogElement() {}

  string name() const { return name_; }

  virtual void Accept(Visitor* visitor) = 0;

protected:
  string name_;
};

class Visitor {
public:
  virtual void VisitBlog(BlogElement* blog) = 0;
};

//----------------------------------------------------

class WebVisitor : public Visitor {
public:
  void VisitBlog(BlogElement* blog) override {
    cout << "ͨ��web����� " << blog->name() << endl;
  }
};

class WapVisitor : public Visitor {
  void VisitBlog(BlogElement* blog) override {
    cout << "ͨ��wap����� " << blog->name() << endl;
  }
};

//-----------------------------------------------------

class Blog : public BlogElement {
public:
  Blog(const string& name)
    : BlogElement(name) {
  }

  void Accept(Visitor* visitor) override {
    visitor->VisitBlog(this);
  }
};

class BlogList : public BlogElement {
public:
  BlogList(const string& name)
    : BlogElement(name) {
  }

  ~BlogList() {
    for (Blog* blog : blogs_) {
      delete blog;
    }
    blogs_.clear();
  }

  void AddBlog(Blog* blog) {
    blogs_.push_back(blog);
  }

  void Accept(Visitor* visitor) override {
    for (Blog* blog : blogs_) {
      blog->Accept(visitor);
    }
  }

private:
  list<Blog*> blogs_;
};

//------------------------------------------------------

int main37() {
  Visitor* web_visitor = new WebVisitor;
  Visitor* wap_visitor = new WapVisitor;

  BlogList blog_list("BlogList");
  blog_list.AddBlog(new Blog("BlogA"));
  blog_list.AddBlog(new Blog("BlogB"));
  blog_list.AddBlog(new Blog("BlogC"));
  blog_list.AddBlog(new Blog("BlogD"));

  blog_list.Accept(wap_visitor);
  blog_list.Accept(web_visitor);

  delete wap_visitor;
  delete web_visitor;

  return 0;
}
