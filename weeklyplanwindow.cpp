#include "weeklyplanwindow.h"

WeeklyPlanWindow::WeeklyPlanWindow(QWidget *parent)
    : QDialog(parent) {
    setWindowTitle("Расписание");
    setGeometry(100, 100, 1100, 400);

    table = new QTableWidget(this);
    table->setGeometry(10, 10, 1000, 385);

    int rowCount = 12;
    int columnCount = 6;

    table->setRowCount(rowCount);
    table->setColumnCount(columnCount);

    QStringList headers;
    headers << "Понедельник" << "Вторник" << "Среда" << "Четверг" << "Пятница" << "Суббота";
    table->setHorizontalHeaderLabels(headers);

    QStringList timeIntervals;
    timeIntervals << "8:00-9:00" << "9:00-10:00" << "10:00-11:00" << "11:00-12:00"
                  << "12:00-13:00" << "13:00-14:00" << "14:00-15:00" << "15:00-16:00"
                  << "16:00-17:00" << "17.00-18.00" << "18.00-19.00" << "19.00-20.00";
    table->setVerticalHeaderLabels(timeIntervals);

    table->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    table->verticalHeader()->setDefaultAlignment(Qt::AlignHCenter);

    table->setColumnWidth(0, 100);
    for (int col = 0; col < columnCount; ++col) {
        table->setColumnWidth(col, 150);
    }

    QStringList studentNames = generateRandomNames(rowCount * columnCount);

    QSet<int> filledCells;

    for (int col = 1; col <= columnCount; ++col) {
        int filledCellCount = QRandomGenerator::global()->bounded(2, 4);
        filledCells.clear();

        while (filledCells.size() < filledCellCount) {
            int row = QRandomGenerator::global()->bounded(rowCount);
            filledCells.insert(row);
        }

        foreach (int row, filledCells) {
            QTableWidgetItem *item = new QTableWidgetItem(studentNames.at(row * columnCount + col - 1));
            table->setItem(row, col, item);
        }
    }
}

QStringList WeeklyPlanWindow::generateRandomNames(int count) {
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
