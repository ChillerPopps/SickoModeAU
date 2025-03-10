#include "pch-il2cpp.h"
#include "_hooks.h"
#include "state.hpp"
#include "logger.h"
#include "utility.h"

void dFungleShipStatus_OnEnable(FungleShipStatus* __this, MethodInfo* method)
{
	FungleShipStatus_OnEnable(__this, method);

	try {
		Replay::Reset();

		State.MatchStart = std::chrono::system_clock::now();
		State.MatchCurrent = State.MatchStart;

		State.selectedDoor = SystemTypes__Enum::Hallway;
		State.mapDoors.clear();
		State.pinnedDoors.clear();

		il2cpp::Array allDoors = __this->fields._.AllDoors;

		for (auto door : allDoors) {
			if (std::find(State.mapDoors.begin(), State.mapDoors.end(), door->fields.Room) == State.mapDoors.end())
				State.mapDoors.push_back(door->fields.Room);
		}

		std::sort(State.mapDoors.begin(), State.mapDoors.end());

		State.mapType = Settings::MapType::Fungle;

		if (!State.DisableSMAU && State.confuser && State.confuseOnStart)
			ControlAppearance(true);
	}
	catch (...) {
		LOG_DEBUG("Exception occurred in FungleShipStatus_OnEnable (FungleShipStatus)");
	}
}