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

	QLabel* labelMatiere = new QLabel("Liste des matières suivies : ");
	topLayout->addWidget(labelMatiere);
	addAllocatedObject(labelMatiere);

	matiereNoteTableView = new QTableView();
	topLayout->addWidget(matiereNoteTableView);
	addAllocatedObject(matiereNoteTableView);

	classeComboBox = new QComboBox();
	bottomLayout->addWidget(classeComboBox);
	addAllocatedObject(classeComboBox);

	labelMatiere->setParent(parent);
	matiereNoteTableView->setParent(parent);
	classeComboBox->setParent(parent);

	labelMatiere->show();
	matiereNoteTableView->show();
	classeComboBox->show();
}
