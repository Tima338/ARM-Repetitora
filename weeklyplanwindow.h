#ifndef WEEKLYPLANWINDOW_H
#define WEEKLYPLANWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QRandomGenerator>

class WeeklyPlanWindow : public QDialog {
    Q_OBJECT

public:
    WeeklyPlanWindow(QWidget *parent = nullptr);

private:
    QTableWidget *table;

    QStringList generateRandomNames(int count);
};

#endif // WEEKLYPLANWINDOW_H
