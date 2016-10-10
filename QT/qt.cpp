#include "qt.h"
#include "Naglowki.h"
QT::QT(QWidget *parent)
	: QDialog(parent)
	
{
	ui.setupUi(this);

	scene = new QGraphicsScene(this);
	ui.graphicsView->setScene(scene);

	QBrush redBrush(Qt::red);
	QPen blackpen(Qt::black);
	blackpen.setWidth(6);
	elipse = scene->addEllipse(10, 10, 20, 20,blackpen,redBrush);


}

QT::~QT()
{

}
