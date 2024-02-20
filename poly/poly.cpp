#include "poly.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <qdebug.h>
#include <QStandardItemModel>
#include <QtSql/QSqlError>


poly::poly(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	mode = NONE;

	QObject::connect(ui.ProfRadioBtn, &QRadioButton::toggled, this, &poly::onToggleRadioButoon);
	QObject::connect(ui.EtudiantRadioBtn, &QRadioButton::toggled, this, &poly::onToggleRadioButoon);
	QObject::connect(ui.okBtn, &QRadioButton::clicked, this, &poly::onBoutonSend);

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("192.168.64.148");
	db.setDatabaseName("polymorphisme");
	db.setUserName("root");
	db.setPassword("root");

	if (db.open()) {
		qDebug() << "Connexion � la base de donn�es �tablie";
	}
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

void poly::onBoutonSend() {
QString prenom = ui.prenomEdit->text();
QString nom = ui.nomEdit->text();
QString rue = ui.adressLineEdit1->text();
QString codePostal = ui.adressLineEdit2->text();
QString ville = ui.adressLineEdit3->text();
QString	age = ui.ageEdit->text();
QString tel = ui.telEdit->text();
QString email = ui.emailEdit->text();

QString adresseComplete = rue + "" + codePostal + "" + ville;

QStringList matieres;

QTableView* tableView = ui.widget->findChild<QTableView*>();
if (tableView) {
	QAbstractItemModel* model = tableView->model();

	if (model) {

		for (int row = 0; row < model->rowCount(); ++row) {
			QModelIndex index = model->index(row, 0);
			QString matiere = model->data(index).toString();
			matieres << matiere;
		}
	}
	else {
		qDebug() << "Le mod�le de la table des mati�res n'est pas accessible.";
	}
}
else {
	qDebug() << "La table des mati�res est introuvable dans le widget.";
}

// classe = classeComboBox->currentText(); // R�cup�rer la classe s�lectionn�e
	 QString classe = "sn1";

if (ui.EtudiantRadioBtn->isChecked()) {
	insertDatabase(prenom, nom, adresseComplete, age.toInt(), tel, email, "etudiant", matieres, classe);
}
else if (ui.ProfRadioBtn->isChecked()) {
	insertDatabase(prenom, nom, adresseComplete, age.toInt(), tel, email, "professeur", matieres, classe);
}
}

void poly::insertDatabase(const QString& nom, const QString& prenom, const QString& adresse, int age, const QString& telephone, const QString& email, const QString& tableName, const QStringList& matieres, const QString& classe)
{
	QSqlQuery query;

	// Construire la requ�te INSERT en fonction du type de table (professeur ou �tudiant)
	QString queryString;
	if (tableName == "etudiant") {
		queryString = "INSERT INTO etudiant (nom, prenom, adresse, age, telephone, email, classe) VALUES (?, ?, ?, ?, ?, ?, ?)";
	}
	else if (tableName == "professeur") {
		queryString = "INSERT INTO professeur (nom, prenom, adresse, age, telephone, email) VALUES (?, ?, ?, ?, ?, ?)";
	}

	// Pr�parer la requ�te avec les param�tres
	query.prepare(queryString);
	query.addBindValue(nom);
	query.addBindValue(prenom);
	query.addBindValue(adresse);
	query.addBindValue(age);
	query.addBindValue(telephone);
	query.addBindValue(email);
	if (tableName == "etudiant") {
		query.addBindValue(classe);
	}

	// Ex�cuter la requ�te principale
	if (!query.exec()) {
		qDebug() << "Erreur lors de l'ex�cution de la requ�te INSERT :" << query.lastError().text();
		return;
	}

	// R�cup�rer l'identifiant g�n�r� pour l'insertion
	int id = query.lastInsertId().toInt();

	// Si l'insertion concerne un �tudiant, ins�rer �galement les mati�res suivies par l'�tudiant dans une table de liaison
	if (tableName == "etudiant") {
		QSqlQuery query1;
		QString queryMatiere = "INSERT INTO MatiereEtudiant (idEtudiant, matiere) VALUES (:id, :matiere)";
		query1.prepare(queryMatiere);
		query1.bindValue(":id", id);
		for (const QString& matiere : matieres) {
			query1.bindValue(":matiere", matiere);
			if (!query1.exec()) {
				qDebug() << "Erreur lors de l'insertion de la mati�re pour l'�tudiant :" << query1.lastError().text();
			}
		}
	}

	qDebug() << "Donn�es ins�r�es avec succ�s.";
}


