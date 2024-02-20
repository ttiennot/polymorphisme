#pragma once
#include "Form.h"
#include <QComboBox>
#include <QTableView>
#include <QLabel>
#include <QStringListModel>

#include <QWidget>
#include <QListWidget>

class EtudiantForm : 
    public Form
{
    Q_OBJECT

public:
    EtudiantForm(QWidget* parent = nullptr); // Constructeur
    virtual ~EtudiantForm(); // Destructeur
    virtual void generateForm(QWidget* parent, QLayout* container) override;

private slots:
    void onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles);
private:
    QTableView* matiereNoteTableView;
    QComboBox* classeComboBox;
    QStringListModel* matiereListModel;
};
