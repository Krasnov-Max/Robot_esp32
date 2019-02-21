/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QToolButton *F_BUT;
    QToolButton *STOP_BUT;
    QToolButton *R_BUT_2;
    QToolButton *L_BUT;
    QToolButton *R_BUT;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *ConnBut;
    QPushButton *CloseBut;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *Distance;
    QLabel *label_5;
    QToolButton *em_stop;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QProgressBar *LeftUpBar;
    QProgressBar *LeftDownBar;
    QProgressBar *RightDownBar;
    QProgressBar *RightUpBar;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(556, 820);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(556, 820));
        MainWindow->setMaximumSize(QSize(556, 820));
        MainWindow->setAnimated(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 420, 239, 231));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        F_BUT = new QToolButton(layoutWidget);
        F_BUT->setObjectName(QStringLiteral("F_BUT"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(F_BUT->sizePolicy().hasHeightForWidth());
        F_BUT->setSizePolicy(sizePolicy1);
        F_BUT->setCheckable(false);

        gridLayout_2->addWidget(F_BUT, 0, 1, 1, 1);

        STOP_BUT = new QToolButton(layoutWidget);
        STOP_BUT->setObjectName(QStringLiteral("STOP_BUT"));
        sizePolicy1.setHeightForWidth(STOP_BUT->sizePolicy().hasHeightForWidth());
        STOP_BUT->setSizePolicy(sizePolicy1);
        STOP_BUT->setCheckable(false);

        gridLayout_2->addWidget(STOP_BUT, 1, 1, 1, 1);

        R_BUT_2 = new QToolButton(layoutWidget);
        R_BUT_2->setObjectName(QStringLiteral("R_BUT_2"));
        sizePolicy1.setHeightForWidth(R_BUT_2->sizePolicy().hasHeightForWidth());
        R_BUT_2->setSizePolicy(sizePolicy1);
        R_BUT_2->setCheckable(false);

        gridLayout_2->addWidget(R_BUT_2, 2, 1, 1, 1);

        L_BUT = new QToolButton(layoutWidget);
        L_BUT->setObjectName(QStringLiteral("L_BUT"));
        sizePolicy1.setHeightForWidth(L_BUT->sizePolicy().hasHeightForWidth());
        L_BUT->setSizePolicy(sizePolicy1);
        L_BUT->setCheckable(false);

        gridLayout_2->addWidget(L_BUT, 1, 0, 1, 1);

        R_BUT = new QToolButton(layoutWidget);
        R_BUT->setObjectName(QStringLiteral("R_BUT"));
        sizePolicy1.setHeightForWidth(R_BUT->sizePolicy().hasHeightForWidth());
        R_BUT->setSizePolicy(sizePolicy1);
        R_BUT->setCheckable(false);

        gridLayout_2->addWidget(R_BUT, 1, 2, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 82, 58));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ConnBut = new QPushButton(layoutWidget1);
        ConnBut->setObjectName(QStringLiteral("ConnBut"));

        verticalLayout->addWidget(ConnBut);

        CloseBut = new QPushButton(layoutWidget1);
        CloseBut->setObjectName(QStringLiteral("CloseBut"));

        verticalLayout->addWidget(CloseBut);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(120, 10, 281, 171));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Distance = new QLabel(layoutWidget2);
        Distance->setObjectName(QStringLiteral("Distance"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Distance->sizePolicy().hasHeightForWidth());
        Distance->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(16);
        Distance->setFont(font);
        Distance->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Distance);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(12);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_5);

        em_stop = new QToolButton(centralWidget);
        em_stop->setObjectName(QStringLiteral("em_stop"));
        em_stop->setGeometry(QRect(420, 10, 131, 101));
        em_stop->setCheckable(true);
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 680, 571, 72));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(420, 120, 131, 551));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(formLayoutWidget->sizePolicy().hasHeightForWidth());
        formLayoutWidget->setSizePolicy(sizePolicy3);
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetNoConstraint);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(0);
        formLayout->setContentsMargins(0, 0, 0, 0);
        LeftUpBar = new QProgressBar(formLayoutWidget);
        LeftUpBar->setObjectName(QStringLiteral("LeftUpBar"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(20);
        sizePolicy4.setVerticalStretch(40);
        sizePolicy4.setHeightForWidth(LeftUpBar->sizePolicy().hasHeightForWidth());
        LeftUpBar->setSizePolicy(sizePolicy4);
        LeftUpBar->setMinimumSize(QSize(60, 0));
        LeftUpBar->setMaximumSize(QSize(60, 16777215));
        LeftUpBar->setMinimum(0);
        LeftUpBar->setMaximum(32767);
        LeftUpBar->setValue(4000);
        LeftUpBar->setTextVisible(false);
        LeftUpBar->setOrientation(Qt::Vertical);

        formLayout->setWidget(0, QFormLayout::LabelRole, LeftUpBar);

        LeftDownBar = new QProgressBar(formLayoutWidget);
        LeftDownBar->setObjectName(QStringLiteral("LeftDownBar"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(20);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(LeftDownBar->sizePolicy().hasHeightForWidth());
        LeftDownBar->setSizePolicy(sizePolicy5);
        LeftDownBar->setMinimumSize(QSize(60, 0));
        LeftDownBar->setMaximumSize(QSize(60, 16777215));
        LeftDownBar->setMinimum(0);
        LeftDownBar->setMaximum(32767);
        LeftDownBar->setValue(8800);
        LeftDownBar->setOrientation(Qt::Vertical);
        LeftDownBar->setInvertedAppearance(true);

        formLayout->setWidget(2, QFormLayout::LabelRole, LeftDownBar);

        RightDownBar = new QProgressBar(formLayoutWidget);
        RightDownBar->setObjectName(QStringLiteral("RightDownBar"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(40);
        sizePolicy6.setHeightForWidth(RightDownBar->sizePolicy().hasHeightForWidth());
        RightDownBar->setSizePolicy(sizePolicy6);
        RightDownBar->setMinimumSize(QSize(60, 0));
        RightDownBar->setMaximumSize(QSize(60, 16777215));
        RightDownBar->setMinimum(0);
        RightDownBar->setMaximum(32767);
        RightDownBar->setValue(8800);
        RightDownBar->setOrientation(Qt::Vertical);
        RightDownBar->setInvertedAppearance(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, RightDownBar);

        RightUpBar = new QProgressBar(formLayoutWidget);
        RightUpBar->setObjectName(QStringLiteral("RightUpBar"));
        sizePolicy4.setHeightForWidth(RightUpBar->sizePolicy().hasHeightForWidth());
        RightUpBar->setSizePolicy(sizePolicy4);
        RightUpBar->setMinimumSize(QSize(60, 0));
        RightUpBar->setMaximumSize(QSize(50, 16777215));
        RightUpBar->setMinimum(0);
        RightUpBar->setMaximum(32767);
        RightUpBar->setValue(4000);
        RightUpBar->setTextVisible(false);
        RightUpBar->setOrientation(Qt::Vertical);

        formLayout->setWidget(0, QFormLayout::FieldRole, RightUpBar);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 319, 241, 91));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setPointSize(20);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 556, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Robot's control", nullptr));
        F_BUT->setText(QApplication::translate("MainWindow", "UP", nullptr));
        STOP_BUT->setText(QApplication::translate("MainWindow", "STOP", nullptr));
        R_BUT_2->setText(QApplication::translate("MainWindow", "DOWN", nullptr));
        L_BUT->setText(QApplication::translate("MainWindow", "LEFT", nullptr));
        R_BUT->setText(QApplication::translate("MainWindow", "RIGHT", nullptr));
        ConnBut->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        CloseBut->setText(QApplication::translate("MainWindow", "Close", nullptr));
        Distance->setText(QApplication::translate("MainWindow", "Distance CM", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        em_stop->setText(QApplication::translate("MainWindow", "Emargance stop", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Acselerate", nullptr));
        label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
