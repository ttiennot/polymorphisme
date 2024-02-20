#pragma once
#include "Form.h"
#include <qcombobox.h>
#include <qtableview.h>
#include <qlabel.h>

class EtudiantForm :
    public Form
{
    Q_OBJECT

    QComboBox* classeComboBox;
    QTableView* matiereNoteTableView;
   // QLineEdit* matiereLineEdit;
    //QLayout* topLayout;
public : 
    virtual void generateForm(QWidget* parent, QLayout* container);
};

