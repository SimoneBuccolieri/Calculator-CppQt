#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    private slots:
        void onButtonClicked();

private:
    QLineEdit *display;
    double previousNumber;  // Memorizza il primo numero dell'operazione
    QString pendingOperation;  // Memorizza l'operazione in corso
};

#endif // MAINWINDOW_H
