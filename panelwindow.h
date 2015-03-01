#ifndef PANELWINDOW_H
#define PANELWINDOW_H

#include "menu_window_exemple.h"
#include <QtCore/QVector>
#include <QtWidgets/QWidget>
#include <QtQuick/QQuickView>
#include <QtWidgets/QGraphicsItem>

class QFont;
class QGraphicsScene;
class QGraphicsView;
class Applet;
class PanelWindow;

class PanelWindow: public QQuickView
{
	Q_OBJECT
public:
	PanelWindow();
	~PanelWindow();

	int screen() const
	{
		return m_screen;
	}

	void setScreen(int screen);

	void updatePosition();

	const QFont& font() const;

	int textBaseLine();

	void resizeEvent(QResizeEvent* event);

	void updateLayout();

	void showPanelContextMenu(const QPoint& point);
	void mousePressEvent (QMouseEvent * event);
	void mouseReleaseEvent (QMouseEvent * event);

public:
	int m_screen;
	MyMenuWindow * menu_win;
};

#endif
