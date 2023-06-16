#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent) {
    setWindowTitle("Расписание");
    setGeometry(100, 100, 200, 100);

    mainLayout = new QVBoxLayout(this);

    QPushButton *weeklyPlanButton = new QPushButton("Недельный план");
    connect(weeklyPlanButton, &QPushButton::clicked, this, &MainWindow::openWeeklyPlan);
    mainLayout->addWidget(weeklyPlanButton);

    QPushButton *completedLessonsButton = new QPushButton("Проведенные занятия");
    connect(completedLessonsButton, &QPushButton::clicked, this, &MainWindow::openCompletedLessons);
    mainLayout->addWidget(completedLessonsButton);

    completedLessonsWindow = new CompletedLessonsWindow();

    setLayout(mainLayout);
}

void MainWindow::openWeeklyPlan() {
    WeeklyPlanWindow *weeklyPlanWindow = new WeeklyPlanWindow();
    weeklyPlanWindow->exec();
}

void MainWindow::openCompletedLessons() {
    completedLessonsWindow->show();
}
