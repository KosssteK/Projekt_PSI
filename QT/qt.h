#ifndef QT_H
#define QT_H
#include "Naglowki.h"

#include "ui_qt.h"



class QT : public QDialog
{
	Q_OBJECT

public:
	QT(QWidget *parent = 0);
	~QT();

	
private:
	Ui::QTClass ui;
	QGraphicsScene *scene;
	QGraphicsEllipseItem *elipse;


};

#endif // QT_H
