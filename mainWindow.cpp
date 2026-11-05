#include "mainWindow.h"
#include <QMessageBox>

TicTacToe::TicTacToe(QWidget *parent) : QMainWindow(parent) {
// game state init
isXTurn = true;
isOTurn = false;
movesCount = 0;
gameActive = true;
gameOver = false;
int boardButtonsTotal = 3 * 3;


centralWidget = new QWidget(this);
mainLayout = new QVBoxLayout(centralWidget);
gridLayout = new QGridLayout();

statusLabel = new QLabel("Player 1's turn", this);
statusLabel->setAlignment(Qt::AlignCenter);
statusLabel->setStyleSheet("font-size: 18px; font-weight: bold; margin-bottom: 10px;");
mainLayout->addWidget(statusLabel);

BoardButtons.resize(boardButtonsTotal);
for (int i = 0; i < boardButtonsTotal; ++i) {
    int row = i / 3;
    int col = i % 3;


    BoardButtons[i] = new QPushButton("", this);
    BoardButtons[i] -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    BoardButtons[i] -> setStyleSheet("font-size: 24px; font-weight: bold; min-width: 75px; min-height: 75px;");

    gridLayout->addWidget(BoardButtons[i], row, col);

    connect(BoardButtons[i], &QPushButton::clicked, [this, row, col]() {
        handleButtonClick(row, col);
    });

}
mainLayout->addLayout(gridLayout);
centralWidget->setLayout(mainLayout);

  
resetButton = new QPushButton("restart match", this);
resetButton->setStyleSheet("font-size: 14px; font-weight: bold; margin-top: 10px;");
connect(resetButton, &QPushButton::clicked, this, &TicTacToe::resetGame);

mainLayout->addWidget(resetButton);
setCentralWidget(centralWidget);
setWindowTitle("Tic Tac Toe");
resize(350, 400);

}

void TicTacToe::handleButtonClick(int row, int col)
{
    int index = row * 3 + col;


    if (!BoardButtons[index]->text().isEmpty() || !gameActive || gameOver) {
        return;
    }

    QString currentToken = isXTurn ? "X" : "O";
    BoardButtons[index]->setText(currentToken);
    movesCount++;

    checkState();



}

void TicTacToe::checkState()
{
    if (checkWin("X")){
        statusLabel->setText("Player 1 wins! (X)");

        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Game Over");
        msgBox.setText("Player 1 wins! (X)");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet("QLabel#qt_msgbox_label { min-width: 250px; }");
        msgBox.exec();
        gameOver = true;
        gameActive = false;
    }
    else if (checkWin("O")){
        statusLabel->setText("Player 2 wins! (O)");
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Game Over");
        msgBox.setText("Player 2 wins! (O)");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet("QLabel#qt_msgbox_label { min-width: 250px; }");
        msgBox.exec();
        gameOver = true;
        gameActive = false;
    }
    else if (movesCount == 9){
        statusLabel->setText("It's a draw!");
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Game Over");
        msgBox.setText("No remaining moves left. It's a draw!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet("QLabel#qt_msgbox_label { min-width: 250px; }");
        msgBox.exec();
        gameOver = true;
        gameActive = false;
    }
    else {
        isXTurn = !isXTurn;
        isOTurn = !isOTurn;
        statusLabel->setText(QString("Player %1's turn (%2)").arg(isXTurn ? "1" : "2").arg(isXTurn ? "X" : "O"));

    }

}

bool TicTacToe::checkWin(const QString &player)
{
    const int lines [8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };


    for (int i = 0; i < 8; ++i)
    {
        if (BoardButtons[lines[i][0]]->text() == player &&
            BoardButtons[lines[i][1]]->text() == player &&
            BoardButtons[lines[i][2]]->text() == player) {
            return true;
        }
    }

    return false;

}

void TicTacToe::resetGame(){
    for (QPushButton* btn : BoardButtons) {
        btn->setText("");
    }
    isXTurn = true;
    isOTurn = false;
    movesCount = 0;
    gameActive = true;
    gameOver = false;
    statusLabel->setText("Player 1's turn (X)");
}