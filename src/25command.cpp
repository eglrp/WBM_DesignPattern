#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// CommandģʽҲ������ģʽ������Ϊ���ģʽ��һ�֡�Commandģʽͨ������ΪCommand�����װ�˶�Ŀ�����ĵ�����Ϊ�Լ����ò�����

// ���������ĳ�������У�һ�����������һ������һ������µĵ��ù����ǣ�����Ŀ�����ʵ�������õ��ò���������Ŀ�����ķ�����
// ������Щ������б�Ҫʹ��һ��ר�ŵ�������ֵ��ù��̼��Է�װ�����ǰ�����ר�ŵ������command�ࡣ
// �������ù��̱ȽϷ��ӣ����ߴ��ڶദ���ֵ��á���ʱ��ʹ��Command��Ըõ��ü��Է�װ�����ڹ��ܵ������á�
// ����ǰ����Ҫ�Ե��ò�������ĳЩ��������ǰ����Ҫ����ĳЩ���⴦��������־�����棬��¼��ʷ�����ȡ�

// �����ڣ�
// �ǽ�һ�������װΪһ�����󣬴Ӷ�ʹ����ò�ͬ������Կͻ��˽��в��������������Ŷӻ��¼������־���Լ�֧�ֿɳ����Ĳ�����

// commandģʽ��Ҫ�������ɫ��ִ���ߣ������ߣ�������󣬾�������ͻ��ˡ�

// ���ʵ��һ��commandģʽ��commandģʽ�ǽ���Ϊ����������������Խ�ÿ���������һ�����󱣴��������������ȴ�ִ����Doctor���֡�
// ��Ϊ�ǽ���Ϊ�����������Խ�Doctor��������Ϊ�����������ҳ���TreatEye��TreatNose��Ȼ��
// ��������Ϊ���в�������Ҳ���ǽ����������������һ������command����
// Ȼ��Ϳ��Զ���command��commandҪ����Doctor��Ȼ��ִ��Doctor�ķ�����
// �����command��ִ���ߺ󣬾���Ҫ����һ�������ߣ���������ʵ���ǹ�����Щcommand���Լ�����commandִ�з����Ľ�ɫ��

//---------------------------------------------------
// ����ӿڱ�̣�����ӿڡ�ִ�����Լ�����ĳ���

class Doctor {
public:
  virtual ~Doctor() {}

  virtual void TreatEye() = 0;
  virtual void TreatNose() = 0;
};

class Command {
public:
  Command(Doctor* doctor)
    : doctor_(doctor) {
  }

  virtual void Treat() = 0;

protected:
  Doctor* doctor_;
};

//---------------------------------------------------
// �����ִ���ߡ�

class InternDoctor : public Doctor {
public:
  void TreatEye() override {
    cout << "Intern treats eye!" << endl;
  }

  void TreatNose() override {
    cout << "Intern treats nose!" << endl;
  }
};

class SpecialistDoctor : public Doctor {
public:
  void TreatEye() override {
    cout << "Specialist treats eye!" << endl;
  }

  void TreatNose() override {
    cout << "Specialist treats nose!" << endl;
  }
};

//------------------------------------------------------
// ��������

class TreatEyeCommand : public Command {
public:
  TreatEyeCommand(Doctor* doctor)
    : Command(doctor) {
  }

  void Treat() override {
    doctor_->TreatEye();
  }
};

class TreatNoseCommand : public Command {
public:
  TreatNoseCommand(Doctor* doctor)
    : Command(doctor) {
  }

  void Treat() override {
    doctor_->TreatNose();
  }
};

//------------------------------------------------------
// �����ߣ�Ҳ���������ߡ�

class BeautyNurse {
public:
  BeautyNurse(Command* command)
    : command_(command) {
  }

  ~BeautyNurse() {
    delete command_;
    command_ = NULL;
  }

  void SubmitCase() {
    command_->Treat();
  }

private:
  Command* command_;
};

class HeadNurse {
public:
  HeadNurse() {}
  ~HeadNurse() {
    for (Command* command : commands_) {
      delete command;
    }
    commands_.clear();
  }

  void ReceiveCase(Command* command) {
    commands_.push_back(command);
  }

  void SubmitCase() {
    for (Command* command : commands_) {
      command->Treat();
    }
  }

private:
  list<Command*> commands_;
};

//------------------------------------------------------
// �ͻ��ˡ�

int main25() {
  Doctor* intern = new InternDoctor;
  Doctor* specialist = new SpecialistDoctor;

  cout << "Beauty nurse: " << endl;
  BeautyNurse beauty_nurse(new TreatEyeCommand(intern));
  beauty_nurse.SubmitCase();

  cout << "----------------------------" << endl;

  cout << "Head nurse: " << endl;
  HeadNurse head_nurse;
  head_nurse.ReceiveCase(new TreatEyeCommand(intern));
  head_nurse.ReceiveCase(new TreatEyeCommand(specialist));
  head_nurse.ReceiveCase(new TreatNoseCommand(intern));
  head_nurse.ReceiveCase(new TreatNoseCommand(specialist));
  head_nurse.SubmitCase();

  delete specialist;
  delete intern;

  return 0;
}
