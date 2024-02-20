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
    void onBoutonSend();
    void insertDatabase(const QString& nom, const QString& prenom, const QString& adresse, int age, const QString& telephone, const QString& email, const QString& tableName, const QStringList& matieres, const QString& classe);

private:
    Ui::polyClass ui;
    QComboBox* classeComboBox;
};
