#include <QApplication>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextEdit txt;
    txt.show();

    return app.exec();
}
