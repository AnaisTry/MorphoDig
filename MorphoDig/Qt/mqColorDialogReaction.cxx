/*=========================================================================

   Program: MorphoDig
   Module:    mqColorDialogReaction.cxx


========================================================================*/
#include "mqColorDialogReaction.h"
#include "mqCoreUtilities.h"
#include "mqColorDialog.h"
#include "mqReaction.h"


//-----------------------------------------------------------------------------
mqColorDialogReaction::mqColorDialogReaction(QAction* parentObject)
  : Superclass(parentObject)
{
	this->Color_dialog = new mqColorDialog(mqCoreUtilities::mainWidget());
}

//-----------------------------------------------------------------------------
void mqColorDialogReaction::showColorDialog(mqColorDialog *Color_dialog)
{
	// fonction statique. C'est � dire que lorsqu'on clique sur "Color", on cr�e un nouvel objet.
	// la r�action, elle, est bien instanci�e � la cr�ation du menu, mais pas la fen�tre. 

  /*mqColorDialog color_dialog(mqCoreUtilities::mainWidget());
  color_dialog.exec();*/
	//Color_dialog->RefreshDialog();
	Color_dialog->show();
}
