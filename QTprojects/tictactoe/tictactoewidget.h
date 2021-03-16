#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H
#include <QPushButton>
#include <QWidget>

class TicTacToeWidget : public QWidget
{
    Q_OBJECT
public:
    enum class Player{
        Invalid,Player1,Player2,Draw
    };
    Q_ENUM(Player)
    Player currentPlayer() const;
    Player checkWinCondition();
    void setCurrentPlayer(Player p);
    void initNewGame();
    explicit TicTacToeWidget(QWidget *parent = 0);
    TicTacToeWidget::Player checkWinConditionForLine(int index1, int index2, int index3) const;
private:
    Player m_currentPlayer;
    QVector<QPushButton*> m_board;
signals:
    void currentPlayerChanged(Player);
    void gameOver(Player);
public slots:
private slots:
    void handleButtonClick(int index);
};

#endif // TICTACTOEWIDGET_H
