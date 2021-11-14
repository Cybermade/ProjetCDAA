#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QDebug>
#include <QString>
#include <cmath>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <contactsmanagement.h>
#include <interactionHandler.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_B_GestionContacts_clicked();

    void on_B_GesionInteractions_clicked();

    void on_B_AnnulerAjout_clicked();

    void on_B_ConfirmerAjout_clicked();

    void on_B_Ajouter_clicked();

    void on_B_Modifier_clicked();

    void on_B_Supprimer_clicked();

    void on_B_Retour_2_clicked();

    void on_B_ConfirmerModif_clicked();

    void on_B_AnnulerModif_clicked();

    void on_B_RetourInteraction_clicked();

    void on_B_Retour_clicked();

    void on_B_AjoutInteraction_clicked();

    void on_B_ModifierInteraction_clicked();

    void on_B_SupprimerInteraction_clicked();

    void on_B_ConfirmerAjoutInteraction_clicked();

    void on_B_AnnulerAjoutInteraction_clicked();

    void on_B_ChoisirParticipant_clicked();

    void on_B_Choisir_clicked();

    void on_B_AfficherToDos_clicked();

    void on_B_AjouterTodo_clicked();

    void on_B_SupprimerTodo_clicked();

    void on_B_RetourTodos_clicked();

    void on_B_ConfirmerAjoutTodos_clicked();

    void on_B_RetourAjoutTodos_clicked();

    void on_B_RetourChoixParticipant_clicked();

    void on_B_ModifierParticipant_clicked();

    void on_B_ConfirmerModificationInteraction_clicked();

    void on_B_AnnulerModifInteraction_clicked();




private:
    Ui::MainWindow *ui;
    CurrentTime T;
    QStandardItemModel *modelContacts;
    QStandardItemModel *modelInteractions;
    QStandardItemModel *modelTodos;



    int idModification;
    int idChoixParticipant;
    int idChoixInteraction;
    Contactsmanagement CM;
    InteractionHandler IH;
    bool AjoutInteraction;
    bool ModifInteraction;
    /**
     * @brief printLastAddedContactOnGui : Affiche le dernier contact ajouté
     */
    void printLastAddedContactOnGui();
    /**
     * @brief printLastAddedInteractionOnGui : Affiche la dernière interaction ajoutée
     */
    void printLastAddedInteractionOnGui();
    /**
     * @brief printLastAddedTodo : Affiche le dernier ToDo ajouté
     */
    void printLastAddedTodo();

    /**
     * @brief AffichageContacts
     */
    void AffichageContacts();
    /**
     * @brief AffichageInteractions
     */
    void AffichageInteractions();
    /**
     * @brief AffichageToDos : Affiche les todos d'une interaction
     * @param id
     */
    void AffichageToDos(unsigned int id);
    /**
     * @brief ClearFormContact
     */
    void ClearFormContact();
    /**
     * @brief ClearFormInteraction
     */
    void ClearFormInteraction();
    /**
     * @brief FormContactIsEmpty
     * @return
     */
    bool FormContactIsEmpty();
    /**
     * @brief FormContactIsEmptyM
     * @return
     */
    bool FormContactIsEmptyM();
    /**
     * @brief FormInteractionIsEmpty
     * @return
     */
    bool FormInteractionIsEmpty();
    /**
     * @brief FormInteractionIsEmptyM
     * @return
     */
    bool FormInteractionIsEmptyM();
    /**
     * @brief FormToDosIsEmpty
     * @return
     */
    bool FormToDosIsEmpty();
    /**
     * @brief EditContactById
     * @param id
     */
    void EditContactById(unsigned int id);
    /**
     * @brief EditInteractionById
     * @param id
     */
    void EditInteractionById(unsigned int id);
    /**
     * @brief PutDataIntoModifFieldContact
     * @param id
     */
    void PutDataIntoModifFieldContact(unsigned int id);
    /**
     * @brief PutDataIntoModifFieldInteraction
     * @param id
     */
    void PutDataIntoModifFieldInteraction(unsigned int id);
    /**
     * @brief ResetViewTableContacts
     */
    void ResetViewTableContacts();
    /**
     * @brief ResetViewTableInteractions
     */
    void ResetViewTableInteractions();
    /**
     * @brief ResetViewTableTodos
     */
    void ResetViewTableTodos();

};
#endif // MAINWINDOW_H
