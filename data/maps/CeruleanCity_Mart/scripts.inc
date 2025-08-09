CeruleanCity_Mart_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Youngster::
	msgbox CeruleanCity_Mart_Text_RepelWorksOnWeakMons, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Woman::
	msgbox CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Clerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeruleanCity_Mart_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeruleanCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

CeruleanCity_Mart_EventScript_TmClerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	goto_if_unset FLAG_BADGE02_GET, CeruleanCity_Mart_EventScript_TmClerkNotReady
	message Text_MayIHelpYou
	waitmessage
	pokemart CeruleanCity_Mart_TMs
	msgbox Text_PleaseComeAgain
	release
	end

CeruleanCity_Mart_EventScript_TmClerkNotReady::
	msgbox PewterCity_Mart_Text_NotReadyComeBackLater, MSGBOX_NPC
	end

	.align 2
CeruleanCity_Mart_TMs::
	.2byte ITEM_TM48
	.2byte ITEM_TM49
	.2byte ITEM_TM03
	.2byte ITEM_NONE
	release
	end
