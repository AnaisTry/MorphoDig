/*=========================================================================

   Program: MorphoDig
   Module:    mqColorDialogReaction.cxx


========================================================================*/
#include "mqSaveMHDMHADialogReaction.h"
#include "mqCoreUtilities.h"
#include "mqSaveMHDMHADialog.h"
#include "mqReaction.h"
#include "mqMorphoDigCore.h"
#include <vtkType.h>
#include <QFileDialog>
#include <QMessageBox>

//-----------------------------------------------------------------------------
mqSaveMHDMHADialogReaction::mqSaveMHDMHADialogReaction(QAction* parentObject)
  : Superclass(parentObject)
{
}

void mqSaveMHDMHADialogReaction::onTriggered()
{
	
		vtkIdType num_selected_volumes = mqMorphoDigCore::instance()->getVolumeCollection()->GetNumberOfSelectedVolumes();
		if (num_selected_volumes == 0) {
			QMessageBox msgBox;
			msgBox.setText("No volume selected. Please select at least one volume to use this option.");
			msgBox.exec();
			return;
		}
		else if (num_selected_volumes > 1)
		{
			QMessageBox msgBox;
			msgBox.setText("More than one volume are currently selected. Please only select one volume");
						
			msgBox.exec();
			 return; 

		}

		
		
		cout << "Save MHDMHA Dialog Triggered!" << endl;
		QString fileName;		
			mqMorphoDigCore::instance()->ComputeSelectedNamesLists();
			 fileName = QFileDialog::getSaveFileName(mqMorphoDigCore::instance()->GetMainWindow(),
				tr("Save MHD or MHA files"), mqMorphoDigCore::instance()->Getmui_LastUsedDir() + QDir::separator() + mqMorphoDigCore::instance()->g_distinct_selected_names.at(0).c_str(),
				tr("MHD (*.mhd);; MHA (*.mha);; (*.*)"), NULL
				//, QFileDialog::DontConfirmOverwrite
			);
		

		cout << fileName.toStdString();
		if (fileName.isEmpty()) return;
		QFileInfo fileInfo(fileName);
		mqMorphoDigCore::instance()->Setmui_LastUsedDir(fileInfo.path());

		

		mqSaveMHDMHADialogReaction::showSaveMHDMHADialog(fileName);
}

//-----------------------------------------------------------------------------
void mqSaveMHDMHADialogReaction::showSaveMHDMHADialog(QString fileName)
{
	// fonction statique. C'est � dire que lorsqu'on clique sur SAVE MHDMHA, on cr�e un nouvel objet.
	// la r�action, elle, est bien instanci�e � la cr�ation du menu, mais pas la fen�tre. 

  mqSaveMHDMHADialog SaveMHDMHA_dialog(mqCoreUtilities::mainWidget(), fileName);
  SaveMHDMHA_dialog.exec();
}
