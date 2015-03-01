/*
 * menu_window_exemple.cpp
 *
 *  Created on: 14 févr. 2015
 *      Author: gschwind
 */


#include "menu_window_exemple.h"
#if 0
#include <QtGui/QApplication>
#include <QtGui/QLineEdit>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QMenu>
#include <QtGui/QStyle>
#include <QtGui/QPixmap>
#include <QtGui/QGraphicsScene>
#include <QtGui/QDesktopWidget>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsSceneMouseEvent>
#include <QtGui/QGraphicsView>
#include <QtGui/QMenu>
#endif

MyMenuWindow::MyMenuWindow(QWidget * parent, int screen)
    // make this Widget a menu popup
	: QWidget(parent, Qt::Popup), screen(screen)
{

	setStyleSheet("background-color:gray;");

	QRect screenGeometry = QApplication::desktop()->screenGeometry(screen);
	QVBoxLayout * layout = new QVBoxLayout;

	// set the window to near full screen (avoid fullscreen to not puzzle WM)
	setBaseSize(screenGeometry.width()-48, screenGeometry.height());
	setMaximumSize(screenGeometry.width()-48, screenGeometry.height());
	setMinimumSize(screenGeometry.width()-48, screenGeometry.height());
	move(0, 0);

	/** block event to all application other windows **/
	setWindowModality(Qt::ApplicationModal);

	QLineEdit * x0 = new QLineEdit(this);
	x0->show();
	layout->addWidget(x0);

	QMenu * menu = new QMenu(this);

	menu->addMenu("action1");
	menu->addMenu("action2");
	menu->addMenu("action3");
	menu->setLayout(new QVBoxLayout);

	menu->show();

	layout->addWidget(menu);
	//sub_frame->show();

	QLabel * l0 = new QLabel("????0", this);
	QLabel * l1 = new QLabel("????1", this);
	QLabel * l2 = new QLabel("????2", this);
	QLabel * l3 = new QLabel("????3", this);
	QLabel * l4 = new QLabel("????4", this);
	QLabel * l5 = new QLabel("????5", this);

	layout->addWidget(l0);
	layout->addWidget(l1);
	layout->addWidget(l2);
	layout->addWidget(l3);
	layout->addWidget(l4);
	layout->addWidget(l5);

	setLayout(layout);

}

MyMenuWindow::~MyMenuWindow()
{

}

void MyMenuWindow::clicked()
{
	move(48, 0);
	show();
	setWindowState(Qt::WindowActive);
}

