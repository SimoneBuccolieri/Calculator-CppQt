#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Display per il risultato
    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setText("0");
    layout->addWidget(display);

    // Crea i pulsanti numerici
    QGridLayout *gridLayout = new QGridLayout();
    QStringList buttons = {"7", "8", "9", "+",
                           "4", "5", "6", "-",
                           "1", "2", "3", "*",
                           "C", "0", "=", "/"};

    int row = 0, col = 0;
    for (const QString &text : buttons) {
        QPushButton *button = new QPushButton(text, this);
        gridLayout->addWidget(button, row, col);
        col++;
        if (col > 3) {
            col = 0;
            row++;
        }

        connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    }

    layout->addLayout(gridLayout);
}

MainWindow::~MainWindow() {}

void MainWindow::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString buttonText = button->text();
    QString currentText = display->text();

    if (buttonText == "C") {
        display->setText("0");
        previousNumber = 0;
        pendingOperation = "";

    } else if (buttonText == "+" || buttonText == "-" || buttonText == "*" || buttonText == "/") {
        // Salva il numero attuale e l'operazione selezionata
        previousNumber = currentText.toDouble();
        pendingOperation = buttonText;

    } else if (buttonText == "=") {
        double currentNumber = currentText.toDouble();
        double result = 0;

        if (pendingOperation == "+") {
            result = previousNumber + currentNumber;
        } else if (pendingOperation == "-") {
            result = previousNumber - currentNumber;
        } else if (pendingOperation == "*") {
            result = previousNumber * currentNumber;
        } else if (pendingOperation == "/") {
            if (currentNumber != 0)
                result = previousNumber / currentNumber;
            else {
                display->setText("Errore: Div. per 0");
                return;
            }
        }

        display->setText(QString::number(result));
        pendingOperation = "";

    } else {
        // Aggiunge numeri al display
        if (currentText == "0") {
            display->setText(buttonText);
        } else {
            if (pendingOperation =="")
                display->setText(currentText + buttonText);
            else
                display->setText(buttonText);
        }
    }
}