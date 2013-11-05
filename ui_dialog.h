/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *btnStartOrPause;
    QLabel *lblOriginal;
    QLabel *lblProcessed;
    QPushButton *CloseApp;
    QTextBrowser *textBrowser;
    QLabel *label;
    QLabel *label_2;
    QPushButton *openFrmGrab;
    QPushButton *closeFrmGrab;
    QLabel *label_3;
    QPushButton *btnSaveImage;
    QLabel *TUMLabel;
    QLabel *MIMEDLabel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1270, 570);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setAutoFillBackground(false);
        Dialog->setSizeGripEnabled(false);
        btnStartOrPause = new QPushButton(Dialog);
        btnStartOrPause->setObjectName(QString::fromUtf8("btnStartOrPause"));
        btnStartOrPause->setGeometry(QRect(1116, 248, 125, 40));
        btnStartOrPause->setCursor(QCursor(Qt::PointingHandCursor));
        lblOriginal = new QLabel(Dialog);
        lblOriginal->setObjectName(QString::fromUtf8("lblOriginal"));
        lblOriginal->setEnabled(true);
        lblOriginal->setGeometry(QRect(48, 104, 500, 375));
        lblOriginal->setMinimumSize(QSize(0, 0));
        lblOriginal->setMaximumSize(QSize(1400, 1050));
        lblOriginal->setAutoFillBackground(false);
        lblOriginal->setStyleSheet(QString::fromUtf8("background-color : black"));
        lblProcessed = new QLabel(Dialog);
        lblProcessed->setObjectName(QString::fromUtf8("lblProcessed"));
        lblProcessed->setGeometry(QRect(596, 104, 500, 375));
        lblProcessed->setMinimumSize(QSize(0, 0));
        lblProcessed->setMaximumSize(QSize(1400, 1050));
        lblProcessed->setAutoFillBackground(false);
        lblProcessed->setStyleSheet(QString::fromUtf8("background-color : black"));
        CloseApp = new QPushButton(Dialog);
        CloseApp->setObjectName(QString::fromUtf8("CloseApp"));
        CloseApp->setGeometry(QRect(1116, 404, 125, 40));
        CloseApp->setCursor(QCursor(Qt::PointingHandCursor));
        textBrowser = new QTextBrowser(Dialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(1116, 180, 125, 40));
        textBrowser->setReadOnly(true);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(184, 484, 217, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(768, 484, 173, 25));
        label_2->setFont(font);
        label_2->setAutoFillBackground(false);
        openFrmGrab = new QPushButton(Dialog);
        openFrmGrab->setObjectName(QString::fromUtf8("openFrmGrab"));
        openFrmGrab->setGeometry(QRect(1116, 100, 125, 40));
        openFrmGrab->setCursor(QCursor(Qt::PointingHandCursor));
        closeFrmGrab = new QPushButton(Dialog);
        closeFrmGrab->setObjectName(QString::fromUtf8("closeFrmGrab"));
        closeFrmGrab->setGeometry(QRect(1116, 144, 125, 40));
        closeFrmGrab->setCursor(QCursor(Qt::PointingHandCursor));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(420, 28, 797, 33));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        btnSaveImage = new QPushButton(Dialog);
        btnSaveImage->setObjectName(QString::fromUtf8("btnSaveImage"));
        btnSaveImage->setGeometry(QRect(1116, 296, 125, 40));
        btnSaveImage->setCursor(QCursor(Qt::PointingHandCursor));
        TUMLabel = new QLabel(Dialog);
        TUMLabel->setObjectName(QString::fromUtf8("TUMLabel"));
        TUMLabel->setGeometry(QRect(64, 24, 85, 41));
        TUMLabel->setAutoFillBackground(true);
        MIMEDLabel = new QLabel(Dialog);
        MIMEDLabel->setObjectName(QString::fromUtf8("MIMEDLabel"));
        MIMEDLabel->setGeometry(QRect(156, 24, 161, 41));
        MIMEDLabel->setAutoFillBackground(true);
        btnStartOrPause->raise();
        lblOriginal->raise();
        lblProcessed->raise();
        CloseApp->raise();
        openFrmGrab->raise();
        textBrowser->raise();
        label->raise();
        label_2->raise();
        closeFrmGrab->raise();
        label_3->raise();
        btnSaveImage->raise();
        TUMLabel->raise();
        MIMEDLabel->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Visual Control", 0, QApplication::UnicodeUTF8));
        btnStartOrPause->setText(QApplication::translate("Dialog", "Start", 0, QApplication::UnicodeUTF8));
        lblOriginal->setText(QString());
        lblProcessed->setText(QString());
        CloseApp->setText(QApplication::translate("Dialog", "Close", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Live endoscopic Image", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Image Processing", 0, QApplication::UnicodeUTF8));
        openFrmGrab->setText(QApplication::translate("Dialog", "Open FrameGrabber", 0, QApplication::UnicodeUTF8));
        closeFrmGrab->setText(QApplication::translate("Dialog", "Close FrameGrabber", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Image- and Robotic-based Steering of a Flexible Endoscope in ENT Diagnoses", 0, QApplication::UnicodeUTF8));
        btnSaveImage->setText(QApplication::translate("Dialog", "save Image", 0, QApplication::UnicodeUTF8));
        TUMLabel->setText(QString());
        MIMEDLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
