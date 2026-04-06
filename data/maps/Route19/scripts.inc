Route19_MapScripts::
	.byte 0

Route19_EventScript_RouteSign::
	msgbox Route19_Text_RouteSign, MSGBOX_SIGN
	end

Route19_EventScript_Lapras::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_LAPRAS, 30
	waitse
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special QuestLog_CutRecording
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route19_EventScript_FoughtLapras
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route19_EventScript_FoughtLapras
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route19_EventScript_FoughtLapras
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Route19_EventScript_FoughtLapras
	setflag FLAG_FOUGHT_ROUTE19_LAPRAS
	release
	end

Route19_EventScript_FoughtLapras::
	setflag FLAG_FOUGHT_ROUTE19_LAPRAS
	goto EventScript_RemoveStaticMon
	end
