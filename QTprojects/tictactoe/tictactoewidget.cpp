#include "tictactoewidget.h"

#include <QGridLayout>
#include <QSignalMapper>

TicTacToeWidget::Player TicTacToeWidget::currentPlayer() const
{
    return m_currentPlayer;
}

TicTacToeWidget::Player TicTacToeWidget::checkWinConditionForLine(
        int index1, int index2, int index3) const {
    QString text1 = m_board[index1]->text();
    if (text1 == " ") {
        return Player::Invalid;
    }
    QString text2 = m_board[index2]->text();
    QString text3 = m_board[index3]->text();
    if (text1 == text2 && text1 == text3) {
        return text1 == "X" ? Player::Player1 : Player::Player2;
    }
    return Player::Invalid;
}

TicTacToeWidget::Player TicTacToeWidget::checkWinCondition()
{
    Player result=Player::Invalid;
    for(int row=0;row<3;row++){
       result= checkWinConditionForLine(3*row,3*row+1,3*row+2);
       if (result != Player::Invalid) {
                  return result;
              }

    }
    for(int colmn=0;colmn<3;colmn++){
        result=checkWinConditionForLine(colmn,colmn+3,colmn+6);
        if(result!=Player::Invalid)
            return result;
    }
    result = checkWinConditionForLine(0, 4, 8);
       if (result != Player::Invalid) {
           return result;
       }
       result = checkWinConditionForLine(2, 4, 6);
       if (result != Player::Invalid) {
           return result;
       }
       // check if there are unoccupied fields left
       for(QPushButton *button: m_board) {
           if(button->text() == " ") {
               return Player::Invalid;
           }
       }
       return Player::Draw;
}

void TicTacToeWidget::setCurrentPlayer(TicTacToeWidget::Player p)
{
    if(m_currentPlayer==p)
        return;
    m_currentPlayer=p;
    emit currentPlayerChanged(p);
}

void TicTacToeWidget::initNewGame()
{
    for(QPushButton *button:m_board){
        button->setText(" ");
        setCurrentPlayer(Player::Player1);
    }
}

TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent)
{
    m_currentPlayer=Player::Invalid;
    QGridLayout *gridLayout=new QGridLayout(this);
    QSignalMapper *mapper=new QSignalMapper(this);
for (int row=0;row<3;++row){
    for (int column=0;column<3;++column){
        QPushButton *button =new QPushButton(" ");
        button->setFixedSize(60,60);
        gridLayout->addWidget(button,row,column);
        m_board.append(button);
        mapper->setMapping(button,m_board.count()-1);
        connect(button,SIGNAL(clicked()),mapper,SLOT(map()));
    }
}
connect(mapper,SIGNAL(mapped(int)),this,SLOT(handleButtonClick(int)));
}

void TicTacToeWidget::handleButtonClick(int index)
{
    if (m_currentPlayer==Player::Invalid){
        return; //game is not started

    }
    if(index<0||index>=m_board.size()){
            return; //out of bounds check

    }
    QPushButton *button=m_board[index];
    if(button->text()!=" ")return; //invalid move
    button->setText(currentPlayer()==Player::Player1?"X":"O");
    Player winner =checkWinCondition();
    if(winner==Player::Invalid){
        setCurrentPlayer(currentPlayer()==Player::Player1?Player::Player2:Player::Player1);
        return;
    }
    else{
        emit gameOver(winner);
    }

}
