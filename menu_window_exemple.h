/*
 * menu_window_exemple.h
 *
 *  Created on: 14 févr. 2015
 *      Author: gschwind
 */

#ifndef MENU_WINDOW_EXEMPLE_H_
#define MENU_WINDOW_EXEMPLE_H_

#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtWidgets/QAction>
//	#include <QtGui/QPlastiqueStyle>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMenu>
#include <QtWidgets/QStyle>
#include <QtGui/QPixmap>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMenu>

class MyMenuWindow: public QWidget
{
	Q_OBJECT

public:
	QVBoxLayout * layout;
	int screen;

	MyMenuWindow(QWidget * parent, int screen);
	~MyMenuWindow();
	void clicked();

};




#endif /* MENU_WINDOW_EXEMPLE_H_ */
