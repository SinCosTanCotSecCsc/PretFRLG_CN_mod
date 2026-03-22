CableClub_OnTransition::
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

CableClub_EventScript_HideOrShowMysteryGiftMan::
	specialvar VAR_RESULT, ValidateSavedWonderCard
	goto_if_eq VAR_RESULT, FALSE, EventScript_HideMysteryGiftMan
	clearflag FLAG_HIDE_MG_DELIVERYMEN
	return

EventScript_HideMysteryGiftMan::
	setflag FLAG_HIDE_MG_DELIVERYMEN
	return

CableClub_EventScript_MysteryGiftMan::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	trywondercardscript

@ Unused
EventScript_MysteryGiftThankYou::
	msgbox Text_ThankYouForAccessingMysteryGift, MSGBOX_NPC
	end

CableClub_OnWarp::
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_CheckTurnAttendant
	.2byte 0

EventScript_CheckTurnAttendant::
	goto_if_eq VAR_0x8007, 0, EventScript_CheckTurnAttendantEnd
	turnobject VAR_0x8007, DIR_WEST
EventScript_CheckTurnAttendantEnd:
	end

CableClub_OnLoad::
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, EventScript_OnLoadFromTradeCenter
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, EventScript_OnLoadFromUnionRoom
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, EventScript_OnLoadFromBerryCrush
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_OnLoadFromGameCorner
	end

EventScript_OnLoadFromColosseum::
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

EventScript_OnLoadFromTradeCenter::
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

EventScript_OnLoadFromUnionRoom::
	call CableClub_EventScript_OpenUnionRoomBarrier
	end

EventScript_OnLoadFromBerryCrush::
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

EventScript_OnLoadFromGameCorner::
	call CableClub_EventScript_OpenGameCornerBarrier
	end

CableClub_OnFrame::
	map_script_2 VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1, CableClub_EventScript_Tutorial
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_ExitTradeCenter
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_ExitUnionRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

CableClub_EventScript_ExitLinkRoom::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_ExitMinigameRoom::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call CableClub_EventScript_CloseGameCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_CloseLinkAndExitLinkRoom::
	special CloseLink
	special HelpSystem_Enable
	special QuestLog_StartRecordingInputsAfterDeferredEvent
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_ExitTradeCenter::
	lockall
	call CableClub_EventScript_PlayerExitTradeCenter
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitTradeCenter::
	special CloseLink
	special HelpSystem_Enable
	special QuestLog_StartRecordingInputsAfterDeferredEvent
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement LOCALID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_ExitUnionRoom::
	lockall
	call CableClub_EventScript_PlayerExitUnionRoom
	call CableClub_EventScript_CloseUnionRoomBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitUnionRoom::
	special HelpSystem_Enable
	special QuestLog_StartRecordingInputsAfterDeferredEvent
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement LOCALID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_TrainerCardDataOverwritten::
	message CableClub_Text_TrainerCardDataOverwritten
	waitmessage
	playse SE_PIN
	message CableClub_Text_HopeToSeeYouAgain
	waitmessage
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_PlayerExitLinkRoom::
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	return

CableClub_EventScript_Tutorial::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox CableClub_Text_FirstTimeRightThisWay
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachCounter
	waitmovement 0
	delay 30
	msgbox CableClub_Text_ExplainWirelessClubFirstTime
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 2
	releaseall
	end

Movement_PlayerApproachCounter:
	walk_up
	walk_up
	step_end

CableClub_EventScript_WelcomeToCableClub::
	message CableClub_Text_WelcomeWhichCableClubService
	waitmessage
	delay 15
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_UnusedWelcomeToCableClub::
	msgbox CableClub_Text_WhichService
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_SelectCableClubRoom::
	setvar VAR_0x8004, 0
	multichoice 0, 0, MULTICHOICE_TRADE_CENTER_COLOSSEUM, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter
	case 1, CableClub_EventScript_Colosseum
	case 2, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_Colosseum::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SelectBattleMode::
	message CableClub_Text_PlayWhichBattleMode
	waitmessage
	multichoice 0, 0, MULTICHOICE_SINGLE_DOUBLE_MULTI_INFO_EXIT, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_SingleBattleMode
	case 1, CableClub_EventScript_DoubleBattleMode
	case 2, CableClub_EventScript_MultiBattleMode
	case 3, CableClub_EventScript_BattleModeInfo
	case 4, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_BattleModeInfo::
	msgbox CableClub_Text_ExplainBattleModes
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SingleBattleMode::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_DoubleBattleMode::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_NeedTwoMonsForDoubleBattle
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_NeedTwoMonsForDoubleBattle::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_MultiBattleMode::
	setvar VAR_0x8004, USING_MULTI_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_TryEnterColosseum::
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	message CableClub_Text_PleaseWaitBCancel
	waitmessage
	special HelpSystem_Disable
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryBattleLinkup
	waitstate
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterColosseum
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	end

CableClub_EventScript_EnterColosseum::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat LOCALID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	goto_if_eq VAR_0x8004, USING_MULTI_BATTLE, CableClub_EventScript_WarpTo4PColosseum
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_2P, 6, 8
	special DoCableClubWarp
	waitstate
	end

@ Unused
CableClub_EventScript_PlayerApproachLinkRoomRight::
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomRight
	waitmovement 0
	return

CableClub_EventScript_WarpTo4PColosseum::
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_4P, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers::
	switch VAR_0x8004
	case USING_SINGLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForSingleBattle
	case USING_DOUBLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle
	case USING_MULTI_BATTLE, CableClub_EventScript_AbortLinkNeedFourPlayers
	goto CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	end

CableClub_EventScript_AbortLinkNeedFourPlayers::
	special CloseLink
	msgbox CableClub_Text_NeedFourPlayers
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle::
	special CloseLink
	msgbox CableClub_Text_CantDoubleBattleWithXPlayers
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForSingleBattle::
	special CloseLink
	msgbox CableClub_Text_CantSingleBattleWithXPlayers
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_ConfirmNumberAndRestart::
	special CloseLink  @ Redundant
	special HelpSystem_Enable
	msgbox CableClub_Text_PleaseConfirmNumberAndRestart
	release
	end

CableClub_EventScript_TradeCenter::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_CheckPartyTradeRequirements
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	message CableClub_Text_PleaseWaitBCancel
	waitmessage
	special HelpSystem_Disable
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryTradeLinkup
	waitstate
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterTradeCenter
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	goto_if_eq VAR_RESULT, LINKUP_PLAYER_NOT_READY, CableClub_EventScript_AbortLinkPlayerNotReady
	goto_if_eq VAR_RESULT, LINKUP_PARTNER_NOT_READY, CableClub_EventScript_AbortLinkOtherTrainerNotReady
	end

CableClub_EventScript_EnterTradeCenter::
	setvar VAR_0x8004, USING_TRADE_CENTER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat LOCALID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_TRADE_CENTER, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_CheckPartyTradeRequirements::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsToTrade
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_CantTradeEnigmaBerry
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsToTrade::
	msgbox CableClub_Text_NeedTwoMonsToTrade
	setvar VAR_RESULT, FALSE
	return

CableClub_EventScript_CantTradeEnigmaBerry::
	msgbox CableClub_Text_CantTradeEnigmaBerry
	setvar VAR_RESULT, FALSE
	return

@ Record Corner is nopped in FRLG
CableClub_EventScript_RecordCorner::
	end

CableClub_EventScript_AbortLinkPlayerNotReady::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_NotSetUpForFarAwayRegion
	release
	end

CableClub_EventScript_AbortLinkOtherTrainerNotReady::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_OtherTrainerNotReady
	release
	end

CableClub_EventScript_AbortLinkConnectionError::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_LinkErrorPleaseReset
	release
	end

CableClub_EventScript_AbortLinkSomeoneNotReady::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_SomeoneIsNotReadyToLink
	release
	end

CableClub_EventScript_AbortLinkDifferentSelections::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_PlayersMadeDifferentSelections
	release
	end

CableClub_EventScript_AbortLink::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_PleaseVisitAgain
	release
	end

CableClub_EventScript_AbortMinigame::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_ComeAgain
	release
	end

@ Unused
CableClub_EventScript_CableClubWarp::
	special SetCableClubWarp
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_IncorrectNumberOfParticipants
	release
	end

CableClub_EventScript_AbortLinkPlayerHasBadEgg::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_YouHaveAMonThatCantBeTaken
	release
	end

CableClub_EventScript_WirelessClubAdjustements::
	msgbox Text_WirelessClubUndergoingAdjustments
	release
	end

CableClub_EventScript_NotReadyYet::
	msgbox Text_AppearsToBeUndergoingAdjustments
	releaseall
	end

Movement_AttendantFaceDown::
	face_down
	step_end

@ Unused
Movement_AttendantFaceRight::
	face_right
	step_end

Movement_AttendantFaceLeft::
	face_left
	step_end

Movement_PlayerExitLinkRoom::
	walk_down
	walk_down
	step_end

Movement_PlayerApproachLinkRoomRight::
	walk_right
	walk_up
	walk_up
	step_end

Movement_PlayerApproachLinkRoomLeft::
	walk_left
	walk_up
	walk_up
	step_end

Movement_PlayerEnterLinkRoom::
	walk_up
	step_end

@ Unused
Movement_PlayerFaceAttendantLeft::
	face_left
	step_end

Movement_PlayerFaceAttendantRight::
	face_right
	step_end

Movement_PlayerEnterMinigameRoom::
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

CableClub_EventScript_ShowBattleRecords::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowBattleRecords
	waitstate
	releaseall
	end

BattleColosseum_2P_EventScript_PlayerSpot0::
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_2P_EventScript_PlayerSpot1::
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot0::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot1::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot2::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger
	setvar VAR_0x8005, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot3::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger
	setvar VAR_0x8005, 3
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_4P_EventScript_CancelSpotTrigger::
	end

TradeCenter_EventScript_Chair0::
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterTradeSeat
	waitstate
	end

TradeCenter_EventScript_Chair1::
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterTradeSeat
	waitstate
	end

@ Unused
TradeCenter_EventScript_Chair2::
	setvar VAR_0x8005, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterTradeSeat
	waitstate
	end

@ Unused
TradeCenter_EventScript_Chair3::
	setvar VAR_0x8005, 3
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterTradeSeat
	waitstate
	end

@ Nop in FRLG
@ Separate labels to match GetDirectionForEventScript
RecordCorner_EventScript_Spot0::
RecordCorner_EventScript_Spot1::
RecordCorner_EventScript_Spot2::
RecordCorner_EventScript_Spot3::
	end

CableClub_EventScript_ReadTrainerCard::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_LookedAtPlayersTrainerCard
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_ReadTrainerCardColored::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_LookedAtPlayersTrainerCardColored
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_TooBusyToNotice::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_TrainerTooBusyToNotice
	closemessage
	end

BattleColosseum_2P_EventScript_Attendant::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special Script_FacePlayer
	msgbox Text_TakeSeatStartBattle
	special Script_ClearHeldMovement
	closemessage
	end

TradeCenter_EventScript_Attendant::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special Script_FacePlayer
	msgbox Text_TakeSeatStartTrade
	special Script_ClearHeldMovement
	closemessage
	end

@ Nop in FRLG
RecordCorner_EventScript_Attendant::
	end

TradeCenter_ConfirmLeaveRoom::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_TerminateLinkIfYouLeaveRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TradeCenter_TerminateLink
	erasebox 0, 0, 29, 19
	releaseall
	end

TradeCenter_TerminateLink::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	messageautoscroll Text_TerminateLinkConfirmation
	waitmessage
	special ExitLinkRoom
	end

CableClub_EventScript_DoLinkRoomExit::
	special CleanupLinkRoomState
	special ReturnFromLinkRoom
	waitstate
	end

CableClub_EventScript_UnionRoomAttendant::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg
	copyvar VAR_0x8007, VAR_LAST_TALKED
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_UnionRoomAdapterNotConnected
	message CableClub_Text_WelcomeUnionRoomEnter
	waitmessage
	goto CableClub_EventScript_AskEnterUnionRoom
	end

CableClub_EventScript_AskEnterUnionRoom::
	multichoice 18, 6, MULTICHOICE_YES_NO_INFO, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_EnterUnionRoom
	case 1, CableClub_EventScript_AbortLink
	case 2, CableClub_EventScript_UnionRoomInfo
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_UnionRoomInfo::
	message CableClub_Text_UnionRoomInfo
	waitmessage
	goto CableClub_EventScript_AskEnterUnionRoom
	end

CableClub_EventScript_EnterUnionRoom::
	call CableClub_EventScript_CheckPartyUnionRoomRequirements
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AbortLink
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	msgbox CableClub_Text_EnjoyUnionRoom
	closemessage
	special HealPlayerParty
	setvar VAR_0x8004, USING_UNION_ROOM
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	special HelpSystem_Disable
	call CableClub_EventScript_OpenUnionRoomBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat LOCALID_PLAYER, 0
	closedoor 5, 1
	waitdooranim
	special Script_ResetUnionRoomTrade
	special SetCableClubWarp
	warpspinenter MAP_UNION_ROOM, 7, 11
	waitstate
	special RunUnionRoom
	waitstate
	end

CableClub_EventScript_CheckPartyUnionRoomRequirements::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsForUnionRoom
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_NoEnigmaBerryInUnionRoom
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsForUnionRoom::
	msgbox CableClub_Text_NeedTwoMonsForUnionRoom
	goto EventScript_SetResultFalse
	end

CableClub_EventScript_NoEnigmaBerryInUnionRoom::
	msgbox CableClub_Text_NoEnigmaBerryInUnionRoom
	goto EventScript_SetResultFalse
	end

CableClub_EventScript_UnionRoomAdapterNotConnected::
	msgbox CableClub_Text_UnionRoomAdapterNotConnected
	release
	return

CableClub_EventScript_WirelessClubAttendant::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	msgbox CableClub_Text_AskAboutLinking, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_DontAskAboutLinking
	msgbox CableClub_Text_ExplainWirelessClub
	release
	return

CableClub_EventScript_DontAskAboutLinking::
	msgbox CableClub_Text_HopeYouEnjoyWirelessSystem
	release
	return

CableClub_EventScript_DirectCornerAttendant::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_WelcomeToCableClub
	message CableClub_Text_WelcomeWhichDirectCornerRoom
	waitmessage
	delay 15
	goto CableClub_EventScript_DirectCornerSelectService
	end

CableClub_EventScript_DirectCornerSelectService::
	goto_if_unset FLAG_GOT_POWDER_JAR, CableClub_EventScript_DirectCornerNoBerry
	multichoice 0, 0, MULTICHOICE_TRADE_COLOSSEUM_CRUSH, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_WirelessBerryCrush
	case 3, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_DirectCornerNoBerry::
	multichoice 0, 0, MULTICHOICE_TRADE_COLOSSEUM_2, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_WirelessTrade::
	msgbox CableClub_Text_TradePokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink
	call CableClub_EventScript_CheckPartyTradeRequirements
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AbortLink
	setvar VAR_0x8004, LINK_GROUP_TRADE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBattleSelect::
	message CableClub_Text_PlayWhichBattleMode
	waitmessage
	multichoice 0, 0, MULTICHOICE_SINGLE_DOUBLE_MULTI_INFO_EXIT, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessSingleBattle
	case 1, CableClub_EventScript_WirelessDoubleBattle
	case 2, CableClub_EventScript_WirelessMultiBattle
	case 3, CableClub_EventScript_WirelessBattleInfo
	case 4, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_WirelessSingleBattle::
	setvar VAR_0x8004, LINK_GROUP_SINGLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessDoubleBattle::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle
	setvar VAR_0x8004, LINK_GROUP_DOUBLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle
	goto CableClub_EventScript_WirelessBattleSelect
	end

CableClub_EventScript_WirelessMultiBattle::
	setvar VAR_0x8004, LINK_GROUP_MULTI_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBattleInfo::
	msgbox CableClub_Text_ExplainBattleModes
	goto CableClub_EventScript_WirelessBattleSelect
	end

CableClub_EventScript_WirelessBerryCrush::
	msgbox CableClub_Text_UseBerryCrush, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink
	special HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_NeedBerryForBerryCrush
	setvar VAR_0x8004, LINK_GROUP_BERRY_CRUSH
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_NeedBerryForBerryCrush::
	msgbox CableClub_Text_NeedBerryForBerryCrush
	goto CableClub_EventScript_DirectCornerSelectService
	end

CableClub_EventScript_SaveAndChooseLinkLeader::
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	switch VAR_0x8004
	case LINK_GROUP_TRADE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_SINGLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_DOUBLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_MULTI_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom4
	case LINK_GROUP_BERRY_CRUSH, CableClub_EventScript_ChooseLinkLeader
	end

CableClub_EventScript_ChooseLinkLeaderFrom2::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeaderOfTwo
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTICHOICE_JOIN_OR_LEAD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup2Players
	case 1, CableClub_EventScript_TryLeadGroup2Players
	case 2, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroup2Players::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup2Players
	release
	return

CableClub_EventScript_TryJoinGroup2Players::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup2Players
	release
	return

CableClub_EventScript_ChooseLinkLeaderFrom4::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeaderOfFour
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTICHOICE_JOIN_OR_LEAD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup4Players
	case 1, CableClub_EventScript_TryLeadGroup4Players
	case 2, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroup4Players::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup4Players
	release
	return

CableClub_EventScript_TryJoinGroup4Players::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup4Players
	release
	return

CableClub_EventScript_ChooseLinkLeader::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeader
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTICHOICE_JOIN_OR_LEAD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroupXPlayers
	case 1, CableClub_EventScript_TryLeadGroupXPlayers
	case 2, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroupXPlayers::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroupXPlayers
	release
	return

CableClub_EventScript_TryJoinGroupXPlayers::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroupXPlayers
	release
	return

CableClub_EventScript_TryBecomeLinkLeader::
	special HelpSystem_Disable
	special TryBecomeLinkLeader
	waitstate
	return

CableClub_EventScript_TryJoinLinkGroup::
	special HelpSystem_Disable
	special TryJoinLinkGroup
	waitstate
	return

CableClub_EventScript_EnterWirelessLinkRoom::
	messageautoscroll CableClub_Text_DirectYouToYourRoom
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat LOCALID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	waitstate
	end

CableClub_EventScript_ShowWirelessCommunicationScreen::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_NotReadyYet
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AdapterNotConnected
	special HelpSystem_Disable
	fadescreen FADE_TO_BLACK
	special ShowWirelessCommunicationScreen
	waitstate
	msgbox CableClub_Text_ParticipantsStepUpToCounter
	special HelpSystem_Enable
	releaseall
	end

CableClub_EventScript_AdapterNotConnected::
	msgbox CableClub_Text_AdapterNotConnected
	releaseall
	end

CableClub_EventScript_OpenUnionRoomBarrier::
	setmetatile 5, 3, METATILE_PokemonCenter_Floor_ShadeLeft, 0
	return

CableClub_EventScript_CloseUnionRoomBarrier::
	setmetatile 5, 3, METATILE_PokemonCenter_CounterBarrier, 1
	return

CableClub_EventScript_OpenDirectCornerBarrier::
	setmetatile 9, 3, METATILE_PokemonCenter_Floor_ShadeLeft, 0
	return

CableClub_EventScript_CloseDirectCornerBarrier::
	setmetatile 9, 3, METATILE_PokemonCenter_CounterBarrier, 1
	return

CableClub_EventScript_OpenGameCornerBarrier::
	setmetatile 5, 3, METATILE_GameCorner_CheckeredFloor_ShadeLeft, 0
	return

CableClub_EventScript_CloseGameCornerBarrier::
	setmetatile 5, 3, METATILE_GameCorner_CounterBarrier, 1
	return

CableClub_OnResume::
	special InitUnionRoom
	end

JoyfulGameCorner_EventScript_InfoMan2::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	message Text_DescribeWhichGame
	waitmessage
	multichoice 0, 0, MULTICHOICE_POKEJUMP_DODRIO, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_PokemonJumpInfo
	case 1, CableClub_EventScript_DodrioBerryPickingInfo
	case 2, CableClub_EventScript_MinigameInfoExit
	case SCR_MENU_CANCEL, CableClub_EventScript_MinigameInfoExit
	end

CableClub_EventScript_PokemonJumpInfo::
	msgbox Text_PokemonJumpInfo
	release
	end

CableClub_EventScript_DodrioBerryPickingInfo::
	msgbox Text_DodrioBerryPickingInfo
	release
	end

CableClub_EventScript_MinigameInfoExit::
	msgbox Text_TalkToManToPlay
	release
	end

JoyfulGameCorner_EventScript_MinigameAttendant::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	message Text_WelcomeCanYouWait
	waitmessage
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AdapterNotConnectedMinigame
	delay 60
	special HelpSystem_Disable
	message Text_PlayWhichGame
	waitmessage
	multichoice 0, 0, MULTICHOICE_POKEJUMP_DODRIO, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_PlayPokemonJump
	case 1, CableClub_EventScript_PlayDodrioBerryPicking
	case 2, CableClub_EventScript_AbortMinigame
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortMinigame
	end

CableClub_EventScript_PlayPokemonJump::
	setvar VAR_0x8005, 0
	special IsPokemonJumpSpeciesInParty
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_NoEligiblePkmn
	msgbox Text_EnterWhichPokemon
	setvar VAR_0x8005, 0
	special ChooseMonForWirelessMinigame
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, CableClub_EventScript_AbortMinigame
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortMinigame
	setvar VAR_0x8004, LINK_GROUP_POKEMON_JUMP
	goto CableClub_EventScript_ChooseLinkLeaderMinigame
	end

CableClub_EventScript_PlayDodrioBerryPicking::
	setvar VAR_0x8005, 1
	special IsDodrioInParty
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_NoEligiblePkmn
	msgbox Text_EnterWhichPokemon
	setvar VAR_0x8005, 1
	special ChooseMonForWirelessMinigame
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, CableClub_EventScript_AbortMinigame
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortMinigame
	setvar VAR_0x8004, LINK_GROUP_BERRY_PICKING
	goto CableClub_EventScript_ChooseLinkLeaderMinigame
	end

CableClub_EventScript_ChooseLinkLeaderMinigame::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeader
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTICHOICE_JOIN_OR_LEAD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinMinigameLinkGroup
	case 1, CableClub_EventScript_TryBecomeMinigameLinkLeader
	case 2, CableClub_EventScript_AbortMinigame
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortMinigame
	end

CableClub_EventScript_TryBecomeMinigameLinkLeader::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterMinigame
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderMinigame
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryBecomeMinigameLinkLeader
	release
	return

CableClub_EventScript_TryJoinMinigameLinkGroup::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterMinigame
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderMinigame
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinMinigameLinkGroup
	release
	return

CableClub_EventScript_EnterMinigame::
	messageautoscroll Text_AllGoodToGo
	waitmessage
	delay 120
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenGameCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerEnterMinigameRoom
	waitmovement 0
	hideobjectat LOCALID_PLAYER, 0
	release
	waitstate
	end

CableClub_EventScript_AdapterNotConnectedMinigame::
	msgbox Text_AdapterNotConnectedMinigame
	release
	end

CableClub_EventScript_NoEligiblePkmn::
	msgbox EventScript_ExplainPokemonJumpRequirements, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortMinigame
	call_if_eq VAR_0x8005, 0, CableClub_EventScript_ExplainPokemonJumpRequirements
	call_if_eq VAR_0x8005, 1, CableClub_EventScript_ExplainDodrioBerryPickingRequirements
	goto CableClub_EventScript_AbortMinigame
	end

CableClub_EventScript_ExplainPokemonJumpRequirements::
	msgbox Text_ShortJumpingPokemonAllowed
	return

CableClub_EventScript_ExplainDodrioBerryPickingRequirements::
	msgbox Text_OnlyDodrioAllowed
	return

TwoIsland_JoyfulGameCorner_EventScript_ShowPokemonJumpRecords::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	special ShowPokemonJumpRecords
	waitstate
	releaseall
	end

TwoIsland_JoyfulGameCorner_EventScript_ShowDodrioBerryPickingRecords::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	special ShowDodrioBerryPickingRecords
	waitstate
	releaseall
	end

CableClub_Text_WelcomeWhichCableClubService::
	.string "欢迎来到\n"
	.string "宝可梦有线俱乐部。\p"
	.string "你需要我们的哪一项\n"
	.string "服务呢？$"

CableClub_Text_WhichService::
	.string "你需要我们的\n"
	.string "哪一项服务呢？$"

CableClub_Text_TradeMonsUsingLinkCable::
	.string "通过GBA连接线与其他的玩家\n"
	.string "交换宝可梦。$"

CableClub_Text_BattleUsingLinkCable::
	.string "你可以通过GBA连接线\n"
	.string "与其他的训练家对战。$"

@ Unused, translated in Emerald
CableClub_Text_CloseThisMenu::
	.string "おわります$"

CableClub_Text_NeedTwoMonsForDoubleBattle::
	.string "如果想要玩双人对战，\n"
	.string "你必须至少拥有两只宝可梦。$"

CableClub_Text_NeedTwoMonsToTrade::
	.string "想要通信，你至少要有两只宝可梦。$"

CableClub_Text_CantTradeEnigmaBerry::
	.string "带着{B_COPY_VAR_1}\n"
	.string "树果的宝可梦不能进行通信。$"

CableClub_Text_PleaseWaitBCancel::
	.string "请稍等。\n"
	.string "……B键：取消$"

CableClub_Text_WhenAllPlayersReadyAConfirmBCancel::
	.string "当所有的玩家都准备好了……\n"
	.string "A键：确认\l"
	.string "B键：取消$"

CableClub_Text_StartLinkWithXPlayersAConfirmBCancel::
	.string "开始与{B_COPY_VAR_1}玩家连接。\n"
	.string "A键：确认\l"
	.string "B键：取消$"

CableClub_Text_AwaitingLinkupBCancel::
	.string "等待连接……\n"
	.string "……B键：取消$"

@ Unused, translated in Emerald
CableClub_Text_OkayToSaveProgress::
	.string "はじめる　まえに　レポートを\n"
	.string "かきますが　よろしいですか？$"

CableClub_Text_PleaseEnter::
	.string "请进。$"

CableClub_Text_DirectYouToYourRoom::
	.string "我会直接去你的房间。$"

CableClub_Text_SomeoneIsNotReadyToLink::
	.string "你的朋友没有准备好。\p"
	.string "请等所有人都准备好\n"
	.string "之后再来吧。$"

CableClub_Text_LinkErrorPleaseReset::
	.string "对不起，出现了通信错误……\n"
	.string "请重启然后再试一次。$"

CableClub_Text_PlayersMadeDifferentSelections::
	.string "通信的伙伴似乎\n"
	.string "有了不同的选择。$"

CableClub_Text_PleaseVisitAgain::
	.string "请再次光临。$"

CableClub_Text_IncorrectNumberOfParticipants::
	.string "参加的人数\n"
	.string "不正确。$"

CableClub_Text_CantSingleBattleWithXPlayers::
	.string "单人对战模式\n"
	.string "在{B_COPY_VAR_1}玩家的情况下不能玩。$"

CableClub_Text_CantDoubleBattleWithXPlayers::
	.string "双人对战模式\n"
	.string "在{B_COPY_VAR_1}玩家的情况下不能玩。$"

CableClub_Text_NeedFourPlayers::
	.string "这个战斗模式\n"
	.string "要求必须要有四个玩家。$"

CableClub_Text_PleaseConfirmNumberAndRestart::
	.string "请确认好参与游戏的\n"
	.string "玩家人数后再来。$"

Text_TerminateLinkIfYouLeaveRoom::
	.string "如果你离开这个房间\n"
	.string "通信会被中止，这样可以吗？$"

Text_TerminateLinkConfirmation::
	.string "中断连接……\n"
	.string "你会被送出这个房间。\l"
	.string "请稍等。$"

Text_TrainerTooBusyToNotice::
	.string "这个训练家很忙\n"
	.string "没空理你……$"

Text_LookedAtPlayersTrainerCard::
	.string "计分！请注意你的{B_COPY_VAR_1}\n"
	.string "训练家卡片！$"

Text_LookedAtPlayersTrainerCardColored::
	.string "计分！请注意你的{B_COPY_VAR_1}\n"
	.string "训练家卡片！$"

Text_TakeSeatStartBattle::
	.string "请找到您的座位\n"
	.string "开始您的战斗。$"

Text_TakeSeatStartTrade::
	.string "请找到您的座位\n"
	.string "开始您的交换。$"

@ Unused, leftover from RS
RecordCorner_Text_ThanksForComing::
	.string "ごりよう　ありがとう　ございました$"

CableClub_Text_TrainerCardDataOverwritten::
	.string "训练家卡片的记录\n"
	.string "会被记录下来。$"

CableClub_Text_HopeToSeeYouAgain::
	.string "我期待下次和你再见！$"

CableClub_Text_NotSetUpForFarAwayRegion::
	.string "我感到很抱歉。\p"
	.string "我们现在还没有开设\n"
	.string "与远方的训练家\l"
	.string "的通信服务……$"

CableClub_Text_OtherTrainerNotReady::
	.string "另外的训练家没有准备好。$"

CableClub_Text_YouHaveAMonThatCantBeTaken::
	.string "你拥有至少一只\n"
	.string "不能带进去的宝可梦。$"

CableClub_Text_AdapterNotConnected::
	.string "无线接收器\n"
	.string "没有正确的连接$"

CableClub_Text_ParticipantsStepUpToCounter::
	.string "参加游戏的人\n"
	.string "已经到了前台了。$"

@ Unused, translated in Emerald
CableClub_Text_Hello::
	.string "こんにちは！$"

@ Unused, translated in Emerald
CableClub_Text_PleaseWait::
	.string "しょうしょう　おまちください$"

CableClub_Text_YouMayTradeHere::
	.string "你可以在这里和其它的训练家\n"
	.string "交换宝可梦。$"

CableClub_Text_YouMayBattleHere::
	.string "你可以在这里\n"
	.string "和你的朋友对战。$"

CableClub_Text_CanMakeBerryPowder::
	.string "两到五名训练家\n"
	.string "可以在一起做树果粉末。$"

@ Unused, Record Mix nopped
CableClub_Text_CanMixRecords::
	.string "ワイヤレス　クラブでの\n"
	.string "あそびかたを　せつめいします$"

CableClub_Text_CancelSelectedItem::
	.string "取消登录的菜单道具。$"

@ Unused, translated in Emerald
CableClub_Text_WhichBattleMode::
	.string "どちらの　しょうぶに　しますか？$"

@ Unused, translated in Emerald
CableClub_Text_ReturnsToPreviousStep::
	.string "ひとつ　まえに　もどります$"

CableClub_Text_NeedBerryForBerryCrush::
	.string "想要使用树果混合服务，\n"
	.string "你需要至少一个树果。$"

CableClub_Text_NeedTwoMonsForUnionRoom::
	.string "想要进入联盟交谊厅，\n"
	.string "你至少得有两只宝可梦。$"

CableClub_Text_NoEnigmaBerryInUnionRoom::
	.string "宝可梦都没有装备{B_COPY_VAR_1}\n"
	.string "树果才能进入联盟交谊厅。$"

CableClub_Text_UnionRoomAdapterNotConnected::
	.string "这里是宝可梦无线俱乐部\n"
	.string "联盟交谊厅。\p"
	.string "不幸的是，你的\n"
	.string "无线接收器没有正确连接。\p"
	.string "请再次光临。$"

@ Unused, translated in Emerald
CableClub_Text_OhExcuseMe::
	.string "あ‥‥\n"
	.string "おきゃくさま！$"

Text_PlayerIsPlayingRightNowGoForIt::
	.string "看来{B_COPY_VAR_1}已经玩得很\n"
	.string "顺利了。\l"
	.string "上吧！$"

Text_DescribeWhichGame::
	.string "如果你乐意，\n"
	.string "我会告诉你游戏规则。\p"
	.string "哪个游戏需要我的说明？$"

Text_PokemonJumpInfo::
	.string "“宝可梦跳绳”\p"
	.string "让你的宝可梦\n"
	.string "按A键跳过藤鞭做的绳子。\p"
	.string "只有那些小于28英寸的宝可梦\n"
	.string "能够参加这个游戏。\p"
	.string "只能生活在水中，地洞中和空中\n"
	.string "的宝可梦对跳跃不删长\p"
	.string "所以呢，这些宝可梦\n"
	.string "也不能参加这个游戏。\p"
	.string "如果每个人在规定时间内完成游戏\n"
	.string "就会有好事情发生。$"

Text_DodrioBerryPickingInfo::
	.string "“嘟嘟利摘树果”\p"
	.string "控制嘟嘟利的三个头\n"
	.string "收集掉落的树果。\p"
	.string "按十字键的\n"
	.string "右，上，左键控制头部。\p"
	.string "想要玩这个游戏，\n"
	.string "你必须拥有一只嘟嘟利。$"

Text_TalkToManToPlay::
	.string "如果你想玩游戏，\n"
	.string "和我旁边这个男人说吧。$"

Text_WelcomeCanYouWait::
	.string "嗨，欢迎！\n"
	.string "通过无线连接系统\l"
	.string "你可以玩到这个游戏！\p"
	.string "可以请你稍微等一下吗？$"

CableClub_Text_ComeAgain::
	.string "没问题，请再来！$"

Text_AdapterNotConnectedMinigame::
	.string "无线接收器\n"
	.string "没有连接好。\p"
	.string "请等它连接好了再来！$"

Text_PlayWhichGame::
	.string "好的，哪一个是你想要玩\n"
	.string "的游戏？$"

Text_EnterWhichPokemon::
	.string "那只宝可梦是你想要\n"
	.string "带进去的？$"

Text_AllGoodToGo::
	.string "好了，一切都准备好了。\n"
	.string "可别让其他人把你给打败了！$"

@ Unused, translated in Emerald
Text_LeavingDoComeAgain::
	.string "きょうは　けえるのか？\n"
	.string "またこいよ！$"

EventScript_ExplainPokemonJumpRequirements::
	.string "看起来你没有能\n"
	.string "带得进去的宝可梦……\p"
	.string "需要我告诉你\n"
	.string "哪些宝可梦可以被带进去吗？$"

Text_ShortJumpingPokemonAllowed::
	.string "“宝可梦跳绳”只对\n"
	.string "尺寸小于28英寸的宝可梦开放。\p"
	.string "不能跳跃的\n"
	.string "宝可梦也不能带进去。\p"
	.string "你懂的，我时说那些宝可梦\n"
	.string "只能生活在水中，洞中，空中的。\p"
	.string "这是你必须知道的。$"

Text_OnlyDodrioAllowed::
	.string "“嘟嘟利摘树果”……\n"
	.string "嗯，这个名字说明了一切。\p"
	.string "要玩这个游戏\n"
	.string "你得拥有一只嘟嘟利。$"

@ Unused, translated in Emerald
Text_RetryFromStartPlease::
	.string "もういちど　はじめから\n"
	.string "やりなおして　みて　くれ$"

CableClub_Text_WelcomeWhichDirectCornerRoom::
	.string "欢迎来到宝可梦无线\n"
	.string "俱乐部直连房间。\p"
	.string "你可以在这里直接\n"
	.string "和你的朋友互动。\p"
	.string "你想进\n"
	.string "哪一个房间？$"

CableClub_Text_TradePokemon::
	.string "你想要交换宝可梦？$"

CableClub_Text_PlayWhichBattleMode::
	.string "哪一种战斗模式\n"
	.string "是你想要参加的？$"

CableClub_Text_UseBerryCrush::
	.string "你想要使用\n"
	.string "树果混合系统？$"

CableClub_Text_ExplainBattleModes::
	.string "这里有三种战斗模式。\p"
	.string "单人对战需要两名训练家\n"
	.string "拥有一只或一只以上的宝可梦。\p"
	.string "战斗时每名训练家\n"
	.string "只能使用一只宝可梦。\p"
	.string "双人对战需要两名训练家\n"
	.string "拥有两只以上的宝可梦。\p"
	.string "每名训练家战斗时\n"
	.string "能使用两只宝可梦。\p"
	.string "多人对战是为四名训练家\n"
	.string "和至少一只的宝可梦准备的。\p"
	.string "每名训练家战斗时\n"
	.string "可以使用一只宝可梦。$"

CableClub_Text_ChooseGroupLeaderOfTwo::
	.string "请决定\n"
	.string "你们两个人谁会成为队长。\p"
	.string "另外一个玩家选择\n"
	.string "“加入队伍。”$"

CableClub_Text_ChooseGroupLeaderOfFour::
	.string "请决定\n"
	.string "你们四个人谁会成为队长。\p"
	.string "另外的玩家选择\n"
	.string "“加入队伍。”$"

CableClub_Text_ChooseGroupLeader::
	.string "请决定\n"
	.string "你们谁会成为队长。\p"
	.string "另外一个玩家选择\n"
	.string "“加入队伍。”$"

CableClub_Text_WelcomeUnionRoomEnter::
	.string "欢迎来到宝可梦无线\n"
	.string "俱乐部联盟交谊厅。\p"
	.string "你可以和其它\n"
	.string "训练家在这里互动，\l"
	.string "可能当中会有你不认识的人。\p"
	.string "你想要进入这个房间吗？$"

CableClub_Text_UnionRoomInfo::
	.string "在联盟交谊厅的训练家\n"
	.string "可能是在你身边\l"
	.string "也进入了这个房间的玩家。\p"
	.string "你在这里可以做各种事。\n"
	.string "比如相互问候。\p"
	.string "带着30级以上的宝可梦\n"
	.string "来场一对一的战斗\p"
	.string "你可以和\n"
	.string "二到五个人聊天。\p"
	.string "或者，你也可以登记你的宝可梦\n"
	.string "进行交换。\p"
	.string "你想要进入房间吗？$"

CableClub_Text_EnjoyUnionRoom::
	.string "希望你能在\n"
	.string "联盟交谊厅度过难忘的时光。$"

CableClub_Text_FirstTimeRightThisWay::
	.string "你好！\n"
	.string "我叫青名。\p"
	.string "你应该是\n"
	.string "第一次来这里的吧！\p"
	.string "我会告诉你无线\n"
	.string "连接系统式怎样工作的。\p"
	.string "首先，我会向你展示\n"
	.string "我们宝可梦中心每层楼。\p"
	.string "请这边走。$"

CableClub_Text_ExplainWirelessClubFirstTime::
	.string "在最顶层\n"
	.string "有两个房间。\p"
	.string "首先，在左边的这个房间\n"
	.string "叫做联盟交谊厅。\p"
	.string "你可以和其它\n"
	.string "在你身边同样进入了\l"
	.string "联盟交谊厅的训练家们通信。\p"
	.string "和他们在一起，\n"
	.string "你可以做一些像聊天，交换，对战的事。\p"
	.string "然后，在右边的这个房间\n"
	.string "叫做直连房间。\p"
	.string "你可以和你的朋友在这个房间里\n"
	.string "对战和交换宝可梦。\p"
	.string "如果无线接收器不能正常\n"
	.string "工作，你可以\l"
	.string "使用GBA连接线。\p"
	.string "如果是那样的话，\n"
	.string "你必须得去直连房间了。\p"
	.string "我希望你能在无线\n"
	.string "通信系统里度过难忘的时光。$"

CableClub_Text_AskAboutLinking::
	.string "你好，{PLAYER}！\p"
	.string "是我，青名，\n"
	.string "宝可梦中心2楼的接待。\p"
	.string "关于通信的事\n"
	.string "你有需要问我的吗？$"

CableClub_Text_ExplainWirelessClub::
	.string "让我来告诉你\n"
	.string "宝可梦无线俱乐部是怎样运作的。\p"
	.string "在最顶层\n"
	.string "有两个房间。\p"
	.string "首先，在左边的这个房间\n"
	.string "叫做联盟交谊厅。\p"
	.string "你可以和其它\n"
	.string "在你身边同样进入了\l"
	.string "联盟交谊厅的训练家通信。\p"
	.string "和他们在一起，\n"
	.string "你可以做一些像聊天，交换，对战的事。\p"
	.string "然后，在右边的这个房间\n"
	.string "叫做直连房间。\p"
	.string "你可以和你的朋友在这个房间里\n"
	.string "对战和交换宝可梦。\p"
	.string "如果无线接收器不能正常\n"
	.string "使用GBA连接线。\p"
	.string "如果是那样的话，\n"
	.string "你必须得去直连房间了。\p"
	.string "我希望你能在无线\n"
	.string "通信系统里度过难忘的时光。$"

CableClub_Text_HopeYouEnjoyWirelessSystem::
	.string "我希望你能在无线\n"
	.string "通信系统里度过难忘的时光。$"
