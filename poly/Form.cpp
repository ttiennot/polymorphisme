#include "Form.h"
#include <qwidget.h>
#include <qlayout.h>

void Form::addAllocatedObject(QObject* obj)
{
	allocatedObjects.push_back(obj);
}

Form::Form(QObject* parent) :QObject(parent)
{
}

Form::~Form()
{
	QList<QObject*> deleteLater;
	if (parentLayout != nullptr)
	{
		for (auto it = allocatedObjects.begin();  it != allocatedObjects.end() ; it++)
		{
			QObject* obj = (*it); 
			QWidget* w = nullptr;
			QLayout* layout = nullptr;
			if ((w = qobject_cast<QWidget*>(obj)) != nullptr)
			{
				parentLayout->removeWidget(w);
				QLayout* l = w->layout();
				if (l != nullptr) l->removeWidget(w);
			}
			else if ((layout = qobject_cast<QLayout*>(obj)) != nullptr)
			{
				QLayout* l = layout->layout();
				parentLayout->removeItem(l);
			}
		}
	}
	for (auto it = allocatedObjects.begin(); it != allocatedObjects.end() ; it++)
	{
		(*it)->deleteLater();
	}
}

void Form::generateForm(QWidget* parent, QLayout* container)
{
	this->parentLayout = container;
}

