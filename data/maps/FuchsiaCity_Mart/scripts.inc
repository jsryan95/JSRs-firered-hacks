FuchsiaCity_Mart_MapScripts::
	.byte 0

FuchsiaCity_Mart_EventScript_CooltrainerF::
	msgbox FuchsiaCity_Mart_Text_DidYouTryXSpeed, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Gentleman::
	msgbox FuchsiaCity_Mart_Text_DontTheyHaveSafariZonePennants, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Clerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart FuchsiaCity_Mart_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
FuchsiaCity_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

FuchsiaCity_Mart_EventScript_TmClerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, FuchsiaCity_Mart_EventScript_TmClerkNotReady
	message Text_MayIHelpYou
	waitmessage
	pokemart FuchsiaCity_Mart_TMs
	msgbox Text_PleaseComeAgain
	release
	end

FuchsiaCity_Mart_EventScript_TmClerkNotReady::
	msgbox PewterCity_Mart_Text_NotReadyComeBackLater, MSGBOX_NPC
	end

	.align 2
FuchsiaCity_Mart_TMs::
	.2byte ITEM_TM06
	.2byte ITEM_TM07
	.2byte ITEM_TM11
	.2byte ITEM_TM18
	.2byte ITEM_TM37
	.2byte ITEM_NONE
	release
	end
