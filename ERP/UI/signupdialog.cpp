#include "signupdialog.h"
#include "ui_signupdialog.h"
#include "Core/SessionManager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>

namespace {
enum IdCheckResult {
    FileError = -1,
    NotDuplicate = 0,
    Duplicate = 1
};
}

SignupDialog::SignupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupDialog)
{
    ui->setupUi(this);
}

SignupDialog::~SignupDialog()
{
    delete ui;
}

void SignupDialog::on_btnCreateAccount_clicked()
{
    QString name = ui->editName->text().trimmed();
    QString id = ui->editUsername->text().trimmed();
    QString pw = ui->editPassword->text().trimmed();
    QString confirmpw = ui->editPasswordConfirm->text().trimmed();

    if (name.isEmpty() || id.isEmpty() || pw.isEmpty() || confirmpw.isEmpty()) {
        QMessageBox::warning(this, "Error", "모든 항목을 입력해주세요.");
        return;
    }

    if (pw != confirmpw) {
        QMessageBox::warning(this, "Error", "비밀번호가 일치하지 않습니다.");
        return;
    }

    int result = isIdDuplicate(id);

    if (result == FileError) {
        QMessageBox::warning(this, "Error", "회원 정보 파일을 읽을 수 없습니다.");
        return;
    }

    if (result == Duplicate) {
        QMessageBox::warning(this, "Error", "이미 존재하는 아이디입니다.");
        return;
    }

    if (!saveMember(name, id, pw)) {
        QMessageBox::warning(this, "Error", "회원 정보 저장에 실패했습니다.");
        return;
    }

    accept();
}

void SignupDialog::on_btnCancel_clicked()
{
    reject();
}

int SignupDialog::isIdDuplicate(const QString &id)
{
    QFile file(SessionManager::getInstance().getMembersJsonPath());

    if (!file.exists()) {
        return NotDuplicate;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        return FileError;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isArray()) {
        return FileError;
    }

    QJsonArray array = doc.array();

    for (int i = 0; i < array.size(); ++i) {
        if (array[i].toObject()["id"].toString() == id) {
            return Duplicate;
        }
    }

    return NotDuplicate;
}

bool SignupDialog::saveMember(const QString &name, const QString &id, const QString &pw)
{
    QString path = SessionManager::getInstance().getMembersJsonPath();
    QFile file(path);

    QJsonArray array;

    if (file.exists()) {
        if (!file.open(QIODevice::ReadOnly)) {
            return false;
        }

        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();

        if (!doc.isArray()) {
            return false;
        }

        array = doc.array();
    }

    QJsonObject newUser;
    newUser["name"] = name;
    newUser["id"] = id;
    newUser["password"] = pw;
    array.append(newUser);

    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    file.write(QJsonDocument(array).toJson());
    file.close();
    return true;
}
