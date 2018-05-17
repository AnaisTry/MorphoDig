/*=========================================================================

   Program: MorphoDig
   Module:    mqColorDialogReaction.cxx


========================================================================*/
#include "mqSaveMAPDialogReaction.h"
#include "mqCoreUtilities.h"
#include "mqSaveMAPDialog.h"
#include "mqReaction.h"
#include "mqMorphoDigCore.h"
#include <vtkType.h>
#include <QFileDialog>
#include <QMessageBox>

//-----------------------------------------------------------------------------
mqSaveMAPDialogReaction::mqSaveMAPDialogReaction(QAction* parentObject)
  : Superclass(parentObject)
{

}

void mqSaveMAPDialogReaction::onTriggered()
{
	
		
		cout << "Save MAP Dialog Triggered!" << endl;


		


		mqSaveMAPDialogReaction::showSaveMAPDialog();
		
		
		
}

//-----------------------------------------------------------------------------
void mqSaveMAPDialogReaction::showSaveMAPDialog()
{
	// fonction statique. C'est � dire que lorsqu'on clique sur SAVE MAP, on cr�e un nouvel objet.
	// la r�action, elle, est bien instanci�e � la cr�ation du menu, mais pas la fen�tre. 

  mqSaveMAPDialog SaveMAP_dialog(mqCoreUtilities::mainWidget());
  SaveMAP_dialog.exec();
}
