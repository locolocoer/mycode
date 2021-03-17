#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include<QPushButton>
#include<QMessageBox>
#include "configurationdialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setFixedSize(200,300);
    ui->setupUi(this);
    connect(ui->gameBoard,&TicTacToeWidget::currentPlayerChanged,this,&MainWindow::updateNameLables);
    connect(ui->startNewGame,&QPushButton::clicked,this,&MainWindow::startNewGame);
    connect(ui->gameBoard,&TicTacToeWidget::gameOver,this,&MainWindow::handleGameOver);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabelBold(QLabel *label, bool isBold)
{
    QFont f=label->font();
    f.setBold(isBold);
    label->setFont(f);
}

void MainWindow::startNewGame()
{
  ConfigurationDialog dialog(this);
  if (dialog.exec()==QDialog::Rejected){
  return;
  }
  ui->player1Name->setText(dialog.player1Name());
  ui->player2Name->setText(dialog.player2Name());
    ui->gameBoard->initNewGame();
    qDebug()<<"button clicked";
}

void MainWindow::updateNameLables()
{
    setLabelBold(ui->player1Name,ui->gameBoard->currentPlayer()==TicTacToeWidget::Player::Player1);
    setLabelBold(ui->player2Name,ui->gameBoard->currentPlayer()==TicTacToeWidget::Player::Player2);
}

void MainWindow::handleGameOver(TicTacToeWidget::Player winner)
{
    QString message;
    if(winner==TicTacToeWidget::Player::Draw)
        message=tr("Game ended with a draw");
    else {
        QString winnerName=winner==TicTacToeWidget::Player::Player1?ui->player1Name->text():ui->player2Name->text();
        message=tr("%1 wins").arg(winnerName);
    }
    QMessageBox::information(this,tr("info"),message);
}
