#include "exitdialog.h"
#include "ui_exitdialog.h"

ExitDialog::ExitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExitDialog)
{
    ui->setupUi(this);

    this->setMaximumHeight(200);
    this->setMaximumWidth(300);
}

ExitDialog::~ExitDialog()
{
    delete ui;
}
