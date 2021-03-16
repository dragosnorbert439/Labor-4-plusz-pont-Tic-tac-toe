#include "mainwindow.h"
#include "rButton.h"
#include <QApplication>
#include <QVBoxLayout>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *window = new QWidget();
    rButton *rBttn = new rButton(); rBttn->setText("This does something...");

    layout->addWidget(rBttn);
    window->setLayout(layout);
    w.setCentralWidget(window);
    w.show();

    return a.exec();
}
