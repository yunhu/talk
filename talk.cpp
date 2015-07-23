#include "talk.h"
#include "ui_talk.h"
#include <QDebug>
#include <QMessageBox>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlDriver>
#include<QtSql/QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>

talk::talk(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::talk)
{
    ui->setupUi(this);
}

talk::~talk()
{
    delete ui;
}




void talk::on_pushButton_2_clicked() {
//
 QString name = ui->lineEdit->text();
 QString pass  = ui->lineEdit_2->text();


 if (name.isEmpty() || pass.isEmpty()) {
      QMessageBox::warning(this,"Error","用户名和密码不能为空",QMessageBox::Close);
 }else{
     //connect mysql
     qDebug()<<QCoreApplication::libraryPaths ();



     QSqlDatabase db( QSqlDatabase::addDatabase( "QMYSQL" ) );
             db.setHostName("localhost");
             db.setDatabaseName("qt");
             db.setUserName("root");
             db.setPassword("tier");


             if(db.open())/*测试数据库是否链接成功*/
             {
                QMessageBox::critical(0, QObject::tr("Databse Error"), db.lastError().text());
                qDebug()<<db.lastError()<<endl;
             }
             else
             {
                qDebug()<<"Ok"<<endl;
             }
 }

}

void talk::on_pushButton_clicked() {
    d1.show();
}


