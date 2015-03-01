/********************************************************************************
** Form generated from reading UI file 'panelapplicationsettings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANELAPPLICATIONSETTINGS_H
#define UI_PANELAPPLICATIONSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PanelApplicationSettings
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *fontLabel;
    QLineEdit *fontName;
    QLabel *iconThemeLabel;
    QLineEdit *iconThemeName;
    QLabel *verticalPositionLabel;
    QComboBox *verticalPosition;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PanelApplicationSettings)
    {
        if (PanelApplicationSettings->objectName().isEmpty())
            PanelApplicationSettings->setObjectName(QString::fromUtf8("PanelApplicationSettings"));
        PanelApplicationSettings->resize(230, 142);
        verticalLayout_2 = new QVBoxLayout(PanelApplicationSettings);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        fontLabel = new QLabel(PanelApplicationSettings);
        fontLabel->setObjectName(QString::fromUtf8("fontLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, fontLabel);

        fontName = new QLineEdit(PanelApplicationSettings);
        fontName->setObjectName(QString::fromUtf8("fontName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, fontName);

        iconThemeLabel = new QLabel(PanelApplicationSettings);
        iconThemeLabel->setObjectName(QString::fromUtf8("iconThemeLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, iconThemeLabel);

        iconThemeName = new QLineEdit(PanelApplicationSettings);
        iconThemeName->setObjectName(QString::fromUtf8("iconThemeName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, iconThemeName);

        verticalPositionLabel = new QLabel(PanelApplicationSettings);
        verticalPositionLabel->setObjectName(QString::fromUtf8("verticalPositionLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, verticalPositionLabel);

        verticalPosition = new QComboBox(PanelApplicationSettings);
        verticalPosition->setObjectName(QString::fromUtf8("verticalPosition"));

        formLayout->setWidget(2, QFormLayout::FieldRole, verticalPosition);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(PanelApplicationSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(PanelApplicationSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), PanelApplicationSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PanelApplicationSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(PanelApplicationSettings);
    } // setupUi

    void retranslateUi(QDialog *PanelApplicationSettings)
    {
        PanelApplicationSettings->setWindowTitle(QApplication::translate("PanelApplicationSettings", "Options", 0, QApplication::UnicodeUTF8));
        fontLabel->setText(QApplication::translate("PanelApplicationSettings", "Font:", 0, QApplication::UnicodeUTF8));
        iconThemeLabel->setText(QApplication::translate("PanelApplicationSettings", "Icon theme:", 0, QApplication::UnicodeUTF8));
        verticalPositionLabel->setText(QApplication::translate("PanelApplicationSettings", "Vertical position:", 0, QApplication::UnicodeUTF8));
        verticalPosition->clear();
        verticalPosition->insertItems(0, QStringList()
         << QApplication::translate("PanelApplicationSettings", "Top", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PanelApplicationSettings", "Bottom", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class PanelApplicationSettings: public Ui_PanelApplicationSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANELAPPLICATIONSETTINGS_H
