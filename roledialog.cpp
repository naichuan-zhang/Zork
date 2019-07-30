#include "roledialog.h"
#include "ui_roledialog.h"

#include <QMessageBox>

#define MESSAGE \
    tr("Please enter your role name: ")
#define MESSAGE2 \
    tr("Please select your gender: ")

RoleDialog::RoleDialog(QWidget *parent) :
    QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::RoleDialog)
{
    ui->setupUi(this);

    setWindowTitle(tr("Create Role"));

    ui->label->setText(MESSAGE);
    ui->label->setStyleSheet("{font:arial;}");

    ui->label2->setText(MESSAGE2);
    ui->label2->setStyleSheet("{font:arial;}");

    ui->nameEdit->setEchoMode(QLineEdit::Normal);

    ui->maleRadioButton->setText("&Male");
    ui->maleRadioButton->setChecked(true);
    ui->femaleRadioButton->setText("&Female");
    ui->femaleRadioButton->setChecked(false);

    genderGroup = new QButtonGroup(this);
    genderGroup->addButton(ui->maleRadioButton, MALE);
    genderGroup->addButton(ui->femaleRadioButton, FEMALE);

    connect(genderGroup, SIGNAL(buttonToggled(int, bool)), this, SLOT(genderButtonsToggled(int, bool)));
}

RoleDialog::~RoleDialog()
{
    delete ui;
}

QString RoleDialog::getName()
{
    if (!(ui->nameEdit->text().isEmpty()))
    {
        name = ui->nameEdit->text();
        return name;
    }

    else
    {
        QMessageBox::warning(this, tr("Alert"), tr("No input!"), QMessageBox::Yes);
        return nullptr;
    }
}

QString RoleDialog::getGender()
{
    gender = genderGroup->checkedButton()->text();
    return gender;
}

void RoleDialog::genderButtonsToggled(int id, bool status)
{
    int tmp = genderGroup->checkedId();
    QString str = genderGroup->checkedButton()->text();
    QByteArray byteArray = str.toLocal8Bit();
    qDebug("flag = %d, status = %d, tmp = %d, checked = %s", id, status, tmp, byteArray.data());
}
