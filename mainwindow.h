#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_key_equals_clicked();
    void handleKeyClicked();
    void on_key_clear_clicked();
    void dotHandle();
    void handleClearHistory();
    void handleAbout();
    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;
    double lastResult = 0;
    bool hasLastResult = false;
};

#endif // MAINWINDOW_H
