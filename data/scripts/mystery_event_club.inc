.equ GAVE_PROFILE,  VAR_TEMP_1

MysteryEventClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq GAVE_PROFILE, TRUE, EventScript_AlreadyGaveProfile
	goto_if_set FLAG_SYS_SET_TRAINER_CARD_PROFILE, EventScript_GivenProfileBefore
	msgbox Text_IdLoveToHearYourProfile
	goto EventScript_AskForProfile
	end

EventScript_AlreadyGaveProfile:
	msgbox Text_TellMoreNextTime
	release
	end

EventScript_AskForProfile:
	message Text_TellMeWhatsYourProfile
	waitmessage
	multichoice 18, 6, MULTICHOICE_YES_NO_INFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveProfile
	case 1, EventScript_DeclineGiveProfile
	case 2, EventScript_ProfileInfo
	case SCR_MENU_CANCEL, EventScript_DeclineGiveProfile
	end

EventScript_ProfileInfo:
	msgbox Text_ExplainProfile
	goto EventScript_AskForProfile
	end

EventScript_AcceptGiveProfile:
	msgbox Text_WhatsYourProfile
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_CancelGiveProfile:
	msgbox Text_DecidedNotTo
	release
	end

EventScript_GaveProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatMessage
	waitmessage
	delay 80
	msgbox Text_ProfileSaysSomethingAboutYou
	release
	end

EventScript_DeclineGiveProfile:
	msgbox Text_DontBeLikeThat
	release
	end

EventScript_GivenProfileBefore:
	msgbox Text_HiWeMeetAgain
	goto EventScript_AskForNewProfile
	end

EventScript_AskForNewProfile:
	message Text_ChangeYourProfile
	waitmessage
	multichoice 18, 6, MULTICHOICE_YES_NO_INFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveNewProfile
	case 1, EventScript_DeclineGiveNewProfile
	case 2, EventScript_ProfileInfo2
	case SCR_MENU_CANCEL, EventScript_DeclineGiveNewProfile
	end

EventScript_ProfileInfo2:
	msgbox Text_ExplainProfile
	goto EventScript_AskForNewProfile
	end

EventScript_AcceptGiveNewProfile:
	msgbox Text_WhatAreYouLikeNow
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_DeclineGiveNewProfile:
	msgbox Text_LikeProfileWayItIs
	release
	end

EventScript_GaveSpecialProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatMessage
	waitmessage
	delay 80
	msgbox Text_HeardThatBefore
	release
	end

EventScript_GiveProfile:
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_0x8004, 0, EventScript_GaveSpecialProfile
	goto_if_eq VAR_RESULT, FALSE, EventScript_CancelGiveProfile
	goto_if_eq VAR_RESULT, TRUE, EventScript_GaveProfile
	end

Text_IdLoveToHearYourProfile:
	.string "嗨，见到你真高兴！\p"
	.string "……可能对你来说有点不友好。\n"
	.string "为什么不也问候一下我呢？\p"
	.string "来吧，\n"
	.string "告诉我关于你的事。\p"
	.string "我很乐意听到你的自我介绍！$"

Text_TellMeWhatsYourProfile:
	.string "告诉我关于你一些好的事情。\n"
	.string "你的自我介绍是？$"

Text_ExplainProfile:
	.string "一份简介\n"
	.string "由四个短语组成。\p"
	.string "你的简介可以由\n"
	.string "各种各样的词来组成。\p"
	.string "短语和词语放在\n"
	.string "了便于找到的词组中。\p"
	.string "首先，选择一个词组，\n"
	.string "然后再选择一个词语或短语。\p"
	.string "……做起来比听起来更容易。\n"
	.string "你为什么不来试一试呢？$"

Text_WhatsYourProfile:
	.string "你的自我介绍是？$"

Text_DontBeLikeThat:
	.string "啊……别这样。\n"
	.string "你可以告诉我你的资料。$"

Text_DecidedNotTo:
	.string "哦，你又不想做了？\n"
	.string "你真善变，不是吗？$"

Text_HiWeMeetAgain:
	.string "嗨！\n"
	.string "我们再次见面了！$"

Text_ChangeYourProfile:
	.string "你想要改改你的个人简介吗？$"

Text_WhatAreYouLikeNow:
	.string "你现在的爱好是什么？\n"
	.string "我很乐意知道噢。$"

Text_LikeProfileWayItIs:
	.string "好样的，\n"
	.string "看起来你很满意你的个人资料了。\p"
	.string "我也是这么想的。$"

Text_ProfileSaysSomethingAboutYou:
	.string "嗯……\p"
	.string "你的个人简介清楚的说明了\n"
	.string "你是一个什么样的人。\p"
	.string "既然我对你的了解更深了。 \n"
	.string "就让我们成为更好的朋友吧！$"

Text_HeardThatBefore:
	.string "喔，我曾经听说过这个事…\p"
	.string "我的侄子住在离这儿很远的地方，\n"
	.string "曾经说起过这个事。$"

Text_TellMoreNextTime:
	.string "下次见面时\n"
	.string "请告诉我关于你更多的事吧！$"
