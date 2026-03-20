#include "global.h"
#include "link_rfu.h"
#include "mystery_gift_server.h"
#include "mystery_gift_client.h"
#include "constants/union_room.h"

ALIGNED(4) const u8 gText_UR_EmptyString[] = _("");
ALIGNED(4) const u8 gText_UR_Colon[] = _(":");
ALIGNED(4) const u8 gText_UR_ID[] = _("{ID}");
ALIGNED(4) const u8 gText_UR_PleaseStartOver[] = _("请从起始的地方开始。");
ALIGNED(4) const u8 gText_UR_WirelessSearchCanceled[] = _("无线连接系统\n搜索被取消了。");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("ともだちからの れんらくを\nまっています");
ALIGNED(4) const u8 gText_UR_AwaitingCommunication[] = _("{B_COPY_VAR_1}！等待\n其他玩家的通信。");
ALIGNED(4) const u8 gText_UR_AwaitingLinkPressStart[] = _("{B_COPY_VAR_1}！等待连接！\n当所有人准备完毕后按开始键。");

ALIGNED(4) static const u8 sText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする");
ALIGNED(4) static const u8 sText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sLinkGroupActionTexts[] = {
    sText_SingleBattle,
    sText_DoubleBattle,
    sText_MultiBattle,
    sText_TradePokemon,
    sText_Chat,
    sText_DistWonderCard,
    sText_DistWonderNews,
    sText_DistWonderCard,
    sText_HoldPokemonJump,
    sText_HoldBerryCrush,
    sText_HoldBerryPicking,
    sText_HoldBerryPicking,
    sText_HoldSpinTrade,
    sText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("需要\n1名玩家。");
static const u8 sText_2PlayersNeeded[] = _("需要\n2名玩家。");
static const u8 sText_3PlayersNeeded[] = _("需要\n3名玩家。");
static const u8 sText_4PlayersNeeded[] = _("あと4にん\nひつよう");
static const u8 sText_2PlayerMode[] = _("2名玩家\n模式");
static const u8 sText_3PlayerMode[] = _("3名玩家\n模式");
static const u8 sText_4PlayerMode[] = _("4名玩家\n模式");
static const u8 sText_5PlayerMode[] = _("5名玩家\n模式");

const u8 *const gTexts_UR_PlayersNeededOrMode[][5] = {
    { // 2 players required
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    { // 4 players required
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    { // 2-5 players required
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    { // 3-5 players required
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    }
};

ALIGNED(4) const u8 gText_UR_BButtonCancel[] = _("{B_BUTTON}取消");
ALIGNED(4) static const u8 sText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouForXAccept[] = _("{B_COPY_VAR_2}为了{B_COPY_VAR_1}想要\n与你连接。接受吗？");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouShareX[] = _("{B_COPY_VAR_2}连接上了你。\n想要交换{B_COPY_VAR_1}？");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouAddToMembers[] = _("{B_COPY_VAR_2}连接上了你。\n添加到成员？");
ALIGNED(4) const u8 gText_UR_AreTheseMembersOK[] = _("{B_COPY_VAR_1}！\n这些成员准备好了吗？");
ALIGNED(4) const u8 gText_UR_CancelModeWithTheseMembers[] = _("取消和其他成员的\n{B_COPY_VAR_1}模式？");
ALIGNED(4) const u8 gText_UR_AnOKWasSentToPlayer[] = _("“OK”被发送给\n{B_COPY_VAR_1}。");

ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("其他训练家好像\n现在不可见……\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("你不能和一个太远的\n训练家进行通信。\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("其他训练家\n没有准备好。\p");

const u8 *const gTexts_UR_CantTransmitToTrainer[] = {
    sText_CantTransmitTrainerTooFar,
    sText_TrainersNotReadyYet
};

ALIGNED(4) const u8 gText_UR_ModeWithTheseMembersWillBeCanceled[] = _("和其他成员的{B_COPY_VAR_1}模式\n将要被取消。{PAUSE 0x6F}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("有1名成员\n断开。\p");

const u8 *const gTexts_UR_PlayerUnavailable[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("另一位训练家似乎\n没准备好……\p");
ALIGNED(4) const u8 gText_UR_PlayerSentBackOK[] = _("{B_COPY_VAR_1}发回“OK”！");
ALIGNED(4) const u8 gText_UR_PlayerOKdRegistration[] = _("{B_COPY_VAR_1}确认被你登录为\n成员。");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{B_COPY_VAR_1}回复，“No…”\p");
ALIGNED(4) const u8 gText_UR_AwaitingOtherMembers[] = _("{B_COPY_VAR_1}！\n等待其他成员！");
ALIGNED(4) const u8 gText_UR_QuitBeingMember[] = _("取消加入？");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("你停止加入。\p");

const u8 *const gTexts_UR_PlayerDisconnected[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) const u8 gText_UR_WirelessLinkEstablished[] = _("无线连接系统\n连接已确定。");
ALIGNED(4) const u8 gText_UR_WirelessLinkDropped[] = _("无线连接系统\n连接失败……");
ALIGNED(4) const u8 gText_UR_LinkWithFriendDropped[] = _("与好友的连接\n失败……");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{B_COPY_VAR_1}回复，“No…”");

const u8 *const gTexts_UR_LinkDropped[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = gText_UR_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = gText_UR_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("你想要加入{B_COPY_VAR_2}\n模式？");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("你想要加入{B_COPY_VAR_2}\n模式？");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("はなしかけています…\nしょうしょう おまちください"); // Unused
ALIGNED(4) const u8 gText_UR_AwaitingPlayersResponseAboutTrade[] = _("等待{B_COPY_VAR_1}的\n交换响应……");

ALIGNED(4) static const u8 sText_Communicating[] = _("通信中{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.\n{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("与{B_COPY_VAR_1}通信中{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.\n{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("请稍等{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.\n{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.{PAUSE 0x0F}.");

const u8 *const gTexts_UR_CommunicatingWait[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("嘿！有什么\n想做的吗？");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("你好！\n想要做什么？");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{B_COPY_VAR_1}：嘿，我们又见面了！\n最近怎么样？");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{B_COPY_VAR_1}：哦！{PLAYER}，你好！\n想要做什么？");

const u8 *const gTexts_UR_HiDoSomething[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("想做点什么？");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("想做点什么？");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{B_COPY_VAR_1}：你现在想要做什么？");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}‘また なにかする？");

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("有人连接上了你。{PAUSE 0x3C}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{B_COPY_VAR_1}连接上了你。{PAUSE 0x3C}");

const u8 *const gTexts_UR_PlayerContactedYou[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("等待\n另一个训练家响应……");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("等待\n{B_COPY_VAR_1}的响应…");

const u8 *const gTexts_UR_AwaitingResponse[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_AwaitingResponseCancelBButton[] = _("あいての ていあんを まっています\nビーボタンで キャンセル");

ALIGNED(4) const u8 gText_UR_ShowTrainerCard[] = _("其他训练家展示\n给你看他们的训练家卡片。\p你也要展示\n训练家卡片？");
ALIGNED(4) const u8 gText_UR_BattleChallenge[] = _("其他训练家想通过战斗挑战你。\p你想要接受挑战吗？");
ALIGNED(4) const u8 gText_UR_ChatInvitation[] = _("其他训练家邀请你聊天。\p你想要接受聊天申请吗？");
ALIGNED(4) const u8 gText_UR_OfferToTradeMon[] = _("有人愿意用一只\nLv. {DYNAMIC 0x02} {DYNAMIC 0x03}\p与你登记的\nLv. {DYNAMIC 0x00} {DYNAMIC 0x01}交换。\p你同意这次交换么？");
ALIGNED(4) const u8 gText_UR_OfferToTradeEgg[] = _("有人想要交换你\n登记的蛋。\l你想要接受交换申请吗？");
ALIGNED(4) const u8 gText_UR_ChatDropped[] = _("聊天断开。\p");
ALIGNED(4) const u8 gText_UR_OfferDeclined1[] = _("你拒绝了请求。\p");
ALIGNED(4) const u8 gText_UR_OfferDeclined2[] = _("你拒绝了请求。\p");
ALIGNED(4) const u8 gText_UR_ChatEnded[] = _("聊天中止了。\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    gText_UR_ShowTrainerCard,
    gText_UR_BattleChallenge,
    gText_UR_ChatInvitation,
    gText_UR_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("嘿！我们正在聊天。\n想要加入我们吗？");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{B_COPY_VAR_1}：嘿，{PLAYER}！\n我们正在聊天。\l想要加入我们吗？");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("哦，你好！我们正在聊天。\n想要加入我们吗？");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{B_COPY_VAR_1}：你好，{PLAYER}！\n我们在聊天。\l想要加入我们吗？");

const u8 *const gTexts_UR_JoinChat[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) const u8 gText_UR_TrainerAppearsBusy[] = _("……\n训练家好像正在忙……\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("来场对战？\n好吧，等我一下。");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("想要聊天？\n好的，等一下。");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("当然！作为“问候”\n这是我的训练家卡片。");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("战斗？当然行，\n但是我需要准备一下。");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("你想聊天？\n好的，但是请稍等。");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("作为自我介绍，我会展示\n给你我的训练家卡片。");

const u8 *const gTexts_UR_WaitOrShowCard[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("チャットだね！\nわかった ちょっと まってて！");
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("谢谢你等了这么久！\n让我们的战斗开始吧！{PAUSE 0x3C}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("好的！\n开始聊吧！{PAUSE 0x3C}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("抱歉让你久等！\n让我们开始吧！{PAUSE 0x3C}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("抱歉让你久等！\n开始聊天吧。{PAUSE 0x3C}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("交换开始。{PAUSE 0x3C}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("对战开始。{PAUSE 0x3C}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("进入聊天中……{PAUSE 0x3C}");

const u8 *const gTexts_UR_StartActivity[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("对不起！我的宝可梦看起来\n好像不太好。\l下次再战斗吧。\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("非常抱歉，但是我的宝可梦\n现在很不好……\p下次再战斗吧。\p");

const u8 *const gTexts_UR_BattleDeclined[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("嗯？我的训练家卡片……\n找不到了？\l对不起！下次展示给你吧！\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("哦？我的训练家卡片呢？……\l对不起！以后展示给你看吧！\p");

const u8 *const gTexts_UR_ShowTrainerCardDeclined[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("如果以后有什么事找我，\n尽管说！\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("如果以后有什么事找我，\n不要客气啊。\p");

const u8 *const gTexts_UR_IfYouWantToDoSomething[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) const u8 gText_UR_TrainerBattleBusy[] = _("哎呦！抱歉，\n但是我有事要做。\l下次吧，好吧？\p");
ALIGNED(4) const u8 gText_UR_NeedTwoMonsOfLevel30OrLower1[] = _("如果想要战斗，你需要\n两只宝可梦必须是\l30级以下的。\p");
ALIGNED(4) const u8 gText_UR_NeedTwoMonsOfLevel30OrLower2[] = _("如果想要战斗，你需要\n宝可梦必须是30级以下的。\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("好吧。\n随时可以来看我，好吧？\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("哦……\n请随时过来看我。\p");

// Response from partner when player declines chat
const u8 *const gTexts_UR_DeclineChat[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("不好意思！\n不能聊了。\l下次再说吧。\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("不好意思。\n现在我有事要做。\l下次再说吧。\p");

// Response from partner when they decline chat
const u8 *const gTexts_UR_ChatDeclined[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("哇！\n你太坚强了！\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("你用了那个招式？\n真是好办法！\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("就这么做！\n真是令人大开眼界！\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("你竟然可以在那种情况下\n使用那只宝可梦？\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("那个宝可梦……\n培养的真好！\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("就是这样！\n现在就是适当的招式！\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("太可怕了！\n你竟然以这种方式战斗？\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("你在选择宝可梦方面\n真有天赋！\p");

const u8 *const gTexts_UR_BattleReaction[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    }, {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("我知道了！\n受教了！\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("不要再说些搞笑的事了！\n从笑声中我感到痛苦！\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("哦？\n那种事发生了。\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("嗯……什么？\n这就是你说的？\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("那样好吗？\n我不知道。\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("哈哈！\n关于什么？\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("就是那样！\n我就是这个意思。\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("换言之……\n是！就是那样！\p");

const u8 *const gTexts_UR_ChatReaction[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    }, {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("展示训练家卡片\n作为打招呼的方式。\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("我希望我可以更好地了解你！\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("我们互相展示\n训练家卡片以求互相认识。\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("很高兴见到你。\n不要认生啊！\p");

const u8 *const gTexts_UR_TrainerCardReaction[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    }, {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("哈哈！\n我确实很想要这只宝可梦！\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("最终，一次交换使得\n宝可梦到手，圆了我长久的梦。\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("我正在交换宝可梦。\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("这只宝可梦是我在\n一次交换中获得的！\p");

const u8 *const gTexts_UR_TradeReaction[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    }, {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

const u8 gText_UR_XCheckedTradingBoard[] = _("{B_COPY_VAR_1}检查了\n交换平台。\p");
ALIGNED(4) const u8 gText_UR_RegisterMonAtTradingBoard[] = _("欢迎来到交换平台。\p你需要登记宝可梦\n来进行交换。\p你现在需要登记\n你的宝可梦吗？");
ALIGNED(4) const u8 gText_UR_TradingBoardInfo[] = _("交换平台是用来\n提供宝可梦进行交换的。\p你所做的就是把\n宝可梦进行登记。\p其他训练家可能会提供\n宝可梦是你想要交换的。\p我们希望你可以登记宝可梦\n用来交换给\l更多更多其他训练家。\p你现在需要登记\n你的宝可梦吗？");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("こうかんけいじばん の とうろくが\nかんりょう しました\pごりよう ありがとう\nございました！\p");
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("けいじばんに だれも ポケモンを\nとうろく していません\p\n");
ALIGNED(4) const u8 gText_UR_ChooseRequestedMonType[] = _("请选择宝可梦类型\n用于交换。\n");
ALIGNED(4) const u8 gText_UR_WhichMonWillYouOffer[] = _("你将会拿什么宝可梦\n用来交换呢？\p");
ALIGNED(4) const u8 gText_UR_RegistrationCanceled[] = _("登记取消。\p");
ALIGNED(4) const u8 gText_UR_RegistraionCompleted[] = _("登记完成。\p");
ALIGNED(4) const u8 gText_UR_TradeCanceled[] = _("交换被取消了。\p");
ALIGNED(4) const u8 gText_UR_CancelRegistrationOfMon[] = _("取消登记你的\nLv. {B_COPY_VAR_2} {B_COPY_VAR_1}？");
ALIGNED(4) const u8 gText_UR_CancelRegistrationOfEgg[] = _("取消登记你的蛋？");
ALIGNED(4) const u8 gText_UR_RegistrationCanceled2[] = _("登记取消。\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("こうかんを きぼうしているひとを\nひょうじします");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("こうかん したい トレーナーを\nえらんで ください");
ALIGNED(4) const u8 gText_UR_AskTrainerToMakeTrade[] = _("你想要和{B_COPY_VAR_1}\n进行交换？");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("……\nあいての へんじを まっています");
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("あなたが こうかんにだす\nポケモンが とうろくされていません\p");
ALIGNED(4) const u8 gText_UR_DontHaveTypeTrainerWants[] = _("你还没有{B_COPY_VAR_2}种类的\n宝可梦是{B_COPY_VAR_1}需要的。\p");
ALIGNED(4) const u8 gText_UR_DontHaveEggTrainerWants[] = _("你还没有蛋是\n{B_COPY_VAR_1}需要的。\p");

ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{B_COPY_VAR_1}还不能和你交换\n你的宝可梦。\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("你还不能交换\n{B_COPY_VAR_1}的宝可梦呢。\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) const u8 gText_UR_TradeOfferRejected[] = _("你的交换请求被拒绝。\p");
ALIGNED(4) const u8 gText_UR_EggTrade[] = _("蛋的交换");
ALIGNED(4) const u8 gText_UR_ChooseJoinCancel[] = _("{DPAD_UPDOWN}选择  {A_BUTTON}加入  {B_BUTTON}取消");
ALIGNED(4) const u8 gText_UR_ChooseTrainer[] = _("请选择一名训练家。");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("请选择一名训练家来进行\n单人对战。");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("请选择一名训练家来进行\n双人对战。");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("请选择队长\n进行多人对战。");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("请选择训练家来进行\n交换。");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("请选择一名训练家\n可以共享神秘卡片。");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("请选择一名训练家\n可以共享神秘新闻。");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("和宝可梦一起跳！\n请选择队长。");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("混合树果！\n请选择队长。");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("嘟嘟利摘树果！\n请选择队长。");

const u8 *const gTexts_UR_ChooseTrainer[] = {
    [LINK_GROUP_SINGLE_BATTLE] = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE] = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]  = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]         = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]  = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]   = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING] = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]   = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]   = sText_ChooseTrainerToShareWonderNews
};

ALIGNED(4) const u8 gText_UR_SearchingForWirelessSystemWait[] = _("搜索一个无线连接系统。\n等待……");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("ダブルバトルでは 2ひき いじょうの\nポケモンが ひつようです\p");
ALIGNED(4) const u8 gText_UR_AwaitingPlayersResponse[] = _("等待{B_COPY_VAR_1}的响应……");
ALIGNED(4) const u8 gText_UR_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{B_COPY_VAR_1}想要登记你\n为成员。请稍后。");
ALIGNED(4) const u8 gText_UR_AwaitingResponseFromWirelessSystem[] = _("等待从\n无线连接系统来的响应。");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("ほかの さんかしゃが そろうまで\nしょうしょう おまちください");

ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("没有卡片\n正在共享。");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("没有新闻\n正在共享。");

const u8 *const gTexts_UR_NoWonderShared[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) const u8 gText_UR_Battle[] = _("对战");
ALIGNED(4) const u8 gText_UR_Chat2[] = _("聊天");
ALIGNED(4) const u8 gText_UR_Greetings[] = _("问候");
ALIGNED(4) const u8 gText_UR_Exit[] = _("退出");

ALIGNED(4) const u8 gText_UR_Exit2[] = _("退出");
ALIGNED(4) const u8 gText_UR_Info[] = _("查看说明");
ALIGNED(4) const u8 gText_UR_NameWantedOfferLv[] = _("名字{CLEAR_TO 0x3C}想要{CLEAR_TO 0x6E}提供{CLEAR_TO 0xC6}Lv.");

ALIGNED(4) const u8 gText_UR_SingleBattle[] = _("单打对战");
ALIGNED(4) const u8 gText_UR_DoubleBattle[] = _("双打对战");
ALIGNED(4) const u8 gText_UR_MultiBattle[] = _("多人对战");
ALIGNED(4) const u8 gText_UR_PokemonTrades[] = _("宝可梦交换");
ALIGNED(4) const u8 gText_UR_Chat[] = _("聊天");
ALIGNED(4) const u8 gText_UR_Cards[] = _("卡片");
ALIGNED(4) const u8 gText_UR_WonderCards[] = _("神秘卡片");
ALIGNED(4) const u8 gText_UR_WonderNews[] = _("神秘新闻");
ALIGNED(4) const u8 gText_UR_PokemonJump[] = _("宝可梦跳绳");
ALIGNED(4) const u8 gText_UR_BerryCrush[] = _("树果混合");
ALIGNED(4) const u8 gText_UR_BerryPicking[] = _("摘树果");
ALIGNED(4) const u8 gText_UR_Search[] = _("搜索");
ALIGNED(4) const u8 gText_UR_SpinTrade[] = _("ぐるぐるこうかん");
ALIGNED(4) const u8 gText_UR_ItemTrade[] = _("アイテムトレード");

ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("这是普通卡。");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("这是青铜卡！");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("这是铜卡！");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("这是银卡！");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("这是金卡！");

const u8 *const gTexts_UR_CardColor[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) const u8 gText_UR_TrainerCardInfoPage1[] = _("这是{DYNAMIC 0x00}{DYNAMIC 0x01}的\n训练家卡片……\l{DYNAMIC 0x02}\p图鉴：{DYNAMIC 0x03}\n时间：   {DYNAMIC 0x04}:{DYNAMIC 0x05}\p");
ALIGNED(4) const u8 gText_UR_TrainerCardInfoPage2[] = _("对战：{DYNAMIC 0x00} 胜  {DYNAMIC 0x02} 负\n交换次数： {DYNAMIC 0x03} 次\p“{DYNAMIC 0x04} {DYNAMIC 0x05}\n{DYNAMIC 0x06} {DYNAMIC 0x07}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 0x01}：很高兴认识了你！{PAUSE 0x3C}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 0x01}：很高兴认识你！{PAUSE 0x3C}");

const u8 *const gTexts_UR_GladToMeetYou[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) const u8 gText_UR_FinishedCheckingPlayersTrainerCard[] = _("{DYNAMIC 0x01}的训练家卡片\n确认完毕。{PAUSE 0x3C}");
ALIGNED(4) static const u8 sText_CanceledReadingCard[] = _("取消读取卡片。");

static const struct MysteryGiftClientCmd sClientScript_DynamicError[] = {
    {CLI_RECV, MG_LINKID_DYNAMIC_MSG},
    {CLI_COPY_MSG},
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_BUFFER_FAILURE}
};

const struct MysteryGiftServerCmd gServerScript_ClientCanceledCard[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_DynamicError)},
    {SVR_SEND},
    {SVR_LOAD_MSG, PTR_ARG(sText_CanceledReadingCard)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_CLIENT_CANCELED}
};
