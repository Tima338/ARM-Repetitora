#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "completedlessonswindow.h"
#include "weeklyplanwindow.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void openWeeklyPlan();
    void openCompletedLessons();

private:
    QVBoxLayout *mainLayout;
    CompletedLessonsWindow *completedLessonsWindow;
};

#endif // MAINWINDOW_H
