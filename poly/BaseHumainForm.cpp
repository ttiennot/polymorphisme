#include "BaseHumainForm.h"
#include "Etudiant.h"

BaseHumainForm::BaseHumainForm(QWidget* parent)
	:QWidget(parent)
{
	containerLayout = new QVBoxLayout(this);
	setLayout(containerLayout);
	form = nullptr;
}

void BaseHumainForm::display(ActiveForm formMode)
{
	if (form != nullptr)
	{
		form->deleteLater();
		form = nullptr;
	}

	if (formMode == ETUDIANT)
	{
		form = new EtudiantForm();
		form->generateForm(this, containerLayout);
	}
	else if (formMode == PROF)
	{

	}
}
