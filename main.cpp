#include <QApplication>
#include <mainwindow.h>
int main(int argc, char **argv)
{
 QApplication app (argc, argv);
 MainWindow mwin;
 mwin.show();
 return app.exec();
}
