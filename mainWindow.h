
#pragma once

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QVector>
#include <QDebug>


class TicTacToe : public QMainWindow {
    Q_OBJECT



    public:
        TicTacToe(QWidget *parent = nullptr);
        ~TicTacToe() = default;

    private slots:
        void handleButtonClick(int row, int col);
        void resetGame();


    private:
        void checkState();
        bool checkWin(const QString &player);

        QWidget *centralWidget;
        QBoxLayout *mainLayout;
        QGridLayout *gridLayout;
        QLabel *statusLabel;
        QPushButton *resetButton;
        QVector<QPushButton*> BoardButtons;

        bool isXTurn;
        bool isOTurn;
        int movesCount;
        bool gameOver;
        bool gameActive;





};


