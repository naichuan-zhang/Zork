#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);

    ui->tableView->setShowGrid(true);
    ui->tableView->setSortingEnabled(false);
    ui->tableView->horizontalHeader()->setSectionsClickable(false);
    ui->tableView->setGridStyle(Qt::DashDotLine);
    ui->tableView->setFrameShape(QFrame::NoFrame);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    QHeaderView *headView = ui->tableView->verticalHeader();
    headView->setHidden(true);

    QStandardItemModel *model = new QStandardItemModel();
    QStringList labels = QObject::tr("ID No.,Name").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    model->setItem(0, 0, new QStandardItem("18111521"));
    model->setItem(0, 1, new QStandardItem("Naichuan Zhang"));
    model->setItem(1, 0, new QStandardItem("18111211"));
    model->setItem(1, 1, new QStandardItem("Xinyi An"));

    ui->tableView->setModel(model);
    ui->tableView->setStyleSheet("QTableView { border:none;"
                                 "selection-background-color:#8EDE21;"
                                 "color:blue }");
    ui->tableView->show();
}

Help::~Help()
{
    delete ui;
}
