
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <iostream>
#include <QImage>
#include <QPixmap>
#include <QMessageBox>
#include <Qtcore>
#include <QResource>
#include <QDir>
#include <QStandardPaths>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings settings("QtAICenter.ini",QSettings::Format::IniFormat);
    settings.setValue("Group_1/Value_1","Qt");
    settings.setValue("Group_1/Value_2","AI");
    settings.setValue("Group_1/Value_3","Center");

    settings.setValue("Group_2/Value_1","Qt");
    settings.setValue("Group_2/Value_2","AI");
    settings.setValue("Group_2/Value_3","Center");

    settings.setValue("Sigle_Value","Qt AI Center");

    QSettings settings_2("QtAICenter_2.ini",QSettings::Format::IniFormat);
    ui->textBrowser->append(settings_2.value("Sigle_Value").toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_2_clicked()
{
//    Read value from ini
    QSettings settings("QtAICenter.ini",QSettings::Format::IniFormat);

    settings.beginGroup("Group_1");
    const QStringList keyList_1 = settings.childKeys();
    foreach (QString Keyname, keyList_1) {
        qDebug() << settings.value(Keyname);
    }
    settings.endGroup();

//    qDebug() << settings.value("Group_1/Value_1") << settings.value("Group_1/Value_2") << settings.value("Group_1/Value_3");
//    qDebug() << settings.value("Group_2/Value_1") << settings.value("Group_2/Value_2") << settings.value("Group_2/Value_3");
}

void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    QSettings settings_2("QtAICenter_2.ini",QSettings::Format::IniFormat);
    if (!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);
        QString filePath = fileInfo.absolutePath();
        ui->lineEdit->setText(filePath);
        settings_2.setValue("Sigle_Value",filePath);
    }
}




void MainWindow::on_pushButton_4_clicked()
{
    QSettings settings_2("QtAICenter_2.ini",QSettings::Format::IniFormat);
    qDebug() << settings_2.value("Sigle_Value");
    ui->textBrowser->append(settings_2.value("Sigle_Value").toString());
}

