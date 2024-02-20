#include "ProfesseurForm.h"

void ProfesseurForm::generateForm(QWidget* parent, QLayout* container)
{
    Form::generateForm(parent, container);

    QLayout* topLayout = new QHBoxLayout();
    addAllocatedObject(topLayout);
    QLayout* bottomLayout = new QHBoxLayout();
    addAllocatedObject(bottomLayout);

    container->addItem(topLayout);
    container->addItem(bottomLayout);

    QLabel* labelMatiere = new QLabel("Liste des mati�res suivies : ");
    topLayout->addWidget(labelMatiere);
    addAllocatedObject(labelMatiere);

    matiereHeuresTableView = new QTableView();
    topLayout->addWidget(matiereHeuresTableView);
    addAllocatedObject(matiereHeuresTableView);

    classeComboBox = new QComboBox();
    bottomLayout->addWidget(classeComboBox);
    addAllocatedObject(classeComboBox);

    labelMatiere->setText("Nombre d'heures enseign�es : ");

    // Utilisation de setEditText pour d�finir un texte d'invite
    classeComboBox->setEditText("S�lectionner le tarif horaire");

    labelMatiere->setParent(parent);
    matiereHeuresTableView->setParent(parent);
    classeComboBox->setParent(parent);

    labelMatiere->show();
    matiereHeuresTableView->show();
    classeComboBox->show();
}
