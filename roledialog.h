#ifndef ROLEDIALOG_H
#define ROLEDIALOG_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class RoleDialog;
}

class RoleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RoleDialog(QWidget *parent = nullptr);
    ~RoleDialog();

    QString getName();
    QString getGender();

    typedef enum {
        MALE,
        FEMALE
    } genderTypes;

public slots:
    void genderButtonsToggled(int, bool);

private:
    Ui::RoleDialog *ui;

    QString name;
    QString gender;

    QButtonGroup *genderGroup;
};

#endif // ROLEDIALOG_H
