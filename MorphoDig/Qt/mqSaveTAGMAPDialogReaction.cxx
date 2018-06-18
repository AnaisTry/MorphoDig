/*=========================================================================

   Program: MorphoDig
   Module:    mqTAGMAPDialogReaction.cxx


========================================================================*/
#include "mqSaveTAGMAPDialogReaction.h"
#include "mqCoreUtilities.h"
#include "mqSaveTAGMAPDialog.h"
#include "mqReaction.h"
#include "mqMorphoDigCore.h"
#include <vtkType.h>
#include <QFileDialog>
#include <QMessageBox>

//-----------------------------------------------------------------------------
mqSaveTAGMAPDialogReaction::mqSaveTAGMAPDialogReaction(QAction* parentObject)
  : Superclass(parentObject)
{

}

void mqSaveTAGMAPDialogReaction::onTriggered()
{
	
		
		cout << "Save TAGMAP Dialog Triggered!" << endl;


		


		mqSaveTAGMAPDialogReaction::showSaveTAGMAPDialog();
		
		
		
}

//-----------------------------------------------------------------------------
void mqSaveTAGMAPDialogReaction::showSaveTAGMAPDialog()
{
	// fonction statique. C'est � dire que lorsqu'on clique sur SAVE TAGMAP, on cr�e un nouvel objet.
	// la r�action, elle, est bien instanci�e � la cr�ation du menu, mais pas la fen�tre. 

  mqSaveTAGMAPDialog SaveTAGMAP_dialog(mqCoreUtilities::mainWidget());
  SaveTAGMAP_dialog.exec();
}
