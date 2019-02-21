/********************************************************************************
** Form generated from reading UI file 'video.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_H
#define UI_VIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Video
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *Video)
    {
        if (Video->objectName().isEmpty())
            Video->setObjectName(QStringLiteral("Video"));
        Video->resize(640, 480);
        verticalLayoutWidget = new QWidget(Video);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 641, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        retranslateUi(Video);

        QMetaObject::connectSlotsByName(Video);
    } // setupUi

    void retranslateUi(QWidget *Video)
    {
        Video->setWindowTitle(QApplication::translate("Video", "Form", nullptr));
        label->setText(QApplication::translate("Video", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Video: public Ui_Video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
