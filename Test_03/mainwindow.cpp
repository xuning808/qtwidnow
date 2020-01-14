#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500, 300);
    //菜单栏
    QMenuBar *mBer = menuBar();

    //添加菜单
    QMenu *pFile = mBer->addMenu("file");

    //添加菜单项,添加动作
    QAction *pNew = pFile ->addAction("new");

    connect(pNew, &QAction::triggered,
            []()
            {
                qDebug() << "new pressed";
            }
            );

    QAction *pOpen = pFile-> addAction("open");

    connect(pOpen, &QAction::triggered,
            []()
    {
        qDebug() << "open pressed";
    });

    // 添加分割线
    pFile->addSeparator();

    QAction *pText = pFile-> addAction("text");

    connect(pText, &QAction::triggered,
            []()
    {
        qDebug() << "text pressed";
    });


    //工具栏
    QToolBar *toolBar = addToolBar("toolBar");
    //菜单栏添加快捷键
//    toolBar->addAction(pNew);
    QPushButton *b = new QPushButton(this);
    b->setText("^_^");
    //设置按钮为工具栏
    toolBar->addWidget(b);

    connect(b, &QPushButton::clicked,
            [b]()
            {
                b->setText("x_x");
            });

    //状态栏 在底部显示
    QStatusBar *sBar = statusBar();
    QLabel *label = new QLabel(this);
    label->setText("Normal text file");
    sBar->addWidget(label);

    //状态栏 方法2
    sBar->addWidget(new QLabel("2", this));
    //以上为从左往右添加
    //从右往左添加
    sBar->addPermanentWidget(new QLabel("3", this));

    //核心控件
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);


    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    //需要两个参数，一个是位置，看帮助文档，一个是窗口
    addDockWidget(Qt::RightDockWidgetArea, dock);
    //给浮动窗口添加功能
    QTextEdit *textEdit1 = new QTextEdit(this);
    dock->setWidget(textEdit1);
}

MainWindow::~MainWindow()
{
}

