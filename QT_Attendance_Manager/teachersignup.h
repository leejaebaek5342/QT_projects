#ifndef TEACHERSIGNUP_H
#define TEACHERSIGNUP_H

#include <QWidget>

namespace Ui {
class teachersignup;
}

class teachersignup : public QWidget
{
    Q_OBJECT

public:
    explicit teachersignup(QWidget *parent = nullptr);
    int isDuplicateId(const QString &id);
    bool saveTeacher(const QString &name, const QString &id, const QString &pw);
    ~teachersignup();

private slots:
    void on_Closebutton_clicked();

    void on_Signupbutton_clicked();

private:
    Ui::teachersignup *ui;
};

#endif // TEACHERSIGNUP_H
