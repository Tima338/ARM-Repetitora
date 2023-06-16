#ifndef COMPLETEDLESSONSWINDOW_H
#define COMPLETEDLESSONSWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QRandomGenerator>
#include <QSet>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDate>

class CompletedLessonsWindow : public QDialog {
    Q_OBJECT

public:
    CompletedLessonsWindow(QWidget *parent = nullptr);

private slots:
    void addLesson();

private:
    QTableWidget *table;

    QStringList generateRandomNames(int count);
};

#endif // COMPLETEDLESSONSWINDOW_H
