#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool ok;

    // Зчитуємо тризначне число з поля вводу
    int n = ui->le_input->text().toInt(&ok);

    // Перевірка коректності введення
    if (!ok || n < 100 || n > 999) {
        QMessageBox::warning(this, "Помилка", "Введіть тризначне ціле число (100–999)!");
        ui->le_input->clear();
        ui->l_result->setText("—");
        ui->le_input->setFocus();
        return;
    }

    // Знаходимо першу (ліву) цифру — сотні
    int hundreds = n / 100;

    // Залишок — останні дві цифри
    int rest = n % 100;

    // Приписуємо першу цифру справа
    int result = rest * 10 + hundreds;

    // Виводимо результат
    ui->l_result->setText(QString::number(result));
}

void MainWindow::on_actionLoad_from_file_triggered()
{
    // Відкриваємо діалог вибору файлу для читання
    QString filePath = QFileDialog::getOpenFileName(this, "Open file",
                                                    QDir::currentPath(), "Текстові файли (*.txt);;Усі файли (*)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Error", "Can not open file!");
        } else {
            QTextStream in(&file);
            QString val;
            in >> val;
            // Підставляємо зчитане значення у поле вводу
            ui->le_input->setText(val);
            file.close();
        }
    } else {
        QMessageBox::warning(this, "Error", "Unknown filename!");
    }
}

void MainWindow::on_actionSave_to_file_triggered()
{
    // Відкриваємо діалог вибору файлу для збереження
    QString filePath = QFileDialog::getSaveFileName(this, "Save file",
                                                    QDir::currentPath(), "Текстові файли (*.txt);;Усі файли (*)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Can not open file:\n" + file.errorString());
        } else {
            QTextStream out(&file);
            // Зберігаємо вхідне число і результат
            out << ui->le_input->text() << "\n";
            out << ui->l_result->text() << "\n";
            file.close();
        }
    } else {
        QMessageBox::warning(this, "Error", "Unknown filename!");
    }
}