#include "poly.h"


poly::poly(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.ProfRadioBtn, &QRadioButton::toggled, this, &poly::onToggleRadioButoon);
	QObject::connect(ui.EtudiantRadioBtn, &QRadioButton::toggled, this, &poly::onToggleRadioButoon);

}

poly::~poly()
{}

void poly::onToggleRadioButoon(bool checked) {
	QObject* obj = sender();

	if (checked) {
		if (obj == ui.ProfRadioBtn)
		{
			ui.widget->display(PROF);
		}
		else if (obj == ui.EtudiantRadioBtn && mode != ETUDIANT)
		{
			ui.widget->display(ETUDIANT);
		}
	}

}