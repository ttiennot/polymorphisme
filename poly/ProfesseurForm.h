#pragma once
#include "Form.h"
#include <qcombobox.h>
#include <qtableview.h>
#include <qlabel.h>

class ProfesseurForm :
	public Form 
{
    Q_OBJECT

    QComboBox* classeComboBox;
    QTableView* matiereNoteTableView;
public:
    virtual void generateForm(QWidget* parent, QLayout* container);
};

