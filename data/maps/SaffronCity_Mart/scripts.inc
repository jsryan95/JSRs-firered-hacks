SaffronCity_Mart_MapScripts::
	.byte 0

SaffronCity_Mart_EventScript_Lass::
	msgbox SaffronCity_Mart_Text_ReviveIsCostly, MSGBOX_NPC
	end

SaffronCity_Mart_EventScript_Youngster::
	msgbox SaffronCity_Mart_Text_MaxRepelMoreEffectiveThanSuper, MSGBOX_NPC
	end

SaffronCity_Mart_EventScript_Clerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart SaffronCity_Mart_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
SaffronCity_Mart_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

SaffronCity_Mart_EventScript_TmClerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	goto_if_unset FLAG_BADGE06_GET, SaffronCity_Mart_EventScript_TmClerkNotReady
	message Text_MayIHelpYou
	waitmessage
	pokemart SaffronCity_Mart_TMs
	msgbox Text_PleaseComeAgain
	release
	end

SaffronCity_Mart_EventScript_TmClerkNotReady::
	msgbox PewterCity_Mart_Text_NotReadyComeBackLater, MSGBOX_NPC
	end

	.align 2
SaffronCity_Mart_TMs::
	.2byte ITEM_TM04
	.2byte ITEM_TM09
	.2byte ITEM_TM47
	.2byte ITEM_TM48
	.2byte ITEM_NONE
	release
	end
