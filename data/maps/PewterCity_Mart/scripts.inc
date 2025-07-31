PewterCity_Mart_MapScripts::
	.byte 0

PewterCity_Mart_EventScript_Youngster::
	msgbox PewterCity_Mart_Text_BoughtWeirdFishFromShadyGuy, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Boy::
	msgbox PewterCity_Mart_Text_GoodThingsIfRaiseMonsDiligently, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Clerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart PewterCity_Mart_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
PewterCity_Mart_Items::
	.2byte ITEM_POKE_BALL
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

PewterCity_Mart_EventScript_TmClerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	goto_if_unset FLAG_BADGE01_GET, PewterCity_Mart_EventScript_TmClerkNotReady
	message Text_MayIHelpYou
	waitmessage
	pokemart PewterCity_Mart_TMs
	msgbox Text_PleaseComeAgain
	release
	end

PewterCity_Mart_EventScript_TmClerkNotReady::
	msgbox PewterCity_Mart_Text_NotReadyComeBackLater, MSGBOX_NPC
	end

	.align 2
PewterCity_Mart_TMs::
	.2byte ITEM_TM20
	.2byte ITEM_TM39
	.2byte ITEM_NONE
	release
	end
