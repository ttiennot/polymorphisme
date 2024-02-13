#pragma once
#include <qobject.h>
#include <qlayout.h>
class Form :
    public QObject
{
    Q_OBJECT
    QList<QObject*> allocatedObjects;
    QLayout* parentLayout;

protected :
    void addAllocatedObject(QObject* obj);

public :
    Form(QObject* parent = nullptr);
     virtual ~Form();
     virtual void generateForm(QWidget* parent, QLayout* container);
};
