#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QPair>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; w.setFixedSize(QSize(404,512));

    QGridLayout *layout = new QGridLayout;
    QWidget *window = new QWidget();
    window->setFixedHeight(480);
    window->setFixedWidth(404);

    QPushButton *button11 = new QPushButton(); button11->setStyleSheet("height: 128px;width: 128px;"); button11->setMaximumWidth(128); button11->setMaximumHeight(128);
    QPushButton *button12 = new QPushButton(); button12->setStyleSheet("height: 128px;width: 128px;"); button12->setMaximumWidth(128); button12->setMaximumHeight(128);
    QPushButton *button13 = new QPushButton(); button13->setStyleSheet("height: 128px;width: 128px;"); button13->setMaximumWidth(128); button13->setMaximumHeight(128);
    QPushButton *button21 = new QPushButton(); button21->setStyleSheet("height: 128px;width: 128px;"); button21->setMaximumWidth(128); button21->setMaximumHeight(128);
    QPushButton *button22 = new QPushButton(); button22->setStyleSheet("height: 128px;width: 128px;"); button22->setMaximumWidth(128); button22->setMaximumHeight(128);
    QPushButton *button23 = new QPushButton(); button23->setStyleSheet("height: 128px;width: 128px;"); button23->setMaximumWidth(128); button23->setMaximumHeight(128);
    QPushButton *button31 = new QPushButton(); button31->setStyleSheet("height: 128px;width: 128px;"); button31->setMaximumWidth(128); button31->setMaximumHeight(128);
    QPushButton *button32 = new QPushButton(); button32->setStyleSheet("height: 128px;width: 128px;"); button32->setMaximumWidth(128); button32->setMaximumHeight(128);
    QPushButton *button33 = new QPushButton(); button33->setStyleSheet("height: 128px;width: 128px;"); button33->setMaximumWidth(128); button33->setMaximumHeight(128);
    QPushButton *buttonReset = new QPushButton();

    QPixmap buttonResetImage("../TTTReset.jpg");
    QPixmap buttonEmptyImage("../TTTEmpty.jpg");
    QPixmap buttonX("../TTTX.jpg");
    QPixmap buttonO("../TTTO.jpg");
    QIcon resetIcon, emptyIcon, xIcon, oIcon;
    resetIcon.addPixmap ( buttonResetImage, QIcon::Normal, QIcon::Off );
    emptyIcon.addPixmap ( buttonEmptyImage, QIcon::Normal, QIcon::Off );
    xIcon.addPixmap ( buttonX, QIcon::Normal, QIcon::Off );
    oIcon.addPixmap ( buttonO, QIcon::Normal, QIcon::Off );
    buttonReset->setIcon(resetIcon);
    buttonReset->setIconSize(QSize(50,20));
    button11->setIcon(emptyIcon); button11->setIconSize(QSize(120,120));
    button12->setIcon(emptyIcon); button12->setIconSize(QSize(120,120));
    button13->setIcon(emptyIcon); button13->setIconSize(QSize(120,120));
    button21->setIcon(emptyIcon); button21->setIconSize(QSize(120,120));
    button22->setIcon(emptyIcon); button22->setIconSize(QSize(120,120));
    button23->setIcon(emptyIcon); button23->setIconSize(QSize(120,120));
    button31->setIcon(emptyIcon); button31->setIconSize(QSize(120,120));
    button32->setIcon(emptyIcon); button32->setIconSize(QSize(120,120));
    button33->setIcon(emptyIcon); button33->setIconSize(QSize(120,120));


    layout->setVerticalSpacing(5);
    layout->setHorizontalSpacing(5);

    layout->addWidget(button11, 0, 0);
    layout->addWidget(button12, 0, 1);
    layout->addWidget(button13, 0, 2);
    layout->addWidget(button21, 1, 0);
    layout->addWidget(button22, 1, 1);
    layout->addWidget(button23, 1, 2);
    layout->addWidget(button31, 2, 0);
    layout->addWidget(button32, 2, 1);
    layout->addWidget(button33, 2, 2);
    layout->addWidget(buttonReset, 3, 2);

    short round = 0;
    short m[3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m[i][j] = 0;
    bool ok;

    QPair<int, int> winnerTiles[] = { {0,0}, {0,0}, {0,0}};
    QPushButton * buttonMatrix[3][3];
    buttonMatrix[0][0] = button11;
    buttonMatrix[0][1] = button12;
    buttonMatrix[0][2] = button13;
    buttonMatrix[1][0] = button21;
    buttonMatrix[1][1] = button22;
    buttonMatrix[1][2] = button23;
    buttonMatrix[2][0] = button31;
    buttonMatrix[2][1] = button32;
    buttonMatrix[2][2] = button33;

    auto isWinner = [&](int ii, int jj)
    {
        ok = true;
        for (int i = 0; i < 3; ++i)
        {
            if (m[i][jj] != m[ii][jj]) ok = false;
            winnerTiles[i] = { i, jj };
        }

        if (ok) return true;

        ok = true;
        for (int j = 0; j < 3; ++j)
        {
            if (m[ii][j] != m[ii][jj]) ok = false;
            winnerTiles[j] = { ii, j };
        }
        if (ok) return true;

        ok = true;
        if (m[0][0] != m[ii][jj] || m[1][1] != m[ii][jj] || m[2][2] != m[ii][jj]) ok = false;
        winnerTiles[0] = {0,0}; winnerTiles[1] = {1,1}; winnerTiles[2] = {2,2};
        if (ok) return true;

        ok = true;
        if (m[2][0] != m[ii][jj] || m[1][1] != m[ii][jj] || m[0][2] != m[ii][jj]) ok = false;
        winnerTiles[0] = {2,0}; winnerTiles[1] = {1,1}; winnerTiles[2] = {0,2};
        if (ok) return true;

        return false;
    };

    auto showWinner = [&](int ii, int jj)
    {
        if (round > 4)
        {
            if (isWinner(ii, jj))
            {
                if (round % 2)
                {
                    QPixmap buttonImage("../TTTX_w.jpg");
                    QIcon winIcon;
                    winIcon.addPixmap ( buttonImage, QIcon::Normal, QIcon::Off );
                    for (auto tile : winnerTiles)
                    {
                        buttonMatrix[tile.first][tile.second]->setIcon(winIcon);
                    }
                    QMessageBox::information(nullptr, "Game over", "X wins", QMessageBox::Discard | QMessageBox::Cancel);
                }
                else
                {
                    QPixmap buttonImage("../TTTO_w.jpg");
                    QIcon winIcon;
                    winIcon.addPixmap ( buttonImage, QIcon::Normal, QIcon::Off );
                    for (auto tile : winnerTiles)
                    {
                        buttonMatrix[tile.first][tile.second]->setIcon(winIcon);
                    }
                    QMessageBox::information(nullptr, "Game over", "O wins", QMessageBox::Discard | QMessageBox::Cancel);
                }
            }
        }
    };

    w.connect(buttonReset, &QPushButton::clicked, [&]()
    {
        button11->setIcon(emptyIcon);
        button12->setIcon(emptyIcon);
        button13->setIcon(emptyIcon);
        button21->setIcon(emptyIcon);
        button22->setIcon(emptyIcon);
        button23->setIcon(emptyIcon);
        button31->setIcon(emptyIcon);
        button32->setIcon(emptyIcon);
        button33->setIcon(emptyIcon);
        round = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                m[i][j] = 0;
    });


    // 1-1
    w.connect(button11, &QPushButton::clicked, [&]()
    {
        if (!m[0][0])
        {
            if (! (round % 2))
            {
                button11->setIcon(xIcon); ++round; m[0][0] = 1;
            }
            else
            {
                button11->setIcon(oIcon); ++round; m[0][0] = -1;
            }
        }
        showWinner(0,0);
    });

    // 1-2
    w.connect(button12, &QPushButton::clicked, [&]()
    {
        if (!m[0][1])
        {
            if (! (round % 2))
            {
                button12->setIcon(xIcon); ++round; m[0][1] = 1;
            }
            else
            {
                button12->setIcon(oIcon); ++round; m[0][1] = -1;
            }
        }
        showWinner(0,1);
    });

    // 1-3
    w.connect(button13, &QPushButton::clicked, [&]()
    {
        if (!m[0][2])
        {
            if (! (round % 2))
            {
                button13->setIcon(xIcon); ++round; m[0][2] = 1;
            }
            else
            {
                button13->setIcon(oIcon); ++round; m[0][2] = -1;
            }
        }
        showWinner(0,2);
    });


    // 2-1
    w.connect(button21, &QPushButton::clicked, [&]()
    {
        if (!m[1][0])
        {
            if (! (round % 2))
            {
                button21->setIcon(xIcon); ++round; m[1][0] = 1;
            }
            else
            {
                button21->setIcon(oIcon); ++round; m[1][0] = -1;
            }
        }
        showWinner(1,0);
    });

    // 2-2
    w.connect(button22, &QPushButton::clicked, [&]()
    {
        if (!m[1][1])
        {
            if (! (round % 2))
            {
                button22->setIcon(xIcon); ++round; m[1][1] = 1;
            }
            else
            {
                button22->setIcon(oIcon); ++round; m[1][1] = -1;
            }
        }
        showWinner(1,1);
    });

    // 2-3
    w.connect(button23, &QPushButton::clicked, [&]()
    {
        if (!m[1][2])
        {
            if (! (round % 2))
            {
                button23->setIcon(xIcon); ++round; m[1][2] = 1;
            }
            else
            {
                button23->setIcon(oIcon); ++round; m[1][2] = -1;
            }
        }
        showWinner(1,2);
    });

    // 3-1
    w.connect(button31, &QPushButton::clicked, [&]()
    {
        if (!m[2][0])
        {
            if (! (round % 2))
            {
                button31->setIcon(xIcon); ++round; m[2][0] = 1;
            }
            else
            {
                button31->setIcon(oIcon); ++round; m[2][0] = -1;
            }
        }
        showWinner(2,0);
    });

    // 3-2
    w.connect(button32, &QPushButton::clicked, [&]()
    {
        if (!m[2][1])
        {
            if (! (round % 2))
            {
                button32->setIcon(xIcon); ++round; m[2][1] = 1;
            }
            else
            {
                button32->setIcon(oIcon); ++round; m[2][1] = -1;
            }
        }
        showWinner(2,1);
    });

    // 3-3
    w.connect(button33, &QPushButton::clicked, [&]()
    {
        if (!m[2][2])
        {
            if (! (round % 2))
            {
                button33->setIcon(xIcon); ++round; m[2][2] = 1;
            }
            else
            {
                button33->setIcon(oIcon); ++round; m[2][2] = -1;
            }
        }
        showWinner(2,2);
    });

    window->setLayout(layout);
    w.setCentralWidget(window);
    w.show();
    return a.exec();
}
