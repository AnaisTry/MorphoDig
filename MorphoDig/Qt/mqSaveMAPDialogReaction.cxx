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
	vtkIdType num_Norm = 0;
	vtkIdType num_T = 0;
	vtkIdType num_Node = 0;
	vtkIdType num_H = 0;
	
		num_Norm = mqMorphoDigCore::instance()->getNormalLandmarkCollection()->GetNumberOfItems();
		num_H = mqMorphoDigCore::instance()->getTargetLandmarkCollection()->GetNumberOfItems();
		num_Node = mqMorphoDigCore::instance()->getNodeLandmarkCollection()->GetNumberOfItems();
		num_H = mqMorphoDigCore::instance()->getHandleLandmarkCollection()->GetNumberOfItems();
	
	
		if (num_Norm==0&& num_T==0&&num_Node==0&&num_H == 0) {
			QMessageBox msgBox;
			msgBox.setText("No landmark nor curve element  exist...");
			msgBox.exec();
			return;
		}
		
		cout << "Save MAP Dialog Triggered!" << endl;


		

		/*if (QFile::exists(fileName))
		{
		QMessageBox msgBox;
		msgBox.setText("Overwrite?");
		msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		msgBox.setDefaultButton(QMessageBox::No);
		int ret = msgBox.exec();
		if (ret == QMessageBox::No) { return; }



		}*/

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
