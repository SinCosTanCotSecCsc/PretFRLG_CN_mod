@ These are event scripts. They should not be moved to C.

#include "constants/global.h"
#include "constants/flags.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "constants/region_map_sections.h"
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.include "constants/constants.inc"

	.section .rodata
	
	.align 2
MysteryEventScript_StampCard::
	setvaddress MysteryEventScript_StampCard
	setorcopyvar VAR_RESULT, 1
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	setorcopyvar VAR_RESULT, 0
	specialvar VAR_0x8009, GetMysteryGiftCardStat
	subvar VAR_0x8008, VAR_0x8009
	buffernumberstring STR_VAR_1, VAR_0x8008
	lock
	faceplayer
	vmessage sText_MysteryGiftStampCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftStampCard:
	.string "感谢使用\n"
	.string "印章卡片系统。\p"
	.string "你需要收集更多{B_COPY_VAR_1}\n"
	.string "来填满图章卡片。$"

MysteryEventScript_SurfPichu::
	setvaddress MysteryEventScript_SurfPichu
	vgoto_if_unset FLAG_MYSTERY_GIFT_DONE, SurfPichu_GiveIfPossible
	returnram

SurfPichu_GiveIfPossible:
	specialvar VAR_EVENT_PICHU_SLOT, CalculatePlayerPartyCount
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, PARTY_SIZE, SurfPichu_FullParty
	setflag FLAG_MYSTERY_GIFT_DONE
	vcall SurfPichu_GiveEgg
	lock
	faceplayer
	vmessage sText_MysteryGiftEgg
	waitmessage
	waitbuttonpress
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	release
	end

SurfPichu_FullParty:
	lock
	faceplayer
	vmessage sText_FullParty
	waitmessage
	waitbuttonpress
	release
	end

SurfPichu_GiveEgg:
	giveegg SPECIES_PICHU
	setmonmodernfatefulencounter VAR_EVENT_PICHU_SLOT
	setmonmetlocation VAR_EVENT_PICHU_SLOT, METLOC_FATEFUL_ENCOUNTER
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, 1, SurfPichu_Slot1
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, 2, SurfPichu_Slot2
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, 3, SurfPichu_Slot3
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, 4, SurfPichu_Slot4
	vgoto_if_eq VAR_EVENT_PICHU_SLOT, 5, SurfPichu_Slot5
	return

SurfPichu_Slot1:
	setmonmove 1, 2, MOVE_SURF
	return

SurfPichu_Slot2:
	setmonmove 2, 2, MOVE_SURF
	return

SurfPichu_Slot3:
	setmonmove 3, 2, MOVE_SURF
	return

SurfPichu_Slot4:
	setmonmove 4, 2, MOVE_SURF
	return

SurfPichu_Slot5:
	setmonmove 5, 2, MOVE_SURF
	return

sText_MysteryGiftEgg:
	.string "感谢使用\n"
	.string "神秘礼物系统。\p"
	.string "我们从宝可梦中心收到了\n"
	.string "一件礼物--宝可梦的蛋！\p"
	.string "请用爱和关怀\n"
	.string "尽心照顾它吧。$"

sText_FullParty:
	.string "你的队伍好像满了。\p"
	.string "请存一只宝可梦到pc后\n"
	.string "再到我这里来。$"

MysteryEventScript_VisitingTrainer::
	setvaddress MysteryEventScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryEventScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainer
	waitmessage
	waitbuttonpress
	release
	end

MysteryEventScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainer_2
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainer:
	.string "感谢使用\n"
	.string "神秘礼物系统。\p"
	.string "因为你持有神秘卡片，\n"
	.string "你可以参与一项在\l"
	.string "宝可梦商店进行的调查。\p"
	.string "通过这些调查你可以\n"
	.string "训练家们来到七岛。\p"
	.string "…我来给你一个\n"
	.string "用于调查的密码吧：\p"
	.string "“GIVE ME\n"
	.string "AWESOME TRAINER”\p"
	.string "把这个写在调查上\n"
	.string "并发送至无线通讯系统。$"

sText_MysteryGiftVisitingTrainer_2:
	.string "感谢使用\n"
	.string "神秘礼物系统。\p"
	.string "有一位训练家为了找你，\n"
	.string "已经抵达了七岛。\p"
	.string "希望你能尽情享受\n"
	.string "与这位来访训练家的对战。\p"
	.string "你也可以输入其他密码来\n"
	.string "邀请其他训练家。\p"
	.string "试着找到其他可能有用的密码吧。$"

MysteryEventScript_BattleCard::
	setvaddress MysteryEventScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryEventScript_BattleCardInfo
	setorcopyvar VAR_RESULT, 2
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, 3, MysteryEventScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_2
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryEventScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "感谢使用\n"
	.string "神秘礼物系统。\p"
	.string "你的战斗积分卡保留着\n"
	.string "你和其他拥有相同卡的\l"
	.string "训练家战斗录像。\p"
	.string "寻找和你持有相同卡的\n"
	.string "训练家进行战斗吧。\p"
	.string "你可以阅读新闻来\n"
	.string "获知总排名。\p"
	.string "一定要试试看哦！$"

sText_MysteryGiftBattleCountCard_2:
	.string "感谢使用\n"
	.string "神秘礼物系统。\p"
	.string "恭喜你了！\p"
	.string "由于在三场对战中获得了优胜，\n"
	.string "你获得了奖励！\p"
	.string "我们希望你在后面的对战中\n"
	.string "再接再厉。$"

MysteryEventScript_AuroraTicket::
	setvaddress MysteryEventScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_FOUGHT_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET, 1
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicket1
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET, 1
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicket2
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketNoPlace
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketGot
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicket1:
	.string "感谢使用\n"
	.string "神秘礼物系统。\p"
	.string "你是{PLAYER}吧？\n"
	.string "这张船票是给你的。$"

sText_AuroraTicket2:
	.string "似乎是在枯叶市港口才能使用的。\p"
	.string "为什么不试一试来\n"
	.string "看看这到底有什么用。$"

sText_AuroraTicketGot:
	.string "感谢使用\n"
	.string "神秘礼物系统。$"

sText_AuroraTicketNoPlace:
	.string "{PLAYER}，很抱歉。\n"
	.string "你包里的重要道具口袋已经满了。\p"
	.string "请先存一些东西在你的电脑中，\n"
	.string "然后再回来。$"

MysteryEventScript_MysticTicket::
	setvaddress MysteryEventScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_FOUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_FOUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET, 1
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicket2
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET, 1
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicket1
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketNoPlace
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketGot
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicket2:
	.string "感谢使用\n"
	.string "神秘礼物系统。\p"
	.string "你是{PLAYER}吧？\n"
	.string "这张船票是给你的。$"

sText_MysticTicket1:
	.string "似乎是在枯叶市港口才能使用的。\p"
	.string "为什么不试一试来\n"
	.string "看看这到底有什么用。$"

sText_MysticTicketGot:
	.string "感谢使用\n"
	.string "神秘礼物系统。$"

sText_MysticTicketNoPlace:
	.string "{PLAYER}，很抱歉。\n"
	.string "你包里的重要道具口袋已经满了。\p"
	.string "请先存一些东西在你的电脑中，\n"
	.string "然后再回来。$"

MysteryEventScript_AlteringCave::
	setvaddress MysteryEventScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, 10, MysteryEventScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryEventScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "感谢使用\n"
	.string "神秘礼物系统。\p"
	.string "最近，出现了一些有关\n"
	.string "稀有宝可梦出没的传闻。\p"
	.string "据说和在外岛上的变化洞窟有关。\p"
	.string "如果传闻是真的，\n"
	.string "何不去一探究竟？$"
