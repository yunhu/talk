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
  //   qDebug()<<QCoreApplication::libraryPaths ();
           QSqlDatabase db( QSqlDatabase::addDatabase( "QSQLITE" ) );
            db.setDatabaseName("talk.db");
            db.setUserName("root");
            db.setPassword("tiger");


            if(!db.open())/*测试数据库是否链接成功*/
            {
               QMessageBox::critical(0, QObject::tr("Databse Error"), db.lastError().text());
               qDebug()<<db.lastError()<<endl;
            }
            else
            {
                 QSqlQuery sql_query;
                   //     QString table =  "create table user (id int primary key, name varchar(30), pass varchar(30))";
                 QString insert = "insert into user values(3, 'zhangyh2','tigera')";
                 QString update = "update user set name='zhangyunhu' where id = 1";
                 QString del = "delete from user where name ='zhangyh'";

                 QString select_all = "select * from user";

                        sql_query.prepare(select_all);

                       // sql_query.addBindValue(1);
                        //sql_query.addBindValue("tiger");
                        //sql_query.addBindValue("tigera");
                        if(!sql_query.exec())
                        {
                            qDebug()<<sql_query.lastError();
                        }
                        else
                        {
                            while(sql_query.next()){
                                int id = sql_query.value(0).toInt();
                                QString name = sql_query.value(1).toString();
                                QString pass   = sql_query.value(2).toString();
                                qDebug()<< id << name << pass;
                            }
                        }
            }
 }

}

void talk::on_pushButton_clicked() {
    d1.show();
}


