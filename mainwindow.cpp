#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Vues->setCurrentIndex(0);

    ui->tableViewInteractions->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewInteractions->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewInteractions->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewInteractions->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableViewContacts->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewContacts->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewContacts->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewContacts->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableViewChoixContacts->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewChoixContacts->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewChoixContacts->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewChoixContacts->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableViewTodos->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewTodos->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewTodos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewTodos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    ui->calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);


    modelContacts= new QStandardItemModel();
    modelInteractions = new QStandardItemModel();
    modelTodos = new QStandardItemModel();

    ui->tableViewChoixContacts->setModel(modelContacts);
    ui->tableViewContacts->setModel(modelContacts);ResetViewTableContacts();AffichageContacts();ClearFormContact();
    ui->tableViewInteractions->setModel(modelInteractions);ResetViewTableInteractions();AffichageInteractions();ClearFormInteraction();
    ui->tableViewTodos->setModel(modelTodos);ResetViewTableTodos();

    ui->calendarWidget->setMinimumDate(ui->calendarWidget->selectedDate());
    ui->calendarWidget->setGridVisible(false);
    ui->calendarWidget->setMaximumDate(QDate(2099, 12, 31));





}

void MainWindow::ResetViewTableContacts()
{
    modelContacts->clear();
    modelContacts->setHorizontalHeaderItem(0, new QStandardItem("Nom"));
    modelContacts->setHorizontalHeaderItem(1, new QStandardItem("Prénom"));
    modelContacts->setHorizontalHeaderItem(2, new QStandardItem("Entreprise"));
    modelContacts->setHorizontalHeaderItem(3, new QStandardItem("Mail"));
    modelContacts->setHorizontalHeaderItem(4, new QStandardItem("Téléphone"));
    modelContacts->setHorizontalHeaderItem(5, new QStandardItem("Photo"));
    modelContacts->setHorizontalHeaderItem(6, new QStandardItem("Date Création"));
    modelContacts->setHorizontalHeaderItem(7, new QStandardItem("Date Modification"));

}
void MainWindow::ResetViewTableInteractions()
{
    modelInteractions->clear();
    modelInteractions->setHorizontalHeaderItem(0, new QStandardItem("Titre"));
    modelInteractions->setHorizontalHeaderItem(1, new QStandardItem("Type"));
    modelInteractions->setHorizontalHeaderItem(2, new QStandardItem("Note"));
    modelInteractions->setHorizontalHeaderItem(3, new QStandardItem("Nom Participant"));
    modelInteractions->setHorizontalHeaderItem(4, new QStandardItem("Prénom Participant"));
    modelInteractions->setHorizontalHeaderItem(5, new QStandardItem("Date Création"));
    modelInteractions->setHorizontalHeaderItem(6, new QStandardItem("Date Modification"));



}
void MainWindow::ResetViewTableTodos()
{
    modelTodos->clear();
    modelTodos->setHorizontalHeaderItem(0, new QStandardItem("Contenu"));
    modelTodos->setHorizontalHeaderItem(1, new QStandardItem("Date"));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete modelContacts;
    CM.showSheetAll();
    std::cout<<"----------------------------\n\n";
    IH.showAllInteractions();

}






void MainWindow::on_B_GestionContacts_clicked()
{
    ui->Vues->setCurrentIndex(2);


}


void MainWindow::on_B_GesionInteractions_clicked()
{
    ui->Vues->setCurrentIndex(4);
}


void MainWindow::on_B_AnnulerAjout_clicked()
{
    ui->Vues->setCurrentIndex(2);
    ClearFormContact();

}


void MainWindow::on_B_ConfirmerAjout_clicked()
{
    QString Q = "Not everything has been filled";
    try {
        if(FormContactIsEmpty())
            throw Q;
        else
        {
            CM.addContact(ui->nomLineEdit->text().toStdString(),ui->prNomLineEdit->text().toStdString(),ui->entrepriseLineEdit->text().toStdString(),ui->mailLineEdit->text().toStdString(),ui->tLPhoneLineEdit->text().toStdString(),ui->photoLineEdit->text().toStdString());
            printLastAddedContactOnGui();
            ui->Vues->setCurrentIndex(2);
            ClearFormContact();
        }
    }  catch (QString Q) {

        QMessageBox msgWarning;
        msgWarning.setText("Vous Devez Tout Remplir");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Attention");
        msgWarning.exec();
    }




}

void MainWindow::ClearFormContact()
{

    ui->nomLineEdit->clear();
    ui->prNomLineEdit->clear();
    ui->entrepriseLineEdit->clear();
    ui->mailLineEdit->clear();
    ui->tLPhoneLineEdit->clear();
    ui->photoLineEdit->clear();

}


void MainWindow::printLastAddedContactOnGui()
{
    QList<QStandardItem*> rowData;
    rowData.clear();
    Contact c = CM.ContactById( CM.getContactsList().size()-1);
    rowData << new QStandardItem(QString::fromStdString(c.getLastName()));
    rowData << new QStandardItem(QString::fromStdString(c.getFirstName()));
    rowData << new QStandardItem(QString::fromStdString(c.getCompany()));
    rowData << new QStandardItem(QString::fromStdString(c.getMail()));
    rowData << new QStandardItem(QString::fromStdString(c.getPhoneNumber()));
    rowData << new QStandardItem(QString::fromStdString(c.getPhoto()));
    rowData << new QStandardItem(QString::fromStdString(c.getCreationDate()));
    rowData << new QStandardItem(QString::fromStdString(c.getModificationDate()));

    modelContacts->appendRow(rowData);

}

void MainWindow::on_B_Modifier_clicked()
{
    QString Q = "No Contact selected";
    QModelIndexList indexes = ui->tableViewContacts->selectionModel()->selectedRows();
    try {
        if(indexes.size() ==0)
            throw Q;
        else
        {
            idModification = indexes.last().row();



            PutDataIntoModifFieldContact(idModification);

            ui->Vues->setCurrentIndex(3);
        }
    }  catch (QString Q) {
        QMessageBox msgWarning;
        msgWarning.setText("Vous devez selectionner un contact à modifier");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Attention");
        msgWarning.exec();
    }





}


void MainWindow::on_B_Supprimer_clicked()
{   QString Q = "No Contact selected";
    QModelIndexList indexes = ui->tableViewContacts->selectionModel()->selectedRows();
    std::sort(indexes.begin(),indexes.end());
    try {
        if(indexes.size() == 0)
            throw Q;
        else
        {
            while (!indexes.isEmpty())
            {
                modelContacts->removeRows(indexes.last().row(), 1);
                CM.deleteContactById(indexes.last().row());

                indexes.removeLast();

            }
        }
    }  catch (QString Q) {
        QMessageBox msgWarning;
        msgWarning.setText("Vous devez selectionner un contact à supprimer");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Attention");
        msgWarning.exec();
    }


}


void MainWindow::on_B_Retour_2_clicked()
{
    ui->Vues->setCurrentIndex(0);
    ClearFormContact();
}
//Database load data update later
void MainWindow::AffichageContacts()
{

    auto data = CM.getContactsList();



    QList<QStandardItem*> rowData;
    Q_FOREACH(const auto &item, data){
        rowData.clear();
        rowData << new QStandardItem(QString::fromStdString(item.getLastName()));
        rowData << new QStandardItem(QString::fromStdString(item.getFirstName()));
        rowData << new QStandardItem(QString::fromStdString(item.getCompany()));
        rowData << new QStandardItem(QString::fromStdString(item.getMail()));
        rowData << new QStandardItem(QString::fromStdString(item.getPhoneNumber()));
        rowData << new QStandardItem(QString::fromStdString(item.getPhoto()));


        modelContacts->appendRow(rowData);

    }



}
void MainWindow::AffichageInteractions()
{
    auto data = IH.getAllInteractions();



    QList<QStandardItem*> rowData;
    Q_FOREACH(const auto &item, data){
        rowData.clear();
        rowData << new QStandardItem(QString::fromStdString(item.getTitle()));
        rowData << new QStandardItem(QString::fromStdString(item.getType()));
        rowData << new QStandardItem(QString::fromStdString(item.getNote()));
        rowData << new QStandardItem(QString::fromStdString(item.getParticipant().getLastName()));
        rowData << new QStandardItem(QString::fromStdString(item.getParticipant().getFirstName()));
        rowData << new QStandardItem(QString::fromStdString(item.getDate()));
        rowData << new QStandardItem(QString::fromStdString(item.getModificationDate()));


        modelInteractions->appendRow(rowData);

    }
}
void MainWindow::AffichageToDos(unsigned int id)
{
    auto data = IH.InteractionById(id).getToDos();



    QList<QStandardItem*> rowData;
    Q_FOREACH(const auto &item, data){
        rowData.clear();
        rowData << new QStandardItem(QString::fromStdString(item.getContenu()).replace(0,6,""));
        rowData << new QStandardItem(QString::fromStdString(item.getDate()).replace(0,6,""));



        modelTodos->appendRow(rowData);

    }
}
void MainWindow::on_B_ConfirmerModif_clicked()
{
    QString Q = "Not everything has been filled";


    try {
        if(FormContactIsEmptyM())
            throw Q;
        else{
            EditContactById(idModification);
            ui->Vues->setCurrentIndex(2);
            idModification = -1;

        }
    }  catch (QString Q) {
        QMessageBox msgWarning;
        msgWarning.setText("Vous devez tout remplir");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Attention");
        msgWarning.exec();

    }




}


void MainWindow::on_B_AnnulerModif_clicked()
{
    ui->Vues->setCurrentIndex(2);
    ClearFormContact();

}
void MainWindow::EditContactById(unsigned int id)
{
    std::string nom = ui->nomLineEditM->text().toStdString();
    std::string prenom = ui->prNomLineEditM->text().toStdString();
    std::string entreprise = ui->entrepriseLineEditM->text().toStdString();
    std::string mail = ui->mailLineEditM->text().toStdString();
    std::string telephone = ui->tLPhoneLineEditM->text().toStdString();
    std::string photo = ui->photoLineEditM->text().toStdString();

    CM.editContact(id,nom,prenom,entreprise,mail,telephone,photo);

    modelContacts->item(id,0)->setData(QString::fromStdString(nom),Qt::DisplayRole);
    modelContacts->item(id,1)->setData(QString::fromStdString(prenom),Qt::DisplayRole);
    modelContacts->item(id,2)->setData(QString::fromStdString(entreprise),Qt::DisplayRole);
    modelContacts->item(id,3)->setData(QString::fromStdString(mail),Qt::DisplayRole);
    modelContacts->item(id,4)->setData(QString::fromStdString(telephone),Qt::DisplayRole);
    modelContacts->item(id,5)->setData(QString::fromStdString(photo),Qt::DisplayRole);
    modelContacts->item(id,6)->setData(QString::fromStdString(CM.ContactById(id).getCreationDate()),Qt::DisplayRole);
    modelContacts->item(id,7)->setData(QString::fromStdString(CM.ContactById(id).getModificationDate()),Qt::DisplayRole);




}
void MainWindow::EditInteractionById(unsigned int id)
{
    std::string titre = ui->titreLineEditM->text().toStdString();
    std::string type = ui->typeLineEditM->text().toStdString();
    std::string note = ui->noteLineEditM->text().toStdString();

    if(idChoixParticipant!=-1)
    {

        Contact c = CM.ContactById(idChoixParticipant);
        std::cout << c;
        IH.editInteraction(id,type,titre,c,note);
    }
    else
        IH.editInteraction(id,type,titre,note);

    std::cout<<IH.InteractionById(id);


    modelInteractions->item(id,0)->setData(QString::fromStdString(titre),Qt::DisplayRole);
    modelInteractions->item(id,1)->setData(QString::fromStdString(type),Qt::DisplayRole);
    modelInteractions->item(id,2)->setData(QString::fromStdString(note),Qt::DisplayRole);
    modelInteractions->item(id,3)->setData(QString::fromStdString(IH.InteractionById(id).getParticipant().getLastName()),Qt::DisplayRole);
    modelInteractions->item(id,4)->setData(QString::fromStdString(IH.InteractionById(id).getParticipant().getFirstName()),Qt::DisplayRole);
    modelInteractions->item(id,5)->setData(QString::fromStdString(IH.InteractionById(id).getDate()),Qt::DisplayRole);
    modelInteractions->item(id,6)->setData(QString::fromStdString(IH.InteractionById(id).getModificationDate()),Qt::DisplayRole);

}
void MainWindow::PutDataIntoModifFieldContact(unsigned int id)
{
    QString nom =  ui->tableViewContacts->model()->index(id,0).data().toString().toStdString().c_str();
    QString prenom =  ui->tableViewContacts->model()->index(id,1).data().toString().toStdString().c_str();
    QString entreprise =  ui->tableViewContacts->model()->index(id,2).data().toString().toStdString().c_str();
    QString mail =  ui->tableViewContacts->model()->index(id,3).data().toString().toStdString().c_str();
    QString telephone =  ui->tableViewContacts->model()->index(id,4).data().toString().toStdString().c_str();
    QString photo =  ui->tableViewContacts->model()->index(id,5).data().toString().toStdString().c_str();

    ui->nomLineEditM->setText(nom);
    ui->prNomLineEditM->setText(prenom);
    ui->entrepriseLineEditM->setText(entreprise);
    ui->mailLineEditM->setText(mail);
    ui->tLPhoneLineEditM->setText(telephone);
    ui->photoLineEditM->setText(photo);

}
void MainWindow::PutDataIntoModifFieldInteraction(unsigned int id)
{
    QString titre =  ui->tableViewInteractions->model()->index(id,0).data().toString().toStdString().c_str();
    QString type =  ui->tableViewInteractions->model()->index(id,1).data().toString().toStdString().c_str();
    QString note =  ui->tableViewInteractions->model()->index(id,2).data().toString().toStdString().c_str();


    ui->titreLineEditM->setText(titre);
    ui->typeLineEditM->setText(type);
    ui->noteLineEditM->setText(note);

}

void MainWindow::on_B_RetourInteraction_clicked()
{
    ui->Vues->setCurrentIndex(0);
}


void MainWindow::on_B_Retour_clicked()
{
    ui->Vues->setCurrentIndex(0);
}


void MainWindow::on_B_AjoutInteraction_clicked()
{
    AjoutInteraction = true;
    ModifInteraction = false;
    ui->Vues->setCurrentIndex(5);

}


void MainWindow::on_B_ModifierInteraction_clicked()
{   QString Q = "No Interaction Selected";
    QModelIndexList indexes = ui->tableViewInteractions->selectionModel()->selectedRows();
    try {
        if(indexes.size()==0)
            throw Q;
        else
        {
            idChoixInteraction = indexes.last().row();
            PutDataIntoModifFieldInteraction(idChoixInteraction);
            AjoutInteraction = false;
            ModifInteraction = true;
            ui->Vues->setCurrentIndex(6);
        }


    }  catch (QString Q) {
        QMessageBox msgWarning;
        msgWarning.setText("Vous devez selectionner une interaction à modifier");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Attention");
        msgWarning.exec();

    }


}


void MainWindow::on_B_SupprimerInteraction_clicked()
{
    QString Q = "No Interaction Selected";
    QModelIndexList indexes = ui->tableViewInteractions->selectionModel()->selectedRows();
    std::sort(indexes.begin(),indexes.end());

    try {
        if(indexes.size()==0)
            throw Q;
        else
        {
            while (!indexes.isEmpty())
            {
                modelInteractions->removeRows(indexes.last().row(), 1);
                IH.deleteInteractionById(indexes.last().row());


                indexes.removeLast();
            }
        }


    }  catch (QString Q) {
        QMessageBox msgWarning;
        msgWarning.setText("Vous devez selectionner une interaction à supprimer");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Attention");
        msgWarning.exec();

    }










}


void MainWindow::on_B_ConfirmerAjoutInteraction_clicked()
{
    QString Q = "Not everything has been filled";
    try {
        if(FormInteractionIsEmpty() || idChoixParticipant == -1)
            throw Q;
        else{
            std::string type = ui->typeLineEdit->text().toStdString();
            std::string titre = ui->titreLineEdit->text().toStdString();
            std::string note = ui->noteLineEdit->text().toStdString();
            Contact C =  CM.ContactById(idChoixParticipant);

            Interaction I(type,titre,C,note);
            IH.addAnInteraction(I);
            printLastAddedInteractionOnGui();
            ui->Vues->setCurrentIndex(4);
            ClearFormInteraction();
        }
    }  catch (QString Q) {
        QMessageBox msgWarning;
        msgWarning.setText("Vous devez tout remplir et choisir le participant");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Attention");
        msgWarning.exec();

    }

}
void MainWindow::ClearFormInteraction()
{
    idChoixParticipant = -1;
    ui->typeLineEdit->clear();
    ui->titreLineEdit->clear();
    ui->noteLineEdit->clear();
}
void MainWindow::printLastAddedInteractionOnGui()
{
    QList<QStandardItem*> rowData;
    rowData.clear();
    Interaction I = IH.InteractionById(IH.getAllInteractions().size()-1);
    rowData << new QStandardItem(QString::fromStdString(I.getTitle()));
    rowData << new QStandardItem(QString::fromStdString(I.getType()));
    rowData << new QStandardItem(QString::fromStdString(I.getNote()));
    rowData << new QStandardItem(QString::fromStdString(I.getParticipant().getLastName()));
    rowData << new QStandardItem(QString::fromStdString(I.getParticipant().getFirstName()));
    rowData << new QStandardItem(QString::fromStdString(I.getDate()));
    rowData << new QStandardItem(QString::fromStdString(I.getModificationDate()));

    modelInteractions->appendRow(rowData);

}
void MainWindow::printLastAddedTodo()
{
    QList<QStandardItem*> rowData;
    rowData.clear();
    ToDo T = IH.InteractionById(idChoixInteraction).ToDoById(
                IH.InteractionById(idChoixInteraction).getToDos().size()-1);

    rowData << new QStandardItem(QString::fromStdString(T.getContenu()).replace(0,6,""));
    rowData << new QStandardItem(QString::fromStdString(T.getDate()).replace(0,6,""));


    modelTodos->appendRow(rowData);
}

void MainWindow::on_B_AnnulerAjoutInteraction_clicked()
{
    ui->Vues->setCurrentIndex(4);
    ClearFormInteraction();
}


void MainWindow::on_B_ChoisirParticipant_clicked()
{
    ui->Vues->setCurrentIndex(9);
}


void MainWindow::on_B_Choisir_clicked()
{
    QModelIndexList indexes = ui->tableViewChoixContacts->selectionModel()->selectedRows();

    idChoixParticipant = indexes.last().row();

    if(AjoutInteraction)
        ui->Vues->setCurrentIndex(5);
    if(ModifInteraction)
        ui->Vues->setCurrentIndex(6);
}


void MainWindow::on_B_AfficherToDos_clicked()
{   QString Q = "Nothing has been selected";
    QModelIndexList indexes = ui->tableViewInteractions->selectionModel()->selectedRows();

    try {
        if(indexes.size()==0)
            throw Q;
        else
        {
            idChoixInteraction = indexes.last().row();
            ResetViewTableTodos();
            AffichageToDos(idChoixInteraction);
            ui->Vues->setCurrentIndex(7);
        }
    }  catch (QString Q) {
        QMessageBox msgWarning;
        msgWarning.setText("Vous devez selectionner une interaction");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Attention");
        msgWarning.exec();
    }


}


void MainWindow::on_B_AjouterTodo_clicked()
{

    ui->Vues->setCurrentIndex(8);
}


void MainWindow::on_B_SupprimerTodo_clicked()
{   QString Q = "Nothing has been selected";
    QModelIndexList indexes = ui->tableViewTodos->selectionModel()->selectedRows();
    std::sort(indexes.begin(),indexes.end());
    try {
        if(indexes.size()==0)
            throw Q;
        else
        {
            while (!indexes.isEmpty())
            {


                IH.deleteToDoForInteraction(idChoixInteraction,
                                            ToDo(ui->tableViewTodos->model()->index(indexes.last().row(),0).data().toString().toStdString().c_str()
                                                 ,ui->tableViewTodos->model()->index(indexes.last().row(),1).data().toString().toStdString().c_str()));

                modelTodos->removeRows(indexes.last().row(), 1);
                indexes.removeLast();
            }
        }
    }  catch (QString Q) {
        QMessageBox msgWarning;
        msgWarning.setText("Vous devez Choisir un todo à supprimer");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Attention");
        msgWarning.exec();


    }





}


void MainWindow::on_B_RetourTodos_clicked()
{
    ui->Vues->setCurrentIndex(4);
}

bool MainWindow::FormContactIsEmpty()
{
    return ui->nomLineEdit->text().toStdString().empty() ||
            ui->prNomLineEdit->text().toStdString().empty() ||
            ui->entrepriseLineEdit->text().toStdString().empty() ||
            ui->mailLineEdit->text().toStdString().empty() ||
            ui->tLPhoneLineEdit->text().toStdString().empty() ||
            ui->photoLineEdit->text().toStdString().empty() ;
}
bool MainWindow::FormContactIsEmptyM()
{
    return ui->nomLineEditM->text().toStdString().empty() ||
            ui->prNomLineEditM->text().toStdString().empty() ||
            ui->entrepriseLineEditM->text().toStdString().empty() ||
            ui->mailLineEditM->text().toStdString().empty() ||
            ui->tLPhoneLineEditM->text().toStdString().empty() ||
            ui->photoLineEditM->text().toStdString().empty() ;
}
bool MainWindow::FormInteractionIsEmpty()
{
    return ui->typeLineEdit->text().toStdString().empty() ||
            ui->titreLineEdit->text().toStdString().empty() ||
            ui->noteLineEdit->text().toStdString().empty() ;
}
bool MainWindow::FormInteractionIsEmptyM()
{
    return ui->typeLineEditM->text().toStdString().empty() ||
            ui->titreLineEditM->text().toStdString().empty() ||
            ui->noteLineEditM->text().toStdString().empty() ;
}
bool MainWindow::FormToDosIsEmpty()
{
    return ui->contenuLineEdit->text().toStdString().empty();
}
void MainWindow::on_B_ConfirmerAjoutTodos_clicked()
{  QString Q = "Not everything has been filled";
    try {
        if(FormToDosIsEmpty())
            throw Q;
        else
        {
            IH.addToDoForInteraction(idChoixInteraction,ToDo(ui->contenuLineEdit->text().toStdString()
                                                             ,ui->calendarWidget->selectedDate().toString("dd/MM/yyyy").toStdString().c_str()));
            printLastAddedTodo();
            ui->Vues->setCurrentIndex(7);
            ui->contenuLineEdit->clear();
            QString date = QString::fromStdString(T.getDateddmmyyyy());
            ui->calendarWidget->setSelectedDate(QDate::fromString(date,"dd/MM/yyyy"));
        }
    }  catch (QString Q) {

    }


}


void MainWindow::on_B_RetourAjoutTodos_clicked()
{
    ui->Vues->setCurrentIndex(7);
    ui->contenuLineEdit->clear();
    QString date = QString::fromStdString(T.getDateddmmyyyy());
    ui->calendarWidget->setSelectedDate(QDate::fromString(date,"dd/MM/yyyy"));
}


void MainWindow::on_B_RetourChoixParticipant_clicked()
{
    if(AjoutInteraction)
        ui->Vues->setCurrentIndex(5);
    if(ModifInteraction)
        ui->Vues->setCurrentIndex(6);
}


void MainWindow::on_B_ModifierParticipant_clicked()
{
    ui->Vues->setCurrentIndex(9);
}


void MainWindow::on_B_ConfirmerModificationInteraction_clicked()
{
    QString Q = "Not everything has been filled";
    try {
        if(FormInteractionIsEmptyM())
            throw Q;
        else
        {
            EditInteractionById(idChoixInteraction);
            ui->Vues->setCurrentIndex(4);
            ClearFormInteraction();
        }
    }  catch (QString Q) {
        QMessageBox msgWarning;
        msgWarning.setText("Vous devez tout remplir");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Attention");
        msgWarning.exec();

    }

}


void MainWindow::on_B_AnnulerModifInteraction_clicked()
{

    ui->Vues->setCurrentIndex(4);
    ClearFormInteraction();
}


void MainWindow::on_B_Ajouter_clicked()
{
    ui->Vues->setCurrentIndex(1);
}

