#pragma once

#include "windows.h"
#include <string>
#include <vector>

#include "../Structs.hpp"
#include "../WwiseHijack.hpp"

namespace VoiceOverControl {
	void PlayVoiceOver(VoiceOver voiceOver);

	inline std::vector<VoiceOver> VO_ResultsScreens{
		VoiceOver("play_VO_RESULTSSCREEN_001_07NARRATOR_DRY_26331", "Adequate Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_04NARRATOR_DRY_26328", "Alright Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_29NARRATOR_DRY_26351", "Amazing Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_05NARRATOR_DRY_26329", "Average Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_10NARRATOR_DRY_26334", "Awesome Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_15NARRATOR_DRY_26312", "Bad Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_15NARRATOR_DRY_26284", "Brilliant Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_23NARRATOR_DRY_26320", "Can Do Better"),
		VoiceOver("play_VO_RESULTSSCREEN_001_29NARRATOR_DRY_26286", "Comin' Along Nicely"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_22NARRATOR_DRY_26319", "Could Be Better"),
		VoiceOver("play_VO_RESULTSSCREEN_001_36NARRATOR_DRY_26293", "Could Be Worse"),
		VoiceOver("play_VO_RESULTSSCREEN_001_13NARRATOR_DRY_26337", "Dazzling Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_31NARRATOR_DRY_26288", "Decent Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_13NARRATOR_DRY_26310", "Disappointing Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_38NARRATOR_DRY_26295", "Don't Quit Your Day Job"),
		VoiceOver("play_VO_RESULTSSCREEN_001_22NARRATOR_DRY_26344", "Excellent Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_09NARRATOR_DRY_26306", "Excellent Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_23NARRATOR_DRY_26345", "Exceptional Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_26NARRATOR_DRY_26348", "Exemplary Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_11NARRATOR_DRY_26308", "Fantastic Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_17NARRATOR_DRY_26339", "Fantastic Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_14NARRATOR_DRY_26311", "Feeble Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_08NARRATOR_DRY_26332", "Fine Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_16NARRATOR_DRY_26338", "First Rate Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_12NARRATOR_DRY_26336", "Flawless Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_18NARRATOR_DRY_26315", "Getting Better"),
		VoiceOver("play_VO_RESULTSSCREEN_001_33NARRATOR_DRY_26290", "Getting Better"),
		VoiceOver("play_VO_RESULTSSCREEN_001_09NARRATOR_DRY_26333", "Good Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_03NARRATOR_DRY_26300", "Good Try"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_19NARRATOR_DRY_26316", "Good Work"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_06NARRATOR_DRY_26303", "Great Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_01NARRATOR_DRY_26325", "Great Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_37NARRATOR_DRY_26294", "Keep Practicing"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_27NARRATOR_DRY_26324", "Masterful Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_20NARRATOR_DRY_26342", "Masterful Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_28NARRATOR_DRY_26350", "Mindblowing Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_08NARRATOR_DRY_26305", "Must Try Harder"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_01NARRATOR_DRY_26298", "Need More Practice"),
		VoiceOver("play_VO_RESULTSSCREEN_001_32NARRATOR_DRY_26289", "Needs Some More Practice"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_21NARRATOR_DRY_26318", "Needs More Practice"),
		VoiceOver("play_VO_RESULTSSCREEN_001_28NARRATOR_DRY_26285", "Needs Some Work"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_20NARRATOR_DRY_26317", "Needs Some Work"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_31NARRATOR_DRY_26353", "Nice Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_30NARRATOR_DRY_26287", "Nice Playing"),
		VoiceOver("play_VO_RESULTSSCREEN_001_03NARRATOR_DRY_26327", "Not Bad Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_35NARRATOR_DRY_26292", "Not Too Bad"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_02NARRATOR_DRY_26299", "Not Too Bad"),
		VoiceOver("play_VO_RESULTSSCREEN_001_02NARRATOR_DRY_26326", "Okay Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_04NARRATOR_DRY_26301", "Okay Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_18NARRATOR_DRY_26340", "Outstanding Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_27NARRATOR_DRY_26349", "Passable Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_25NARRATOR_DRY_26321", "Perfect Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_11NARRATOR_DRY_26335", "Perfect Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_07NARRATOR_DRY_26304", "Poor Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_34NARRATOR_DRY_26291", "Pretty Good Playin'"),
		VoiceOver("play_VO_RESULTSSCREEN_001_21NARRATOR_DRY_26343", "Rockstar Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_16NARRATOR_DRY_26313", "Rough Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_06NARRATOR_DRY_26330", "Satisfactory Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_24NARRATOR_DRY_26346", "Spectacular Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_17NARRATOR_DRY_26314", "Subpar Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_30NARRATOR_DRY_26352", "Superb Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_10NARRATOR_DRY_26307", "Superb Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_14NARRATOR_DRY_26283", "Superb Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_24NARRATOR_DRY_26322", "Top Notch Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_26NARRATOR_DRY_26323", "True Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_25NARRATOR_DRY_26347", "Unparallel Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_05NARRATOR_DRY_26302", "Very Good Performance"),
		VoiceOver("play_VO_RESULTSSCREEN2_001_12NARRATOR_DRY_26309", "Weak Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_19NARRATOR_DRY_26341", "Wonderful Performance"),
		VoiceOver("play_VO_RESULTSSCREEN_001_39NARRATOR_DRY_26296", "You're Gonna Be A Superstar"),
	};

	inline VoiceOver selectedVoiceOver;
}