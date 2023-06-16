#include "completedlessonswindow.h"

CompletedLessonsWindow::CompletedLessonsWindow(QWidget *parent)
    : QDialog(parent) {
    setWindowTitle("Проведенные занятия");
    setGeometry(100, 100, 600, 600);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    table = new QTableWidget(this);
    table->setGeometry(10, 10, 580, 280);

    int rowCount = 15;
    int columnCount = 4;

    table->setRowCount(rowCount);
    table->setColumnCount(columnCount);

    QStringList headers;
    headers << "Имя" << "Дата" << "Продолжительность" << "Стоимость";
    table->setHorizontalHeaderLabels(headers);

    table->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    table->verticalHeader()->setDefaultAlignment(Qt::AlignHCenter);

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStringList studentNames = generateRandomNames(rowCount);

    for (int row = 0; row < rowCount; ++row) {
        QTableWidgetItem *itemName = new QTableWidgetItem(studentNames.at(row));
        table->setItem(row, 0, itemName);

        QDate date = QDate(2023, 5, 1).addDays(QRandomGenerator::global()->bounded(31));
        QTableWidgetItem *itemDate = new QTableWidgetItem(date.toString("yyyy.MM.dd"));
        table->setItem(row, 1, itemDate);

        QTableWidgetItem *itemDuration = new QTableWidgetItem("60 мин");
        table->setItem(row, 2, itemDuration);

        QTableWidgetItem *itemCost = new QTableWidgetItem("600");
        table->setItem(row, 3, itemCost);
    }

    mainLayout->addWidget(table);

    QPushButton *addButton = new QPushButton("Добавить занятие");
    connect(addButton, &QPushButton::clicked, this, &CompletedLessonsWindow::addLesson);
    mainLayout->addWidget(addButton);

    setLayout(mainLayout);
}

QStringList CompletedLessonsWindow::generateRandomNames(int count) {
    QStringList names;
    QStringList surnames;
    names << "Иван" << "Александр" << "Николай" << "Василий" << "Павел";
    surnames << "Иванов" << "Петров" << "Сидоров" << "Смирнов" << "Кузнецов";

    QStringList randomNames;
    for (int i = 0; i < count; ++i) {
        QString name = names.at(QRandomGenerator::global()->bounded(names.size()));
        QString surname = surnames.at(QRandomGenerator::global()->bounded(surnames.size()));
        randomNames << QString("%1 %2").arg(name).arg(surname);
    }
    return randomNames;
}

void CompletedLessonsWindow::addLesson() {
    int newRow = table->rowCount();
    table->insertRow(newRow);
}
