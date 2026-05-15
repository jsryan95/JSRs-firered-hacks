PokemonMansion_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_B1F_OnLoad
	.byte 0

PokemonMansion_B1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_B1F
	end

PokemonMansion_B1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 3
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_B1F_EventScript_DiarySep1st::
	msgbox PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful, MSGBOX_SIGN
	end

PokemonMansion_B1F_EventScript_Lewis::
	trainerbattle_single TRAINER_BURGLAR_LEWIS, PokemonMansion_B1F_Text_LewisIntro, PokemonMansion_B1F_Text_LewisDefeat
	msgbox PokemonMansion_B1F_Text_LewisPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_EventScript_Ivan::
	trainerbattle_single TRAINER_SCIENTIST_IVAN, PokemonMansion_B1F_Text_IvanIntro, PokemonMansion_B1F_Text_IvanDefeat
	msgbox PokemonMansion_B1F_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_EventScript_Bill::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_PIN
	applymovement LOCALID_MANSION_BILL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MANSION_BILL, Common_Movement_Delay48
	waitmovement 0
	faceplayer
	msgbox CinnabarIsland_Text_HeyIfItIsntPlayer
	msgbox CinnabarIsland_Text_ComeWithMeToOneIsland
	closemessage
	delay 10
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 7, PokemonMansion_B1F_EventScript_BillExitBottom
	call PokemonMansion_B1F_EventScript_BillExit
	removeobject LOCALID_MANSION_BILL
	setflag FLAG_HIDE_POKEMON_MANSION_B1F_BILL
	clearflag FLAG_HIDE_CINNABAR_BILL
	releaseall
	end

PokemonMansion_B1F_EventScript_BillExitBottom::
	applymovement LOCALID_MANSION_BILL, PokemonMansion_B1F_Movement_BillExitBottom
	waitmovement 0
	return

PokemonMansion_B1F_EventScript_BillExit::
	applymovement LOCALID_MANSION_BILL, PokemonMansion_B1F_Movement_BillExit
	waitmovement 0
	return

PokemonMansion_B1F_Movement_BillExitBottom::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PokemonMansion_B1F_Movement_BillExit::
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
