/*=========================================================================

   Program: MorphoDig
   Module:    mqColorDialogReaction.cxx


========================================================================*/
#include "mqCameraDialogReaction.h"
#include "mqCoreUtilities.h"
#include "mqCameraDialog.h"
#include "mqReaction.h"


//-----------------------------------------------------------------------------
mqCameraDialogReaction::mqCameraDialogReaction(QAction* parentObject)
  : Superclass(parentObject)
{
	this->cam_dialog = new mqCameraDialog(mqCoreUtilities::mainWidget());
}

//-----------------------------------------------------------------------------
void mqCameraDialogReaction::showCameraDialog(mqCameraDialog *cam_dialog)
{
	// fonction statique. C'est � dire que lorsqu'on clique sur "Camera", on cr�e un nouvel objet.
	// la r�action, elle, est bien instanci�e � la cr�ation du menu, mais pas la fen�tre. 

  //mqCameraDialog Camera_dialog(mqCoreUtilities::mainWidget());
  ///Camera_dialog.exec();
	cam_dialog->RefreshDialog();
	cam_dialog->show();

}
