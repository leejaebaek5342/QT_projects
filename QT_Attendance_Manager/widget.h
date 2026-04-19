#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include "teachersignup.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private slots:

    void on_TeacherButton_2_clicked();

    void on_StudentButton_2_clicked();

    void on_signupbutton_clicked();

    void on_backbutton_clicked();

    void on_loginbutton_clicked();

    void on_regisbutton_clicked();

    void on_savebutton_clicked();

    void on_logoutbutton_clicked();

    void on_viewbutton_clicked();

    void on_goback_clicked();

    void on_gobackbutton_clicked();

    void on_goback_2_clicked();

    void on_Checkbutton_clicked();

private:
    Ui::Widget *ui;
    void resetTeacherSessionData();
    QString teacherStudentsFilePath(const QString &teacherId) const;
    QString teacherAttendanceFilePath(const QString &teacherId) const;
    QString sanitizeFileComponent(const QString &value) const;
    QString selectedStudentId() const;
    int isDuplicateStudentId(const QString &studentId);
    void loadStudentsToTable();
    int saveAttendanceByDate();
    void loadStudentsToComboBox();
    void loadStudentAttendanceforteach(const QString &studentName, const QString &studentId);
    int checkStudentInfo(const QString &name, const QString &id);
    void loadStudentAttendanceforst(const QString &name, const QString &id);
    teachersignup *ts;
    QString currentTeacherId;

};
#endif // WIDGET_H
