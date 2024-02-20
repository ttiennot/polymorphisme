#include "EtudiantForm.h"
#include <QStringListModel>

EtudiantForm::EtudiantForm(QWidget* parent)
    : Form(parent), matiereNoteTableView(nullptr), classeComboBox(nullptr), matiereListModel(nullptr)
{
    // Initialisation des membres
    matiereNoteTableView = new QTableView();
    classeComboBox = new QComboBox();
    matiereListModel = new QStringListModel();
}

EtudiantForm::~EtudiantForm()
{
    // Nettoyage de la mémoire
    delete matiereNoteTableView;
    delete classeComboBox;
    delete matiereListModel;
}

void EtudiantForm::generateForm(QWidget* parent, QLayout* container)
{
    Form::generateForm(parent, container);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    container->addItem(mainLayout);

    QHBoxLayout* topLayout = new QHBoxLayout();
    mainLayout->addItem(topLayout);
    QHBoxLayout* bottomLayout = new QHBoxLayout();
    mainLayout->addItem(bottomLayout);

    QLabel* labelMatiere = new QLabel("Liste des matières suivies : ");
    topLayout->addWidget(labelMatiere);

    matiereNoteTableView->setModel(matiereListModel);
    topLayout->addWidget(matiereNoteTableView);

    QLabel* labelClasse = new QLabel("Classe : ");
    bottomLayout->addWidget(labelClasse);

    classeComboBox->addItems({ "SN1", "SN2", "CIEL1", "CIEL2", "IRIS1", "IRIS2" });
    bottomLayout->addWidget(classeComboBox);

    labelMatiere->setParent(parent);
    matiereNoteTableView->setParent(parent);
    labelClasse->setParent(parent);
    classeComboBox->setParent(parent);

    labelMatiere->show();
    matiereNoteTableView->show();
    labelClasse->show();
    classeComboBox->show();

    // Ajouter les matières initiales
    QStringList matieres;
    matieres << ""; // Ajouter une ligne vide initiale
    matiereListModel->setStringList(matieres);

    // Connecter le signal dataChanged du modèle à une fonction de gestion
    connect(matiereListModel, &QStringListModel::dataChanged, this, &EtudiantForm::onDataChanged);
}

void EtudiantForm::onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles)
{
    Q_UNUSED(bottomRight)
        Q_UNUSED(roles)

        // Vérifier si la dernière ligne est modifiée
        if (matiereListModel->rowCount() - 1 == topLeft.row())
        {
            // Récupérer le texte de la dernière ligne
            QString text = matiereListModel->data(topLeft).toString();

            // Si la dernière ligne est vide, et qu'il y a plus d'une ligne dans la liste, la supprimer
            if (text.isEmpty() && matiereListModel->rowCount() > 1)
            {
                matiereListModel->removeRow(matiereListModel->rowCount() - 1);
            }
            // Si la dernière ligne n'est pas vide, ajouter une nouvelle ligne vide
            else if (!text.isEmpty())
            {
                matiereListModel->insertRow(matiereListModel->rowCount());
            }
        }
}