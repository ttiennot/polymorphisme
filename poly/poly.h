#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_poly.h"
#include "Etudiant.h"
#include "ActiveForm.h"


class poly : public QMainWindow
{
    Q_OBJECT
        ActiveForm mode;
private slots :
    void onToggleRadioButoon(bool checked);

public:
    poly(QWidget *parent = nullptr);
    ~poly();

private:
    Ui::polyClass ui;
};
